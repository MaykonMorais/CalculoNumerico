#include<iostream>
#include<math.h>
using namespace std;

double f(double x);
double riemann (double x0,double xf,int divisions);
int main()
{
    double x0, xf;
    int divisions;
    cout<<"Digite um valor para x inicial: ";
    cin>>x0;
    cout<<"Digite um valor para o x final: ";
    cin>>xf;
    cout<<"Digite o numero de divisoes: ";
    cin>>divisions;

    

    cout<<"Integral por Riemann: "<<riemann(x0,xf,divisions);
}

double f(double x)
{
    const double euler = 2.718281828;\
    // return pow(euler,-pow(x,2));
    // return pow(x,3) + 2;
}

double riemann (double x0,double xf,int divisions)
{
    double h=(xf-x0)/divisions;
    double integral = 0;
    for (size_t i = 0; i < divisions; i++)
    {
        integral += (h* f(x0+h*i));
    }
    return integral;
}