#include<iostream>
#include<math.h>
#include <string>
#include <locale.h>
using namespace std;

float Function(float x, float y);

int main(){

	long n;
	float h;

	cout << "Digite a quantidade de pontos: ";	
	cin >> n;
	
	while(n <= 0)
	{
		cout << "Deve ser maior que zero (n>0) \nDigite novamente: ";
		cin >> n;
	}
	
	float * x = new float[n];
	float * y = new float[n];
	
	cout << "Digite o valor inicial de x: ";
	cin >> x[0];
	cout << "Digite o valor final de x: ";
	cin >> x[n-1];
	cout << "Digite o valor inicial de y: ";
	cin >> y[0];
	
	// partições
	h = (x[n-1] - x[0])/n; 
	
	for (int i = 0; i < n-1; i++)
	{
		y[i+1] = y[i] + h *(Function(x[i],y[i]));
		x[i+1] = x[i] + h;	
	}
	
	cout << "\nX\t\tY\n";
	
	cout << fixed;
	
	for (int i = 0 ; i < n; i++)
	{
		cout << x[i] << "\t" << y[i] << endl;
	}
	
	cout << "\nValor de h: " << h << endl;
	
	delete [] x;
	delete [] y;
		
	return 0;
}

float Function(float x, float y)
{
	float f = x;
	return f;
}	
