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
	{{"hamilton10ns.txt","euler10s.txt"},{"hamilton10ns.txt","euler10s.txt"}},
	{{"hamilton20ns.txt","euler20s.txt"},{"hamilton20ns.txt","euler20s.txt"}},
	{{"hamilton30ns.txt","euler30s.txt"},{"hamilton30ns.txt","euler30s.txt"}},
	{{"hamilton40ns.txt","euler40s.txt"},{"hamilton40ns.txt","euler40s.txt"}},
	{{"hamilton50ns.txt","euler50s.txt"},{"hamilton50ns.txt","euler50s.txt"}},
	{{"hamilton60ns.txt","euler60s.txt"},{"hamilton60ns.txt","euler60s.txt"}},
	{{"hamilton70ns.txt","euler70s.txt"},{"hamilton70ns.txt","euler70s.txt"}},
	{{"hamilton80ns.txt","euler80s.txt"},{"hamilton80ns.txt","euler80s.txt"}},
	{{"hamilton90ns.txt","euler90s.txt"},{"hamilton90ns.txt","euler90s.txt"}}
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
	for (int g=0;g<2;g++)	//skierowany lub nie
	{
		czySkierowany=g;
		for (int i=100;i<=2000;i+=100)	//ka¿de n
		{
			for (int s=0;s<9;s++) // nasycenie - (s+1)*10
			{
				//utworzLosowo(i,(s+1)*10);
				for (int j=0;j<2;j++) //euler lub hamilton
				{
					for (int k=0;k<5;k++)  // 5 prób 
					{
						start = chrono::steady_clock::now();
						cykle[j][g]();
						endx = chrono::steady_clock::now();
						pomiary[k]=chrono::duration_cast<chrono::milliseconds>(endx - start).count();
					}
					zapisz(pomiary, i, pliki[s][g][j]);
				}
				usun[czySkierowany]();
			}
		}
	}
}
