#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int soma(int n1, int n2) {
  return n1 + n2;
};

int subtracao(int n1, int n2) {
  return n1 - n2;
};

int multiplicacao(int n1, int n2) {
  return n1 * n2;
};

float divisao(int n1, int n2) {
  if( n2 == 0 ) {
      printf("Não é possivel dividir por zero!\n");
      return 0;
  }
  return n1 / n2;
};

int resto(int n1, int n2) {
  return n1 % n2;
};

float potencia(float n1, float n2) {
  return pow(n1,n2);
};

int main(void) {
  int n1 = 0, n2 = 0, resp = 0;
  char opcao = ' ';

  do{ 
    printf("Insira o primeiro valor:\n");
    scanf("%d", &n1);
    printf("Insira o segundo valor:\n");
    scanf("%d", &n2);
    printf("Escolha a operação:\n");
    printf("[1] - Soma\n[2] - Subtração\n[3] - Multiplicação\n[4] - Divisão\n[5] - Resto da Divisão\n[6] - Potencia\n");
    scanf("%d", &resp);
    
    switch(resp){
      case 1:
        printf("Resultado: %d\n",soma(n1,n2));
        break;
      case 2:
        printf("Resultado: %d\n",subtracao(n1,n2));
        break;
      case 3:
        printf("Resultado: %d\n",multiplicacao(n1,n2));
        break;
      case 4:
        if(divisao(n1,n2) == 0){
          break;
        }else{
          printf("Resultado: %.2f\n",divisao(n1,n2));
        }
        break;
      case 5:
        printf("Resultado: %d\n",resto(n1,n2));
        break;
      case 6:
        printf("Resultado: %.2f\n", potencia(n1,n2));
        break;
      default:
        printf("Opção inválida!\n");
     };
  
    printf("Escolha uma opção:\n");
    printf("[R] - Repetir\n[S] - Sair\n");
    scanf("%s", &opcao);
  }while(opcao == 'r' || opcao == 'R');

  return 0;
};