#include <iostream>
using namespace std;
#include<climits>
#include <vector>
#include <algorithm>

typedef struct
{
	bool valida;
	int anchura;
}tCarretera;

void modificarAprox(vector<int> vMin, vector<int> aprox, vector<vector<int>> matriz, int numQ, int numC,
	vector<int> anchurasCoche,vector<int> anchurasCarr)
{
	vector<int> cuenta; cuenta.resize(numQ);
	int i = 0;
	/*while (i < numC)
	{
		if (cuenta[aprox[i]] == 1 || anchurasCoche[aprox[i]]>anchurasCarr[i])
		{
			int j = 0;
			while (cuenta[j] == 1 || anchurasCoche[j] > anchurasCarr[i])j++;
			aprox[i] = j;
		}
		else cuenta[aprox[i]]++;
		i++;
	}*/
	int aux, suma = 0;
	for (int i = numC - 1; i >= 0; i--)
	{
		aux = vMin[i];
		vMin[i] = suma;
		suma += aux;
	}
}

bool verSiEsPrometedor(int indice, vector<int>& vMax, int maxim, int cantidadTotal, int pr)
{
	return (pr + vMax[indice] > maxim);
}

int vueltaAtras(vector<int> &vMax, vector<vector<int>> &matriz, int indice, vector<int> &anchuraCoche, 
	vector<tCarretera> vCarreteras, int maximoC, int cantidadTotal, int maximAnc)
{
	int maxim = 0;

	if (indice == maximoC)return cantidadTotal;

	else
	{
		if (anchuraCoche[indice] > maximAnc)
		{
			return vueltaAtras(vMax, matriz, indice + 1, anchuraCoche, vCarreteras, maximoC, cantidadTotal, maximAnc);
		}
		else
		{
			for (int i = -1; i < (int)vCarreteras.size(); i++)//sumar 1?
			{
				if (i != -1)
				{
					if (vCarreteras[i].anchura >= anchuraCoche[indice] && vCarreteras[i].valida)

					{
						vCarreteras[i].valida = false;
						int nouPrec = cantidadTotal + matriz[indice][i];
						if(verSiEsPrometedor(indice,vMax,maxim,cantidadTotal,nouPrec))
							maxim= max(maxim, vueltaAtras(vMax, matriz, indice + 1, anchuraCoche, vCarreteras, maximoC, nouPrec, maximAnc));
						vCarreteras[i].valida = true;
					}
				}
				if (i == -1)
					maxim= max(maxim, vueltaAtras(vMax, matriz, indice+1, anchuraCoche, vCarreteras, maximoC, cantidadTotal, maximAnc));
			}
		}
	}
	return maxim;
}

void r()
{
	int numQ, numC;
	cin >> numQ >> numC;
	//Leemos la anchura de las maquinas 
	vector<int> vectorAnchurasMaq;
	vectorAnchurasMaq.resize(numQ);
	for (int i = 0; i < numQ; i++)
	{
		int a;
		cin >> a;
		vectorAnchurasMaq[i] = a;
	}
	//Leemos la anchura de la carretera
	vector<tCarretera> vectorAnchurasCarr;
	vectorAnchurasCarr.resize(numC);
	int maxi = 0;
	for (int i = 0; i < numC; i++)
	{
		int a;
		cin >> a;
		vectorAnchurasCarr[i] = {true,a};
		if (a > maxi)maxi = a;
	}

	vector<vector<int>> matrizEfic;
	vector<int> vMaxEf; vMaxEf.resize(numC,0);
	vector<int> aprox; aprox.resize(numQ);

	matrizEfic.resize(numQ);
	for (int i = 0; i < numQ; i++)
	{
		matrizEfic[i].resize(numC);
		for (int j = 0; j < numC; j++)
		{
			int ef; cin >> ef;
			matrizEfic[i][j] = ef;
			if (ef > vMaxEf[j]) 
			{ 
				vMaxEf[j] = ef;
				//aprox[j] = i;//El vector aproximacion me dice que coche tiene la mayor eficiencia para la carretera j
				//Puede darse que en algun momento la anchura de la carretera no sea valida o que haya una quitanieves que haya hecho
				//mas de una carretera y no puede ser
			}
		}
	}
	
	int aux, suma = 0;
	for (int i = numC - 1; i >= 0; i--)
	{
		aux = vMaxEf[i];
		vMaxEf[i] = suma;
		suma += aux;
	}

	cout << vueltaAtras(vMaxEf,matrizEfic,0,vectorAnchurasMaq,vectorAnchurasCarr,numQ,0,maxi)<<endl;
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