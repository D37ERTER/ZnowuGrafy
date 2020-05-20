#include "grafyLepsze.h"

void szukajHamiltonMacSas1(int i, int * out, int * oi, bool * odwiedzone, bool * znaleziono) //i - prztwarzany wierzcholek
{
    odwiedzone[i] = true;
    out[(*oi)++] = i; //dodawanie do out;
    if(*oi == v) //sprawdzanie czy wszystkie wierzcholki byly odwiedzone
    {
        if(macSas[i][1] == 1) //sprawdzanie czy mozna wrocic do pierwszego
        {
            *znaleziono = true; //znaleziono cykl mozna konczyc szukanie
            return;
        }
        odwiedzone[i] = false; //usuwanie z out i wracanie
        (*oi)--;
        return;
    }
    for(int j=1; j<=v; j++) //szukanie wierzcholkow do przejscia
    {
        if(macSas[i][j] == 1 && !odwiedzone[j])
        {
        	cout<<"13H"<<endl;
            szukajHamiltonMacSas1(j, out, oi, odwiedzone, znaleziono); //przechodzenie do kolejnego wierzcholka
            if(*znaleziono) //jak znaleziono cykl to przestan szukac
                return;
        }
    }
    odwiedzone[i] = false; //usuwanie z out i wracanie
    (*oi)--;
}

void szukajHamiltonMacSas()
{
    int out[v+1] = {0}; //tablica wynikowa
    int oi = 0; //out index
    bool odwiedzone[v+1] = {0}; //informacja o odwiedzeniu wierzcholka
    bool znaleziono = false; //informacja o znalezieniu cyklu i konczeniu szukania
    cout<<"11H"<<endl;
	szukajHamiltonMacSas1(1, out, &oi, odwiedzone, &znaleziono);
	cout<<"12H"<<endl;
    if(!znaleziono) //nie udalo sie znalezc cyklu
    {
        cout << "Graf wejsciowy nie zawiera cyklu." << endl;
        return;
    }
    out[oi++] = 1;
    cout << endl;
    for(int i=0; i<v+1; i++) //wypisywanie wyniku
        cout << out[i] << endl;
}

void szukajHamiltonListNast1(int i, int * out, int * oi, bool * odwiedzone, bool * znaleziono) //i - prztwarzany wierzcholek
{
    odwiedzone[i] = true;
    out[(*oi)++] = i; //dodawanie do out;
    if(*oi == v) //sprawdzanie czy wszystkie wierzcholki byly odwiedzone
    {
        if(lisNast[i] && lisNast[i]->dane == 1) //sprawdzanie czy mozna wrocic do pierwszego
        {
            *znaleziono = true; //znaleziono cykl mozna konczyc szukanie
            return;
        }
        odwiedzone[i] = false; //usuwanie z out i wracanie; znalazlo scieszke Hamiltona ale nie cykl
        (*oi)--;
        return;
    }
    listaElem * e = lisNast[i];
    while(e) //szukanie wierzcholkow do przejscia
    {
        if(!odwiedzone[e->dane])
        {
            szukajHamiltonListNast1(e->dane, out, oi, odwiedzone, znaleziono); //przechodzenie do kolejnego wierzcholka
            if(*znaleziono) //jak znaleziono cykl to przestan szukac
                return;
        }
        e=e->next;
    }
    odwiedzone[i] = false; //usuwanie z out i wracanie
    (*oi)--;
}

void szukajHamiltonListNast()
{
    int out[v+1] = {0}; //tablica wynikowa
    int oi = 0; //out index
    bool odwiedzone[v+1] = {0}; //informacja o odwiedzeniu wierzcholka
    bool znaleziono = false; //informacja o znalezieniu cyklu i konczeniu szukania
    szukajHamiltonListNast1(1, out, &oi, odwiedzone, &znaleziono);
    if(!znaleziono) //nie udalo sie znalezc cyklu
    {
        cout << "Graf wejsciowy nie zawiera cyklu." << endl;
        return;
    }
    out[oi++] = 1;
    cout << endl;
    for(int i=0; i<v+1; i++) //wypisywanie wyniku
        cout << out[i] << endl;
}

tproc hamilton[]=
{
	szukajHamiltonMacSas,
	szukajHamiltonListNast
};
