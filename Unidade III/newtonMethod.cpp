#include<iostream>
#include <cmath>
using namespace std;
typedef struct
{
    double x;
    double y;
}Vector2;

int main() {
    
    int size;
    cout<<"Digite a quantidade de pontos: ";
    cin>>size;
    Vector2 p[size];
    double d[size];

    for (size_t i = 0; i < size; i++)
    {
        cout<<"\nPonto p"<<i<<endl;
        cout<<"x: ";
        cin>>p[i].x;
        cout<<"y: ";
        cin>>p[i].y;
    }
    
    cout<<endl;
    double previous[size];
    double current[size];
    for (size_t i = 0; i < size; i++)
    {
        previous[i] = p[i].y;
    }
    d[0] = p[0].y;
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            current[j] = (previous[j+1] - previous[j])/(p[i+j+1].x - p[j].x);
        }
        d[i+1] = current[0];
        for (size_t k = 0; k < size-i-1; k++)
        {
            previous[k] = current[k];
        }
        cout<<endl;
    }
    for (size_t i = 0; i < size; i++)
    {
        cout<<"d"<<i<<" = "<<d[i]<<endl;
    }
    cout<<"P(x) = ";
    for (size_t i = 0; i < size; i++)
    {
        cout<<"("<<d[i]<<")";
        for (size_t j = 0; j < i; j++)
        {
            cout<<"(x - ("<<p[j].x<<"))";
        }
        if(i < size-1)
        {
            cout<<" + ";
        }
    }
}