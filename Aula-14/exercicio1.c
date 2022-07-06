#include <stdio.h>
#include <stdlib.h>

int main(){ 
  int *vector;
  int size;

  printf("Informe o tamanho do vetor: ");
  scanf("%d%*c", &size);

  vector = (int *) malloc(size * sizeof(int));

  for(int i = 0; i < size; i++){
    printf("Informe o elemento %d do vetor: ",i);
    scanf("%d%*c", &vector[i]);
  }

  printf("\n");

  for(int i = 0; i < size; i++){
    printf("Valor: %d - Endereço: %p\n", vector[i], &vector[i]);
  }

  free(vector);

  return 0;
}