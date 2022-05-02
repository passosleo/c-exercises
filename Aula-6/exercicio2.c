#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int m1[3][3];
  int m2[3][3];
  int result[3][3];
  int n;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Preencha o valor para M1[%d][%d]:\n",i,j);
      scanf("%d", &n);
      m1[i][j] = n;
    }
  }

  printf("A primeira matriz foi preenchida!\n");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Preencha o valor para M2[%d][%d]:\n",i,j);
      scanf("%d", &n);
      m2[i][j] = n;
    }
  }

  printf("A segunda matriz foi preenchida!\n");

  printf("Calculando o resultado...\n");

  for (int i = 0; i < 3; i++) {
    printf("|");
    for (int j = 0; j < 3; j++) {
      result[i][j] = m1[i][j] * m2[i][j];
      printf(" %d ", result[i][j]);
    }
    printf("|\n");
  }
  
  return 0;
};