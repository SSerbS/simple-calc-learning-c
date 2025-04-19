#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNING
void exibeMenu() {
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção:\n");
}

int getOpcao() {
    int op = 0;
    scanf_s(" %d", &op);
    if(op < 1 || op > 5){
        do { printf("Por favor insira um valor entre 1 e 5: "); scanf_s(" %d", &op); } while (op < 1 || op > 5);
    }
    return op;
}

void doOperacoes(int op) {
    int num1 = 0;
    int num2 = 0;
    printf("Digite o primeiro número: ");
    scanf_s("%d", &num1);
    printf("Digite o segundo número: ");
    scanf_s("%d", &num2);

    switch (op) {
    case 1:
        printf("Resultado: %d + %d = %d\n", num1, num2, num1 + num2);
        break;
    case 2:
        printf("Resultado: %d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case 3:
        printf("Resultado: %d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case 4:
        printf("Resultado: %d / %d = %d\n", num1, num2, num1 / num2);
        break;
    default:
        break;
    }
}




bool rodaDenovo() {
    char sn;
    printf("Deseja realizar outra operação? (s/n): ");
    scanf_s("%c", &sn);
    do { printf("Escreva 's' ou 'n': "); scanf_s("%c", &sn); } while ((sn != 's') && (sn != 'n'));
    if (sn == 's') {
        return 1;
    }
    else { return 0; }
}
int main() {
    while (1) {
        exibeMenu();
        int opcao = getOpcao();
        if (opcao == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.");
            break;
        }
        else { doOperacoes(opcao); }
        if (!rodaDenovo()) {
            break;
        }
    }

    return 0;
}
