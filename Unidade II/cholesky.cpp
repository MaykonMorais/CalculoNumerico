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
    float ** matriz, ** matrizL, ** matrizLT;
    float *vetY, *vetX, *vetResult;
    
    vetY = new float[SIZE];
    vetX = new float[SIZE];
    vetResult = new float[SIZE];

    matrizL = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matrizL[i] = new float[SIZE];
    }

    matriz = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matriz[i] = new float[SIZE];
    }
    char Choice;

    //geracao de matriz
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        matrizGenerate(SIZE,SIZE,matriz);
        vetorGenerate(SIZE,vetResult);
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                cout<<"Posicao["<<i<<"]["<<j<<"]:";
                cin>>matriz[i][j];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            cout<<"Resultado["<<i<<"]:";
            cin>>vetResult[i];
        }
    }

    cout<<"\nMatriz Original:\n";
    showMatriz(SIZE,SIZE,matriz);

    statusErro = !isPositiveDefinite(SIZE,matriz);
    if (!statusErro)
    {
        // matrizL = lowerTriangular(SIZE,SIZE,matriz,&statusErro);
        matrizL[0][0] = sqrt(matriz[0][0]);
        showMatriz(SIZE,SIZE,matrizL);
        cout<<endl;
        for (int i = 1; i < SIZE; i++)
        {
            matrizL[i][0] = matriz[i][0]/matrizL[0][0];
            showMatriz(SIZE,SIZE,matrizL);
            cout<<endl;
        }
        for (int i = 1; i < SIZE; i++)
        {
            float sum = 0;
            for (int j = 0; j < i; j++)
            {
                float sum2 = 0;
                for (int k = 0; k < j; k++)
                {
                    sum2 += matrizL[i][k]*matrizL[j][k];
                }
                matrizL[i][j] = (matriz[i][j] - sum2)/matrizL[j][j];
                sum += pow(matrizL[i][j],2);
            }
            matrizL[i][i] = sqrt(matriz[i][i]-sum);
        }
        matrizLT = transposed(SIZE, matrizL);

        for (int i = 0; i < SIZE; i++)
        {
            vetY[i] = vetResult[i];
            for (int j = i-1; j >= 0; j--)
            {
                vetY[i] -= matrizL[i][j]*vetY[j];
            }
            vetY[i] /= matrizL[i][i];        
        }

        for (int i = SIZE-1; i >= 0; i--)
        {
            vetX[i] = vetY[i];
            for (int j = i+1; j < SIZE; j++)
            {
                vetX[i] -= matrizLT[i][j]*vetX[j];
            }
            vetX[i] /= matrizLT[i][i];        
        }
        cout<<"\nMatriz L:\n";
        showMatriz(SIZE,SIZE,matrizL);
        cout<<"\nMatriz Lt:\n";
        showMatriz(SIZE,SIZE,matrizLT);
        cout<<"\nVetor Y:\n";
        showVetor(SIZE,vetY);
        cout<<"\nVetor X:\n";
        showVetor(SIZE,vetX);
    }
    else
    {
        cout<<"Nao eh possivel usar cholesky com essa matriz";
    } 
}