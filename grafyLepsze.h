#ifndef GRAFY_H
#define GRAFY_H

    #include <iostream> //konsola
    #include <fstream> //pliki
    #include <stdlib.h> //random
    #include <time.h>   //random
    #include <queue> //kolejka
    #include <chrono> //czas

    using namespace std;

    //struktury
    struct listaElem
    {
        listaElem * next;
        short dane;
    };
    //zmienne globalne (main) - grafy
    extern int v, e;
    extern short ** macSas;
    extern listaElem ** lisNast;

    //funkcje konsola
    int toInt(string s);
    string toString(int i);
    int zKonsoli(int minv, int maxv, string komunikat, string blad);
    int zKonsoli(string komunikat, string blad);
    void wypEl(int element);

    //funkcje wypisywania grafow
    void wypiszMacSas();
    void wypiszLisNast();

    //funckcje tworzenia grafow
    short ** kopiujMacSas();
    listaElem ** kopiujLisNast();
    void utworzLosowo();
    void utworzLosowoTest(int wierzcholki, int procenty);
    void utworzZKonsoli();
    void utworzZPliku();

    //funkcje wyszukiwania Hamilton
    void szukajHamiltonMacSas();
    void szukajHamiltonListNast();

    //funkcje wyszukiwania Euler
    void szukajEulerMacSas(short ** macSas, int v, int e);
    void szukajEulerListNast(listaElem ** lisNast, int v, int e);




#endif
