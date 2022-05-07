#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char word[50], option = ' ', vowels[50], consonants[50];
  int size = 0, i = 0, j = 0, k = 0;
  short is_valid = 0, compost = 0;

  //valida frase
  while(!is_valid){
    printf("Informe uma palavra:\n");
    fflush(stdin);
    fgets(word, 50, stdin);
    size = strlen(word) - 1;
    is_valid = 1;

    if(word[size - 1] == ' '){
      is_valid = 0;
    };

    if(!is_valid){
      printf("Entrada inválida!\n");
    };
  };

  is_valid = 0;

  //valida opção
  while(!is_valid){
    printf("Escolha a ordem:\n [V] - para vogais\n [C] - para consoantes\n");
    scanf("%s", &option);
    option = tolower(option);
    is_valid = 1;
    
    if(option != 'v' && option != 'c'){
      is_valid = 0;
    };

    if(!is_valid){
      printf("Opção inválida!\n");
    };
  };

  //separa vogais de consoantes
  for(i = 0; i < size; i++){
    word[i] = tolower(word[i]);
    if(isalpha(word[i])){
      if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
        vowels[j] = word[i];
        j++;
      }else{
        consonants[k] = word[i];
        k++;
      };
    };
  };

  //finaliza as strings
  vowels[j] = '\0';
  consonants[k] = '\0';

  if(option == 'v'){
    printf("Resultado: %s %s", vowels,consonants);
  }else{
    printf("Resultado: %s %s", consonants,vowels);
  };
  
  return 0;
};