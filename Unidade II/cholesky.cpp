#include<iostream>
#include<math.h>
#include"arrayHandle.cpp"
using namespace std;


int main()
{
    //instanciando variaveis
    int SIZE = 0;
    cout<<"Digite a ordem da matriz: ";
    cin>>SIZE;
    bool statusErro = false;
    float ** matriz, ** matrizL;
    matriz = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matriz[i] = new float[SIZE+1];
    }
    matrizL = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matrizL[i] = new float[SIZE+1];
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
    statusErro = !isPositiveDefinite(SIZE,matriz);
    if (!statusErro)
    {
        cout<<"A matriz L:\n";
        matrizL[0][0] = sqrt(matriz[0][0]);
        showMatriz(SIZE,SIZE,matrizL);
        // showMatriz(SIZE,SIZE+1,matrizUpper); //exibe a matriz final
        // float * x = new float[SIZE];
        // for (int i = SIZE-1; i >= 0; i--)
        // {
        //     x[i] = matrizUpper[i][SIZE];
        //     for (int j = i+1; j < SIZE; j++)
        //     {
        //         x[i] -= matrizUpper[i][j]*x[j];
        //     }
        //     x[i] /= matrizUpper[i][i];        
        // }
        // for (size_t i = 0; i < SIZE; i++)
        // {
        //     cout<<"x"<<i+1<<" = "<<x[i]<<endl; 
        // } 
    }
    else
    {
        cout<<"Nao eh possivel usar cholesky com essa matriz";
    } 
}