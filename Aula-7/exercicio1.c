#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char name[50], first_name[50], last_name[50];
  int name_size = 0, last_index = 0, ln_index = 0;
  short is_valid = 0, error = 0;

  //Valida se o nome inserido é válido
  do{
    if(error){
      printf("Entrada inválida!\n");
    };

    printf("Informe o seu nome completo:\n");
    fflush(stdin);
    fgets(name, 50, stdin);
    name_size = strlen(name);

    for(int i = 0; i <= name_size; i++){
      if(name[i] == 32 && name[name_size - 2] != 32){
        is_valid = 1;
        break;
      }else{
        error = 1;
      };
    };
  }while(is_valid == 0);

  //Monta a string do primeiro nome e finaliza ao encontrar o primeiro espaço da string
  for(int i = 0; i < name_size; i++){
    if(name[i] == 32){
      first_name[i] = 0;
    }else if(i == 0){
      first_name[i] = toupper(name[i]);
    }else{
      first_name[i] = tolower(name[i]);
    };
  };

  //Encontra a posição do último espaço da string
  for(int i = 0; i < name_size; i++){
    if(name[i] == 32){
      last_index = i;
    };
  };

  //Monta a string do último nome partindo do último espaço até o final
  for(int i = last_index + 1; i <= name_size; i++){
    if(name[i] == 10){
      last_name[ln_index] = 0;
    }else{
      last_name[ln_index] = toupper(name[i]);
      ln_index++;
    };
  };

  printf("Nome formatado: %s, %s\n",last_name, first_name);

  return 0;
};