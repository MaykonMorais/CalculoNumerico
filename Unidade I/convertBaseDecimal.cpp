#include <iostream>
#include <string.h> // manipulação de strings (atoi)
#include <math.h>


int convertBaseDec(char * vet, int base);
int convertAsciiNumber(char caracter);
using namespace std;

int main() {
    char num[50];
    int base;
    cout << "Digite uma Base: ";
    cin >> base;
    cout << "Digite um numero na base escolhida: ";
    cin >> num;
    cout << "Decimal: " << convertBaseDec(num, base) << endl;
    return 0;
}

int convertBaseDec(char * vet, int base) {
    int tam = strlen(vet);
    int somador = 0;

    for(int i = 0, j = tam-1; i < tam; i++,j--) {
        int num = convertAsciiNumber(vet[i]);
        somador+= num * pow(base, j);  // forma linear
    }
    return somador;
}

int convertAsciiNumber(char caracter)
{
    if (caracter >= 48 && caracter <= 57)
        return (int)(caracter-48);
    else if(caracter >= 65 && caracter <= 90)
        return (int)(caracter-55);
    else if(caracter >= 97 && caracter <= 122)
        return (int)(caracter-87);
    else
    {
        cout<<"[ERROR]\n";
        return 0;
    }
    
}