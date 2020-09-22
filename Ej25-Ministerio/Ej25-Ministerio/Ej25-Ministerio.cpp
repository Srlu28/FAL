#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/*
	Bueno para este problema lo que hacemos es el esquema clasico de vuelta atras aplicando una poda
	Para realizar la poda lo que hacemos es recoger para cada funcionario el tiempo que menos tarda en realizar la tarea y lo guardamos en 
	el vector vMin.
	una vez esto ha sido realizado, hacemos una modificacion el vector vMin para que cada posicion nos de la suma desde esa posicion hasta el final
	de los menores elementos, esto es basicamente que si la posicion es 0,vMin[0] es la suma de los minimos de todos los trabajadores, sin embargo
	v[1] sera la suma de los minimos de todos los trabajadores a partir del 1.

	Así para ver si al escoger una determinada combinacion es prometedora hemos de ver que si la suma del tiempo de todos los trabajadores 
	que llevamos mas la correspondiente suma de los minimos del resto de los trabajadores es mayor que el maximo, entonces no tendremos una solucion
	factible.

	
*/

bool esPrometedor(int cantAcumulada, long long int const maximo, vector<int> & minV, int const func, int const numF)
{
	if (func < numF && cantAcumulada + minV[func] >= maximo)return false;
	else return true;
}

void minimizar(int cantidadAcumulada, int funci, int const numF, vector<vector<int>> & matriz, vector<int>& vMin,
	long long int & mejor, vector<bool> &tareaHecha)
{
	for (int i = 0; i < numF; i++)//Interpretamos las i como tareas hechas, y el funcionario es el indice
	{
		if (!tareaHecha[i])//si la tarea no ha sido cogida continuamos
		{
			//Marcamos
			tareaHecha[i] = true;
			cantidadAcumulada += matriz[funci][i];

			if (funci + 1 == numF)//Si llegamos al tope tenemos una solución pero hemos de ver si es mejor que la que teniamos antes.
			{
				if (cantidadAcumulada < mejor)mejor = cantidadAcumulada;//Si es mejor el maximo a superar ahora cambia
			}
			else
			{
				if (esPrometedor(cantidadAcumulada, mejor, vMin, funci + 1, numF))//Comprobamos que lo que acabamos de marcar sea algo prometedor
				{
					minimizar(cantidadAcumulada, funci + 1, numF, matriz, vMin, mejor, tareaHecha);//Si es prometedor 
					//hemos elegido un funcionario y le hemos asignado una tarea asi que pasamos al siguiente funcionario
				}
			}

			//Desmarcamos
			tareaHecha[i] = false;
			cantidadAcumulada -= matriz[funci][i];
		}
	}
}

bool r()
{
	int num; cin >> num;
	if (!num)return false;

	vector<vector<int>> matrizFun;//De aqui sacamos los datos
	vector<int> vMin; vMin.resize(num);//Este vector lo usamos para la poda 
	vector<bool> tareaHecha; tareaHecha.resize(num);//Para ver si una tarea ha sido hecha
	

	matrizFun.resize(num);
	for (int i = 0; i < num; i++)
	{
		matrizFun[i].resize(num);
		int min = 10000;
		for (int j = 0; j < num; j++)
		{//Leemos los datos y vemos si tenemos que actualizar el minimo de un funcionario
			int aux; cin >> aux;
			matrizFun[i][j] = aux;
			if (aux < min)min = aux;
		}
		vMin[i] = min;
	}
	for (int i = num - 2; i >= 0; i--)
	{//Remodelamos un poco el vectorMin
		vMin[i] += vMin[i + 1];
	}

	long long int maxi = INT_MAX;//El maxi lo ponemos a una valor muy alto.(Realmente seria un minimo)
	minimizar(0, 0, num, matrizFun, vMin, maxi, tareaHecha);//Hacemos la primera llamada del backtracking
	cout << maxi << endl;//Hacemos que se imprima el maxi.
	return true;
}

int main()
{
	while (r()); return 0;
}
