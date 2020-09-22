#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>

typedef struct
{
	vector<int> pref;
	int edad;
}tNino;

typedef struct
{
	int edad;
	int ninoAdjud;
}tJuguete;

int hallarSuma(vector<tJuguete>& vecJug, vector<tNino>& vecNin)
{
	int suma = 0;
	for (int i = 0; i < vecJug.size(); i++)
	{
		if (vecJug[i].ninoAdjud != -1)
		{
			suma += vecNin[vecJug[i].ninoAdjud].pref[i];
		}
	}
	return suma;
}

bool solValida(vector<tNino>& vecNins, vector<tJuguete>& vecJug, 
	int indice, int maxJug, int maxEdad, int minimoARepartir,vector<int> & jugXNino)
{
	bool valido = true;
	int i = 0;
	while (i < indice && valido)
	{
		if (vecJug[i].ninoAdjud != -1)
			valido = vecNins[vecJug[i].ninoAdjud].edad >= vecJug[i].edad;
		i++;
	}
	if (!valido)return valido;

	//Planteamos una poda

	int faltan = 0;
	for (int i = 0; i < vecNins.size(); i++)
	{
		int numJug = jugXNino[i];
		if (numJug < minimoARepartir)faltan++;
	}
	valido = faltan <= maxJug - indice;
	return valido;
}

int backtrack(vector<tNino>& vecNins, vector<tJuguete>& vecJug, int indice, 
	int maxJug, int maxEdad, int minimoARepartir,vector<int> & jugXNin)
{
	int maxim = 0;
	if (indice == maxJug)
		return hallarSuma(vecJug, vecNins);
	else
	{
		for (int i = 0; i < vecNins.size(); i++)
		{
			if (maxEdad < vecJug[indice].edad)vecJug[indice].ninoAdjud = -1;
			else
			{
				vecJug[indice].ninoAdjud = i;
				jugXNin[i]++;
			}
			if (solValida(vecNins,vecJug,indice+1,maxJug,maxEdad,minimoARepartir,jugXNin))
			{
				maxim=max(maxim,backtrack(vecNins, vecJug, indice + 1, maxJug, maxEdad, minimoARepartir,jugXNin));
			}
			jugXNin[i] = max(jugXNin[i]-1, 0);
		}
	}
	return maxim;
}

bool r()
{
	int J, N, M;
	cin >> J >> N >> M;
	if (J == 0 && N == 0 && M == 0)return false;
	else
	{
		vector<tNino> vecNins(N);
		vector<tJuguete> vecJug(J);

		for (int i = 0; i < J; i++)
		{
			int edadR;
			cin >> edadR;
			vecJug[i].edad = edadR;
			vecJug[i].ninoAdjud = -1;
		}

		int maxEdad = 0;
		for (int i = 0; i < N; i++)
		{
			int edad; cin >> edad;
			maxEdad = max(maxEdad,edad);
			vecNins[i].edad = edad;
		}

		for (int i = 0; i < N; i++)
		{
			vecNins[i].pref.resize(J);
			for (int j = 0; j < J; j++)
			{
				int sat; cin >> sat;
				vecNins[i].pref[j] = sat;
			}
		}

		vector<int>jucXNin(N, 0);
		cout << backtrack(vecNins, vecJug, 0, J, maxEdad, M, jucXNin)<<endl;
		return true;
	}
}

int main()
{
	while (r());
	return 0;
}