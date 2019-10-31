#include <iostream>
#include <cmath>
#include "arrayHandle.cpp"
using namespace std;

float matrizEuclidiana(int lines, float * vetor);

int main()
{
    int Linha = 0;
    int Coluna = 0;
    cout<<"Digite a quantidade de linhas da matriz: ";
    cin>>Linha;
    bool statusErro = false;
    float * vetor;
    vetor = new float[Linha];
    char Choice;

    //geracao de matriz
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        vetorGenerate(Linha,vetor);
    }
    else
    {
        for (int i = 0; i < Linha; i++)
        {
            cout<<"Posicao["<<i<<"]:";
            cin>>vetor[i];
        }
    }

    cout<<"Matriz Original:\n";
    showVetor(Linha,vetor);
    cout<<"\nNorma Euclidiana: "<< matrizEuclidiana(Linha,vetor);
}

float matrizEuclidiana(int lines, float * vetor)
{
    float euclidiana;
    for (size_t i = 0; i < lines; i++)
    {
        euclidiana += pow(vetor[i],2);
    }
    euclidiana = sqrt(euclidiana);
    return euclidiana;
}
