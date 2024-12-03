#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 200
#define NOMBRE_LEN 50
#define RECURSO_LEN 50

void ingresarProductos(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int *total_productos) {
    if (*total_productos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        fgets(nombres[*total_productos], NOMBRE_LEN, stdin);
        nombres[*total_productos][strcspn(nombres[*total_productos], "\n")] = 0;
        printf("Ingrese la cantidad: ");
        scanf("%d", &cantidades[*total_productos]);
        printf("Ingrese el tiempo de fabricacion: ");
        scanf("%d", &tiempos[*total_productos]);
        printf("Ingrese el nombre del recurso: ");
        getchar(); // Limpiar el buffer
        fgets(recursos[*total_productos], RECURSO_LEN, stdin);
        recursos[*total_productos][strcspn(recursos[*total_productos], "\n")] = 0;
        printf("Ingrese la cantidad del recurso: ");
        scanf("%d", &cantidadRecursos[*total_productos]);
        (*total_productos)++;
    } else {
        printf("No se pueden ingresar mas productos.\n");
    }
}

void editarProducto(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int total_productos) {
    int index;
    printf("Ingrese el indice del producto a editar (0-%d): ", total_productos - 1);
    scanf("%d", &index);
    if (index >= 0 && index < total_productos) {
        printf("Ingrese el nuevo nombre del producto: ");
        getchar(); // Limpiar el buffer
        fgets(nombres[index], NOMBRE_LEN, stdin);
        nombres[index][strcspn(nombres[index], "\n")] = 0; // Eliminar el salto de línea
        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &cantidades[index]);
        printf("Ingrese el nuevo tiempo de fabricacion: ");
        scanf("%d", &tiempos[index]);
        printf("Ingrese el nuevo nombre del recurso: ");
        getchar(); // Limpiar el buffer
        fgets(recursos[index], RECURSO_LEN, stdin);
        recursos[index][strcspn(recursos[index], "\n")] = 0; // Eliminar el salto de línea
        printf("Ingrese la nueva cantidad del recurso: ");
        scanf("%d", &cantidadRecursos[index]);
    } else {
        printf("indice no valido.\n");
    }
}

void eliminarProducto(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int *total_productos) {
    int index;
    printf("Ingrese el indice del producto a eliminar (0-%d): ", *total_productos - 1);
    scanf("%d", &index);
    if (index >= 0 && index < *total_productos) {
        // Desplazar los productos hacia la izquierda para eliminar el producto
        for (int i = index; i < *total_productos - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            tiempos[i] = tiempos[i + 1];
            strcpy(recursos[i], recursos[i + 1]); // Mover los recursos también
            cantidadRecursos[i] = cantidadRecursos[i + 1]; // Mover la cantidad de recursos
        }
        (*total_productos)--; // Disminuir el conteo de productos
        printf("Producto eliminado.\n");
    } else {
        printf("indice no valido.\n");
    }
}

void mostrarProductos(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int total_productos,int cantidadRecursos[MAX_PRODUCTOS]) {
    printf("Lista de productos:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("Producto %d: Nombre: %s, Cantidad: %d, Tiempo de fabricacion: %d, Recursos necesarios: %s, Cantidad de recursos: %d\n", 
               i, nombres[i], cantidades[i], tiempos[i], recursos[i], cantidadRecursos[i]);
    }
}

void verificarCumplimiento(int cantidades[], int tiempos[], int cantidadRecursos[], char nombres[][NOMBRE_LEN], int total_productos, int tiempoLimite, int recursosLimite) {
    int tiempoTotal = 0;
    int recursosTotal = 0;

    printf("Detalles de los productos:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("Producto: %s, Recursos necesarios: %d, Tiempo de fabricacion: %d\n", nombres[i], cantidadRecursos[i], tiempos[i]);
        tiempoTotal += tiempos[i];
        recursosTotal += cantidadRecursos[i]; // Sumar los recursos totales
    }

    printf("\nTiempo de fabricacion total: %d, Tiempo limite: %d\n", tiempoTotal, tiempoLimite);
    printf("Recursos totales: %d, Recursos limite: %d\n", recursosTotal, recursosLimite);

    if (tiempoTotal <= tiempoLimite && recursosTotal <= recursosLimite) {
        printf("Cumple con la demanda.\n");
    } else {
        printf("No cumple con la demanda.\n");
    }
}