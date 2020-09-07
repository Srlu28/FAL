/*
	PRECONDICION
	{N>0}
	FUNCION (V[0,....n) de ent , E :ent)dev i1:int i2:int
	POSTCONDICION
	{(b-a)= max a,b : 0<=a<=b<N y para todo i : a<=i<=b: V[i]>=E : b-a}

	INVARIANTE
	{(b-a)= max a,b : 0<=a<=b<n y para todo i : a<=i<=b: V[i]>=E : b-a && n<N}
	COTA
	{N-n}
*/
#include <iostream>
using namespace std;
#include<math.h>
#include <vector>
#include <algorithm>
void calcSegmento(const vector<long long int>& v, const long long int alt, long long int& ini, long long int& fin);

void resuelveCaso() {
	vector<long long int> linea;
	long long int num, ini = 0, fin = 0;
	long long int alt, aux;

	cin >> num;
	cin >> alt;

	for (long long int i = 0; i < num; ++i) {
		cin >> aux;
		linea.push_back(aux);
	}

	calcSegmento(linea, alt, ini, fin);
	cout << ini << " " << fin << endl;
}

void calcSegmento(const vector<long long int>& v, const long long int alt, long long int& ini, long long int& fin) {
	bool seg = false;
	long long int min = 0, max = -1, longSeg = 0, maxLong = 0;

	for (long long unsigned int i = 0; i < v.size(); ++i) {
		if (v[i] > alt) {
			++longSeg;
			if (longSeg > maxLong) {
				maxLong = longSeg;
				ini = min;
				fin = i;
			}
		}
		else {
			min = i + 1;
			longSeg = 0;
		}
	}
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		resuelveCaso();
	}
	return 0;
}