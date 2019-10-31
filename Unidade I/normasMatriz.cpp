#include <iostream>
#include <cmath>
#include "arrayHandle.cpp"
using namespace std;

float matrizMaximo(int lines, int columns, float ** matriz);
float matrizSoma(int lines, int columns, float ** matriz);

int main()
{
    int Linha = 0;
    int Coluna = 0;
    cout<<"Digite a quantidade de linhas da matriz: ";
    cin>>Linha;
    cout<<"Digite a quantidade de colunas da matriz: ";
    cin>>Coluna;
    bool statusErro = false;
    float ** matriz;
    matriz = new float*[Linha];
    for (int i = 0; i < Linha; i++)
    {
        matriz[i] = new float[Coluna];
    }
    char Choice;

    //geracao de matriz
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        matrizGenerate(Linha,Coluna,matriz);
    }
    else
    {
        for (int i = 0; i < Linha; i++)
        {
            for (int j = 0; j < Coluna; j++)
            {
                cout<<"Posicao["<<i<<"]["<<j<<"]:";
                cin>>matriz[i][j];
            }
        }
    }

    cout<<"Matriz Original:\n";
    showMatriz(Linha,Coluna,matriz);
    cout<<"\nNorma de Maximo: "<< matrizMaximo(Linha,Coluna,matriz);
    cout<<"\nNorma da Soma: "<< matrizSoma(Linha,Coluna,matriz);
}

float matrizMaximo(int lines, int columns, float ** matriz)
{
    float * x = new float[lines];

    for (size_t i = 0; i < lines; i++)
    {
        x[i] = 0;
        for (size_t j = 0; j < columns; j++)
        {
            x[i] += abs(matriz[i][j]);
        }
    }
    float most = 0;
    for (size_t i = 0; i < lines; i++)
    {
        if(x[i]>most)
            most = x[i];
    }
    return most;    
    
}

float matrizSoma(int lines, int columns, float ** matriz)
{
    float * x = new float[columns];

    for (size_t i = 0; i < columns; i++)
    {
        x[i] = 0;
        for (size_t j = 0; j < lines; j++)
        {
            x[i] += abs(matriz[j][i]);
        }
    }
    float most = 0;
    for (size_t i = 0; i < columns; i++)
    {
        if(x[i]>most)
            most = x[i];
    }
    return most;    
}
