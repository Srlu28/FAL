#include <iostream>
using namespace std;
#include<vector>

/*bool casillaValida(int fila, int columna, vector<pair<int, int>> vectorCasillas)
{
	pair<int, int> p = { fila,columna };
	for (int i = 0; i < vectorCasillas.size(); i++)
	{
		if (vectorCasillas[i] == p)return false;
	}
	return true;
}

void backtrack(int pos,int tam,int& numSols, int numTorres, int numReinas, vector<pair<int, int>> vectorCasillas, vector<bool> col,
	vector<bool> diagT, vector<bool> diagR)
{
	for (int colu = 1; colu <= tam; colu++)
	{
		if(casillaValida(pos,colu,vectorCasillas))
		{
			if (numReinas)
			{
				if (!col[colu] && !diagT[colu + pos + 2 * tam-2] && !diagT[colu - pos + tam] && !diagR[colu - pos + tam]
					&& !diagR[colu + pos + 2 * tam-2])
				{
					//Marcado
					col[colu] = true; diagR[colu + pos + 2 * tam-2] = true; diagR[colu - pos + tam] = true;
					if (pos == tam)numSols++;
					else
					{
						backtrack(pos + 1, tam, numSols, numTorres, numReinas - 1, vectorCasillas, col, diagT, diagR);
					}
					//Desmarcado
					col[colu] = false; diagR[colu + pos + 2 * tam-2] = false; diagR[colu - pos + tam] = false;
				}
			}
			if (numTorres)
			{
				if (!col[colu] &&  !diagR[colu - pos + tam] && !diagR[colu + pos + 2 * tam-2])
				{
					//Marcado
					col[colu] = true; diagT[colu + pos + 2 * tam-2] = true; diagT[colu - pos + tam] = true;
					if (pos == tam)numSols++;
					else
					{
						backtrack(pos + 1, tam, numSols, numTorres-1, numReinas, vectorCasillas, col, diagT, diagR);
					}
					//Desmarcado
					col[colu] = false; diagT[colu + pos + 2 * tam-2] = false; diagT[colu - pos + tam] = false;
				}
			}
		}
	}
}

bool r()
{
	int torres, reinas;
	cin >> torres;
	if (cin.fail())return false;
	cin >> reinas;
	int n = torres + reinas;

	int numCasInvalidas;
	cin >> numCasInvalidas;
	vector<pair<int, int>> vecCasIn; vecCasIn.resize(numCasInvalidas);
	for (int i = 0; i < numCasInvalidas; i++)
	{
		pair<int, int> par;
		cin >> par.first >> par.second;
		vecCasIn[i] = par;
	}

	vector<bool> columnas, diagonalReinas, diagonalTorres;
	for (int i = 0; i <= n; i++)
		columnas.push_back(false);
	for (int i = 0; i <= 4 * n - 2; i++)
	{
		diagonalReinas.push_back(false); diagonalTorres.push_back(false);
	}

	int numSols = 0;
	backtrack(1, n, numSols, torres, reinas, vecCasIn, columnas, diagonalTorres, diagonalReinas);
	cout << numSols << endl;

	return true;
}

int main()
{
	while (r()); return 0;
}*/
bool casillaValida(vector<pair<int, int>>& invalid, int fila, int columna) {
	// Comprobamos que no se encuentre en ninguna casilla inv�lida.
	for (int i = 0; i < invalid.size(); ++i) {
		if (invalid[i].first == fila && invalid[i].second == columna)
			return false;
	}
	return true;
}

void formasPosibles(vector<pair<int, int>>& invalid, vector<bool>& col, vector<bool>& diag, vector<int>& diagTorres, int fila, int const lado,
	int const numReinas, int const numTorres, long long int& soluciones) {

	for (int columna = 0; columna < lado; ++columna) {
		// Si la casilla que vamos a usar es v�lida...
		if (casillaValida(invalid, fila, columna)) {
			// Si a�n quedan reinas por colocar...
			if (numReinas) {
				// Comprobamos que no se encuentre atacada la nueva reina por ninguna otra, ni haya ninguna torre en sus diagonales.
				if (!col[columna] && !diag[columna - fila + lado] && !diag[fila + columna + 2 * lado] &&
					!diagTorres[columna - fila + lado] && !diagTorres[fila + columna + 2 * lado]) {
					// Proceso de marcado con los vectores de booleanos.
					col[columna] = true;
					diag[columna - fila + lado] = true;
					diag[fila + columna + 2 * lado] = true;

					if (fila + 1 == lado) ++soluciones;// Si es la �ltima reina que podemos a�adir, es una soluci�n v�lida, y la sumamos.
					else formasPosibles(invalid, col, diag, diagTorres, fila + 1, lado, numReinas - 1, numTorres, soluciones);

					// Quitamos el marcado, puesto que vamos a eliminar la reina del tablero.
					col[columna] = false;
					diag[columna - fila + lado] = false;
					diag[fila + columna + 2 * lado] = false;
				}
			}
			// Si a�n quedan torres por colocar...
			if (numTorres) {
				// Comprobamos que la torre no se encuentre atacada por ninguna reina en las diagonales ni la columna, ni por ninguna torre
				// en la columna (el vector diagTorres solo es modificado por las torres).
				if (!col[columna] && !diag[columna - fila + lado] && !diag[fila + columna + 2 * lado]) {
					// Proceso de marcado del vector de columnas y el de las diagonales de las torres.
					col[columna] = true;
					diagTorres[columna - fila + lado]++;
					diagTorres[fila + columna + 2 * lado]++;

					if (fila + 1 == lado) ++soluciones;
					else formasPosibles(invalid, col, diag, diagTorres, fila + 1, lado, numReinas, numTorres - 1, soluciones);

					// Quitamos el marcado.
					col[columna] = false;
					diagTorres[columna - fila + lado]--;
					diagTorres[fila + columna + 2 * lado]--;
				}
			}
		}
	}
}

bool resuelveCaso() {
	vector<bool> col, diag;
	vector<int> diagTorres;
	vector<pair<int, int>> invalid;
	int numReinas, numTorres, numInvalid, aux1, aux2;

	cin >> numTorres >> numReinas >> numInvalid;
	if (cin.fail()) return false;

	// Calculamos el lado del tablero.
	int lado = numReinas + numTorres;

	// Colocamos los vectores de marcado de las columnas y diagonales a los valores para un tablero vac�o.
	for (int i = 0; i < lado; ++i)
		col.push_back(false);
	for (int i = 0; i < 4 * lado; ++i) {
		diag.push_back(false);
		diagTorres.push_back(0);
	}
	// Guardo las casillas inv�lidas.
	for (int i = 0; i < numInvalid; ++i) {
		cin >> aux1 >> aux2;
		invalid.push_back(make_pair(aux1, aux2));
		invalid[i].first--;
		invalid[i].second--;
	}

	long long int soluciones = 0;
	formasPosibles(invalid, col, diag, diagTorres, 0, lado, numReinas, numTorres, soluciones);
	cout << soluciones << "\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}