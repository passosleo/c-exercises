#include<stdio.h>
#include<stdlib.h>

int main() {
    char nome[50];
    int ano_nasc;
    printf("Informe seu nome:\n");
    scanf("%s", nome);
    printf("Informe seu ano de nascimento:\n");
    scanf("%d", &ano_nasc);
    printf("Seu nome é %s e sua idade é %d anos\n", nome, 2022 - ano_nasc);
    return 0;
};