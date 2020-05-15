#include "grafyLepsze.h"

tproc wysw[]=
{
	wypiszMacSas, 
	wypiszLisNast
};

tproc hamilton[]=
{
	szukajHamiltonMacSas,
	szukajHamiltonListNast
};

tproc euler[]=
{
	szukajEulerMacSas,//pierwsza funkcja dla nieskierowanych, druga skierowanych
	szukajEulerListNast
};

tproc usun[] =
{
	usunMacSas,
	usunLisNast
};

//grafy w pamieci
int v, e;
//short ** macSas;
vector<vector<short>> macSas;
listaElem ** lisNast;
bool czySkierowany;
auto start = chrono::steady_clock::now();
auto end = chrono::steady_clock::now();

void rodzajG()
{
	int jaki;
	cout<<"Podaj jaki rodzaj grafu chcesz wygenerowaæ: "<<endl;
	cout<<"1 - Graf skierowany"<<endl;
	cout<<"2 - Graf nieskierowany"<<endl;
	jaki = zKonsoli(1, 2, "","Bledne polecenie.");
	if (jaki == 1) czySkierowany=true;
	else if (jaki == 2) czySkierowany=false;
}

int main()
{
    srand(time(NULL));
    cout << "Witaj w PRAWIE najlepszym programie do szukania cykli w grafach. (v 0.0.2)" << endl;
    int opcjaI;
    bool zamykanie = false;
    v=0;
    e=0;
    while(!zamykanie)
    {
        cout << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1 - Utworz graf z liczb losowych" << endl;
        cout << "2 - Utworz graf z danych wpisanych w konsoli" << endl;
        cout << "3 - Utworz graf z pliku" << endl;
        cout << "4 - Wyswietl graf" << endl;
        cout << "6 - Szukaj cykl Hamiltona" << endl;
        cout << "8 - Szukaj cykl Eulera" << endl;
        cout << "10 - Zamknij program" << endl;
        cout << endl;
        opcjaI = zKonsoli(0, 10, "","Bledne polecenie.");

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
        	wysw[czySkierowany]();
            break;
        case 6:
        	hamilton[czySkierowany]();
            break;
        case 8:
        	euler[czySkierowany]();
            break;
        case 10:
            // TODO usuwanie
            cout << "Konczenie pracy programu" << endl;
            zamykanie = true;
            break;
        }
    }
    return 0;
}
