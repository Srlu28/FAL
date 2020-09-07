#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

/*
	PRECONDICION
	{0<N<=10000 V[0,....,N) para todo i : 0<= i <N:1000>V[i]>-274}
	FUNCION(v[0,...,n) de ent) dev numP : int numV:int
	POSTCONDICION
	{
		numP:(# i : 0<i<N : V[i-1]<V[i]>V[i+1])
		numV:(# i : 0<i<N : V[i-1]>V[i]<V[i+1])
	}

	INVARIANTE
	{
		numP:(# i : 0<i<n : V[i-1]<V[i]>V[i+1]) y 0<=n<=N
		numV:(# i : 0<i<n : V[i-1]>V[i]<V[i+1]) y 0<=n<=N
	}
	COTA{N-n >=0}
*/

void resolverCaso()
{
	int numP = 0;
	int numV = 0;
	int tam;
	cin >> tam;
	vector<int> v;
	
	for (int i = 0; i < tam; i++)
	{
		int el;
		cin >> el;
		v.push_back(el);
	}

	for (int i = 0; i < tam; i++)
	{
		if (i > 0 && i < tam - 1)
		{
			if (v[i - 1] < v[i] && v[i] > v[i + 1])numP++;
			else if (v[i - 1] > v[i] && v[i] < v[i + 1])numV++;
		}
	}

	cout << numP << " " << numV<<endl;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		resolverCaso();
	}
	return 0;
}