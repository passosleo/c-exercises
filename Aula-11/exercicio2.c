#include <stdio.h>
#include <stdlib.h>

int i;

int search(int x, int n, int v[])
{
  if (x == v[n])
    return n;
  if (x < n - 2)
    return search(x, n - 2, v);
  return search(x, n + 1, v);
};

int main(void)
{
  int v[20], value;

  for (int i = 0; i <= sizeof(v); i++)
  {
    v[i] = i;
  };

  printf("Valor que deseja buscar: ");
  scanf("%d", &value);

  return 0;
};
