#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
//using namespace std;

void showMatriz(int lines, int columns, int** mat);
void matrizGenerate(int lines, int columns, int** mat);
void showVetor(int lines, int* vet);
void vetorGenerate(int lines, int* vet);
void showMatriz(int lines, int columns, double** mat);
void matrizGenerate(int lines, int columns, double ** mat);

void showVetor(int lines, int* vet)
{
    int i;
    for ( i = 0; i < lines; i++)
    {
        printf("[%d] ",vet[i]);        
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

void showMatriz(int lines, int columns, int** mat)
{
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("[%d] ",mat[i][j]);
        }
        printf("\n");       
    }    
}

void matrizGenerate(int lines, int columns, int ** mat)
{
    srand(time(NULL));
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            mat[i][j] = rand()%10;
        }
        
    }
    
}

void showMatriz(int lines, int columns, double** mat)
{
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("[%.2lf] ",mat[i][j]);
        }
        printf("\n");       
    }    
}

void matrizGenerate(int lines, int columns, double ** mat)
{
    srand(time(NULL));
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            double num =  rand()%10;
            mat[i][j] = num;
        }
        
    }
    
}
