#include <iostream>
using namespace std;
#include <vector>


/*
	{N>=0 && V[0,....n) && Existe i : 0<= i <N : V[i] && (para todo j: 0<=j<i && j mod 2 ==0 : V[j]=V[j+1]) && 
	(para todo k:i<k<N && k mod 2 ==1 : V[k] =V[k+1])}
	fun algor(V[0,....n)) dev b: ent
	{b=Existe i : 0<=i<N: frec(V[i],v)=1}
	frec(a : ent,V[0,...N) de ent ) dev n:ent
	{n = #i : 0<=i<N: V[i]=a}

	La recurrencia es final y el orden de complejidad es log_2(n)
*/
int posLibroPerdido(vector<int> v, int ini, int fin)
{

	if (ini >= fin - 1)
	{
		return ini;
	}
	int mitad = (ini + fin) / 2;
	mitad = 2 * (mitad / 2);

	if (v[mitad] == v[mitad + 1])
		return posLibroPerdido(v, mitad + 2, fin);
	else return posLibroPerdido(v, ini, mitad);
}

void ejNum()
{
	int tam;
	cin >> tam;
	vector<int> v;
	
	for (int i = 0; i < tam; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	cout << posLibroPerdido(v,0,v.size()-1)<<endl;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		ejNum();
}