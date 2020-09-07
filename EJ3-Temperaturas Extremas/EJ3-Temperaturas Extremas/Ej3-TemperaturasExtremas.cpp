/*
	PRECONDICION
	{V[0,....N) y 1 <=N<=10000 y para todo i : 0<=i<N : 0<V[i]<10^(18)}
	FUNCION(V[0,...N)) dev Max : int Min:int frecMax:int frecMin:int
	POSTCONDICION
	{
	 Max=(max i : 0<=i<N : V[i])
	 Min=(min i : 0<=i<N : V[i])
	 frecMax=(#i:0<=i<N : V[i]=Max)
	 frecMin=(#i:0<=i<N:V[i]=Min)
	}
	Invariante
	 Max=(max i : 0<=i<n : V[i])
	 Min=(min i : 0<=i<n : V[i])
	 frecMax=(#i:0<=i<n : V[i]=Max)
	 frecMin=(#i:0<=i<n:V[i]=Min)
	 0<=n<=N
	Cota
	N-n>=0
	Coste lineal O(n)
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void resolverCaso()
{
	long long int num;
	cin >> num;
	vector<int> v;
	long long int mini = pow(10, 18);
	int c = 0;
	long long int maxi = 0,cm=0;
	while (num != 0)
	{
		v.push_back(num);
		if (num < mini)
		{
			mini = num;
			c = 1;
		}
		else if (num == mini)c++;

		if (num > maxi)
		{
			maxi = num;
			cm = 1;
		}
		else if (maxi == num)cm++;

		cin >> num;
	}

	cout << mini << " " << c << " " << maxi << " " << cm << endl;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		resolverCaso();
	}
}