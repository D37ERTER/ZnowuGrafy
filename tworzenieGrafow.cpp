#include "grafyLepsze.h"

void utworzMacSas(int v)
{
    macSas = new short * [v];
    for(int i=0; i<v; i++)
        macSas[i] = new short[v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            macSas[i][j] = 0;
    }
}

int dodajDoMacSas(int x, int y)
{
    macSas[x][y] = 1;
    macSas[y][x] = -1;
    return 0;
}

void utworzLisNast(int v)
{
    lisNast = new listaElem * [v];
    for(int i=0; i<v; i++)
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

void utworzLosowo() //nowe dostosowane do cykli
{
    cout << "Tworzenie grafu losowo." << endl;
    v = zKonsoli(0, 2000, "podaj ilosc wierzcholkow: ", "Niepoprawna ilosc. (musi byc od 0 do 2000)");
    int p = zKonsoli(0, 2000, "podaj procent nasycenia krawedziami [%]: ", "Niepoprawna ilosc procent.");
    e = v*(v-1)*p/200;
    utworzMacSas(v);
    utworzLisNast(v);
    cout << "Losowanie lukow." << endl;
    int maxE = v*(v-1); // max numer luku
    bool wylosowaneLuki[maxE]; //true jeżeli luk już istnieje
    for(int i=0; i<maxE ;i++)
        wylosowaneLuki[i] = false;
    int wylos; // wylosowany numer luku
    int wylosOdrot; //numer luku w druga strone (trzeba go też zablokowac)
    int x; //poczatek luku
    int y; //koniec luku

    cout <<"ilosc: " << e << endl;
    for(int i=0; i<e; i++) // i - index luku
    {
        if(e>10 &&!(i%(e/10)))
            cout << (i*100)/e << "%  " << endl;
        do
            wylos = (rand()*rand()) % maxE;
        while(wylosowaneLuki[wylos]);

        x = wylos/(v-1);
        y = wylos%(v-1);
        y += (x <= y);
        wylosOdrot = y*(v-1) + x - (y<x);
        wylosowaneLuki[wylos] = true;
        wylosowaneLuki[wylosOdrot] = true;

        dodajDoMacSas(x, y);
        dodajDoLisNast(x, y);
    }
    cout << "100%" << endl;
}

void utworzLosowoTest(int wierzcholki, int procenty) //nowe dostosowane do cykli (wersja do testów na sprawozdanie)
{
    v = wierzcholki;
    e = v*(v-1)*procenty/200;
    utworzMacSas(v);
    utworzLisNast(v);
    int maxE = v*(v-1); // max numer luku
    bool wylosowaneLuki[maxE]; //true jeżeli luk już istnieje
    for(int i=0; i<maxE ;i++)
        wylosowaneLuki[i] = false;
    int wylos; // wylosowany numer luku
    int wylosOdrot; //numer luku w druga strone (trzeba go też zablokowac)
    int x; //poczatek luku
    int y; //koniec luku

    for(int i=0; i<e; i++) // i - index luku
    {
        do
            wylos = (rand()*rand()) % maxE;
        while(wylosowaneLuki[wylos]);

        x = wylos/(v-1);
        y = wylos%(v-1);
        y += (x <= y);
        wylosOdrot = y*(v-1) + x - (y<x);
        wylosowaneLuki[wylos] = true;
        wylosowaneLuki[wylosOdrot] = true;

        dodajDoMacSas(x, y);
        dodajDoLisNast(x, y);
    }
}

void utworzZKonsoli()
{
    cout << "Tworzenie grafu z konsoli." << endl;
    v = zKonsoli(0,1000,"podaj ilosc wierzcholkow: ", "Niepoprawna ilosc.");
    e = zKonsoli(0,v*(v-1)*0.5,"podaj ilosc lukow: ", "Niepoprawna ilosc.");
    utworzMacSas(v);
    utworzLisNast(v);
    cout << "Wprowadzanie lukow z konsoli." << endl;
    int err; //kod bledu
    int x, y; //poczatek i koniec lukow
    for(int i=0; i<e; i++)
    {
        do
        {
            x = zKonsoli(1, v, "podaj poczatek luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.") -1;
            y = zKonsoli(1, v, "podaj koniec luku (" + toString(i+1) + "/" + toString(e) + "): ", "Bledne id wierzcholka.") -1;

            err = dodajDoMacSas(x, y);
            if(err == -1)
                cout << "Luki nie moga byc petlami wlasnymi (nie moga wychodzic i wchodzic do tego samego wierzcholka)." << endl;
            else if(err == -2)
                cout << "Taki luk juz istnieje (nie ma multigrafow)." << endl;
            else if(err == -3)
                cout << "Taki luk spowoduje cykl." << endl;
        }
        while(err<0);
        dodajDoLisNast(x, y);
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
        if(e>v*(v-1)*0.5)
        {
            cout << "Zbyt duzo lukow." << endl;
            plik.close();
            return;
        }
        utworzMacSas(v);
        utworzLisNast(v);
        int err; //kod bledu
        int x, y; //poczatek i koniec lukow
        while(!plik.eof())
        {
            plik >> x;
            plik >> y;
            x--;
            y--;
            err = dodajDoMacSas(x, y);
            if(err == -1)
                cout << "Plik zawiera wierzolki z petlami wlasnymi." << endl;
            else if(err == -2)
                cout << "Graf zapisany w plku jest multigrafem." << endl;
            else if(err == -3)
                cout << "Graf posiada cykl." << endl;
            if(err < 0)
            {
                plik.close();
                return;
            }
            dodajDoLisNast(x, y);
        }
    }
    else
    {
        cout << "Niepoprawna lokalizacja. :C";
    }
    plik.close();
}
