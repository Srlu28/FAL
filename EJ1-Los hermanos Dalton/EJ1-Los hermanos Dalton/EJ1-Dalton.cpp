/*
	Comentarios sobre el problema 
	PRECONDICION
	{2<=N<=100000}
	Fun dalton(V[0,...,N) de ent) dev dalton:bool
	POSTCONDICION
	{dalton=(para todo i, j : 0<=i<=j<N : V[i]<V[j]) o (para todo i, j : 0<=i<=j<N : V[i]>V[j])}

	INVARIANTE
	((para todo i, j : 0<=i<=j<n : V[i]<V[j] 0) o (para todo i, j : 0<=i<=j<n : V[i]>V[j])) y 0<=n<=N
	FUNCION DE COTA
	N-n>0
*/
#include <iostream>
#include<vector>
using namespace std;

bool resuelveCaso()
{
	int num;
	cin >> num;
	if (num > 0)
	{
		vector<int> v;
		
		for (int i = 0; i < num; i++)
		{
			int el;
			cin >> el;
			v.push_back(el);
		}

		bool dalton=true;
		int i = 0;
		
		bool ordenMenorMayor=false, ordenMayorMenor=false;
		int n1 = v[0], n2 = v[1];
		if (n1 > n2)
			ordenMayorMenor = true;
		else if (n1 < n2)
			ordenMenorMayor = true;
		if (ordenMayorMenor)
		{
			while (dalton&& i < num - 1) //En el caso peor tiene coste lineal
			{
				int hermanoIz = v[i];
				int hermanoDer = v[i + 1];
				dalton = hermanoIz > hermanoDer;
				i++;
			}
		}
		else if (ordenMenorMayor)
		{
			while (dalton && i < num - 1) //En el caso peor tiene coste lineal
			{
				int hermanoIz = v[i];
				int hermanoDer = v[i + 1];
				dalton = hermanoIz < hermanoDer;
				i++;
			}
		}
		else
			dalton = false;

		if (dalton)cout << "DALTON\n";
		else cout << "DESCONOCIDOS\n";
		
		return true;
	}
	return false;
}

int main()
{
	while (resuelveCaso());
	return 0;
}