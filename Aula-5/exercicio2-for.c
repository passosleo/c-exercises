#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main() {
    int n;
    int i;

    printf("Informe um número positivo:\n");
    scanf("%d", &n);
    
    while(n < 1){
      printf("Número inválido! Informe um número positivo:\n");
      scanf("%d", &n);
    }

    for(i = 1; i <= n; i++) {
      if(i % 2 != 0){
        printf("Impar: %d\n",i);
      }
    } 
    return 0;
};