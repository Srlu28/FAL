#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

typedef struct
{
	bool enviada;
	vector<int> vBasuras;
}tPersona;

typedef struct
{
	bool limpia;
	int basuraTotal;
	int basuraRestante;
}tPlaya;

pair<int,int>  backtrack(vector<int> & vMax,vector<tPlaya>& pl, int indice, int maxim, int minimALimp, vector<tPersona>& vPer, int kgTot, int numLimpias, int mejorSol)
{
	pair<int, int> sol = { -1,-1 };
	if (indice == maxim)
	{
		if (numLimpias < minimALimp)return { -1,-1 };
		int limp = numLimpias;
		return { kgTot,limp };
	}
	else
	{
		//Vamos por las playas
		for (int i = 0; i < pl.size(); i++)
		{
			if (!pl[i].limpia)
			{
				//Aqui planteariamos la poda.

				int basuraPer = vPer[indice].vBasuras[i];
				int nouCant = kgTot + min(pl[i].basuraRestante, basuraPer);
				int antiguoRest = pl[i].basuraRestante;
				pl[i].basuraRestante = max(0,pl[i].basuraRestante-basuraPer);
				if (pl[i].basuraRestante == 0)
				{
					numLimpias++;
					pl[i].limpia = true;
				}
				if (nouCant + vMax[indice] >= mejorSol )//&& (maxim-indice-1)>=(minimALimp-numLimpias))
				{
					pair<int, int> p = backtrack(vMax, pl, indice + 1, maxim, minimALimp, vPer, nouCant, numLimpias, mejorSol);
					if (p.first > mejorSol)mejorSol = p.first;
					if (p.first > sol.first)sol = p;
				}
				if (pl[i].basuraRestante == 0)
				{
					numLimpias--;
					pl[i].limpia = false;
				}
				pl[i].basuraRestante = antiguoRest;
			}
		}
	}
	return sol;
}


void r()
{
	int numPe, numPl, minALim;
	cin >> numPe >> numPl >> minALim;
	vector<tPlaya> vPl(numPl);

	for (int i = 0; i < numPl; i++)
	{
		cin >> vPl[i].basuraTotal;
		vPl[i].basuraRestante = vPl[i].basuraTotal;
		vPl[i].limpia = false;
	}

	vector<tPersona> vPer(numPe);
	vector<int> vMax(numPe);
	
	for (int i = 0; i < numPe; i++)
	{
		vPer[i].vBasuras.resize(numPl);
		for (int j = 0; j < numPl; j++)
		{
			cin >> vPer[i].vBasuras[j];
			if(vPer[i].vBasuras[j]>vMax[i])vMax[i]= vPer[i].vBasuras[j];
		}
	}

	int aux = 0, suma=0;
	for (int i = numPe - 1; i >= 0; i--)
	{
		aux = vMax[i];
		vMax[i] = suma;
		suma += aux;
	}

	int c = 0;
	pair<int,int> num = backtrack(vMax,vPl, 0, numPe, minALim, vPer, 0, 0,-1);
	if (num.first == -1)cout << "IMPOSIBLE\n";
	else
		cout << num.first << " " << num.second << endl;

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