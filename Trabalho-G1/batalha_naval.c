#include <stdio.h>
#include <ctype.h>
#include <time.h>

char *battlefield[10][10], columns[10] = {'A','B','C','D','E','F','G','H','I','J'};
int i;
int j;

void showBattlefield(char *battlefield[i][j]) {
  int label = 1, k = 0;
  
  printf("   ");
  for(k = 0; k < 10; k++){
    printf(" %c ", columns[k]);
  };
  printf("\n");
  
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      if(j == 0){
        if(label != 10){
          printf(" %d ", label);
        }else{
          printf("%d ", label);
        };
        label++;
      };
      printf(" %s ", battlefield[i][j]);
    };
    printf("\n");
  };
};

void clearScreen() {
  printf("\033[0;0H\033[2J");
}

void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
}

int main(void) {
  char column = ' ', direction = ' ';
  int ships = 3, row = 0, index_limit = 0;
  short player1 = 1, is_valid = 0;

  printf("____________________________________\n\n");
  printf("              /        _________\n");
  printf("     /  |\\   *    /   |         |\n");
  printf("    *   |_\\      *    | BATALHA |\n");
  printf("  ______|______       |  NAVAL  |\n");
  printf("  \\-o-o-o-o-o-/       |_________|\n");
  printf("   \\_________/                    \n");
  printf("  ~~~~ ~ ~~ ~~~ ~ ~~~~ ~  ~~ ~ ~~~\n");
  printf("  ~~ ~~ ~~ ~ ~~ ~~ ~ ~~~ ~ ~ ~~ ~~\n");
  printf("____________________________________\n\n");
  printf("---> Presione [Enter] para iniciar");
  getchar();
  clearScreen();

  //Preenche a matriz genericamente
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      battlefield[i][j] = "~";
    };
  };

  do{
    printf("\n\n----------- Jogador 1 -----------\n\n");
    
    showBattlefield(battlefield);
    
    printf("\nNavios restantes: %d\n\n", ships);

    do{
      //Escolha do sentido
      printf("\nEscolha o sentido do navio\n[H] para Horizontal\n[V] para Vertical\n");
      fflush(stdin);
      fgets(&direction, 50, stdin);

      if(isalpha(direction)){
        direction = toupper(direction);
        if(direction == 'H' || direction == 'V'){
          is_valid = 1;
        };
      };
  
      if(!is_valid){
        printf("\nOpção inválida!\n");
      };
    }while(!is_valid);

    is_valid = 0;

    //Escolha da coluna
    do{
      printf("\nEscolha a coluna: ");
      fflush(stdin);
      fgets(&column, 50, stdin);

      //Valida se é letra, se direção for horizontal limita em F (index_limit)
      if(isalpha(column)){
        column = toupper(column);
        if(direction == 'H'){
          index_limit = 6;
        }else{
          index_limit = 10;
        }
        for(int c = 0; c < index_limit; c++){
          if(column == columns[c]){
            is_valid = 1;
          };
        };
      };
  
      if(!is_valid){
        printf("\nLocal inválido!\n");
      };
    }while(!is_valid);
  
    is_valid = 0;

    //Escolha da linha
    do{
      printf("\nEscolha a linha: ");
      scanf("%d%*c", &row);

      //Valida se é número, se direção for horizontal limita na coluna F (index_limit)
      if(!isalpha(row)){
        if(direction == 'V'){
          index_limit = 6;
        }else{
          index_limit = 10;
        };
    
        if(row >= 1 && row <= index_limit){
          is_valid = 1;
        };
      };
       
  
      if(!is_valid){
        printf("\nLocal inválido!\n");
      };
    }while(!is_valid);  
  
    printf("\n\nNavio posicionado com sucesso!\n\n");
    is_valid = 0;
    ships--;
    delay(2);
    clearScreen();
    
    //debugger
    printf("\n\nDEBUGGER\n\ndirection: %c\ncolumn: %c\nrow: %d\n\n",direction,column,row);
    
  }while(ships != 0);
  
  return 0;
};