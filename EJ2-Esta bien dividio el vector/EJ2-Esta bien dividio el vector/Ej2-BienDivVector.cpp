/*
	PRECONDICION
	{N>0 0<=pos<=N}
	FUNCION(pos,V[0,...,N) de ent) dev b:bool
	POSTCODICION
	{b= para todo i,j :0<=i<=pos<j<N: V[i]<V[j]}
	otra forma 
	{b= para todo j : pos<j<N : V[j]> (max i : 0<=i<=pos : V[i])

	INVARIANTE
	{para todo i,j :0<=i<=pos<j<n: V[i]<V[j]//para todo j : pos<j<n : V[j]< (max i : 0<=i<=pos : V[i]) && 0<=n<=N}
	COTA
	{N-n>=0}
*/
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>

void resuelveCaso()
{
	int n;
	vector<int> v;
	int pos;
	cin >> n >> pos;
	
	for (int i = 0; i < n; i++)
	{
		int el;
		cin >> el;
		v.push_back(el);
	}

	int maxi = v[0];
	for (int i = 0; i <= pos; i++)
	{
		maxi = max(maxi, v[i]);
	}
	
	bool a = true;
	
	int i = pos+1;
	while (i < n && a)
	{
		if (v[i] <= maxi)a = false;
		i++;
	}

	if (a)cout << "SI\n";
	else cout << "NO\n";
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		resuelveCaso();
	}
	return 0;
}

