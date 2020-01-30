#include<iostream>

using namespace std;

int main()
{
	float a[10][10], b[10], x[10], y[10];
	int n = 0, m = 0, i = 0, j = 0;
	cout << "METODO DE GAUSS SEIDEL\n";
	cout << "Entre com o valor de n (Matriz nxn): ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Valor da Matriz na Posicao: (" << i << ", " << j << ") = ";
			cin >> a[i][j];
		}
	}
	cout << "\nEntre com as constantes (valores do lado direito):\n";
	for (i = 0; i < n; i++)
	{
		cout << "Posicao: (" << i << ", " << j << ") = ";
		cin >> b[i];
	}

	cout << "\nNumero de Iteracoes: ";
	cin >> m;

	for (i = 0; i < n; i++)
	{
		x[i] = b[i] / a[i][i];
		cout << fixed;
		cout << "x" << i + 1 << " = " << x[i] << "\t";
	}

	cout << endl;

	while (m > 1)
	{
		for (i = 0; i < n; i++)
		{
			y[i] = (b[i] / a[i][i]);
			for (j = 0; j < n; j++)
			{
				if (j == i)
					continue;
				y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
				x[i] = y[i];
			}
			//printf("x%d = %f    ", i + 1, y[i]);
			cout << fixed;
			cout << "x" << i + 1 << " = " << y[i] << "\t";
		}
		cout << "\n";
		m--;
	}
	return 0;
}

// Como Calcular o � (epsilon):
/* 
	Exemplo:
	Para calcular o � da itera��o 3, voc� pega a matriz dos valores da itera��o 3 e diminui da matriz dos valores dados na itera��o 2 (anterior).
	Na matriz resultado dessa subtra��o, voc� pega o maior n�mero [EM M�DULO].
	Esse maior n�mero [EM M�DULO] voc� divide pelo maior n�mero [EM M�DULO] da matriz de valores da itera��o atual (No nosso caso a itera��o 3)

	Itera��o 1: x1 = 0.700000   x2 = -1.600000  x3 = 0.600000
	Itera��o 2: x1 = 0.960000   x2 = -1.912000  x3 = 0.981600
	Itera��o 3: x1 = 0.984240   x2 = -1.993168  x3 = 1.001102

		It 3				It 2		   Matriz Subtra��o	
	| 0.984240 |	-	| 0.960000 |	=	| 0.024240 |
	|-1.993168 |	-	|-1.912000 |	=	| 0.081168 |
	| 1.001102 |	-	| 0.981600 |	=	| 0.019424 |

	� = Maior n�mero [EM M�DULO] da matriz subtra��o / Maior n�mero [EM M�DULO] da matriz da itera��o atual (3)
	� = 0.81168 / 1.993168 = 0.0407 
	Se a quest�o pedir um � = 0.05 ent�o voc� precisar� de apenas 3 itera��es j� que 0.0407 < 0.05 ( O � na itera��o 2 era 0.347 que � maior que 0.05, ent�o foi necess�rio fazer mais uma itera��o )


*/