#include <stdio.h>
#include <ctype.h>

int i;
int j;

void showBattlefield(char *battlefield[i][j]) {
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      printf(" %s ", battlefield[i][j]);
    }
    printf("\n");
  };
};

int main(void) {
  char *battlefield[10][10], row = ' ';
  int ships = 3, column = 0;
  short player1 = 1;

  // while(player1){
    printf("========= Jogador 1 ==========\n\n");
    
    for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
        battlefield[i][j] = "~";
      };
    };

    showBattlefield(battlefield);
  
    printf("\nNavios restantes: %d\n\n", ships);
  
    printf("Escolha a coluna: ");
    scanf("%d", &column);

    while(column > 10 || column < 1){
      printf("\nLocal inválido!\n");
      printf("\nEscolha a coluna: ");
      scanf("%d", &column);
    }
  
    printf("Escolha a linha: ");
    scanf("%s", &row);
    row = tolower(row);
  
    while(row != 'a' && row != 'b' && row != 'c' & row != 'd' & row != 'e' & row != 'f' & row != 'g' && row != 'h' && row != 'i' && row != 'j')      {
      printf("\nLocal inválido!\n");
      printf("Escolha a linha: ");
      scanf("%s", &row);
      row = tolower(row);
    }

    
  // };
  return 0;
};