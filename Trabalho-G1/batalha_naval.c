#include <stdio.h>
#include <ctype.h>
#include <time.h>

char battlefield[10][10], columns[10] = {'A','B','C','D','E','F','G','H','I','J'};
int i;
int j;

void showBattlefield(char battlefield[i][j], short visible) {
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
      if(visible){
        printf(" %c ", battlefield[i][j]);
      }else if(battlefield[i][j] == 'o'){
        printf(" o ");
      }else if(battlefield[i][j] == 'X'){
        printf(" X ");
      }else{
        printf(" ~ ");
      };
    };
    printf("\n");
  };
};

void clearScreen() {
  printf("\033[0;0H\033[2J");
};

void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
};

int main(void) {
  char column, direction;
  int ships, 
      col,
      row,
      index_limit,
      shots,
      hits,
      score_p1 = 0,
      score_p2 = 0,
      replay = 0;
  short is_valid = 0;
  
  printf(" _           _   _   _           _     _\n");
  printf("| |         | | | | | |         | |   (_)\n");
  printf("| |__   __ _| |_| |_| | ___  ___| |__  _ _ __\n");
  printf("| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\\n");
  printf("| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n");
  printf("|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/\n");
  printf("                                        | |\n");
  printf("                                        |_|\n");   
  printf("          (`-,-,\n");
  printf("        ('(_,( )\n");
  printf("         _   `_'\n");
  printf("      __|_|__|_|_\n");
  printf("    _|___________|__\n");
  printf("   |o o o o o o o o/\n");
  printf("~ ~~ ~~~ ~ ~~ ~~~ ~ ~~~~ ~  ~~ ~ ~~~\n");
  printf("~ ~~~~ ~~ ~~ ~ ~~ ~~ ~ ~~~ ~ ~ ~~ ~~\n");
  printf("\n---> Presione [Enter] para iniciar");
  getchar();

  do{
    column = ' ',
    direction = ' ',
    ships = 3, 
    col = 0,
    row = 0,
    index_limit = 0,
    shots = 30,
    hits = 15,
    replay = 0;
    
    clearScreen();
  
    //Preenche a matriz genericamente
    for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
        battlefield[i][j] = '~';
      };
    };
  
    //Tela jogador 1
    do{
            //debugger
      // printf("\n\nDEBUGGER\n\ndirection: %c\ncol: %d\nrow: %d\n\n",direction,col,row);
      printf("---------- Scoreboard -----------\n\n");
      if(score_p1 < score_p2){
        printf("* Jogador 2 --- %d\n* Jogador 1 --- %d",score_p2,score_p1);
      }else{
        printf("* Jogador 1 --- %d\n* Jogador 2 --- %d",score_p1,score_p2);
      }
      printf("\n\n---------------------------------\n");
      printf("----------- Jogador 1 -----------\n\n");
      
      showBattlefield(battlefield,1);
      
      //Quebra o laço ao posicionar todos os navios
      if(ships == 0){
        break;
      }
  
      printf("\nNavios restantes: %d\n\n", ships);
  
      do{
        //Escolha do sentido
        printf("\n[H] para Horizontal\n[V] para Vertical\nEscolha o sentido do navio: ");
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
          };
          for(int c = 0; c < index_limit; c++){
            if(column == columns[c]){
              is_valid = 1;
              //converte a coluna de char pra int
              col = c;
            };
          };
        };
    
        if(!is_valid){
          printf("\nLocal inválido!.\n");
        };
      }while(!is_valid);
    
      is_valid = 0;
  
      //Escolha da linha
      do{
        printf("\nEscolha a linha: ");
        scanf("%d%*c", &row);
  
        //Valida se é número, se direção for vertical limita na coluna F (index_limit)
        if(!isalpha(row)){
          if(direction == 'V'){
            index_limit = 6;
          }else{
            index_limit = 10;
          };
      
          if(row >= 1 && row <= index_limit){
            is_valid = 1;
            //Subtrai 1 de row para comparar com a matriz (0 a 9)
            row--;
          }; 
        };
    
        if(!is_valid){
          printf("\nLocal inválido!.\n");
        };
      }while(!is_valid);
  
      is_valid = 1;
      
      //Preenche matriz com o navio ocupando 5 indices na direção selecionada, e valida se há outro navio no caminho
      if(direction == 'H'){
        for(j = col; j < col + 5; j++){
          if(battlefield[row][j] != '~'){
            is_valid = 0;
            break;
          };
        };
        if(is_valid){
          for(j = col; j < col + 5; j++){
            battlefield[row][j] = 'N';
          };
        };
      }else if(direction == 'V'){
        for(i = row; i < row + 5; i++){
          if(battlefield[i][col] != '~'){
            is_valid = 0;
            break;
          };
        };
        if(is_valid){
          for(i = row; i < row + 5; i++){
            battlefield[i][col] = 'N';
          };
        };
      };
  
      //Se todas as validações passaram, limpa a tela, indica que o navio foi posicionado e avança para o próximo
      if(!is_valid){
        printf("\nLocal inválido! Já existe um navio no caminho.\n");
        delay(2);
        showBattlefield(battlefield,1);
        clearScreen();
      }else{
        printf("\n\nNavio posicionado com sucesso!\n\n");
        is_valid = 0;
        ships--;
        delay(2);
        showBattlefield(battlefield,1);
        clearScreen();
      };
  
    }while(ships >= 0 || !is_valid);
    
    printf("\nTodos os navios foram posicionados!\n");
    printf("\n---> Presione [Enter] para limpar a tela\n");
    getchar();
    clearScreen();
  
    //Tela jogador 2
    do{
      printf("---------- Scoreboard -----------\n");
      if(score_p1 < score_p2){
        printf("* Jogador 2 --- %d\n* Jogador 1 --- %d",score_p2,score_p1);
      }else{
        printf("* Jogador 1 --- %d\n* Jogador 2 --- %d",score_p1,score_p2);
      }
      printf("\n---------------------------------\n");
      printf("\n----------- Jogador 2 -----------\n\n");
  
      showBattlefield(battlefield,0);
  
      if(shots == 0 || hits == 0){
        break;
      };
  
      printf("\nTiros restantes: %d\n",shots);
  
      do{
        printf("\nEscolha a coluna: ");
        fflush(stdin);
        fgets(&column, 50, stdin);
  
        //Valida se é letra e se esta entre as colunas válidas
        if(isalpha(column)){
          column = toupper(column);
          for(int c = 0; c < 10; c++){
            if(column == columns[c]){
              is_valid = 1;
              //converte a coluna de char pra int para comparar com a matriz (0 a 9)
              col = c;
            };
          };
        };
  
        if(!is_valid){
          printf("\nColuna inválida!\n");
        };
      }while(!is_valid);
  
      is_valid = 0;
  
      do{
        printf("\nEscolha a linha: ");
        scanf("%d%*c", &row);
  
        //Valida se é número, se direção for vertical limita na coluna F (index_limit)
        if(!isalpha(row)){
          if(row >= 1 && row <= 10){
            is_valid = 1;
            //Subtrai 1 de row para comparar com a matriz (0 a 9)
            row--;
          }; 
        };
    
        if(!is_valid){
          printf("\nLinha inválida!\n");
        };
      }while(!is_valid);
  
      //Indica os erros e acertos também valida os locais disparados
      if(battlefield[row][col] == 'N'){
        printf("\nAcertou!!!\n");
        shots--;
        battlefield[row][col] = 'X';
        hits--;
      }else if(battlefield[row][col] == 'X' || battlefield[row][col] == 'o'){
        printf("\nOps, você já disparou aqui...\n");
      }else{
        printf("\nErrou!!!\n");
        shots--;
        battlefield[row][col] = 'o';
      };
  
      is_valid = 0;
  
      //Soma pontuação dos players ao final da partida
      if(hits == 0){
        score_p2++;
      }else if(shots == 0){
        score_p1++;
      };
  
      delay(2);
      clearScreen();
      
    }while(shots >= 0 || hits >= 0);
    
    if(hits == 0){
      printf("\nO jogador 2 venceu!!!\n");
    }else{
      printf("\nO jogador 1 venceu!!!\n");
    };
  
    printf("\nJogar novamente?\n[1]Sim\n[2]Não\n");
    scanf("%d%*c", &replay);
    
  }while(replay == 1);
  
  return 0;
};