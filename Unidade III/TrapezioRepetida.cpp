/// REGRA DO TRAP�ZIO REPETIDA
#include <iostream>
#include <cmath> 
using namespace std;

#define E 2.71828182845904523536

double funcao(double);

int main(){
	
	int i, m;
	double a, b, aux;
	
	cout << "---------REGRA DO TRAP�ZIO REPETIDA---------\n\n";
	cout << "Digite o valor de a: ";
	cin >> a;
	cout << "Digite o valor de b: ";
	cin >> b;
	cout << "Digite o valor de m: " ;
	cin >> m;

	//condi��o para que o valor de b seja sempre o maior valor
	if(a>b)
	{ 
	    aux=a;
	    a=b;
	    b=aux;
	}
	
	double h, I;
	double* x = new double[m];
	double* y = new double[m];
	
	h = (b-a) / m;
	
	for(i=0; i<=m; i++)
	{	
	    x[i] = a + i * h;
	    y[i] = funcao(x[i]);
	}
	
	I = (y[0] + y[m]) / 2;
	
	for(i=1; i<m; i++)
	{
		I = I + y[i];
	}
	
	I = h * I;
	
	cout <<"\nA aproxima��o da integral numerica �: " << I << endl;
		
	return 0;
}

// definir a fun��o
double funcao(double x)
{
	return(pow(E,x));

    // return 3*x-7;
}


