#include<iostream>
#include<conio.h>

using namespace std;

int main(void)
{
	float a[10][10], b[10], x[10], y[10];
	int n = 0, m = 0, i = 0, j = 0;
	cout << "MÉTODO DE GAUSS SEIDEL\n";
	cout << "Entre com o valor de n (Matriz nxn): ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "Valor da Matriz na Posição: (" << i << ", " << j << ") = ";
			cin >> a[i][j];
		}
	}
	cout << "\nEntre com as constantes (valores do lado direito):\n";
	for (i = 0; i < n; i++)
	{
		cout << "Posição: (" << i << ", " << j << ") = ";
		cin >> b[i];
	}

	cout << "\nNúmero de Iterações: ";
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

// Como Calcular o £ (epsilon):
/* 
	Exemplo:
	Para calcular o £ da iteração 3, você pega a matriz dos valores da iteração 3 e diminui da matriz dos valores dados na iteração 2 (anterior).
	Na matriz resultado dessa subtração, você pega o maior número [EM MÓDULO].
	Esse maior número [EM MÓDULO] você divide pelo maior número [EM MÓDULO] da matriz de valores da iteração atual (No nosso caso a iteração 3)

	Iteração 1: x1 = 0.700000   x2 = -1.600000  x3 = 0.600000
	Iteração 2: x1 = 0.960000   x2 = -1.912000  x3 = 0.981600
	Iteração 3: x1 = 0.984240   x2 = -1.993168  x3 = 1.001102

		It 3				It 2		   Matriz Subtração	
	| 0.984240 |	-	| 0.960000 |	=	| 0.024240 |
	|-1.993168 |	-	|-1.912000 |	=	| 0.081168 |
	| 1.001102 |	-	| 0.981600 |	=	| 0.019424 |

	£ = Maior número [EM MÓDULO] da matriz subtração / Maior número [EM MÓDULO] da matriz da iteração atual (3)
	£ = 0.81168 / 1.993168 = 0.0407 
	Se a questão pedir um £ = 0.05 então você precisará de apenas 3 iterações já que 0.0407 < 0.05 ( O £ na iteração 2 era 0.347 que é maior que 0.05, então foi necessário fazer mais uma iteração )


*/