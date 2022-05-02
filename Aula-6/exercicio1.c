#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int tabuada[11][11];
  int resp;

  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      tabuada[i][j] = i * j;
    }
  }

  do {
    printf("Informe um número de 1 a 10 para obter a tabuada:\n");
    scanf("%d", &resp);
  } while (resp < 1 || resp > 10);


  for (int j = 1; j <= 10; j++) {
    printf("%d x %d = %d\n", resp, j, tabuada[resp][j]);
  }
  
  return 0;
}