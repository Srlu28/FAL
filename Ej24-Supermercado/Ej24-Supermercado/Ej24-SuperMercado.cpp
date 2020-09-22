#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <climits>

/*
	Para este ejercicio planteamos el esquema clasico de vuelta atras y realizamos una poda basada en coger los productos mas baratos
	independientemente del mercado, una vez hacemos esto adaptamos esta estrategia para que de los productos minimos que hemos usado no 
	haya mas de 3 de ellos que hayamos comprado en el mismo supermercado
	
	Una vez que hemos hecho esto tenemos una aproximacion hecha a partir de coger los elementos más baratos pero puede que esta no 
	sea la más optima, pues hemos elegido posiciones arbitrarias para adecuar la posición.

	Al hacer esto cuando vayamos avanzando en el backtracking comprobaremos si un elemnto es prometedor, para ello tenemos el vector min[] que
	nos indica el valor de la suma de los valores minimos desde el producto i, es decir si estoy comprando el primer prodcuto min[0] me 
	indica la suma de los n-1 productos siguientes con el precio más bajo.
	Esto es especialmente util porque si yo estoy en una solución en la que llevo una compra hecha, si con la suma de los productos más baratos
	que me quedan aun así aumento la estimación hecha anteriormente entonces descarto esta compra por que tengo una estimación valida que 
	es menos costosa.
*/
int calcularSuma(vector<int> & solucion, vector<vector<int>> & matrizPrec, int indice)
{
	int sol = 0;//Calculamos el precio de la compra que llevamos hecha
	for (int i = 0; i < indice; i++)
	{
		int precio = matrizPrec[solucion[i]][i];
		sol += precio;
	}
	return sol;
}

bool solValida(vector<int> & sol, int indice, int numS)
{
	vector<int> cuentas; cuentas.resize(numS);//Miramos que una solución cumpla con los requisitos que se nos pide.
	int i = 0;
	bool valido = true;
	while (valido && i < indice)
	{
		int leido = sol[i];
		cuentas[leido]++;
		i++;
		valido = cuentas[leido] <= 3;
	}
	return valido;
}

int resolver(vector<int> &sol, int indice, vector<int> & minimos, vector<vector<int>>& matrizPrec, int numProd, int aprox, int maxim)
{//Vuelta atras
	int minimo = aprox;//El minimo que tenemos de referencia es la aproximacion
	if (indice == maxim)
	{
		return calcularSuma(sol, matrizPrec, indice);//Si el indice es el maximo devolvemos la suma y ademas era prometedora la solucion 
		//devolvemos el nuevo resultado
	}
	else
	{
		for (int j = 0; j < matrizPrec.size(); j++)//Si no vamos probando supermercados (el indice es el producto)
		{
			sol[indice] = j;
			int precSig = calcularSuma(sol, matrizPrec, indice + 1);//Calculamos una vez hemos comprado
			if (precSig + minimos[indice] < minimo && solValida(sol, indice + 1, matrizPrec.size()))//si el precio que hemos calculado
			//mas la suma de los menores elementos es menor que la aproximación que hemos hecho entonces podemos seguir(si la solucion planteada es valida)
				minimo = min(minimo, resolver(sol,indice+1,minimos,matrizPrec,numProd,aprox,maxim));//Hacemos el minimo entre la aproximación y lo que devuelva resolver
		}
	}
	return minimo;
}

void calcularAproximacion(vector<int>& minimos, vector<int> & aprox, vector<vector<int>> matrizPrec, int numP, int numS)
{
	vector<int> cuenta;
	int i = 0;
	cuenta.resize(numS);

	while (i < numP)
	{
		if (cuenta[aprox[i]] == 3)
		{
			int j = 0;
			while (cuenta[j] == 3)j++;
			aprox[i] = j;
		}
		else cuenta[aprox[i]]++;
		i++;
	}//Hemos hecho que la aproximación se ajuste a las restricciones que se nos piden
	int aux, suma = 0;//Calculamos bien el vector minimos para que nos diga lo que queremos
	for (int i = numP - 1; i >= 0; i--)
	{
		aux = minimos[i];
		minimos[i] = suma;
		suma += aux;
	}
}

void r()
{
	int numSup, numProd;
	cin >> numSup >> numProd;
	if (!numSup || !numProd)cout << "Sin solución factible\n";
	else
	{
		vector<int> vectProdxSup;
		vectProdxSup.resize(numSup);

		vector<vector<int>> preciosxSuper;
		preciosxSuper.resize(numSup);
		vector<int> vMin;
		vMin.resize(numProd, INT_MAX);
		vector<int> aprox;
		aprox.resize(numProd);

		for (int i = 0; i < numSup; i++) {
			preciosxSuper[i].resize(numProd);
			for (int j = 0; j < numProd; j++)
			{
				int num; cin >> num;
				preciosxSuper[i][j] = num;
				if (num < vMin[j])
				{
					vMin[j] = num;
					aprox[j] = i;
				}
			}
		}

		vector<int> sol;
		sol.resize(numProd);
		calcularAproximacion(vMin, aprox, preciosxSuper, numProd, numSup);
		int s = calcularSuma(aprox, preciosxSuper, numProd);
		cout << resolver(sol, 0, vMin, preciosxSuper, numProd, s, numProd)<<endl;
	}


}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		r();
	}
}

/*
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

void imprimirVector(std::vector<int>& v, int indice);

int precio(std::vector<int>& solucion, std::vector<std::vector<int>>& precios,
	int indice) {
	// Funcion objetivo a minimizar, calcula el coste de una solucion dada
	int suma = 0;
	for (int i = 0; i < indice; i++)
		suma += precios[solucion[i]][i];
	return suma;
}

bool valido(std::vector<int>& solucion, int numSupermercados, int indice) {
	// Funcion de restriccion implicita, comprueba que no hay mas de tres elementos repetidos
	//  en el vector
	bool valido = true;
	std::vector<int> cuenta;
	cuenta.resize(numSupermercados);

	int  leido, i = 0;
	while (valido && i < indice) {
		leido = solucion[i];
		cuenta[leido]++;
		i++;
		valido = cuenta[leido] <= 3;
	}


	return valido;
}

int resolver(std::vector<int>& solucion, std::vector<std::vector<int>>& precios, int i, int maximo,
	std::vector<int>& minimos, int aproximacion) {
	int minimo = aproximacion;
	if (i == maximo) return precio(solucion, precios, i);
	else {
		for (int j = 0; j < precios.size(); j++) {
			solucion[i] = j;
			if (precio(solucion, precios, i + 1) + minimos[i] < minimo && valido(solucion, precios.size(), i + 1))
				minimo = std::min(minimo, resolver(solucion, precios, i + 1, maximo, minimos, minimo));
		}
	}
	return minimo;

}

void imprimirVector(std::vector<int>& v, int indice) {
	for (int i = 0; i < indice; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void calcularAproximacion(std::vector<int>& aproximacion, std::vector<int>& minimos, std::vector<std::vector<int>>& precios, int numProductos, int numSupermercados) {
	std::vector<int> cuenta;    // vector con las ocurrencias de cada elemento en *minimos*
		 // se utiliza para comprobar que la aproximacion forma parte de la familia de soluciones
	cuenta.resize(numSupermercados);
	bool valido = true;
	int i = 0;

	while (i < numProductos) {          // se _arregla_ el vector de aproximacion, que contiene todos los minimos 
			// para que cumpla las restricciones implicitas
		if (cuenta[aproximacion[i]] == 3) {
			int j = 0;
			while (cuenta[j] == 3) j++;
			aproximacion[i] = j;
		}
		else cuenta[aproximacion[i]]++;
		i++;
	}

	int aux, suma = 0;   // se calcula la suma acumulada de los minimos que permite saber si la extension de un vector puede ser optima
	for (int i = numProductos - 1; i >= 0; i--) {
		aux = minimos[i];
		minimos[i] = suma;
		suma += aux;
	}
}

int main()
{
	std::vector<std::vector<int>> precios;
	std::vector<int> solucion;
	int casos, numSupermercados, numProductos;

	std::cin >> casos;
	for (int c = 0; c < casos; c++) {
		std::cin >> numSupermercados >> numProductos;
		if (!numSupermercados || !numProductos) {
			std::cout << "Sin solucion factible\n";
			continue;
		}

		precios.resize(numSupermercados);
		solucion.resize(numProductos);
		for (int j = 0; j < numSupermercados; j++)
			precios[j].resize(numProductos);

		std::vector<int> minimo, aproximacion;
		aproximacion.resize(numProductos);
		minimo.resize(numProductos, INT_MAX);
		for (int i = 0; i < numSupermercados; i++) {
			for (int j = 0; j < numProductos; j++) {
				std::cin >> precios[i][j];
				if (precios[i][j] < minimo[j]) {
					minimo[j] = precios[i][j];
					aproximacion[j] = i;
				}
			}
		}

		calcularAproximacion(aproximacion, minimo, precios, numProductos, numSupermercados);
		int s = precio(aproximacion, precios, numProductos);
		std::cout << resolver(solucion, precios, 0, numProductos, minimo, s) << std::endl;
	}

}*/