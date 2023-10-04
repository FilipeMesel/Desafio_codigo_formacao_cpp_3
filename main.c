#include <stdio.h>
#include <math.h>

int main() {
    char operador;
    double num1, num2, resultado;

    printf("Calculadora Científica\n");
    printf("Operações disponíveis:\n");
    printf("+ (adição)\n- (subtração)\n* (multiplicação)\n/ (divisão)\n");
    printf("s (seno)\nc (cosseno)\nt (tangente)\n");
    printf("e (exponenciação)\nr (raiz quadrada)\n");

    // Solicita ao usuário que insira o operador e os números
    printf("Digite o operador ou a letra da função desejada: ");
    scanf(" %c", &operador);

    // Verifica se o operador é uma função trigonométrica
    if (operador == 's' || operador == 'c' || operador == 't') {
        printf("Digite o ângulo (em graus): ");
        scanf("%lf", &num1);
        num1 = num1 * M_PI / 180; // Converte de graus para radianos
    } else {
        printf("Digite o primeiro número: ");
        scanf("%lf", &num1);
        if (operador != 'r') { // A raiz quadrada tem apenas um número
            printf("Digite o segundo número: ");
            scanf("%lf", &num2);
        }
    }

    // Realiza a operação com base no operador inserido
    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero não é permitida.\n");
                return 1; // Saída com erro
            }
            break;
        case 's':
            resultado = sin(num1);
            break;
        case 'c':
            resultado = cos(num1);
            break;
        case 't':
            resultado = tan(num1);
            break;
        case 'e':
            resultado = pow(num1, num2);
            break;
        case 'r':
            resultado = sqrt(num1);
            break;
        default:
            printf("Erro: Operador ou função inválidos.\n");
            return 1; // Saída com erro
    }

    // Exibe o resultado
    printf("Resultado: %.2lf\n", resultado);

    return 0; // Saída sem erro
}
