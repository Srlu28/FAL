#include <iostream>
using namespace std;
#include <vector>



/*

El coste de este algoritmo es log_2(n) en todos los casos.
La recursión utilizada es recursión simple.

{z - a <= 26 && 0 <= a < 26 && 0 < z <= 26}
fun hallarChar(V[z - a] de car., a ent., z ent.) dev c: char;
{c = (existe i : a <= i <= z : [V[i] != (char)(i + 97) && (para todo j : a <= j < i : V[j] == (char)(j + 97)) &&
&& (para todo k : i < k <= z : V[k] == (char)(k + 97))])}

 */

char presos();
char hallarChar(char v[], int a, int z);

char hallarChar(char v[], int a, int z) { // A y Z representan el inicio y fin del subvector de v que tratamos (sin contar
	// la letra que falta).
	int mitad = (a + z) / 2; // Obtenemos la mitad del vector o subvector que estamos tratando.

	if (z - a <= 2) { // Si la diferencia entre el inicio y el fin es igual a 2, tenemos el caso base.
		// Si el primer elemento es distinto del que le corresponde...
		if (v[a] != (char)(a + 97)) return (char)(a + 97);
		// Si el último elemento (menos uno porque no saseguran que falta uno) es distinto del que le corresponde...
		if (v[z - 1] != (char)(z + 97)) return (char)(z + 97);
		// Si ambos son iguales, falta el elemento entre ellos.
		else return (char)(mitad + 97);
	}
	// En el caso de que el elemento de la mitad sea el que debiera ir, el problema lo tenemos en el subvector
	// de la derecha, ya que en el de la izquierda tenemos todos los elementos.
	if (v[mitad] == (char)(mitad + 97))
		return hallarChar(v, mitad + 1, z);
	else return hallarChar(v, a, mitad);
}

char presos() {
	char a, z;
	char v[26];

	cin >> a >> z;

	// Los introducimos en su lugar según el abecedario, es decir, el primer elemento no va en la posición cero,
	// únicamente en el caso de que éste sea la 'a'.
	for (int i = (int)(a - 97); i < (int)(z - 97); ++i) {
		cin >> v[i];
	}
	return hallarChar(v, ((int)a - 97), ((int)z - 97));
}