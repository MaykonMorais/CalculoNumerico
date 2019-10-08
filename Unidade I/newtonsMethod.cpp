#include<iostream>
#include<math.h>
#include<time.h>
#include"derived.cpp"
#define ZERO 0.0001

using namespace std;

double f(double num);
double bisection(double x);
double findRoot(double x);
int interaction;
bool existBisection;

int main()
{
    cout<<"f(x) = x^3 -3x^2 + 1\n";
    double x;
    cout<<"Digite um valor inicial para a busca da raiz: \n";
    cin>>x;
    cout<<"raiz: ";
    double root = findRoot(x);
    cout<<"f("<<root<<")"; 
    cout<<"\nInteracoes: "<<interaction;
}
//funcao para o exemplo f(x) = x^3 -3x^2 + 1
double f(double x) 
{
    return pow(x,3) -3 * pow(x,2) + 1;
}
//metodo de Newton
double newtonsMethod(double x)
{
    interaction++;
    double xn = x - f(x)/derived(f,x);
    double fxn = f(xn);
    if (fxn<ZERO && fxn>-ZERO)
    {
        return xn;
    }
    else
       return newtonsMethod(xn);      
}
//metodo que encontra a raiz de uma funcao em um intervalo [a,b]
double findRoot(double x)
{
    return newtonsMethod(x);
}

