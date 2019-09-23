#include <iostream>
#include <string.h> // manipulação de strings (atoi)
#include <math.h>


int convertBinDec(char * vet);
using namespace std;

int main() {
    char num[50];
    cout << "Digite em binario: ";
    cin >> num;

    cout << "Decimal: " << convertBinDec(num) << endl;
    return 0;
}


int convertBinDec(char * vet) {
    int tam = strlen(vet);
    int somador = 0;

    for(int i = 0, j = tam-1; i < tam; i++,j--) {
        somador+= (int)(vet[i]-48) * pow(2, j);  // forma linear
    }

    return somador;
}