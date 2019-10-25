#include<iostream>
#include"arrayHandle.cpp"
using namespace std;

void operation1(int linesChange, int columns, float ** mat, float numMult);
void operation2(int linesChange1,int linesChange2, int columns, float ** mat);
void operation3(int linesChange1,int linesChange2, int columns, float ** mat, float numMult);

int main()
{
    int SIZE = 0;
    cout<<"Digite a ordem da matriz: ";
    cin>>SIZE;
    bool giveUp = false;
    float ** matriz;
    matriz = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matriz[i] = new float[SIZE];
    }
    
    char Choice;
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        matrizGenerate(SIZE,SIZE,matriz);
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
    }

    cout<<"Matriz Original:\n";
    showMatriz(SIZE,SIZE,matriz);
    
    cout<<"\nMatriz Triangular Superior:\n";
    for (int j = SIZE-1; j >=0 && !giveUp; j--)
    {
        // cout<<"Etapa "<< j << endl;
        if (matriz[j][j] == 0)// se o elemento da pivotacao for 0 ele tenta trocar por outra linha viavel
        {
            bool find = false;
            // cout<<"Tentou\n";
            for (int i = j-1; i >= 0 && !find; i--)
            {
                if (matriz[i][j]!=0)
                {
                    // cout<<"operacao2: "<<i<<", "<<j<<endl;
                    operation2(i,j,SIZE,matriz);
                    find = true;
                }
            }
            if (!find)
            {
                giveUp = true; //se ele nao encontrar, nao e possivel triangularizar a matriz
            }
            
        }
        if (!giveUp)
        {
            // cout<<"operacao1: "<<j<<endl;
            operation1(j,SIZE,matriz,1/matriz[j][j]); //transforma o elemento da pivotacao em 1
            
            // showMatriz(SIZE,SIZE,matriz);
            for (int i = j-1; i >=0; i-=1)
            {
                // cout<<"operacao3: "<<i<<", "<<j<<endl;
                if (matriz[i][j]!=0)
                {
                    
                    operation3(i,j,SIZE,matriz,-matriz[i][j]); //o elementos acima do elemento da pivotacao deve ser 0
                }
                // showMatriz(SIZE,SIZE,matriz);
            }
        }
    }
    if (!giveUp)
    {
        // cout<<"\nFinal:\n";
        showMatriz(SIZE,SIZE,matriz); //exibe a matriz final 
    }
    else
    {
        cout<<"Essa matriz nao pode ser triangular superior";
    }
     
}

//mutiplica uma linha
void operation1(int linesChange, int columns, float ** mat, float numMult)
{
    for (int i = 0; i < columns; i++)
    {
        mat[linesChange][i] = mat[linesChange][i]*numMult;
    }
}

//troca de linhas
void operation2(int linesChange1,int linesChange2, int columns, float ** mat)
{
    float * lineAux = new float [columns];
    for (int i = 0; i < columns; i++)
    {
        lineAux[i] = mat[linesChange1][i];
    }
    for (int i = 0; i < columns; i++)
    {
        mat[linesChange1][i] = mat[linesChange2][i];
    }
    for (int i = 0; i < columns; i++)
    {
        mat[linesChange2][i] = lineAux[i];
    } 
}

//soma uma linha pelo o multiplo de outra linhas
void operation3(int linesChange1,int linesChange2, int columns, float ** mat, float numMult)   
{
    float * lineAux = new float [columns];
    for (int i = 0; i < columns; i++)
    {
        lineAux[i] = mat[linesChange2][i]*numMult;
    }
    for (int i = 0; i < columns; i++)
    {
        mat[linesChange1][i] += lineAux[i];
    } 
}