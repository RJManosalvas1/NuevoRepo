#include <stdio.h>

void opcion1() {
    printf("Transacción realizada\n");
}

void opcion2(float costo_total) {
    int pago;
    printf("Ingrese el monto de efectivo: ");
    scanf("%d", &pago);

    float cambio = pago - costo_total;
    printf("El cambio a entregar es: $%.2f\n", cambio);
}

int main() {
    int horas, minutos;
    char dia;

    do {
        printf("Ingrese el número de horas: ");
        scanf("%d", &horas);

        printf("Ingrese el número de minutos: ");
        scanf("%d", &minutos);

        printf("Ingrese el día de la semana (D para domingo, cualquier otra letra para otros días): ");
        scanf(" %c", &dia);

        int total_minutos = horas * 60 + minutos;
        float costo_total = 0;

        if (total_minutos > 10) {
            total_minutos -= 10;
            costo_total += 3 * (total_minutos > 15 ? total_minutos - 15 : 0);
        }

        if (horas >= 1) {
            costo_total += 10;
            horas--;

            if (horas > 0) {
                costo_total += horas * 5;
            }
        }

        if (dia == 'D' || dia == 'd') {
            costo_total *= 0.9;
        }

        printf("El valor de pago es: $%.2f\n", costo_total);

        int opcion;

        printf("Ingrese cómo va a pagar:\n");
        printf("1. Tarjeta débito/crédito\n");
        printf("2. Efectivo\n");
        printf("3. Salir\n");
        printf("Ingrese el número de opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                opcion1();
                printf("Transacción realizada\n");
                break;
            case 2:
                opcion2(costo_total);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }

        printf("Presione 'S' para continuar o cualquier otra letra para salir: ");
        scanf(" %c", &dia);
        printf("\n");
    } while (dia == 'S' || dia == 's');

    return 0;
}
