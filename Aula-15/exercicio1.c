#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char **argv) {
  char op;
  int n1, n2, i;
  
  if (argc > 4 || argc == 2 || (argc == 3 && *argv[1] == 'a') || (argc == 3 && *argv[1] == 's') || (argc == 3 && *argv[1] == 'm') || (argc == 3 && *argv[1] == 'd') || (argc == 3 && *argv[1] == 'r') || (argc == 3 && *argv[1] == 'p') || (argc == 4 && *argv[1] == 'q') || (argc == 4 && *argv[1] == 'c'))  {
    printf("Erro: número de argumentos inválido\n");
    return 1;
  } else if (argc == 1){
    printf("Argumentos: \n\n");
    printf("a n1 n2 - adicao\n");
    printf("s n1 n2 - subtracao\n");
    printf("m n1 n2 - multiplicacao\n");
    printf("d n1 n2 - divisao\n");
    printf("r n1 n2 - resto\n");
    printf("p n1 n2 - potencia\n");
    printf("q n - raiz quadrada\n");
    printf("c n - raiz cubica\n");
    return 0;
  }

  op = *argv[1];

  if(argv[2] != NULL){
    n1 = atoi(argv[2]);
  }
  
  if(argv[3] != NULL){
    n2 = atoi(argv[3]);
  }
  
  switch (op) {
    case 'a':
      printf("\nResultado: %d\n\n",adicao(n1,n2));
      break;
    case 's':
      printf("\nResultado: %d\n\n",subtracao(n1,n2));
      break;
    case 'm':
      printf("\nResultado: %d\n\n",multiplicacao(n1,n2));
      break;
    case 'd':
      if((i = divisao(n1,n2)) == 0){
        return 0;
      }
      printf("\nResultado: %.2f\n\n",divisao(n1,n2));
      break;
    case 'r':
      printf("\nResultado: %d\n\n",resto(n1,n2));
      break;
    case 'p':
      if(argv[2] != NULL){
        n1 = atof(argv[2]);
      }

      if(argv[3] != NULL){
        n2 = atof(argv[3]);
      }
      
      printf("\nResultado: %.2lf\n\n",potencia(n1,n2));
      break;
    case 'q':
      if(argv[2] != NULL){
        n1 = atof(argv[2]);
      }
      
      printf("\nResultado: %.2lf\n\n",raizquadrada(n1));
      break;
    case 'c':
      if(argv[2] != NULL){
        n1 = atof(argv[2]);
      }
      
      printf("\nResultado: %.2lf\n\n",raizcubica(n1));
      break;
    default:
      printf("Erro: argumento inválido\n");
      return 1;
  }
  return 0;
}