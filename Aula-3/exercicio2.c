#include<stdio.h>
#include<stdlib.h>

int main() {
    int ano_nasc;
    printf("Informe seu ano de nascimento:\n");
    scanf("%d", &ano_nasc);
    printf("Sua idade é: %d anos\n", 2022 - ano_nasc);
    return 0;
};