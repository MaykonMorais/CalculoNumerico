#include<iostream>
#include"arrayHandle.cpp"
using namespace std;

void operation1(int linesChange, int columns, double ** mat, int numMult);
void operation2(int linesChange1,int linesChange2, int columns, double ** mat);
void operation3(int linesChange1,int linesChange2, int columns, double ** mat, int numMult);

int main()
{
    int SIZE = 4;
    double ** matriz;
    matriz = new double*[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        matriz[i] = new double[SIZE+1];
    }
    matrizGenerate(SIZE,SIZE+1,matriz);
    showMatriz(SIZE,SIZE+1,matriz);
    //operation1(0, SIZE+1, matriz, 2);
    //operation2(0,1, SIZE+1, matriz);
    //operation3(0,1,SIZE+1,matriz,2);
    //showMatriz(SIZE,SIZE+1,matriz);

    //1 2 1 3; 2 -3 -1 4; 3 -1 -2 1
}

//mutiplica uma linha
void operation1(int linesChange, int columns, double ** mat, int numMult)
{
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange][i] = mat[linesChange][i]*numMult;
    }
}

//troca de linhas
void operation2(int linesChange1,int linesChange2, int columns, double ** mat)
{
    double * lineAux = new double [columns];
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
void operation3(int linesChange1,int linesChange2, int columns, double ** mat, int numMult)   
{
    double * lineAux = new double [columns];
    for (size_t i = 0; i < columns; i++)
    {
        lineAux[i] = mat[linesChange2][i]*numMult;
    }
    for (size_t i = 0; i < columns; i++)
    {
        mat[linesChange1][i] += lineAux[i];
    } 
}