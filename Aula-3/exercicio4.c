#include<stdio.h>
#include<stdlib.h>

int printaVogal() {
  return printf("É vogal\n");
}

int main() {
    char tecla;
    printf("Pressione uma tecla:\n");
    scanf("%c", &tecla);
    
    switch(tecla){
      case 'a': 
        printaVogal();
      break;
      case 'e': 
        printaVogal();
      break;
      case 'i': 
        printaVogal();
      break;
      case 'o': 
        printaVogal();
      break;
      case 'u': 
        printaVogal();
      break;
      default:
        printf("É consoante\n");
    };

    return 0;
};