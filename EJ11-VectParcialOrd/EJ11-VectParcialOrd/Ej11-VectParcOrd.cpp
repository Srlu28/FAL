#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

/*
	Usamos recurrencia multiple , ya que llamamos varias veces a la funcion recursiva.El coste de la solución es lineal

	{N=2^x}
	fun parcOrdenada(V[N] de ent, ini:ent,fin:ent,E/S min,E/S max:ent)dev b bool
	{b=parcOrdenada(V[0,...,N/2] de ent,ini,N/2 - 1,V[ini],v[N/2 -1]) && parcOrdenada(v[N/2,...N),N/2,fin,v[N/2],v[fin])&& v[ini]<=v[fin] 
	&& (min=(min i:0<=i<N/2:V[i]) < max=(max i:N/2<=i<N:V[i]))}
	fun parcOrdenado(v[2],ini:ent,fin:ent, min:ent, max : ent) dev b:bool
	{b= (v[0]<=v[1])&&(v[0]=min && v[1]=max)}

*/

typedef struct
{
	bool ok;
	long long int maxi, mini;
}tInfo;

tInfo fRec(vector<long long int > v, long long int pos1, long long int pos2)
{
	if (pos1 == pos2-1)return { v[pos1]<=v[pos2],v[pos1],v[pos2] };
	else
	{
		long long int posInter = (pos2 + pos1) / 2;
		tInfo left = fRec(v, pos1, posInter);
		tInfo right = fRec(v, posInter + 1, pos2);
		return { left.ok && right.ok && left.mini <= right.mini && left.maxi <= right.maxi, left.maxi,right.mini };
	}
}

bool resuelveCaso()
{
	long long int num;
	cin >> num;
	if (num == 0)return false;
	else
	{
		vector<long long int> v;
		while (num != 0)
		{
			v.push_back(num); cin >> num;
		}

		tInfo ejer = fRec(v, 0, v.size() - 1);
		if (ejer.ok)cout << "SI\n";
		else cout << "NO\n";
		return true;
	}
}

int main()
{
	while (resuelveCaso());
	return 0;
}