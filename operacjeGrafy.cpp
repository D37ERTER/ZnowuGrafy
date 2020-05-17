#include "grafyLepsze.h"

//tworzenie grafu
void utworzMacSas(int v)
{
	usun[czySkierowany]();
    macSas.resize(v+1);
    for (int i=0;i<macSas.size();i++)
    {
    	macSas[i].resize(v+1,0);
    	macSas[i][0]=i;
    	macSas[0][i]=i;
	}
}

void utworzLisNast(int v)
{
	//usun[czySkierowany]();
    lisNast = new listaElem * [v+1];
    for(int i=1; i<=v; i++)
        lisNast[i] = NULL;
}

tproc1arg utworz[] =
{
	utworzMacSas,
    utworzLisNast
};


//szukanie krawędzi
bool znajdzMacSas(int x, int y)
{
    if (macSas[x][y]==1||macSas[y][x]==1)
		return true;
	else
        return false;
}

bool znajdzLisNast(int x, int y)
{
	listaElem * teraz = lisNast[x];
	while(teraz && teraz->dane <=y)
	{
		if(teraz->dane==y)
			return true;
		teraz=teraz->next;
	}
	return false;
}

tbool znajdz[] =
{
	znajdzMacSas,
    znajdzLisNast
};


//dodawanie krawędzi
void dodajDoMacSas(int x, int y)
{
    macSas[x][y] = 1;
    macSas[y][x] = 1;
}

void dodajDoLisNast(int x, int y) //dodawanie w sposposob posortowany
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

tproc2arg dodaj[] =
{
	dodajDoMacSas,
    dodajDoLisNast
};


//usuwanie grafu z pamięci
void usunMacSas()
{
	macSas.clear();
}

void usunLisNast()
{
	listaElem * usun;
	for (int i=1;i<=v;i++)
    {
        while(lisNast[i] && lisNast[i]->next)
        {
            usun=lisNast[i]->next;
            lisNast[i]->next=lisNast[i]->next->next;
            delete usun;
        }
        if(lisNast[i]) delete lisNast[i];
    }
	if(lisNast) delete lisNast;
}

tproc usun[] =
{
	usunMacSas,
	usunLisNast
};

void naprawMacSas()
{
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            if(macSas[i][j]==-2)
                macSas[i][j]=1;
        }
    }
}

void eulerujMacSas() // nie dzia�a
{
	int stopien;
	int dodawany;
	for(int i=1;i<=v;i++)
	{
		stopien = 0;
		for(int j=1;j<=v;j++)
		{
			if (macSas[i][j]==1) stopien++;
		}
		if (stopien%2==1)
		{
			dodawany = i + 1 + rand() % (v-i-1);
			if (macSas[i][dodawany]==1)
			{
				macSas[i][dodawany]=0;
				macSas[dodawany][i]=0;
			}
			else
			{
				macSas[i][dodawany]=1;
				macSas[dodawany][i]=1;
			}
		}
	}
}
