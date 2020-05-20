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
    //grafy
    extern int v, e;
    extern vector<vector<short>> macSas;
    extern listaElem ** lisNast;
    extern bool czySkierowany;
    extern bool czyPusto;
	extern listaElem ** kopia;

    //funkcje konsola
    int toInt(string s);
    string toString(int i);
    int zKonsoli(int minv, int maxv, string komunikat, string blad);
    int zKonsoli(string komunikat, string blad);
    void wypEl(int element);

    //funkcje wypisywania grafow
    extern tproc wysw[];

    //operacje na grafach
    extern tproc1arg utworz[];
    extern tbool znajdz[];
    extern tproc2arg dodaj[];
    extern tproc usun[];
    void naprawMacSas();

    //funckcje tworzenia grafow
    void utworzLosowo();
    void utworzZKonsoli();
    void utworzZPliku();

    //funkcje wyszukiwania cykli
    extern tproc hamilton[];
    extern tproc euler[];
    void szukajHamiltonMacSas();
    void szukajHamiltonListNast();
    void szukajEulerMacSas();
    void szukajEulerListNast();

    //extern tproc euleruj[];
    listaElem ** kopiaLisNast();
	
	void utworzMacSas(int v);
	void utworzLisNast(int v);
	void utworzLisNast(int v);
	bool znajdzMacSas(int x, int y);
	bool znajdzLisNast(int x, int y);
	void dodajDoMacSas(int x, int y);
	void dodajDoLisNast(int x, int y);
	void usunMacSas();
	void usunLisNast();
	
	void test();
	void utworzLosowoTesty(int w, int p);

#endif
