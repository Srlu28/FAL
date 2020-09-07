#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*

	{Existe i:0<=i<N : V[i] && (para todo j:0 < j <=i : V[j-1]>V[j]) && (para todo j: i<K<N-1:V[K]>V[k-1] && V[i]<V[K]) && ini=0 && fin=N-1}
	fun EncontrarMin(V[0,...,N) de ent) dev b : ent
	{b=min(i:0<=i<N:V[i])}

	El coste del algoritmo es logarítmico, debido a que se divide por la mitad en cada recurrencia por lo que el orden es de log_2(n)

*/
int fRec(vector<long long int> v, int ini, int fin)
{
	if (ini >= fin - 1)
	{
		return min(v[ini], v[fin]);
	}

	int m = (ini + fin) / 2;
	
	if (v[m] < v[ini])return fRec(v, m, fin);
	else return fRec(v, ini, m - 1);
}

bool r()
{
	int tam;
	cin >> tam;
	if (cin.fail())return false;
	else
	{
		vector<long long int> v;

		for (int i = 0; i < tam; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		cout << fRec(v, 0, v.size() - 1)<<endl;
		return true;
	}
}

int main()
{
	while (r()); return 0;
}