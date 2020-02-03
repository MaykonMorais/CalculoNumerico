// Trapezio Simples
#include <iostream>
#include <cmath>
using namespace std;
#define E 2.71828182845904523536
double Funcao(double);

int main()
{
	double x0, x1, h, area, b1, b2;
	cout << "Valor de x inicial: ";
	cin >> x0;
	cout << "Valor de x final: ";
	cin >> x1;
	h = x1 - x0;
	b1 = Funcao(x0);
	b2 = Funcao(x1);

	area = ((b1 + b2) * h) / 2;

	cout << "\nValor da área: " << area << endl;
	//cout << "b1: " << b1 << "\nb2: " << b2 << endl;

}

double Funcao(double x)
{
	return 2*x - 2;
}
