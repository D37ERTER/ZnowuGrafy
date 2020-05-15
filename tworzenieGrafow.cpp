#include "grafyLepsze.h"

tbool znajdz[]=  //mo¿liwe ¿e nie dzi³a bo trzeba przenieœæ pod deklaracjê(nwm czy w "grafyLepsze.h" nie wystarczy, tyczy siê ka¿dej, dla ró¿nej liczby argumentów trzeba nowej deklaracji
{
	znajdzMacSas,
    znajdzLisNast
};

bool znajdzMacSas(int x, int y)
{
	if (macSas[x][y]==1||macSas[y][x]==1)
		return true;
	else return false;
}

bool znajdzLisNast(int x, int y)
{
	if (lisNast[x]==NULL)
		return true;
	listaElem* teraz=lisNast[x];
	do
	{
		if (teraz->dane==y)
			return true;
		teraz=teraz->next;
	} while (teraz!=lisNast[x]);
	return false;
}

void utworzMacSas(int v)
{
    /*macSas = new short * [v];
    for(int i=0; i<v; i++)
        macSas[i] = new short[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            macSas[i][j] = 0;
    }*/
    macSas.resize(v+1);
    for (int i=0;i<macSas.size();i++)
    {
    	macSas[i].resize(v+1,0);
    	macSas[i][0]=i;
    	macSas[0][i]=i;
	}
}

void dodajDoMacSas(int x, int y)
{
    macSas[x][y] = 1;
    macSas[y][x] = 1;
}

void utworzLisNast(int v)
{
    lisNast = new listaElem * [v+1];
    for(int i=0; i<v+1; i++)
        lisNast[i] = NULL;
}

void dodajDoLisNast(int x, int y)
{
    if(lisNast[x] && lisNast[x]->dane < y)
    {
        listaElem * rodz = lisNast[x];
        while(rodz->next && rodz->next->dane < y)
            rodz = rodz->next;
        listaElem * nowy = new listaElem;
        nowy->next = rodz->next;
        nowy->dane = y;
        rodz->next = nowy;
    }
    else
    {
        listaElem * nowy = new listaElem;
        nowy->next = lisNast[x];
        nowy->dane = y;
        lisNast[x] = nowy;
    }
}

tproc1arg utworz[]=	//mo¿liwe ¿e nie dzi³a bo trzeba przenieœæ pod deklaracjê(nwm czy w "grafyLepsze.h" nie wystarczy
{
	utworzMacSas,
    utworzLisNast
};

tproc2arg dodaj[]=
{
	dodajDoMacSas,
    dodajDoLisNast
};

void utworzLosowo() 
{
    cout << "Tworzenie grafu losowo." << endl;
    v = zKonsoli(0, 1000, "podaj ilosc wierzcholkow: ", "Nie poprawna ilosc. (musi byc od 0 do 2000)");
    int p = zKonsoli(0, 100, "podaj procent nasycenia krawedziami [%]: ", "Nie poprawna ilosc procent.");
    e = v*(v-1)*p*(1+czySkierowany)/200;
    utworz[czySkierowany](v);
    cout << "Tworzenie losowej tablicy." << endl;
    cout << "Losowanie lukow." << endl;
    int x; //poczatek luku w "poprawnej" numeracji
    int y; //koniec luku w "poprawnej" numeracji

    cout <<"ilosc: " << e << endl;
    for(int i=0; i<e; i++) 
    {
        cout << (i*100)/e << "%  " << endl;
        
        do
        {
            x = 1 + rand() % v;
            y = 1 + rand() % v;
            
            if(x == y || znajdz[czySkierowany](x,y))
            {
                continue;
        	}
            else
            {
               dodaj[czySkierowany] (x,y);
               break;
            }
        }
        while(true);
    }
    cout << "100%" << endl;
}

void utworzZKonsoli()
{
    cout << "Tworzenie grafu z konsoli." << endl;
    v = zKonsoli(0,1000,"podaj ilosc wierzcholkow: ", "Nie poprawna ilosc.");
    e = zKonsoli(0,v*(v-1)*0.5*(1+czySkierowany),"podaj ilosc lukow: ", "Nie poprawna ilosc.");
    utworz[czySkierowany](v);
    cout << "Wprowadzanie lukow z konsoli." << endl;
    //int err; //kod bledu
    int x, y; //poczatek i koniec lukow
    for(int i=0; i<e; i++)
    {
        do
        {
            x = zKonsoli(1, v, "podaj poczatek luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.");
            y = zKonsoli(1, v, "podaj koniec luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.");
            
            if(x == y)
            {
                cout << "Plik zawiera wierzolki z petlami wlasnymi." << endl;
        	}
            else if(znajdz[czySkierowany](x,y))
            {
                cout << "Graf zapisany w plku jest multigrafem." << endl;
        	}
            else
            {
               dodaj[czySkierowany] (x,y);
               break;
            }
        }
        while(true);
    }
}

void utworzZPliku()
{
    string loc;
    fstream plik;
    cout << "Generowanie grafu z plku." << endl;
    cout << "podaj lokalizacje pliku: ";
    cin >> loc;
    plik.open(loc.c_str(), ios::in);
    if(plik.good())
    {
        plik >> v;
        plik >> e;
        if(e>v*(v-1)*0.5*(1+czySkierowany)) //graf pe³ny nieskierowany ma n*(n-1)/2 wiêc graf skierowany mo¿e miêc 2 razy wiêcej. Prawda?
        {
            cout << "Zbyt duzo lukow." << endl;
            plik.close();
            return;
        }
        utworz[czySkierowany](v);
        //int err; //kod bledu
        int x, y; //poczatek i koniec lukow
        while(!plik.eof())
        {
            plik >> x;
            plik >> y;
            if(x == y)
            {
                cout << "Plik zawiera wierzolki z petlami wlasnymi." << endl;
                plik.close();
                return;
        	}
            else if(znajdz[czySkierowany](x,y))
            {
                cout << "Graf zapisany w plku jest multigrafem." << endl;
                plik.close();
                return;
        	}
            else
            {
               dodaj[czySkierowany] (x,y);
            }
        }
    }
    else
    {
        cout << "Niepoprawna lokalizacja. :C";
    }
    plik.close();
}
