#include <iostream>
using namespace std;

#include <vector>

/*
	Sea n:=b-a

	T(n)=|c1 n=0
		 |T(n/2) + c2 n!=0

	El coste de este algoritmo es log(n)
	La recursion es final

	{V1[0,....N) y para todo i: 0<=i<N-1 : V[i]<V[i+1] && V2[0,....n) y para todo j:0<=j<N-1:V[j]>V[j+1]}
	fun alg(V1[0,....N) de ent, V2[0,....N) de ent)dev res:bool cruce : int
	{
		existe i:0<=i<N && v2[p]==v1[p] => res=true && cruce = min p : 0<=p<N && v2[p]==v1[p]
		&&
		existe i:0<=i<N && v2[p]<v1[p] => res=False && cruce = min p : 0<=p<N && v2[p]<v1[p]-1
		&& 
		(!(existe i :0<=i<N && v[2]<v1[p]))=>(res = False && cruce =N-1)  
	}
*/

bool fRec(vector<int> v1, vector<int> v2, int ini, int fin, int& cruce)
{
	if (ini == fin)
	{
		if (v1[ini] == v2[ini]) {
			cruce = ini;
			return true;
		}
		else if (v1[ini] < v2[ini])
		{
			cruce = ini;
			return false;
		}
		else if (v1[ini] > v2[ini])
		{
			cruce = ini-1;
			return false;
		}
	}

	int mitad = (ini + fin) / 2;

	if (v1[mitad] == v2[mitad])
	{
		cruce = mitad;
		return true;
	}
	if (v1[mitad] > v2[mitad])
	{
		return fRec(v1, v2, ini, mitad, cruce);
	}
	if (v1[mitad] < v2[mitad])
	{
		return fRec(v1, v2, mitad + 1, fin, cruce);
	}
}

bool r()
{
	int n;
	cin >> n;
	if (n == 0)
		return false;
	else
	{
		vector<int> v1;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v1.push_back(a);
		}
		vector<int> v2;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v2.push_back(a);
		}

		int cruce = 0;
		bool a = fRec(v1, v2, 0, n - 1, cruce);

		if (a)cout << "SI " << cruce << endl;
		else cout << "NO " << cruce << " " << cruce + 1 << endl;
		return true;
	}
}

int main()
{
	while (r());
	return 0;
}