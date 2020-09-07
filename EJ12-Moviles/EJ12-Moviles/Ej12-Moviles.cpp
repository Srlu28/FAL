#include <iostream>
using namespace std;
#include <vector>

/*
	
	Recursion multiple pues hacemos varias llamadas a la funcion recursiva dentro de la propia recursion

	movil tiene 
	pi:movil o entero
	di:distancia 1
	pd:movil o entero
	dd:distancia 2

	fun deep(a : ent) dev b:ent
	{b=1}

	fun deep(a : movil) dev b:ent
	{b=deep(a.iz)+ deep(a+der)+1}

	fun peso(a :ent) dev b:ent
	{b=a}

	fun peso(m:movil)dev b:ent
	{b=peso(m.iz)+peso(m.der)}

	fun algor(m:ent) dev b: bool
	{b=true}

	fun algor(m : movil) dev b:bool
	{b= algor(m.iz) && algor(m.der) && peso(m.iz)*di=peso(m.der)*dd}
	
	Coste del algoritmo: deep(m)

*/

typedef struct
{
	long long int p, d;
}tI;

bool fRec(long long int& peso)
{
	bool b = true;
	long long int p1;
	long long int d1;
	long long int p2;
	long long int d2;
	cin >> p1;
	cin >> d1;
	cin >> p2;
	cin >> d2;
	if (p1 == 0)
	{
		b = fRec(p1) && b;
	}
	if (p2 == 0)
	{
		b = fRec(p2) && b;
	}
	peso = p1 + p2;
	b = b && (p1 * d1 == p2 * d2);
	return b;
}

void r()
{
	long long int a;
	bool t=fRec(a);
	if (t)cout << "SI\n";
	else cout << "NO\n";
}

int main()
{
	int num; cin >> num;
	for (int i = 0; i < num; i++)
	{
		r();
	}
	return 0;
}