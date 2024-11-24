#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PRODUCTOS 200
#define MAX_CANTIDAD 200
#define MAX_TIEMPO 200
#define NOMBRE_LEN 50
#define MAX_RECURSOS 10

void ingresarProductos(Producto productos[], int *total_productos);
void editarProducto(Producto productos[], int total_productos);
void eliminarProducto(Producto productos[], int *total_productos);
void mostrarProductos(Producto productos[], int total_productos);
void verificarCumplimiento(Producto productos[], int total_productos, int tiempoLimite, int recursosLimite);

int main() {
    Producto productos[MAX_PRODUCTOS];
    int total_productos = 0;
    int opcion;
    int tiempoLimite = 100; // Tiempo límite total por defecto
    int recursosLimite = 50;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Verificar cumplimiento de demanda\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                ingresarProductos(productos, &total_productos);
                break;
            case 2:
                editarProducto(productos, total_productos);
                break;
            case 3:
                eliminarProducto(productos, &total_productos);
                break;
            case 4:
                mostrarProductos(productos, total_productos);
                break;
            case 5:
                printf("Ingrese el nuevo tiempo limite de fabricacion: ");
                scanf("%d", &tiempoLimite);
                break;
            case 6:
                verificarCumplimiento(productos, total_productos, tiempoLimite, recursosLimite);
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