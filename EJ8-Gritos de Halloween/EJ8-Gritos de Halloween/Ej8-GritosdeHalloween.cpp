#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/*
	PRECONDICION
	{10^18>N>0 0<=k<V(N).size}
	Fun(V[0,....N) , k) dev letra:char
	{letra=V(K)}

	Si n=1 V="BUH"
	Si n>1 V=V(n-1) + "B"+ (n+2)"U" + "H" + V(n-1)

	{N>=1}
	Fun size(V[0,....N)) dev size:int
	{size=V.size}
*/
long long int tam(int n)
{
	if (n == 0)return 0;
	else return 2 * tam(n - 1) + n + 2;
}

string fRec(int tamAnterior,int n, int k)
{
	if (n > 1)
	{
		if (k <= tam(n - 1))return fRec(tam(n - 1), n - 1, k);
		if (k > tam(n - 1) + 2 + n) return fRec(tam(n - 1), n - 1, k - tamAnterior - n - 2);
	}
	if (k == tam(n - 1) + 1)return "B";
	else if (k == tam(n - 1) + n + 2)return "H";
	else return "U";
}

bool resCaso()
{
	int n, k;
	cin >> n;
	if (cin.fail())return false;
	cin >> k;
	cout << fRec(tam(n-1),n, k)<<endl;
	return true;
}

int main()
{
	while (resCaso());
	return 0;
}