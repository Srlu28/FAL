#include <iostream>
using namespace std;
#include<vector>
typedef struct
{
	bool ok;
	int elemD;
}tMatriz;

tMatriz funRec(int ini_f, int ini_col, vector<vector<int>> matriz, int lado)
{
	if (lado == 1)
	{
		tMatriz dev;
		dev.ok = true;
		dev.elemD = matriz[ini_f][ini_col];
		return dev;
	}
	else
	{
		tMatriz left_top,left_down,right_top,right_down;
		left_top = funRec(ini_f, ini_col, matriz, lado / 2);
		left_down = funRec(ini_f + lado / 2, ini_col, matriz, lado / 2);
		right_top = funRec(ini_f, ini_col + lado / 2, matriz, lado / 2);
		right_down = funRec(ini_f + lado / 2, ini_col + lado / 2, matriz, lado / 2);

		int diagPr = left_top.elemD * right_down.elemD;
		int diagSec = left_down.elemD * right_top.elemD;
		bool ok = left_down.ok && left_top.ok && right_top.ok && right_down.ok &&(diagPr == diagSec);

		tMatriz m = { ok,diagPr };
		return m;
	}
}

void r()
{
	int tam;
	cin >> tam;
	vector<vector<int >> matriz(tam);
	for (int i = 0; i < tam; i++)
	{
		matriz[i].resize(tam);
		for (int j = 0; j < tam; j++)
			cin >> matriz[i][j];
	}

	tMatriz m = funRec(0, 0, matriz, tam);
	if (m.ok)cout << "SI " << m.elemD << endl;
	else cout << "NO\n";
}

int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		r();
	return 0;
}