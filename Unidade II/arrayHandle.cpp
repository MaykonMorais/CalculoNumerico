#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <iostream>
using namespace std;

void showMatriz(int lines, int columns, int** matriz);
void matrizGenerate(int lines, int columns, int** matriz);
void showVetor(int lines, int* vet);
void showVetor(int lines, float* vet);
void vetorGenerate(int lines, int* vet);
void vetorGenerate(int lines, float* vet);
void showMatriz(int lines, int columns, float** matriz);
void matrizGenerate(int lines, int columns, float ** matriz);

void operation1(int linesChange, int columns, float ** matriz, float numMult);
void operation2(int linesChange1,int linesChange2, int columns, float ** matriz);
void operation3(int linesChange1,int linesChange2, int columns, float ** matriz, float numMult);

void arrayCopy(int lines, int columns, float ** src,float ** target);
float ** transposed(int size, float ** matriz);
float ** arrayMutiply(int linesA, int columnsA, int linesB, int columnsB, float ** matrizA, float ** matrizB, bool * statusErro);
float ** upperTriangular(int lines, int columns, float ** matriz,bool * statusErro);
float ** lowerTriangular(int lines, int columns, float ** matriz,bool * statusErro);

float determinant(int size, float ** matriz, bool * statusErro);
bool isSymmetric(int size, float ** matriz);
bool isPositiveDefinite(int size, float ** matriz);


void showVetor(int lines, int* vet)
{
    int i;
    for ( i = 0; i < lines; i++)
    {
        printf("[%d] ",vet[i]);        
    }    
}
void showVetor(int lines, float* vet)
{
    int i;
    for ( i = 0; i < lines; i++)
    {
        cout.setf(std::ios::fixed,std::ios::floatfield);
        cout.precision(3);
        float num = vet[i];
        if (num<0.0001 && num>-0.0001)
        {
            num =  0;
        }
        cout<<'['<<num<<"]\t";
        printf("\n");       
    }    
}
void vetorGenerate(int lines, int* vet)
{
    int i;
    srand(time(NULL));
    for ( i = 0; i < lines; i++)
    {
        vet[i] = rand()%10;        
    }
    
}

void vetorGenerate(int lines, float* vet)
{
    int i;
    srand(time(NULL));
    for ( i = 0; i < lines; i++)
    {
        vet[i] = rand()%10;        
    }
    
}

void showMatriz(int lines, int columns, int** matriz)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("[%d] ",matriz[i][j]);
        }
        printf("\n");       
    }    
}

void matrizGenerate(int lines, int columns, int ** matriz)
{
    srand(time(NULL));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matriz[i][j] = rand()%10;
        }
        
    }
    
}

void showMatriz(int lines, int columns, float** matriz)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout.setf(std::ios::fixed,std::ios::floatfield);
            cout.precision(6);
            float num = matriz[i][j];
            if (num<0.0001 && num>-0.0001)
            {
                num =  0;
            }
            
            cout<<'['<<num<<"]";
        }
        printf("\n");       
    }    
}
//gera uma matriz com valores aleatórios
void matrizGenerate(int lines, int columns, float ** matriz)
{
    srand(time(NULL));
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            float num =  rand()%10;
            matriz[i][j] = num;
        }
        
    }   
}

//---------------------------------Opercoes com Matrizes------------------------------------------------------
//mutiplica uma linha
void operation1(int linesChange, int columns, float ** matriz, float numMult)
{
    for (int i = 0; i < columns; i++)
    {
        matriz[linesChange][i] = matriz[linesChange][i]*numMult;
    }
}

//troca de linhas
void operation2(int linesChange1,int linesChange2, int columns, float ** matriz)
{
    float * lineAux = new float [columns];
    for (int i = 0; i < columns; i++)
    {
        lineAux[i] = matriz[linesChange1][i];
    }
    for (int i = 0; i < columns; i++)
    {
        matriz[linesChange1][i] = matriz[linesChange2][i];
    }
    for (int i = 0; i < columns; i++)
    {
        matriz[linesChange2][i] = lineAux[i];
    } 
}

//soma uma linha pelo o multiplo de outra linha
void operation3(int linesChange1,int linesChange2, int columns, float ** matriz, float numMult)   
{
    float * lineAux = new float [columns];
    for (int i = 0; i < columns; i++)
    {
        lineAux[i] = matriz[linesChange2][i]*numMult;
    }
    for (int i = 0; i < columns; i++)
    {
        matriz[linesChange1][i] += lineAux[i];
    } 
}
//---------------------------------------FIM------------------------------------------------------------------
//---------------------------------Opercoes com Matrizes------------------------------------------------------
void arrayCopy(int lines, int columns, float ** src,float ** target)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            target[i][j] = src[i][j];
        }
    }
    
}
float ** arrayMutiply(int linesA, int columnsA, int linesB, int columnsB, float ** matrizA, float ** matrizB, bool * statusErro)
{
    float ** matrizMutiply = new float*[linesA];
    for (int i = 0; i < linesA; i++)
    {
        matrizMutiply[i] = new float[columnsB];
    }
    if (columnsA == linesB)
    {
        for (int i = 0; i < linesA; i++)
        {
            for (int j = 0; j < columnsB; j++)
            {
                float result = 0;
                for (int k = 0; k < columnsA; k++)
                {
                    result += matrizA[i][k]*matrizB[k][j];
                }
                matrizMutiply[i][j] = result;
            }
        }
    }
    else
    {
        *statusErro = true;
    }
    return matrizMutiply;
}
float ** upperTriangular(int lines, int columns, float ** matriz,bool * statusErro)
{
    float ** matrizUpper = new float*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrizUpper[i] = new float[columns];
    }
    arrayCopy(lines,columns, matriz,matrizUpper);
    for (int j = 0; j < lines && !*statusErro; j++)
    {
        if (matrizUpper[j][j] == 0)// se o elemento da pivotacao for 0 ele tenta trocar por outra linha viavel
        {
            bool find = false;
            for (int i = j+1; i < lines && !find; i++)
            {
                if (matrizUpper[i][j]!=0)
                {
                    operation2(i,j,columns,matrizUpper);
                    find = true;
                }
            }
            if (!find)
            {
                *statusErro = true; //se ele nao encontrar, nao e possivel triangularizar a matriz
            }  
        }
        if (!*statusErro)
        {
            for (int i = j+1; i < lines; i++)
            {
                if (matrizUpper[i][j]!=0)
                {
                    operation3(i,j,columns,matrizUpper,-matrizUpper[i][j]/matrizUpper[j][j]); //o elementos abaixo do elemento da pivotacao deve ser 0
                }
            }
        }
    }
    if (!*statusErro)
    {
        return matrizUpper;
    }
    else
    {
        return NULL;
    }
}

float ** lowerTriangular(int lines, int columns, float ** matriz, bool * statusErro)
{
    float ** matrizLower = new float*[lines];
    for (int i = 0; i < lines; i++)
    {
        matrizLower[i] = new float[columns];
    }
    arrayCopy(lines,columns, matriz,matrizLower);
    for (int j = lines-1; j >=0 && !* statusErro; j--)
    {
        if (matrizLower[j][j] == 0)// se o elemento da pivotacao for 0 ele tenta trocar por outra linha viavel
        {
            bool find = false;
            for (int i = j-1; i >= 0 && !find; i--)
            {
                if (matrizLower[i][j]!=0)
                {
                    operation2(i,j,columns,matrizLower);
                    find = true;
                }
            }
            if (!find)
            {
                * statusErro = true; //se ele nao encontrar, nao e possivel triangularizar a matriz
            }            
        }
        if (!* statusErro)
        {
            for (int i = j-1; i >=0; i-=1)
            {
                if (matrizLower[i][j]!=0)
                {               
                    operation3(i,j,columns,matrizLower,-matrizLower[i][j]/matrizLower[j][j]); //o elementos acima do elemento da pivotacao deve ser 0
                }
            }
        }
    }
    if (!*statusErro)
    {
        return matrizLower;
    }
    else
    {
        return NULL;
    }
}
//transposição de matriz
float ** transposed(int size, float ** matriz)
{
    float ** matrizTransposed = new float*[size];
    for (int i = 0; i < size; i++)
    {
        matrizTransposed[i] = new float[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrizTransposed[i][j] = matriz[j][i];
        }
    }
    return matrizTransposed;
}
//---------------------------------------FIM------------------------------------------------------------------
float determinant(int size, float ** matriz, bool * statusErro)
{
    float num = 1;
    float ** matTriangular = new float *[size];
    for (int i = 0; i < size; i++)
    {
        matTriangular[i] = new float[size];
    }
    bool st = false;
    matTriangular = upperTriangular(size,size,matriz, &st);
    if (!st)
    {
        for(int i = 0; i < size; i++)
        {
            num *= matTriangular[i][i];
        }    
    }
    *statusErro = st;
    return num;
}

bool isSymmetric(int size, float ** matriz)
{
    bool symmetric = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(matriz[i][j] != matriz[j][i])
                symmetric = false;
        }
        i++;
    }
    return symmetric;
}
bool isPositiveDefinite(int size, float ** matriz)
{
    bool control = isSymmetric(size,matriz);
    for (int i = 0; (i <= size && control); i++)
    {
        bool st = false;
        if(determinant(i,matriz,&st)<=0 || st)
        {
            control=false;
        }
    }  
    return control;
}
