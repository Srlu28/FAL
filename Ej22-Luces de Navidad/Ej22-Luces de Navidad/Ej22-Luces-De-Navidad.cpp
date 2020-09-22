#include <iostream>
using namespace std;
#include <vector>

bool esValido(int color,vector<int> coloresUsados,int consumido, int maxAconsumir,int colorUltimo,int colorPenultimo,int indice)
{
	if ((color != colorUltimo || colorUltimo != colorPenultimo) && coloresUsados[color] <= 1 + indice / 2 && consumido <= maxAconsumir)return true;
	else return false;
}

void backtrack(int& numSols, vector<int> consumos,vector<int> coloresUsados, 
	int consumido, int maxAconsumir, int colorUltimo, int colorPenultimo,int numC,int longi, int   indice )
{
	for (int i = 0; i < numC; i++)
	{	
		//Marcamos
		consumido += consumos[i];
		coloresUsados[i]++;

		if (esValido(i,coloresUsados,consumido,maxAconsumir,colorUltimo,colorPenultimo,indice))
		{
			if (indice + 1 == longi)numSols++;
			else
			{
				backtrack(numSols, consumos, coloresUsados, consumido, maxAconsumir, i, colorUltimo,numC, longi, indice + 1);
			}
		}

		consumido -= consumos[i];
		coloresUsados[i]--;
	}
}

bool r()
{
	int longL, numCol, maxCon;
	cin >> longL;
	if (longL == 0)return false;
	cin >> numCol>>maxCon;

	vector<int> consumos;
	consumos.resize(numCol, 0);
	vector<int> coloresUsados;
	coloresUsados.resize(numCol, 0);

	for (int i = 0; i < numCol; i++)
	{
		int num; cin >> num;
		consumos[i] = num;
	}

	int consum = 0;
	int numSol = 0;
	backtrack(numSol, consumos, coloresUsados, consum, maxCon, -1, -1, numCol, longL, 0);
	cout << numSol << endl;

	return true;
}

int main()
{
	while (r());
	return 0;
}