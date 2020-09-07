#include <iostream>
using namespace std;
/*
	Sea 
	longNum(n) :=log_10(n) +1

	esPolidisible(n):
	n>=0 y(pt i : 0<=i<longitudNum(n):(n/10^i)%(longNum(n)-i+1)==0)
	
	Prec{esPolidivisible(n) ^long<=i}
	fun poli(n:ent, long : ent , i : ent) dev V[N] de ent
	Posc{pt i:0<=i<N:esPolidivisible(V[i])y V[i]/(long-longNum(n))==n}
*/

int numCifrasNumero(long long int a)
{
	int d = 0;
	while (a != 0)
	{
		++d;
		a /= 10;
	}
	return d;
}

void fRec(long long int num, int maxCifras, int numCifras)
{
	if (numCifras <= maxCifras && (num % numCifras == 0))
	{
		cout << num << "\n";
		for (int i = 0; i < 10; i++)
		{
			fRec(num * 10 + i, maxCifras, numCifras + 1);
		}
	}
}

bool resCaso()
{
	long long int num;
	cin >> num;

	if (cin.fail())return false;
	
	int numA;
	cin >> numA;
	fRec(num, numA, numCifrasNumero(num));
	cout << "---\n";
	return true;
}

int main()
{
	while (resCaso())
	{

	}return 0;
}