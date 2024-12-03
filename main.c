#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 200
#define NOMBRE_LEN 50
#define RECURSO_LEN 50

int main() {
    char nombres[MAX_PRODUCTOS][NOMBRE_LEN];
    int cantidades[MAX_PRODUCTOS];
    int tiempos[MAX_PRODUCTOS];
    char recursos[MAX_PRODUCTOS][RECURSO_LEN]; // Arreglo para almacenar los recursos necesarios como cadenas
    int cantidadRecursos[MAX_PRODUCTOS]; // Arreglo para almacenar la cantidad de recursos
    int total_productos = 0;
    int opcion;
    int tiempoLimite = 100; // Tiempo límite total por defecto
    int recursosLimite = 50; // Límite de recursos total por defecto

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Ingresar tiempo limite de fabricacion\n");
        printf("6. Verificar cumplimiento de demanda\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer

        switch (opcion) {
            case 1:
                ingresarProductos(nombres, cantidades, tiempos, recursos, cantidadRecursos, &total_productos);
                break;
            case 2:
                editarProducto(nombres, cantidades, tiempos, recursos, cantidadRecursos, total_productos);
                break;
            case 3:
                eliminarProducto(nombres, cantidades, tiempos, recursos, cantidadRecursos, &total_productos);
                break;
            case 4:
                mostrarProductos(nombres, cantidades, tiempos, recursos, total_productos, cantidadRecursos);
                break;
            case 5:
                printf("Ingrese el tiempo limite de fabricacion: ");
                scanf("%d", &tiempoLimite);
                break;
            case 6:
                verificarCumplimiento(cantidades, tiempos, cantidadRecursos, nombres, total_productos, tiempoLimite, recursosLimite);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 7);
    
    return 0;
}