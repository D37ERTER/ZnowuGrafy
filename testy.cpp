#include "grafyLepsze.h"

auto start = chrono::steady_clock::now();
auto endx = chrono::steady_clock::now();



string pliki[9][2][2]=
{
	{{"wyniki/hamilton10ns.txt","wyniki/euler10ns.txt"},{"wyniki/hamilton10s.txt","wyniki/euler10s.txt"}},
	{{"wyniki/hamilton20ns.txt","wyniki/euler20ns.txt"},{"wyniki/hamilton20s.txt","wyniki/euler20s.txt"}},
	{{"wyniki/hamilton30ns.txt","wyniki/euler30ns.txt"},{"wyniki/hamilton30s.txt","wyniki/euler30s.txt"}},
	{{"wyniki/hamilton40ns.txt","wyniki/euler40ns.txt"},{"wyniki/hamilton40s.txt","wyniki/euler40s.txt"}},
	{{"wyniki/hamilton50ns.txt","wyniki/euler50ns.txt"},{"wyniki/hamilton50s.txt","wyniki/euler50s.txt"}},
	{{"wyniki/hamilton60ns.txt","wyniki/euler60ns.txt"},{"wyniki/hamilton60s.txt","wyniki/euler60s.txt"}},
	{{"wyniki/hamilton70ns.txt","wyniki/euler70ns.txt"},{"wyniki/hamilton70s.txt","wyniki/euler70s.txt"}},
	{{"wyniki/hamilton80ns.txt","wyniki/euler80ns.txt"},{"wyniki/hamilton80s.txt","wyniki/euler80s.txt"}},
	{{"wyniki/hamilton90ns.txt","wyniki/euler90ns.txt"},{"wyniki/hamilton90s.txt","wyniki/euler90s.txt"}}
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

void hamiltonTest()
{
	hamilton[czySkierowany]();
}

void eulerTest()
{
	//listaElem ** kopia;
    /*if(czySkierowany)
    {
		kopia = kopiaLisNast();
	}*/
    euler[czySkierowany]();
    if(czySkierowany)
    /*{
    	delete [] lisNast;
    	lisNast = kopia;
    	delete [] kopia;
	}*/
    if(!czySkierowany)
        naprawMacSas();
	
}

tproc cykle[]=
{
	hamiltonTest,
	eulerTest
};

void test()
{
	long long int pomiary[5];
	for (int g=0;g<2;g++)	//nieskierowany lub skierowany
	{
		czySkierowany=g;
		for (int i=20;i<=200;i+=20)	//ka�de n
		{
			for (int s=0;s<9;s++) // nasycenie (w %) - (s+1)*10
			{
				utworzLosowoTesty(i,(s+1)*10); //stworzy� procedur�
				cout<<"8"<<endl;
				for (int j=0;j<2;j++) //hamilton lub euler  
				{
					for (int k=0;k<5;k++)  // 5 pomiar�w
					{
						cout<<"9"<<endl;
						start = chrono::steady_clock::now();
						cykle[j]();
						endx = chrono::steady_clock::now();
						pomiary[k]=chrono::duration_cast<chrono::milliseconds>(endx - start).count();
					}
					zapisz(pomiary, i, pliki[s][czySkierowany][j]);
				}
				wysw[czySkierowany]();
				usun[czySkierowany]();
			}
		}
	}
}
