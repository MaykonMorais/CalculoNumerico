#include <stdio.h>

#include <stdlib.h>

 
typedef double (*Function)(double x, double y);

double f(double x, double y);

double f2(double x, double y);

double k1(double xk, double yk, Function fun);

double k2(double xk, double yk, double h, Function fun);

double k3(double xk, double yk, double h, Function fun);

double k4(double xk, double yk, double h, Function fun);


 

int main(void){

    int n;

    double h;    

 

    printf("Digite a quantidade de pontos: ");

    scanf("%d", &n);

 

    double * x = (double *) calloc(n, sizeof(double));

    double * y = (double *) calloc(n, sizeof(double));
    double * y2 = (double *) calloc(n, sizeof(double));

 

    while(n<=0){

    printf("Digite a quantidade de pontos: ");

    scanf("%d", &n);

    }

 

    printf("Digite o valor inicial de x: ");

    scanf("%lf", &x[0]);

    printf("Digite o valor final de x: ");

    scanf("%lf", &x[n]);

    printf("Digite o valor inicial de y: ");

    scanf("%lf", &y[0]);

 	printf("Digite o valor inicial de y2: ");

    scanf("%lf", &y2[0]);

    h = (x[n]-x[0])/n;

 

    for(int i=0; i<n-1;i++){
        y[i+1] = y[i] + (h/6)*(k1(x[i], y[i],f) + 2*k2(x[i], y[i], h,f) + 2*k3(x[i], y[i], h,f) + k4(x[i], y[i], h,f));
        y2[i+1] = y2[i] + (h/6)*(k1(x[i], y2[i],f2) + 2*k2(x[i], y2[i], h,f2) + 2*k3(x[i], y2[i], h,f2) + k4(x[i], y2[i], h,f2));
        x[i+1] = x[i] + h;

    }
 

    FILE * arquivo;

 

    arquivo = fopen("RKO4.dat", "w");

 

    if(arquivo == NULL){

        printf("ERRO: Não foi possível abrir o arquivo\n");

        return 1;

    }

    

    printf("X\tY\n");

    fprintf(arquivo,"X\tY\n");

    for(int i=0;i<n;i++){

        fprintf(arquivo,"%lf\t%lf\t%lf\n", x[i], y[i],y2[i]);

        printf("%lf\t%lf\t%lf\n", x[i], y[i],y2[i]);

    }

    printf("Arquivo salvo com sucesso!");

    free(x);

    free(y);
    
 	free(y2);
 

    //system("pause");

    return 0;

}

 

double f(double x, double y){

    return (y);

}

double f2(double x, double y){

    return (2*y);

}

double k1(double xk, double yk, Function fun){

    return fun(xk, yk);

}

 

double k2(double xk, double yk, double h, Function fun){

    return fun(xk + (h/2), yk + k1(xk, yk, fun)*(h/2));

}

 

double k3(double xk, double yk, double h, Function fun){

    return fun(xk + (h/2), yk + k2(xk, yk, h,fun)*(h/2));

}

 

double k4(double xk, double yk, double h, Function fun){

    return fun(xk + h, yk + k3(xk, yk, h,fun)*h);

}
