#include<iostream>
#include<math.h>
using namespace std;

double f(double x);
double simpson(double x0,double xf);
int main()
{
    double x0,xf;
    cout<<"Digite um valor para x inicial: ";
    cin>>x0;
    cout<<"Digite um valor para o x final: ";
    cin>>xf;

    cout<<"Integral por Simpson: "<<simpson(x0,xf);
}

double f(double x)
{
    const double euler = 2.718281828;
    return pow(euler,-pow(x,2));
    // return pow(x,3) + 2;
}

double simpson (double x0,double xf)
{
    double integral = 0;
    double h = (xf-x0)/2;
    double x1 = x0+h;
    integral = (h/3)*(f(x0) + 4*f(x1) + f(xf));
    return integral;
}