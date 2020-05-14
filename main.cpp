#include "grafyLepsze.h"

//grafy w pamieci
int v, e;
short ** macSas;
listaElem ** lisNast;
auto start = chrono::steady_clock::now();
auto end = chrono::steady_clock::now();

int main()
{
    srand(time(NULL));
    cout << "Witaj w PRAWIE najlepszym programie do szukania cykli w grafach. (v 0.0.1)" << endl;
    int opcjaI;
    bool zamykanie = false;
    while(!zamykanie)
    {
        cout << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1 - Utworz graf z liczb losowych" << endl;
        cout << "2 - Utworz graf z danych wpisanych w konsoli" << endl;
        cout << "3 - Utworz graf z pliku" << endl;
        cout << "4 - Wyswietl graf - Macierz sasiedztwa" << endl;
        cout << "5 - Wyswietl graf - Lista nastepnikow" << endl;
        cout << "6 - Szukaj cykl Hamiltona - Macierz sasiedztwa" << endl;
        cout << "7 - Szukaj cykl Hamiltona - Lista nastepnikow" << endl;
        cout << "8 - Szukaj cykl Eulera  - Macierz sasiedztwa" << endl;
        cout << "9 - Szukaj cykl Eulera  - Lista nastepnikow" << endl;
        cout << "10 - Zamknij program" << endl;
        cout << endl;
        opcjaI = zKonsoli(0, 13, "","Bledne polecenie.");

        switch(opcjaI)
        {
        case 1:
            utworzLosowo(2000, 50);
            break;
        case 2:
            utworzZKonsoli();
            break;
        case 3:
            utworzZPliku();
            break;
        case 4:
            wypiszMacSas();
            break;
        case 5:
            wypiszLisNast();
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

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
