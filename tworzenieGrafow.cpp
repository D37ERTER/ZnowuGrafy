#include "grafyLepsze.h"

void utworzLosowo()
{
    cout << "Tworzenie grafu losowo." << endl;
    v = zKonsoli(0, 1000, "podaj ilosc wierzcholkow: ", "Nie poprawna ilosc. (musi byc od 0 do 1000)");
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
        if(e >= 10 && i%(e/10) == 0)
            cout << (i*100)/e << "%  " << endl;
        do
        {
            x = 1 + rand() % v;
            y = 1 + rand() % v;
        }
        while(x == y || znajdz[czySkierowany](x,y));
        dodaj[czySkierowany] (x,y);

    }
    cout << "100%" << endl;
    czyPusto = false;
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
                cout << "Nie można dodac luku bedacego petla wlasna." << endl;
        	}
            else if(znajdz[czySkierowany](x,y))
            {
                cout << "Taki luk juz istnieje." << endl;
        	}
            else
            {
               break;
            }
        }
        while(true);
        dodaj[czySkierowany] (x,y);
    }
    czyPusto = false;
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
        if(e>v*(v-1)*(2-czySkierowany)) //graf pe�ny nieskierowany ma n*(n-1)/2 wi�c graf skierowany mo�e mi�c 2 razy wi�cej. Prawda?
        {
            cout << "Zbyt duzo lukow." << endl;
            plik.close();
            czyPusto = true;
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
                czyPusto = true;
                return;
        	}
            else if(znajdz[czySkierowany](x,y))
            {
                cout << "Graf zapisany w plku jest multigrafem." << endl;
                plik.close();
                czyPusto = true;
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
        czyPusto = true;
    }
    plik.close();
    czyPusto = false;
}
