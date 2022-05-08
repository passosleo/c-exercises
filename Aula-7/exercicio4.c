#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char input[100];
  int size;
  short is_valid = 0, is_palindrome = 1;

  //valida frase
  while(!is_valid){
    printf("Insira uma frase:\n");
    fflush(stdin);
    fgets(input, 100, stdin);
    size = strlen(input) - 1;
    is_valid = 1;

    if(input[size - 1] == ' '){
      is_valid = 0;
    };

    if(!is_valid){
      printf("Entrada inválida!\n");
    };
  };

  //remove espaços
  for(int i = 0, j = 0; i < size; i++){
    if(isalpha(input[i])){
      input[j] = input[i];
      j++;
    }else{
      i++;
      input[j] = input[i];
      j++;
    };

    if(i == size - 1){
      input[j] = '\0';
    };
  };

  size = strlen(input) - 1;

  //testa se é palindromo
  for(int i = size, j = 0; i >= 0; i--){
    if(input[i] != input[j]){
      is_palindrome = 0;
      break;
    };
    j++;
  };

  if(is_palindrome){
    printf("É palindromo\n");
  }else{
    printf("Não é palindromo\n");
  };
  
  return 0;
};