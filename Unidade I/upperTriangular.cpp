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
    for (size_t i = 0; i < SIZE; i++)
    {
        matriz[i] = new float[SIZE+1];
    }
    
    char Choice;
    cout<<"Gerar matriz aleatoria? [S/N]";
    cin>>Choice;
    if (Choice == 's' || Choice == 'S')
    {
        matrizGenerate(SIZE,SIZE+1,matriz);
    }
    else
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE+1; j++)
            {
                cout<<"Posicao["<<i<<"]["<<j<<"]:";
                cin>>matriz[i][j];
            }
        }
    }

    cout<<"Matriz Original:\n";
    showMatriz(SIZE,SIZE+1,matriz);
    
    cout<<"\nMatriz Triangular Superior:\n";
    for (size_t j = 0; j < SIZE && !giveUp; j++)
    {
        // cout<<"Etapa "<< j << endl;
        if (matriz[j][j] == 0)
        {
            bool find = false;
            for (size_t i = j+1; i < SIZE && !find; i++)
            {
                if (matriz[i][j]!=0)
                {
                    // cout<<"operacao2: "<<i<<", "<<j<<endl;
                    operation2(i,j,SIZE+1,matriz);
                    find = true;
                }
            }
            if (!find)
            {
                giveUp = true;
            }
            
        }
        if (!giveUp)
        {
            // cout<<"operacao1: "<<j<<endl;
            operation1(j,SIZE+1,matriz,1/matriz[j][j]);
            for (size_t i = j+1; i < SIZE; i++)
            {
                if (matriz[i][j]!=0)
                {
                    // cout<<"operacao3: "<<i<<", "<<j<<endl;
                    operation3(i,j,SIZE+1,matriz,-matriz[i][j]);
                }
            }
        }
        // showMatriz(SIZE,SIZE+1,matriz);
    }
    if (!giveUp)
    {
        // cout<<"\nFinal:\n";
        showMatriz(SIZE,SIZE+1,matriz);
    }
    else
    {
        cout<<"Essa matriz nao pode ser triangular superior";
    }
     
}

//mutiplica uma linha
void operation1(int linesChange, int columns, float ** mat, float numMult)
{
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange][i] = mat[linesChange][i]*numMult;
    }
}

//troca de linhas
void operation2(int linesChange1,int linesChange2, int columns, float ** mat)
{
    float * lineAux = new float [columns];
    for (size_t i = 0; i < columns; i++)
    {
        lineAux[i] = mat[linesChange1][i];
    }
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange1][i] = mat[linesChange2][i];
    }
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange2][i] = lineAux[i];
    } 
}

//soma uma linha pelo o multiplo de outra linhas
void operation3(int linesChange1,int linesChange2, int columns, float ** mat, float numMult)   
{
    float * lineAux = new float [columns];
    for (size_t i = 0; i < columns; i++)
    {
        lineAux[i] = mat[linesChange2][i]*numMult;
    }
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange1][i] += lineAux[i];
    } 
}