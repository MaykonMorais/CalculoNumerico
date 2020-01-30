#include<iostream>
#include<math.h>
using namespace std;

double f(double x);
double riemann (double x0, int divisions, double h);
int main()
{
    double x0, xf, h;
    int divisions;
    cout<<"Digite um valor para x inicial: ";
    cin>>x0;
    cout<<"Digite um valor para o x final: ";
    cin>>xf;
    cout<<"Digite o numero de divisoes: ";
    cin>>divisions;

    h=(xf-x0)/divisions;

    cout<<"Integral por Riemann: "<<riemann(x0,divisions,h);
}

double f(double x)
{
    const double EULER = 2.71828182845904523536;
    return  pow(EULER,x);
}

double riemann (double x0,int divisions, double h)
{
    double integral = 0;
    for (size_t i = 0; i < divisions; i++)
    {
        integral += h* f(x0+h*i);
    }
    return integral;
}