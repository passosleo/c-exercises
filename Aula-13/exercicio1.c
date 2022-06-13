#include <stdio.h>
#include <string.h>
#include <time.h>
#include <string.h>

struct registro_aluno {
  int matricula;
  char nome[50];
  float nota;
};

void clearScreen() {
  printf("\033[0;0H\033[2J");
};

void delay(unsigned int secs) {
  unsigned int end = time(0) + secs;
  while (time(0) < end);
};

int main() {
  FILE *database;
  int option = 0, num_matricula, total_alunos = 0;
  float total_media = 0, menor_nota = 0, maior_nota = 0;
  short find;
  char name[50], al_menor_nota[50], al_maior_nota[50];
  struct registro_aluno aluno;
  
  while(option != 5){
    printf("\n========= MENU ========= \n");
    printf("[1] Mostrar alunos\n");
    printf("[2] Procurar aluno\n");
    printf("[3] Cadastrar\n");
    printf("[4] Estatisticas\n");
    printf("[5] Sair\n");
    printf("\nDigite a opcao desejada: ");
    scanf("%d%*c", &option);

    database = fopen ("alunos.dat", "ab+");

    if (database == NULL) {
      printf("Erro intero. Nao foi possivel abrir a tabela de cadastros.");
      return 0;
    }
    
    switch(option) {
      case 1:
        clearScreen();
        printf("Tabela de Alunos:\n\n");
        
        while(fread(&aluno, sizeof(struct registro_aluno), 1, database)) {
          find = 1;
      		printf ("Matricula: %d\nNome: %s\nNota Final: %.2f\n\n", aluno.matricula, aluno.nome, aluno.nota);
      	}

        if(!find){
          printf("Ops... Ainda nao ha registros\n");
        }
        find = 0;
        
        break;
      
      case 2:
        printf("\nDigite o numero da matricula: ");
        scanf("%d%*c",&num_matricula);
        
        clearScreen();
        
        while(fread(&aluno, sizeof(struct registro_aluno), 1, database)) {
          if(aluno.matricula == num_matricula){
            find = 1;
            printf("Resultado da pesquisa:\n\n");
            printf ("Matricula: %d\nNome: %s\nNota Final: %.2f\n\n", aluno.matricula, aluno.nome, aluno.nota);
          }
      	}

        if(!find){
          printf("Ops... Matricula %d nao encontrada\n",num_matricula);
        }
        find = 0;
        
        break;
      
      case 3:
        printf("\nCodigo da matricula: ");
        scanf("%d%*c",&aluno.matricula);
        
        printf("Nome: ");
        fgets(aluno.nome, 50, stdin);
        aluno.nome[strlen(aluno.nome) - 1] = '\0';
        
        printf("Nota Final: ");
        scanf("%f%*c",&aluno.nota);
        
        fwrite (&aluno, sizeof(struct registro_aluno), 1, database);
        
        printf("\nCadastro realizado com sucesso.\n");
        delay(2);
        clearScreen();

        break;
      
      case 4:
        clearScreen();
        printf("Estatisticas:\n\n");
        
        while(fread(&aluno, sizeof(struct registro_aluno), 1, database)) {
          total_alunos++;
          total_media = total_media + aluno.nota;
          if(aluno.nota < menor_nota || (menor_nota == 0 && aluno.nota != 0)){
            menor_nota = aluno.nota;
            for(int i = 0; i < sizeof aluno.nome; i++){
              al_menor_nota[i] = aluno.nome[i];
            }
          }
          if(aluno.nota > maior_nota){
            maior_nota = aluno.nota;
            for(int i = 0; i < sizeof aluno.nome; i++){
              al_maior_nota[i] = aluno.nome[i];
            }
          }
      	}

        printf("Total de alunos: %d\nMedia das notas: %.2f\nAluno com menor nota: %s\nAluno com maior nota: %s\n",total_alunos,(total_media / total_alunos), al_menor_nota, al_maior_nota);
    
        total_alunos = 0;
        total_media = 0;

        break;
      
      case 5:    
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
