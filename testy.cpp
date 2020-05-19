#include "grafyLepsze.h"

auto start = chrono::steady_clock::now();
auto endx = chrono::steady_clock::now();

tproc cykle[2][2]=
{
	{szukajHamiltonMacSas, szukajHamiltonListNast},
	{szukajEulerMacSas, szukajEulerListNast}
};

string pliki[9][2][2]=
{
	{{"hamilton10ns.txt","euler10ns.txt"},{"hamilton10s.txt","euler10s.txt"}},
	{{"hamilton20ns.txt","euler20ns.txt"},{"hamilton20s.txt","euler20s.txt"}},
	{{"hamilton30ns.txt","euler30ns.txt"},{"hamilton30s.txt","euler30s.txt"}},
	{{"hamilton40ns.txt","euler40ns.txt"},{"hamilton40s.txt","euler40s.txt"}},
	{{"hamilton50ns.txt","euler50ns.txt"},{"hamilton50s.txt","euler50s.txt"}},
	{{"hamilton60ns.txt","euler60ns.txt"},{"hamilton60s.txt","euler60s.txt"}},
	{{"hamilton70ns.txt","euler70ns.txt"},{"hamilton70s.txt","euler70s.txt"}},
	{{"hamilton80ns.txt","euler80ns.txt"},{"hamilton80s.txt","euler80s.txt"}},
	{{"hamilton90ns.txt","euler90ns.txt"},{"hamilton90s.txt","euler90s.txt"}}
};

void zapisz(long long pomiary[], int ile, string nazwa)
{
	ofstream zapis;
	zapis.open(nazwa, ios_base::app);
	zapis<<ile<<'\t';
	for (int i=0;i<5;i++)
	{
		zapis<<pomiary[i]<<'\t';
	}
	zapis<<'\n';
	zapis.close();
}

void test()
{
	long long int pomiary[5];
	for (int g=0;g<2;g++)	//nieskierowany lub skierowany
	{
		czySkierowany=g;
		for (int i=10;i<=20;i+=2)	//ka�de n
		{
			for (int s=0;s<9;s++) // nasycenie (w %) - (s+1)*10
			{
				utworzLosowoTesty(i,(s+1)*10); //stworzy� procedur�
				for (int j=0;j<2;j++) //euler lub hamilton
				{
					for (int k=0;k<5;k++)  // 5 pomiar�w
					{
						start = chrono::steady_clock::now();
						cykle[j][czySkierowany]();
						endx = chrono::steady_clock::now();
						pomiary[k]=chrono::duration_cast<chrono::milliseconds>(endx - start).count();
					}
					zapisz(pomiary, i, pliki[s][czySkierowany][j]);
				}
				usun[czySkierowany]();
			}
		}
	}
}
