#include <stdio.h>
#include <string.h>
#include <time.h>
#include <string.h>

void clearScreen() {
  printf("\033[0;0H\033[2J");
};

void delay(unsigned int secs) {
  unsigned int end = time(0) + secs;
  while (time(0) < end);
};

int main() {
  FILE *database;
  int option = 0, row = 0, counter = 0;
  char name[50] = " ", age[2] = " ";
  char data[100] = " ";
  
  while(option != 4){
    printf("\n========= MENU ========= \n");
    printf("[1] Mostrar cadastros\n");
    printf("[2] Procurar cadastro\n");
    printf("[3] Cadastrar\n");
    printf("[4] Sair\n");
    printf("\nDigite a opcao desejada: ");
    scanf("%d%*c", &option);

    database = fopen("cadastro.txt", "a+");

    if (database == NULL) {
      printf("Erro intero. Nao foi possivel abrir a tabela de cadastros.");
      return 0;
    }
    
    switch(option) {
      case 1:
        clearScreen();
        printf("Tabela de Cadastros: \n\n");
        while(fgets(data, 50, database) != NULL) {
          printf("%s", data);
        };

        break;
      case 2:
        printf("\nDigite o numero do cadastro: ");
        scanf("%d%*c",&row);
        row = row - 1;
        
        clearScreen();
        printf("Resultado da pesquisa: \n\n");
        
        while(fgets(data, 50, database) != NULL) {
          if(counter == row){
            for(int i = strlen(data) - 3, j = 0; i != strlen(data); i++, j++){
              age[j] = data[i];
            };
            
            printf("Nome: %s\n",strtok(data, ","));
            printf("Idade: %s\n",age);
            
            break;
          }
          counter++;
        };
        counter = 0;
        
        break;
      case 3:
        printf("\nDigite o nome: ");
        fgets(name, 50, stdin);
        printf("Digite a idade: ");
        fgets(age, 3, stdin);
        
        name[strlen(name) - 1] = '\0';
        age[strlen(name) - 1] = '\0';
        
        fputs(name, database);
        fputs(", ", database);
        fputs(age, database);
        fputs("\n", database);
        
        printf("\nCadastro realizado com sucesso.\n");
        delay(2);
        clearScreen();

        break;
      case 4:    
        break;
  
      default:
        printf("\nOpcao invalida!\n");
        delay(2);
        clearScreen();
    }
    fclose(database);
  }
  
  return 0;
}
