#include "grafyLepsze.h"

void szukajEulerMacSas1(int i)
{
    for(int j=1; j<=v; j++)
    {
        if(macSas[i][j] == 1)
        {
            macSas[i][j] = -2;
            macSas[j][i] = -2;
            szukajEulerMacSas1(j);
        }
    }
    cout << i << endl;
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
        cout << "Nie ma ¿adnych krawêdzi, czyli w sumie jest to cykl eulera." << endl;
        return;
    }
    szukajEulerMacSas1(pierwszyNieizolowany);
}

void szukajEulerListNast1()
{

}

void szukajEulerListNast()
{

}

tproc euler[]=
{
	szukajEulerMacSas,
	szukajEulerListNast
};
