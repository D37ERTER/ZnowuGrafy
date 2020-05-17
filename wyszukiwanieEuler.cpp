#include "grafyLepsze.h"

void szukajEulerMacSas1(int i)
{
    for(int j=1; j<=v; j++)
    {
        if(macSas[i][j] == 1) //szukanie krawedzi
        {
            macSas[i][j] = -2; // usuwanie krawedzi; wartosc -2 to usunieta krawedz
            macSas[j][i] = -2;
            szukajEulerMacSas1(j);
        }
    }
    cout << i << endl; //dodawanie wierzcholka do sciezki nie trzeba tablicy wynikowej bo krawedzie moga byc na odwrot
}

void szukajEulerMacSas() //po wykonaniu potrzeba "naprawy" macierzy
{
    int pierwszyNieizolowany = 0; //w grafie z cyklem moga byc izolowane wierzcholki i nie mozna od nich zaczac :P
    int sumaKrawedzi = 0; //suma krawedzi incydentych z wierzcholkiem
    for(int i=1; i<=v; i++) //sprawdzanie czy ilosc krawedzi incydentych jest parzysta dla kazdego wierzcholka
    {
        for(int j=1; j<=v; j++)
        {
            if(macSas[i][j] == 1)
            {
                if(pierwszyNieizolowany == 0)
                    pierwszyNieizolowany = i;
                sumaKrawedzi++;
            }
        }
        if(sumaKrawedzi%2 == 1)
        {
            cout << "Graf wejsciowy nie zawiera cyklu." << endl;
            return;
        }
    }
    if(pierwszyNieizolowany == 0)
    {
        cout << "Nie ma zadnych krawedzi, czyli w sumie jest to cykl eulera." << endl;
        return;
    }
    cout << endl;
    szukajEulerMacSas1(pierwszyNieizolowany);
}

void szukajEulerListNast1(int i, int * out, int * oi)
{
    while(lisNast[i]) //dla kazdej wychodzacej krawedzi
    {
        listaElem * e = lisNast[i]; //zapamietywanie pierwszej krawedzi
        lisNast[i] = lisNast[i]->next; //usuwanie pierwszej krawedzi
        szukajEulerListNast1(e->dane, out, oi);
        delete e;
        out[(*oi)++] = i; //dodawanie wierzcholka do sciezki
    }
}

void szukajEulerListNast() //zmienia zawartosc listy
{
    int pierwszyNieizolowany = 0; //w grafie z cyklem moga byc izolowane wierzcholki i nie mozna od nich zaczac :P
    int sumaIn[v+1] = {0}, sumaOut[v+1] = {0}; //stopnie in i out wierzcholkow
    for(int i=1; i<=v; i++) //liczenie stopni in i out
    {
        listaElem * e = lisNast[i];
        while(e)
        {
            sumaOut[i]++;
            sumaIn[e->dane]++;
            e=e->next;
        }
    }
    for(int i=1; i<=v; i++) //sprawdzanie czy: stopien in = stopnien out
    {
        if(sumaIn[i] != sumaOut[i])
        {
            cout << "Graf wejsciowy nie zawiera cyklu." << endl;
            return;
        }
    }
    for(int i=1; i<=v; i++) //szukanie pierwszego nieizolowanego wierzcholka
    {
        if(sumaOut[i]>0)
        {
            pierwszyNieizolowany = i;
            break;
        }
    }
    if(pierwszyNieizolowany == 0)
    {
        cout << "Nie ma zadnych krawedzi, czyli w sumie jest to cykl eulera." << endl;
        return;
    }
    int out[e+1] = {0}; //tablica wynikowa jest potrzebna bo luki nie dzialaja w 2 strony
    int oi = 0; //out index
    out[oi++] = pierwszyNieizolowany;
    szukajEulerListNast1(pierwszyNieizolowany, out, &oi);
    if(oi < e+1)
    {
        cout << "Graf wejsciowy jest niespojny, wiec graf wejsciowy nie zawiera cyklu." << endl;
        return;
    }
    cout << endl;
    for(int i=e;i>=0;i--) //wypisywanie wyniku
        cout << out[i] << endl;
}

tproc euler[]=
{
	szukajEulerMacSas,
	szukajEulerListNast
};
