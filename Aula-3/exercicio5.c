#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main() {
    float n;
    int i;
    int aux1;
    float aux2;

    printf("Raizes perfeitas ímpares de 1 a 1000:\n");

    for(i = 1; i <= 1000; i++) {
      n = sqrt(i);
      aux1 = n;
      aux2 = n-aux1;
      if(aux2 == 0 && aux1 % 2 != 0 ){
        printf("%.2f\n", n);
      }
    } 
    return 0;
};