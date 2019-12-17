#include<iostream>
#include<math.h>
#include <string>
#include <locale.h>
using namespace std;

double Function(double, double);
double Function2(double, double);

int main(){

	long n;
	double h, k11, k21, k31, k41, k12, k22, k32, k42; 
	
	cout << "Digite a quantidade de pontos: ";
	cin >> n;
	
	while(n<=0)
	{
		cout << "Deve ser maior que zero (n>0)\nDigite novamente: ";
		cin >> n;
	}

	double * x = new double[n];
	double * y = new double[n];
	double * y2 = new double[n];
	
	cout << "Digite o valor inicial de x: ";
	cin >> x[0];
	cout << "Digite o valor final de x: ";
	cin >> x[n-1];
	cout << "Digite o valor inicial de y: ";
	cin >> y[0];
	cout << "Digite o valor inicial de y2: ";
	cin >> y2[0];

	h = (x[n-1] - x[0]) / n; 

	for(int i=0; i<n-1; i++)
	{
		k11 = Function(x[i], y[i]);
		k21 = Function(x[i] + (h/2), y[i] + (h/2) * k11);
		k31 = Function(x[i] + (h/2), y[i] + (h/2) * k21);
		k41 = Function(x[i] + h, y[i] + h * k31);
		
		y[i+1] = y[i] + (h/6) * (k11 + 2 * k21 + 2 * k31 + k41);
		x[i+1] = x[i] + h;	
	}
	
		for(int i=0; i<n-1; i++)
	{
		k12 = Function2(x[i], y2[i]);
		k22 = Function2(x[i] + (h/2), y2[i] + (h/2) * k12);
		k32 = Function2(x[i] + (h/2), y2[i] + (h/2) * k22);
		k42 = Function2(x[i] + h, y2[i] + h * k32);
		
		y2[i+1] = y2[i] + (h/6) * (k12 + 2 * k22 + 2 * k32 + k42);
		//x[i+1] = x[i] + h;	
	}

	cout << "\nX\t\tY\t\tY2\n";

	cout << fixed;
	
	for(int i=0; i<n; i++)
	{
		cout << x[i] << "\t" << y[i] << "\t" << y2[i] << endl;
	}

	cout << endl << "Valor de h: " << h << endl;
	
	delete [] x;
	delete [] y;
	delete [] y2;

	return 0;
}

double Function(double x, double y){

	double f = y;
	return f;
}

double Function2(double x, double y){

	double f = 2*y;
	return f;
}

