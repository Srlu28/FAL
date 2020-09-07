#include <iostream>
using namespace std;
#include <vector>
/*
	PRECONDICION
	{100000>=N>=2 V[0,.N) de ent y (para todo i : 0<=i<N : V[i] >=0 }
	fun avituallamiento(V[0,..,N) de ent, x :ent ) dev numK : int
	POSTCONDICION
	{numK = (max a,b : 0<=a<=b<N y para todo a<=i<=b : V[a]=V[i] :b-a )}

	COTA N-n
	INVARIANTE {numK = (max a,b : 0<=a<=b<n y para todo a<=i<=b : V[a]=V[i] :b-a ) y 0<=n<=N}
	Coste del algoritmo: lineal


*/

bool resuelveCaso()
{
	int num;
	cin >> num;
	if (num == -1)return false;
	else{
		vector<int> v;
		while (num != -1)
		{
			v.push_back(num);
			cin >> num;
		}

		int tramo = 0;
		int maxtramo = tramo;

		for (int i = 0; i < v.size()-1; i++)
		{
			if (v[i] == v[i + 1])
			{
				tramo++;
				if (tramo > maxtramo)maxtramo = tramo;
			}
			else
			{
				tramo = 0;
			}
		}

		if (maxtramo > 0)
			cout << maxtramo << endl;
		else cout << "HOY NO COMEN\n";

		return true;
	}
}

int main()
{
	while (resuelveCaso()); return 0;
}