#include <iostream>
using namespace std;

#include <vector>

/*
	0->azul
	1->rojo
	2->verde
*/
bool backtrack(vector<int> colUsados, vector<int>& sol, vector<int> cantColDisp, int height, bool& exito, int pos);
bool r()
{
	int altura, azulDisp, rojoDisp, verdeDisp;
	cin >> altura >> azulDisp >> rojoDisp >> verdeDisp;
	if (altura == 0 && azulDisp == 0 && rojoDisp == 0 && verdeDisp == 0)return false;

	vector<int> cantColDisp;
	vector<int> colUsados;
	cantColDisp.resize(3);
	colUsados.resize(3);
	vector<int> sol;

	cantColDisp[0] = azulDisp;
	cantColDisp[1] = rojoDisp;
	cantColDisp[2] = verdeDisp;
	sol.resize(altura,-1);

	for (int i = 0; i < 3; i++)colUsados[i]=0;

	sol[0] = 1;
	
	colUsados[1]++;

	bool exito = false;
	if (!backtrack(colUsados, sol, cantColDisp, altura, exito, 1))
	{
		cout << "SIN SOLUCION\n";
	}
	cout << "\n";

	return true;
}

bool esValido(vector<int> colUsados,vector<int> sol,vector<int> cantColDisp, int pos)
{
	if (sol[pos - 1] == 2 && sol[pos] == 2)return false;
	if (cantColDisp[1]<colUsados[1] || cantColDisp[2] < colUsados[2] || cantColDisp[0] < colUsados[0])return false;
	if (colUsados[2] > colUsados[0])return false;
	else return true;
}
bool esValidoFin(vector<int> colUsados,vector<int> sol)
{
	if (colUsados[1] <= colUsados[0] + colUsados[2])return false;
	else return true;
}
void impr(vector<int>& sol)
{
	for (int i = 0; i < sol.size(); ++i) {
		if (sol[i] == 0) cout << "azul ";
		else if (sol[i] == 1) cout << "rojo ";
		else if (sol[i] == 2) cout << "verde ";
	}
	cout << "\n";
}

bool backtrack(vector<int> colUsados, vector<int>& sol, vector<int> cantColDisp, int height, bool & exito, int pos)
{
	for (int i = 0; i < 3; i++)
	{
		sol[pos] = i;
		colUsados[i]++;
		if (esValido(colUsados, sol, cantColDisp,pos))
		{
			if (pos + 1 == height)
			{
				if (esValidoFin(colUsados, sol)) {
					exito = true;
					impr(sol);
				}
			}
			else backtrack(colUsados, sol, cantColDisp, height, exito, pos + 1);
		}
		colUsados[i]--;
		sol[pos] = -1;
	}
	return exito;
}

int main()
{
	while (r()); return 0;
}