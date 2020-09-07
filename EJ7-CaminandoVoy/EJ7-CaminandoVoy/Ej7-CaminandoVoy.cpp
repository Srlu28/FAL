#include <iostream>
using namespace std;
#include <vector>

/*
	PRECONDICION
	{0<=D<=1000000 y 1<= N <=200000 V[0,..,N) para todo i: 0<=i<N :0<=V[i]<=1000000}
	Funcion f(V[0,....N), D) dev apta : bool
	POSTCONDICION
	{apta = (max (a,b : 0<= a <b<N y para todo i : a<=i<b : V[i]<V[i+1] : V[b]-V[a])<=D)}
	INVARIANTE
	{apta = (max (a,b : 0<= a <b<n y para todo i : a<=i<b : V[i]<V[i+1] : V[b]-V[a])<=D) y 0<=n<=N}
	COTA N-n
	Orden lineal
*/

bool resCaso()
{
	int numA, numB;
	cin >> numA;
	if (!cin.fail())
	{
		cin >> numB;
		vector<int> v;
		for (int i = 0; i < numB; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		int longi = 0;
		int maxLongi = longi;
		int cotaInf = 0, cotaSup = 0;
		for (int i = 0; i < v.size()-1; i++)
		{
			if (v[i] < v[i + 1])
			{
				longi++;
				if (longi > maxLongi)
				{
					maxLongi = longi;
					cotaSup =i + 1;
				}
			}
			else
			{
				longi = 0;
			}
		}

		cotaInf = v[cotaSup - maxLongi];
		int des = v[cotaSup] - cotaInf;
		if (des <= numA)cout << "APTA\n";
		else cout << "NO APTA\n";

		return true;
	}
	return false;
}

int main()
{
	while (resCaso()); return 0;
}