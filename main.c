#include <stdio.h>
#include <ctype.h> 

int main()
{
    char x;
    char continuar;

    do {
        printf("Seja bem-vindo(a) à CP01, digite uma das opções:\n");
        printf("A - Quantidade de carboidratos no saco de tomates\n");
        printf("B - Quantidade de carboidratos de uma colher\n");
        printf("C - Molho macarronada\n");
        printf("D - Fazer extrato de tomate\n");
        printf("Opção: ");
        if (scanf(" %c", &x) != 1) {
            printf("Entrada inválida! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }

        x = toupper(x);

        switch(x) {
            case 'A': {
                int gTomates;
                printf("Você escolheu a opção A!\n");
                printf("Peso dos tomates (em gramas): ");
                if (scanf("%d", &gTomates) != 1 || gTomates < 0) {
                    printf("Valor inválido! Use apenas números positivos.\n");
                    while (getchar() != '\n');
                    break;
                }

                float carboidratos = gTomates * 3.1f / 100; 
                printf("Quantidade de carboidrato no saco de tomates: %.2f g\n", carboidratos);
                break;
            }
            case 'B': {
                printf("Você escolheu a opção B!\n");

                float carboidratoPor30g = 4.0;
                float colher15g = 15.0;
                float porcao30g = 30.0;
        
                float carboidrato_por_15g = (colher15g / porcao30g) * carboidratoPor30g;
        
                printf("Quantidade de carboidrato em 1 colher de sopa (15g) de extrato de tomate: %.2f g\n", carboidrato_por_15g);
                break;
            }
            case 'C': {
                printf("Você escolheu a opção C!\n");

                float pesoTomates, pesoExtrato;
                printf("Peso dos tomates (em gramas): ");
                if (scanf("%f", &pesoTomates) != 1 || pesoTomates < 0) {
                    printf("Valor inválido para o peso dos tomates.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Peso do extrato (em gramas): ");
                if (scanf("%f", &pesoExtrato) != 1 || pesoExtrato < 0) {
                    printf("Valor inválido para o peso do extrato.\n");
                    while (getchar() != '\n');
                    break;
                }

                float carbTomateTotal = pesoTomates * 3.1f / 100.0f;
                float carbExtratoTotal = pesoExtrato * 4.0f / 30.0f;
                float carbTotal = carbTomateTotal + carbExtratoTotal;

                printf("\nTotal de carboidratos no molho: %.2f g\n", carbTotal);

                if (carbExtratoTotal > carbTomateTotal) {
                    printf("O extrato de tomate contribuiu mais com os carboidratos do molho.\n");
                } else if (carbTomateTotal > carbExtratoTotal) {
                    printf("O tomate contribuiu mais com os carboidratos do molho.\n");
                } else {
                    printf("Ambos os ingredientes contribuíram igualmente com os carboidratos do molho.\n");
                }
                break;
            }
            case 'D': {
                printf("Você escolheu a opção D!\n");
            
                float capacidadeRecipiente;
                printf("Capacidade do recipiente em gramas: ");
                if (scanf("%f", &capacidadeRecipiente) != 1 || capacidadeRecipiente < 0) {
                    printf("Valor inválido para a capacidade do recipiente.\n");
                    while (getchar() != '\n');
                    break;
                }
            
                float pesoTomates = capacidadeRecipiente * 6.0f;
            
                printf("Serão necessários aproximadamente %.2f g de tomates para fazer %.2f g de extrato artesanal.\n", pesoTomates, capacidadeRecipiente);
                break;
            }
            default:
                printf("Essa opção não se encontra no menu. Tente novamente.\n");
                break;
        }

        printf("\nDeseja continuar testando? (y/n): ");
        if (scanf(" %c", &continuar) != 1) {
            printf("Entrada inválida. Encerrando programa.\n");
            break;
        }
        continuar = tolower(continuar);
        printf("\n");

    } while (continuar == 'y');

    printf("Programa encerrado! Espero que tenha gostado!\n");

    return 0;
}
