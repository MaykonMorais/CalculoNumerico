#include<iostream>
#include"arrayHandle.cpp"
using namespace std;


int main()
{
    //instanciando variaveis
    int SIZE = 0;
    cout<<"Digite a ordem da matriz: ";
    cin>>SIZE;
    bool statusErro = false;
    float ** matriz, ** matrizUpper, ** matrizLower;
    matriz = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matriz[i] = new float[SIZE+1];
    }
    char Choice;

    //geracao de matriz
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        matrizGenerate(SIZE,SIZE+1,matriz);
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE+1; j++)
            {
                cout<<"Posicao["<<i<<"]["<<j<<"]:";
                cin>>matriz[i][j];
            }
        }
    }

    cout<<"Matriz Original:\n";
    showMatriz(SIZE,SIZE+1,matriz);

    //triangularizacao
    cout<<"\nMatriz Triangular Superior:\n";
    matrizUpper = upperTriangular(SIZE,SIZE+1,matriz,&statusErro);
    if (!statusErro)
    {
        showMatriz(SIZE,SIZE+1,matrizUpper); //exibe a matriz final 
    }
    else
    {
        cout<<"Essa matriz nao pode ser triangular superior";
    }
    
    cout<<"\nMatriz Triangular Inferior:\n";
    matrizLower = lowerTriangular(SIZE,SIZE+1,matriz,&statusErro);
    if (!statusErro)
    {
        showMatriz(SIZE,SIZE+1,matrizLower); //exibe a matriz final 
    }
    else
    {
        cout<<"Essa matriz nao pode ser triangular superior";
    }  
}