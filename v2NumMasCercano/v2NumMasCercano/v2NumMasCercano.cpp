#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>
#include<math.h>

int numABuscar(vector<int> v, int num, int ini, int fin)
{
	int mid;
	bool encontrado = false;
	while (ini <= fin && !encontrado) {
		mid = (ini + fin) / 2;
		if (v[mid] == num) encontrado = true;
		else if (v[mid] > num) fin = mid - 1;
		else ini = mid + 1;
	}

	if (encontrado) return v[mid];
	int dIni = abs(num - v[ini]);
	int dFin = abs(num - v[fin]);
	if (dFin <= dIni) return v[fin];
	else return v[ini];
}

void r()
{
	int numABus;
	cin >> numABus;
	int tam;
	cin >> tam;
	vector<int> v(tam);
	for (int i = 0; i < tam; i++)
	{
		cin >> v[i];
	}
	if (tam > 1)
	{
		cout << numABuscar(v, numABus, 0, tam - 1) << endl;
	}
	else if (tam == 1)cout << v[0] << endl;
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
	{
		r();
	}
}