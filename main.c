#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    if (op < 1 || op > 5) {
        do { printf("Por favor insira um valor entre 1 e 5: "); scanf_s(" %d", &op); } while (op < 1 || op > 5);
    }
    return op;
}

void doOperacoes(int op) {
    float num1 = 0;
    float num2 = 0;
    printf("Digite o primeiro número: ");
    scanf_s(" %f", &num1);
    printf("Digite o segundo número: ");
    scanf_s(" %f", &num2);
    if (num2 == 0) {
        do { printf("Digite um segundo número diferente de zero: "); scanf_s("%f", &num2); } while (num2 == 0);
    }

    switch (op) {
    case 1:
        printf("Resultado: %f + %f = %f\n", num1, num2, num1 + num2);
        break;
    case 2:
        printf("Resultado: %f - %f = %f\n", num1, num2, num1 - num2);
        break;
    case 3:
        printf("Resultado: %f * %f = %f\n", num1, num2, num1 * num2);
        break;
    case 4:
        printf("Resultado: %f / %f = %f\n", num1, num2, num1 / num2);
        break;
    default:
        break;
    }
}




bool rodaDenovo() {
    char sn;
    printf("Deseja realizar outra operação? (s/n): ");
    sn = getchar();
    do { printf("Escreva 's' ou 'n': "); sn = getchar(); } while (((sn != 's') && (sn != 'n') && (sn != 'S') && (sn != 'N')));
    if (sn == 's' || sn == 'S') {
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
