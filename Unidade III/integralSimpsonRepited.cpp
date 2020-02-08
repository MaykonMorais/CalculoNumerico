#include<iostream>
#include<math.h>
using namespace std;

double f(double x);
double simpsonRepeated (double x0,double xf,int divisions);
double simpson (double x0,double xf, double h);
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

    cout<<"Integral por Simpson: "<<simpsonRepeated(x0,xf,divisions);
}

double f(double x)
{

    const double euler = 2.718281828;
    return pow(euler,-pow(x,2));
    // return pow(x,3) + 2;
}

double simpsonRepeated (double x0,double xf,int divisions)
{
    double integral = 0;
    double h = (xf-x0)/2*divisions;
    double xP = x0;
    for (int i = 0; i < divisions; i++)
    {
        integral += simpson(xP,xP+2*h,h);
        xP += 2*h;
    }
    return integral;
}

double simpson (double x0,double xf, double h)
{
    double integral = 0;
    double x1 = x0+h;
    integral = (h/3)*(f(x0) + 4*f(x1) + f(xf));
    return integral;
}