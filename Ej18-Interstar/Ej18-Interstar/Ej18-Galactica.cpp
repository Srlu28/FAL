#include<iostream>
using namespace std;
#include <vector>
/*
	Haremos mergeShort pero devolviendo el numero de inversiones que se ha tenido que realizar, contando el nuemro de las 
	mismas en subintervalos suyos

	Al contar las inversiones lo hacemos al mezclar en los arrays

	Partimos de que , en la funcion mezclarOrden(), los subintervalos de la dcha e izda estan ordenados y no hay 
	inversiones en ellos, ya que se han ordenado y contado antes, asi hay que contar cada elemento del intervalo central
	Si el elemento que cogemos es del intervalo de la izquiesa quiere decir que no tiene inversiones con el dcho.Si el
	elegido es el de la dcha tiene una inversion con todos los elementos que no se han añadido al vector auxiliar
	en el cual los copiamos ordenadamente ,por tanto sumamos dicha cantidad.Cuando se acabe con un subintervalo el otro ya esta 
	contabilizado

	{0<N && (para todo i : 0<=i<N : 0<V[i]<=N) && (para todo i,j : 0<=i<j<N : V[i] != V[j])}
	fun numI(V[0,...N) de ent, ini: ent, fin:ent) dev res: ent
	{res=#i,j:0<=i<j<N:V[i]>V[j])}

	El coste este algoritmo es igual que el de mergeSort nlog_2(n)


*/
int numInverS(vector<long long int>& v, vector<long long int>& aux, long long int ini, long long int fin)
{
	long long int longit = fin - ini + 1;

	if (longit <= 2)
	{
		if (v[ini] > v[fin])
		{
			int aux1 = v[ini];
			v[ini] = v[fin];
			v[fin] = aux1;
			return 1;
		}
		return 0;
	}

	int mitad = (ini + fin) / 2;
	int r = 0;
	r += numInverS(v, aux, ini, mitad);
	r += numInverS(v, aux, mitad + 1, fin);

	for (int i = ini; i <= fin; ++i)
		aux[i] = v[i];
	int indI = ini, indD=mitad + 1, indv = ini;

	while (indI <= mitad && indD <= fin)
	{
		if (aux[indI] > aux[indD])
		{
			v[indv] = aux[indD];
			++indD;
			r += mitad + 1 - indI;
		}
		else {
			v[indv] = aux[indI];
			++indI;
		} ++indv;
	}

	while (indI < mitad + 1) {
		v[indv] = aux[indI];
		++indI;
		++indv;
	}

	return r;

}

bool res()
{
	long long int n, entry;
	vector<long long int> v;

	cin >> n;
	if (!cin) return false;
	for (int i = 0; i < n; i++)
	{
		cin >> entry;
		v.push_back(entry);
	}
	vector <long long int> aux(v.size());
	cout << numInverS(v, aux, 0, n - 1) << endl;
	return true;
}

int main()
{
	while (res());
	return 0;
}