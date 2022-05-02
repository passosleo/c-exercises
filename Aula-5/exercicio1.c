#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main() {
    int n;
    int i;

    printf("Informe um número de 1 a 10:\n");
    scanf("%d", &n);

    while(n < 1 || n > 10){
      printf("Valor inválido!\nInforme um número de 1 a 10:\n");
      scanf("%d", &n);
    }
    
    printf("Tabuada do %d:\n",n);

    for(i = 1; i <= 10; i++) {
      printf("%d x %d = %d\n",n,i,n*i);
    } 
    return 0;
};