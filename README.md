# ZnowuGrafy

Kolejny odcinek męczenia się z grafami. Czyli świetna zabawa z algorytmami.

Polecam : zielony przycik po prawej -> download zip

# Zadanie 4: Algorytmy z powracaniem
# I program  
Zaimplementuj algorytm z powracaniem znajdujący cykl Hamiltona w grafie nieskierowanym (na macierzy sąsiedztwa) i w grafie skierowanym (na liście następników).

Zaimplementuj algorytm z powracaniem znajdujący cykl Eulera w grafie nieskierowanym (na macierzy sąsiedztwa) i w grafie skierowanym (na liście następników).

W przypadku braku poszukiwanego cyklu w grafie należy wyświetlić komunikat: Graf wejściowy nie zawiera cyklu.

Jeśli poszukiwany cykl istnieje program wypisuje go w postaci listy wierzchołków, przez które przechodzi cykl.

Program powinien mieć możliwość wczytywania danych z klawiatury

oraz z pliku tekstowego zawierającego graf zapisany w postaci listy krawędzi, gdzie para liczb w pierwszej linii to informacja o liczbie wieczchołków i liczbie krawędzi/łuków, a pary w kolejnych liniach to pary wierzchołków połączonych krawędzią/łukiem. Spacja jest separatorem liczb w pojedynczej linii.

# II testy
Wygeneruj grafy nieskierowane i skierowane o n wierzchołkach i współczynniku nasycenia krawędziami równym s={10,20,30,40,50,60,70,80,90} (dla wszystkich 9-ciu wartości) oraz dla 10-15 różnych wartości n z przedziału <10,k> (k należy dobrać eksperymentalnie tak, aby możliwe było wykonanie pomiarów i aby jego wartość była możliwie duża).
Zastosuj algorytmy do znalezienia cykli w wygenerowanych grafach. Zapisz czasy działania algorytmów.

# III sprawozdanie
Wykonaj 2 wykresy (jeden wykres dla grafu nieskierowanego, drugi wykres dla grafu skierowanego) t=f(n) zależności czasu obliczeń t od liczby n wierzchołków w grafie przy stałej wartości nasycenia s=50%. Na każdym wykresie przedstaw 2 krzywe - po jednej krzywej dla każdego algorytmu.
Wykonaj 2 wykresy (jeden wykres dla każdego algorytmu) t=f(n) zależności czasu obliczeń t od liczby n wierzchołków w grafie przy stałej wartości nasycenia s=50%. Na każdym wykresie przedstaw 2 krzywe - jedna krzywa dla grafu nieskierowanego, druga dla grafu skierowanego.
Wykonaj 2 wykresy (jeden wykres dla grafu nieskierowanego, drugi wykres dla grafu skierowanego) t=f(s) zależności czasu obliczeń t od nasycenia s przy stałej liczbie wierzchołków n. Na każdym wykresie przedstaw 2 krzywe - po jednej krzywej dla każdego algorytmu.
Wykonaj 2 wykresy (jeden wykres dla każdego algorytmu) t=f(s) zależności czasu obliczeń t od nasycenia s przy stałej liczbie wierzchołków n. Na każdym wykresie przedstaw 2 krzywe - jedna krzywa dla grafu nieskierowanego, druga dla grafu skierowanego.
Wykonaj 2 wykresy 3D (jeden wykres dla każdego algorytmu) t=f(n,s) zależności czasu obliczeń t od liczby n wierzchołków w grafie i nasycenia s, dla poszukiwania cyklu w grafie skierowanym.
Wykonaj 2 wykresy 3D (jeden wykres dla każdego algorytmu) t=f(n,s) zależności czasu obliczeń t od liczby n wierzchołków w grafie i nasycenia s, dla poszukiwania cyklu w grafie nieskierowanym.
Podaj jaka jest złożoność obliczeniowa zaproponowanych algorytmów oraz do jakich klas złożoności obliczeniowej należą badane problemy poszukiwania cyklu Hamiltona i cyklu Eulera w grafie (wersja przeszukiwania i wersja decyzyjna).
Przedstaw obserwacje związane z działaniem zaimplementowanych algorytmów dla grafów o różnym nasyceniu.
dpowiedz jaką reprezentację maszynową grafu Twoim zdaniem najlepiej zastosować w przypadku każdego algorytmu i dlaczego.


