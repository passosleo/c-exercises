#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main() {
    int n;
    int res = 0;

    printf("Informe um número positivo:\n");
    scanf("%d", &n);
    
    while(n < 1){
      printf("Número inválido! Informe um número positivo:\n");
      scanf("%d", &n);
    }

    while(res <= n){
      if(res % 2 != 0){
        printf("Impar: %d\n",res);
      }
      res++;
    }
    return 0;
};