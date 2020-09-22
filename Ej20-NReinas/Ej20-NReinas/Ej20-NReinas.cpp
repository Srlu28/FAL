#include <iostream>
using namespace std;
#include <vector>

/*
	El espacio de soluciones está formado por el vector reinas en el que a cada reina se le asigna una fila y una columna
	Las condiciones para pertenecer al espacio de soluciones son:
	-No debe haber dos reinas en la misma diagonal.
	-No debe haber dos reinas en la misma fila
	-No debe haber dos reinas en la misma columna

	El arbol de soluciones tiene altura numReinas y anchura numReinas por cada rama

	Introducimos un vector de bool que es col en el que cada posicion es una columna y es true si hay una reina en alguna de esas
	columnas

	Algo similar ocurre con el vector diag

*/

void backtracking(int& numS, int fila, int numR, vector<bool>& D, vector<bool>& C)
{
	for (int col = 1; col <= numR; col++)
	{
		//
		if (!D[col - fila + numR] && !C[col] && !D[fila + col + 2 * numR - 2])//Vemos si podemos seguir explorando
		{
			//Marcado
			D[col - fila + numR] = true; C[col] = true; D[fila + col + 2 * numR - 2] = true;

			if (fila == numR) numS++;//Preguntamos si es solución
			else
			{
				backtracking(numS, fila+1, numR, D, C);//Si no es solucion pasamos al siguiente 
			}

			//Desmarcado
			D[col - fila + numR] = false; C[col] = false; D[fila + col + 2 * numR - 2] = false;
		}
	}
}

void initCD(int n, vector<bool> & C, vector<bool>& D)
{
	for (int i = 0; i <= n; i++)
		C.push_back(false);
	for (int i = 0; i <= 4 * n - 2; i++)
		D.push_back(false);
}

void r()
{
	int NxN; cin >> NxN;
	int numS = 0;

	vector<bool> C,D;

	initCD(NxN, C, D);

	backtracking(numS, 1, NxN, D, C);
	cout << numS << endl;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		r();
	}
}