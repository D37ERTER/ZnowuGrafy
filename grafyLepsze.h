#ifndef GRAFY_H
#define GRAFY_H

    #include <iostream> //konsola
    #include <fstream> //pliki
    #include <stdlib.h> //random
    #include <time.h>   //random
    #include <queue> //kolejka
    #include <chrono> //czas
	#include <vector>
	
    using namespace std;
	
	typedef void (*tproc)();
	typedef void (*tproc1arg)(int v);
	typedef void (*tproc2arg)(int x, int y);
	typedef bool (*tbool)(int x, int y);
	
    //struktury
    struct listaElem
    {
        listaElem * next;
        short dane;
    };
    //zmienne globalne (main) - grafy
    extern int v, e;
    //extern short ** macSas;
    extern vector<vector<short>> macSas;
    extern listaElem ** lisNast;
    extern bool czySkierowany;

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
    void utworzLosowo();
    void utworzLosowoTest(int wierzcholki, int procenty);
    void utworzZKonsoli();
    void utworzZPliku();

    //funkcje wyszukiwania Hamilton
    void szukajHamiltonMacSas();
    void szukajHamiltonListNast();

    //funkcje wyszukiwania Euler
    void szukajEulerMacSas();
    void szukajEulerListNast();
	
	
	bool znajdzMacSas(int x, int y);
	bool znajdzLisNast(int x, int y);
	void usunMacSas();
	void usunLisNast();
	

#endif
