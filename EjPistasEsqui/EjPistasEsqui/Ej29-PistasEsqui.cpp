#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include<algorithm>

/*
Precondicion
{0<=N<=1000}
fun encontrar(V[0,...N)) dev a:ent
{a=max(a,b:0<=a<=b<N y para todo i:a<=i<=b-1 : V[i]>=V[i+1]:b-a)}
Invariante
{a=max(a,b:0<=a<=b<n y para todo i:a<=i<=b-1 : V[i]>=V[i+1]:b-a) N>=n}
Funcion de cota
N-n>=0
*/

void r()
{
	long long int tam;
	cin >> tam;
	vector<long long int> vect(tam);
	for (int i = 0; i < tam; i++)
	{
		cin >> vect[i];
	}
	if (tam == 0)cout << 0 << endl;
	else
	{
		long long int longMaxSeg = 1, seg = 1;
		for (int i = 0; i < tam - 1; i++)
		{
			if (vect[i] >= vect[i + 1])
			{
				seg++;
				if (seg > longMaxSeg)longMaxSeg = seg;
			}
			else
			{
				seg = 1;
			}
		}
		cout << longMaxSeg << endl;
	}
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
	{
		r();
	}
	return 0;
}