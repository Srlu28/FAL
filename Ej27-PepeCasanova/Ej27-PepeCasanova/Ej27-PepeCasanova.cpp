#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <algorithm>

typedef struct
{
	int dur, punt;
	float relacion;
}tCancion;
typedef struct
{
	int dur, punt;
}tCara;

int divide(vector<tCancion>& cancion, int ini, int fin) {
	int left, right;
	float pivot;
	tCancion tmp;

	pivot = cancion[ini].relacion;
	left = ini;
	right = fin;

	while (left < right) {
		while (cancion[right].relacion > pivot) --right;
		while (left < right && cancion[left].relacion <= pivot) ++left;

		if (left < right) {
			tmp = cancion[left];
			cancion[left] = cancion[right];
			cancion[right] = tmp;
		}
	}

	tmp = cancion[right];
	cancion[right] = cancion[ini];
	cancion[ini] = tmp;

	return right;
}
void quicksort(vector<tCancion>& cancion, int ini, int fin) {
	int pivot;

	if (ini < fin) {
		pivot = divide(cancion, ini, fin);

		quicksort(cancion, ini, pivot - 1);
		quicksort(cancion, pivot + 1, fin);
	}
}

int estimacion(int freeSpace, int k, int  pts, vector<tCancion>& v)
{
	while (k >= 0 && v[k].dur <= freeSpace)
	{
		freeSpace -= v[k].dur;
		pts += v[k].punt;
		--k;
	}
	if (k >= 0)
	{
		pts += freeSpace * v[k].relacion;
	}return pts;
}

void backtrack( int k, int& maxpts, vector<tCancion>& v, int longxCara, pair<tCara, tCara> & tCinta)
{
	if (k >= 0)
	{
		//Por la cara A
		if (tCinta.first.dur + v[k].dur <= longxCara)
		{
			//Marcado
			tCinta.first.dur += v[k].dur;
			tCinta.first.punt += v[k].punt;

			if (tCinta.first.punt + tCinta.second.punt > maxpts)
			{
				maxpts = tCinta.first.punt + tCinta.second.punt;
			}
			if (tCinta.first.dur + tCinta.second.dur <= 2 * longxCara)
			{
				backtrack(k - 1, maxpts, v, longxCara, tCinta);
			}

			//Desmarcado
			tCinta.first.dur -= v[k].dur;
			tCinta.first.punt -= v[k].punt;
		}
		//Por la cara B
		if (tCinta.second.dur + v[k].dur <= longxCara)
		{
			//Marcado
			tCinta.second.dur += v[k].dur;
			tCinta.second.punt += v[k].punt;

			if (tCinta.first.punt + tCinta.second.punt > maxpts)
			{
				maxpts = tCinta.first.punt + tCinta.second.punt;
			}

			if (tCinta.first.dur + tCinta.second.dur <= 2 * longxCara)
			{
				backtrack(k - 1, maxpts, v, longxCara, tCinta);
			}

			//Desmarcado
			tCinta.second.dur -= v[k].dur;
			tCinta.second.punt -= v[k].punt;
		}
		if (estimacion(2 * longxCara - (tCinta.first.dur + tCinta.second.dur), k - 1, tCinta.first.punt + tCinta.second.punt, v) > maxpts)
			backtrack(k - 1, maxpts, v, longxCara, tCinta);
	}
}

bool r()
{
	int numC;
	cin >> numC;
	if (numC == 0)return false;
	else
	{
		int durxCara;
		vector<tCancion> vecCanc;
		cin >> durxCara;
		for (int i = 0; i < numC; i++)
		{
			tCancion tema;
			cin >> tema.dur >> tema.punt;
			tema.relacion = (float)tema.punt / (float)tema.dur;
			vecCanc.push_back(tema);
		}
		quicksort(vecCanc, 0, vecCanc.size() - 1);
		pair<tCara, tCara> pares;
		int a = 0;
		backtrack(numC - 1, a, vecCanc, durxCara, pares);
		cout << a << endl;
		return true;
	}
}

int main()
{
	while (r()); return 0;
}