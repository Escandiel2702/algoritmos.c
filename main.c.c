
#include <stdio.h>
#include <locale.h>

// Fun��o para calcular o M�ximo Divisor Comum (MDC)
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fun��o para somar fra��es
void somar_fracoes(int num1, int den1, int num2, int den2) {
    int num_resultado, den_resultado;

    // Encontrar o MMC dos denominadores
    int mcm = (den1 * den2) / mdc(den1, den2);

    // Converter as fra��es para o mesmo denominador
    num1 = num1 * (mcm / den1);
    num2 = num2 * (mcm / den2);
    den_resultado = mcm;

    // Somar os numeradores
    num_resultado = num1 + num2;

    // Simplificar a fra��o resultante
    int divisor_comum = mdc(num_resultado, den_resultado);
    num_resultado /= divisor_comum;
    den_resultado /= divisor_comum;


    printf("Resultado da soma: %d/%d\n", num_resultado, den_resultado);
}

// Fun��o para subtrair fra��es
void subtrair_fracoes(int num1, int den1, int num2, int den2) {
    int num_resultado, den_resultado;

    // Encontrar o MMC dos denominadores
    int mcm = (den1 * den2) / mdc(den1, den2);

    // Converter as fra��es para o mesmo denominador
    num1 = num1 * (mcm / den1);
    num2 = num2 * (mcm / den2);
    den_resultado = mcm;

    // Subtrair os numeradores
    num_resultado = num1 - num2;

    // Simplificar a fra��o resultante
    int divisor_comum = mdc(num_resultado, den_resultado);
    num_resultado /= divisor_comum;
    den_resultado /= divisor_comum;


    printf("Resultado da subtra��o: %d/%d\n", num_resultado, den_resultado);
}

// Fun��o para multiplicar fra��es
void multiplicar_fracoes(int num1, int den1, int num2, int den2) {
    int num_resultado = num1 * num2;
    int den_resultado = den1 * den2;

    // Simplificar a fra��o resultante
    int divisor_comum = mdc(num_resultado, den_resultado);
    num_resultado /= divisor_comum;
    den_resultado /= divisor_comum;


    printf("Resultado da multiplica��o: %d/%d\n", num_resultado, den_resultado);
}

// Fun��o para dividir fra��es
void dividir_fracoes(int num1, int den1, int num2, int den2) {
    int num_resultado = num1 * den2;
    int den_resultado = den1 * num2;

    // Simplificar a fra��o resultante
    int divisor_comum = mdc(num_resultado, den_resultado);
    num_resultado /= divisor_comum;
    den_resultado /= divisor_comum;


    printf("Resultado da divis�o: %d/%d\n", num_resultado, den_resultado);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero1, numero2, denominador1, denominador2, menu;

    // Menu de opera��es
    printf("Calculadora de fra��o:\n");
    printf("1. SOMAR\n");
    printf("2. SUBTRAIR\n");
    printf("3. MULTIPLICAR\n");
    printf("4. DIVIDIR\n");
    printf("Digite o n�mero da op��o a qual voc� deseja acessar:\n");
    scanf("%d", &menu);

    // Leitura das fra��es
    printf("Digite o primeiro numerador da fra��o:\n");
    scanf("%d", &numero1);
    printf("Digite o primeiro denominador da fra��o:\n");
    scanf("%d", &denominador1);
    printf("Digite o segundo numerador da fra��o:\n");
    scanf("%d", &numero2);
    printf("Digite o segundo denominador da fra��o:\n");
    scanf("%d", &denominador2);

    // Realizar a opera��o escolhida pelo usu�rio
    switch (menu) {
        case 1:
            somar_fracoes(numero1, denominador1, numero2, denominador2);
            break;
        case 2:
            subtrair_fracoes(numero1, denominador1, numero2, denominador2);
            break;
        case 3:
            multiplicar_fracoes(numero1, denominador1, numero2, denominador2);
            break;
        case 4:
            dividir_fracoes(numero1, denominador1, numero2, denominador2);
            break;
        default:
            printf("Op��o inv�lida!\n");
            break;
    }

    return 0;
}

