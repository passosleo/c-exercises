#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n, a = 0, b = 1, aux;

  printf("Digite um número: ");
  scanf("%d", &n);
  printf("\nSequencia de Fibonacci:\n\n");

  for (int i = 0; i < n; i++)
  {
    if (n == 0)
      printf("%d\n", a);
    if (n == 1)
      printf("%d\n", b);
    aux = a + b;
    a = b;
    b = aux;

    printf("%d\n", aux);
  };

  return 0;
};