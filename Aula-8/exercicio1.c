#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vogais_consoantes( char *palavra, int *vogais, int *consoantes, int *letras, char *primeira_letra, char *ultima_letra ) {

  for(int i = 0; i < strlen(palavra); i++){
    //Converte para lowercase antes de testar se vogal ou consoante
    palavra[i] = tolower(palavra[i]);
    if(palavra[i] == 'a' || palavra[i] == 'e'|| palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'){
      *vogais = *vogais + 1;
    } else {
      *consoantes = *consoantes + 1;
    };

    *letras = *letras + 1;

    //Converte para uppercase primero e último caractere
    if(i == 0){
      *primeira_letra = toupper(palavra[i]);
    };

    if(i == strlen(palavra) - 1){
      *ultima_letra = toupper(palavra[i]);
    };
  };
};

int main(void) {
  char palavra[50], primeira_letra = ' ', ultima_letra = ' ';
  int tamanho = 0, letras = 0, vogais = 0, consoantes = 0;
  short is_valid = 0;

  //Valida a entrada do usuário
  while(!is_valid){
    printf("Insira uma palavra:\n");
    fflush(stdin);
    fgets(palavra, 50, stdin);
  
    tamanho = strlen(palavra);
    palavra[tamanho - 1] = '\0';
    is_valid = 0;

    if(tamanho > 1){
      is_valid = 1;
    };

    if(!is_valid){
      printf("Entrada inválida!\n");
    };
  };

  vogais_consoantes( palavra, &vogais, &consoantes, &letras, &primeira_letra, &ultima_letra );

  printf("Quantidade de caracteres: %d\n", letras);
  printf("Quantidade de vogais: %d\n", vogais);
  printf("Quantidade de consoantes: %d\n", consoantes);
  printf("Primeiro e último caracteres concatenados: %c%c\n", primeira_letra, ultima_letra);
  
  return 0;
};