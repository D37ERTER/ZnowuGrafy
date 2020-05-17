#include "grafyLepsze.h"

void wypiszMacSas()
{
    cout << "Wypisywanie macierzy sasiectwa: " << endl;
    for(int i=0; i<macSas.size(); i++)
    {
        for(int j=0; j<macSas[i].size(); j++)
        	wypEl(macSas[i][j]);
        cout << endl;
    }
}

void wypiszLisNast()
{
    cout << "Wypisywanie listy nastepnikow: " << endl;
    for(int i=1; i<v+1; i++)
    {
        cout << i << ": ";
        listaElem * e = lisNast[i];
        while(e)
        {
            cout << "->" << e->dane;
            e = e->next;
        }
        cout << endl;
    }
}

tproc wysw[]=
{
	wypiszMacSas,
	wypiszLisNast
};
