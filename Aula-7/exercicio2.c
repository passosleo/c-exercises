#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char name[50];
  int size = 0, words = 1, counter = 0;
  short is_valid = 0;

  while(!is_valid){
    printf("Informe o seu nome completo:\n");
    fflush(stdin);
    fgets(name, 50, stdin);
    size = strlen(name) - 1;
    is_valid = 1;

    if(name[size - 1] == ' '){
      is_valid = 0;
    };

    if(!is_valid){
      printf("Entrada inválida!\n");
    };
  };
 
  printf("Resultado: ");
  for(int i = size - 1; i >= 0; i--){
    if(name[i] == ' ' || i == 0){
      if(i == 0){
        i = i - 1;
      }else{
        words++;
      };
      for(int j = i + 1; j <= size; j++){
        if(name[j] == ' ' || j == size){
          printf(" ");
          break;
        }else{
          printf("%c",name[j]);
        };
      };
    };
  };
  
  printf("\nQuantidade de palavras: %d\n", words);
  
  return 0;
};