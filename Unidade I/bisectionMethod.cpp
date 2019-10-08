#include<iostream>
#include<math.h>
#define ZERO 0.0001

using namespace std;

float f(float num);
float bisection(float a, float b, bool* exist);
float findRoot(float a, float b);
int interaction;
bool existBisection;

int main()
{
    cout<<"f(x) = x^3 -3x^2 + 1\n";
    float a,b;
    cout<<"Digite valores para o intervalo a e b: \n";
    cin>>a;
    cin>>b;

    cout<<"raiz: ";

    float root = findRoot(a,b);
    if(existBisection)
        cout<<"f("<<root<<")";
    else
        cout<<"\nA funcao nao satisfaz o teorema de bolzano!\n";  
    cout<<"\nInteracoes: "<<interaction;
}
//funcao para o exemplo f(x) = x^3 -3x^2 + 1
float f(float x) 
{
    return pow(x,3) -3 * pow(x,2) + 1;
}
//metodo da bisseccao
float bisection(float a, float b, bool* exist)
{
    interaction++;
    float fa = f(a);
    float fb = f(b);
    //verifica se f(a) e f(b) tem sinais opostos
    if((fa > 0 && fb < 0) || (fa < 0 && fb > 0))
    {
        float p = (a+b)/2;
        float fp = f(p);

        //se f(p) ~= 0, entao ele encontrou a raiz
        if (fp<ZERO && fp>-ZERO)
        {
            *exist = true;
            return p;
        }
        else
        {
            //faz uma nova bisseccao a direita, se nao encontra, faz outra a esquerda
            bool existRight, existLeft;
            float bRight = bisection(a, p, &existRight);
            if (!existRight)
            {
                float bLeft = bisection(p, b, &existLeft);
                if(!existLeft) 
                {
                    *exist = false;
                    return 0;
                }
                else
                {
                    *exist = true;
                    return bLeft;
                }
            }
            else
            {
                *exist = true;
                return bRight;
            }
        }       
    }
    //se f(a) e f(b) nao tiverem sinais opostos entao nao ha raiz no intervalo
    else
    {
        *exist = false;
        return 0;
    }
}
//metodo que encontra a raiz de uma funcao em um intervalo [a,b]
float findRoot(float a, float b)
{
    float fa = f(a);
    float fb = f(b);
    if (fa == 0)
        return fa;
    if(fb == 0)
        return fb;
    return bisection(a, b, &existBisection);
}

