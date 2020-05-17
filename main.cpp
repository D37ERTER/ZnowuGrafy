#include "grafyLepsze.h"


//grafy w pamieci
int v, e;
vector<vector<short>> macSas;
listaElem ** lisNast;
bool czySkierowany;
bool czyPusto = true;


void rodzajG()
{
	cout<<"Podaj jaki rodzaj grafu chcesz wygenerowac: "<<endl;
	cout<<"1 - Graf skierowany"<<endl;
	cout<<"2 - Graf nieskierowany"<<endl;
	int jaki = zKonsoli(1, 2, "","Bledne polecenie.");
	if (jaki == 1)
        czySkierowany=true;
	else if (jaki == 2)
        czySkierowany=false;
}

int main()
{
    srand(time(NULL));
    cout << "Witaj w PRAWIE najlepszym programie do szukania cykli w grafach. (v 0.1.4)"<< endl;
    int opcjaI;
    bool zamykanie = false;
    v=0;
    e=0;
    while(!zamykanie)
    {
        cout << endl;
        if(czyPusto)
            cout << "Brak grafu w pamieci" << endl;
        else if(czySkierowany)
            cout << "Pamiec : graf skierowany" << endl;
        else
            cout << "Pamiec : graf nieskierowany" << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1 - Utworz graf z liczb losowych" << endl;
        cout << "2 - Utworz graf z danych wpisanych w konsoli" << endl;
        cout << "3 - Utworz graf z pliku" << endl;
        if(!czyPusto)
        {
            cout << "4 - Wyswietl graf" << endl;
            cout << "5 - Szukaj cykl Hamiltona" << endl;
            cout << "6 - Szukaj cykl Eulera" << endl;
            cout << "7 - Zamknij program" << endl;
        }
        else
        {
            cout << "4 - Zamknij program" << endl;
        }

        cout << endl;
        opcjaI = zKonsoli(1, czyPusto? 4 : 7, "","Bledne polecenie.");

        switch(opcjaI)
        {
        case 1:
        	rodzajG();
            utworzLosowo();
            break;
        case 2:
        	rodzajG();
            utworzZKonsoli();
            break;
        case 3:
        	rodzajG();
            utworzZPliku();
            break;
        case 4:
            if(czyPusto)
            {
                cout << "Konczenie pracy programu" << endl;
                zamykanie = true;
                break;
            }
            else
            wysw[czySkierowany]();
            break;
        case 5:
        	hamilton[czySkierowany]();
            break;
        case 6:
        	euler[czySkierowany]();
        	if(!czySkierowany)
                naprawMacSas();
            break;
        case 7:
        	usun[czySkierowany]();
            cout << "Konczenie pracy programu" << endl;
            zamykanie = true;
            break;
        }
    }
    return 0;
}
