#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 200
#define MAX_CANTIDAD 200 // Límite maximo para cantidad
#define MAX_TIEMPO 200 // Límite maximo para tiempo de fabricación
#define NOMBRE_LEN 50
#define MAX_RECURSOS 10
// Funcion para mostrar los productos
void mostrarProductos(Producto productos[], int total_productos) {
    printf("\nLista de productos:\n");
    for (int i = 0; i < total_productos; i++) {
        printf("ID: %d | Nombre: %s | Cantidad: %d | Tiempo de fabricacion: %d | Recursos:\n",
               i, productos[i].nombre, productos[i].cantidad, productos[i].tiempo_fabricacion);
        for (int j = 0; j < productos[i].total_recursos; j++) {
            printf("   - %s: %d\n", productos[i].nombre_recursos[j], productos[i].cantidad_recursos[j]);
        }}}
void ingresarProductos(Producto productos[], int *total_productos) {
    if (*total_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }
    Producto p;
    p.total_recursos = 0; // Inicializamos el contador de recursos
    printf("Ingrese el nombre del producto: ");
    fgets(p.nombre, NOMBRE_LEN, stdin);
    p.nombre[strcspn(p.nombre, "\n")] = '\0';
    do {
        printf("Ingrese la cantidad del producto (1 - %d): ", MAX_CANTIDAD);
        scanf("%d", &p.cantidad);
        if (p.cantidad < 0 || p.cantidad > MAX_CANTIDAD) {
            printf("Cantidad invalida. Debe estar entre 1 y %d.\n", MAX_CANTIDAD);
        }
    } while (p.cantidad < 0 || p.cantidad > MAX_CANTIDAD);
    do {
        printf("Ingrese el tiempo de fabricacion del producto (1 - %d): ", MAX_TIEMPO);
        scanf("%d", &p.tiempo_fabricacion);
        if (p.tiempo_fabricacion < 0 || p.tiempo_fabricacion > MAX_TIEMPO) {
            printf("Tiempo de fabricacion invalido. Debe estar entre 1 y %d.\n", MAX_TIEMPO);
        }
    } while (p.tiempo_fabricacion < 0 || p.tiempo_fabricacion > MAX_TIEMPO);
    int num_recursos;
    do {
        printf("Cuantos recursos necesita el producto (1 - %d): ", MAX_RECURSOS);
        scanf("%d", &num_recursos);
        if (num_recursos < 1 || num_recursos > MAX_RECURSOS) {
            printf("Numero invalido. Debe estar entre 1 y %d.\n", MAX_RECURSOS);
        }
    } while (num_recursos < 1 || num_recursos > MAX_RECURSOS);
    for (int i = 0; i < num_recursos; i++) {
        printf("Ingrese el nombre del recurso %d: ", i + 1);
        getchar();
        fgets(p.nombre_recursos[i], NOMBRE_LEN, stdin);
        p.nombre_recursos[i][strcspn(p.nombre_recursos[i], "\n")] = '\0'; // Eliminar el salto de línea
        do {
            printf("Ingrese la cantidad de %s (0 - %d): ", p.nombre_recursos[i], MAX_CANTIDAD);
            scanf("%d", &p.cantidad_recursos[i]);
            if (p.cantidad_recursos[i] < 0 || p.cantidad_recursos[i] > MAX_CANTIDAD) {
                printf("Cantidad invalida. Debe estar entre 0 y %d.\n", MAX_CANTIDAD);
            }
        } while (p.cantidad_recursos[i] < 0 || p.cantidad_recursos[i] > MAX_CANTIDAD);}
    p.total_recursos = num_recursos;
    productos[*total_productos] = p;
    (*total_productos)++;
    printf("Producto agregado exitosamente.\n");}
void editarProducto(Producto productos[], int total_productos) {
    int id;
    printf("Ingrese el ID del producto a editar (0 - %d): ", total_productos - 1);
    scanf("%d", &id);
    if (id < 0 || id >= total_productos) {
        printf("ID invalido.\n");
        return;}
    printf("Ingrese el nuevo nombre del producto (actual: %s): ", productos[id].nombre);
    getchar();
    fgets(productos[id].nombre, NOMBRE_LEN, stdin);
    productos[id].nombre[strcspn(productos[id].nombre, "\n")] = '\0';
    do {
        printf("Ingrese la nueva cantidad del producto (actual: %d): ", productos[id].cantidad);
        scanf("%d", &productos[id].cantidad);
        if (productos[id].cantidad < 0 || productos[id].cantidad > MAX_CANTIDAD) {
            printf("Cantidad invalida. Debe estar entre 0 y %d.\n", MAX_CANTIDAD);
        }
    } while (productos[id].cantidad < 0 || productos[id].cantidad > MAX_CANTIDAD);
    do {
        printf("Ingrese el nuevo tiempo de fabricacion del producto (actual: %d): ", productos[id].tiempo_fabricacion);
        scanf("%d", &productos[id].tiempo_fabricacion);
        if (productos[id].tiempo_fabricacion < 0 || productos[id].tiempo_fabricacion > MAX_TIEMPO) {
            printf("Tiempo de fabricacion invalido. Debe estar entre 0 y %d.\n", MAX_TIEMPO);
        }
    } while (productos[id].tiempo_fabricacion < 0 || productos[id].tiempo_fabricacion > MAX_TIEMPO);
    int num_recursos;
    printf("Cuantos recursos necesita el producto (actual: %d): ", productos[id].total_recursos);
    do {
        scanf("%d", &num_recursos);
        if (num_recursos < 1 || num_recursos > MAX_RECURSOS) {
            printf("Numero invalido. Debe estar entre 1 y %d.\n", MAX_RECURSOS);
        }
    } while (num_recursos < 1 || num_recursos > MAX_RECURSOS);
    for (int i = 0; i < num_recursos; i++) {
        printf("Ingrese el nombre del recurso %d (actual: %s): ", i + 1, productos[id].nombre_recursos[i]);
        getchar();
        fgets(productos[id].nombre_recursos[i], NOMBRE_LEN, stdin);
        productos[id].nombre_recursos[i][strcspn(productos[id].nombre_recursos[i], "\n")] = '\0'; // Eliminar el salto de línea
        do {
            printf("Ingrese la cantidad de %s (actual: %d): ", productos[id].nombre_recursos[i], productos[id].cantidad_recursos[i]);
            scanf("%d", &productos[id].cantidad_recursos[i]);
            if (productos[id].cantidad_recursos[i] < 0 || productos[id].cantidad_recursos[i] > MAX_CANTIDAD) {
                printf("Cantidad invalida. Debe estar entre 0 y %d.\n", MAX_CANTIDAD);
            }
        } while (productos[id].cantidad_recursos[i] < 0 || productos[id].cantidad_recursos[i] > MAX_CANTIDAD);}
    productos[id].total_recursos = num_recursos;
    printf("Producto editado exitosamente.\n");}
void eliminarProducto(Producto productos[], int *total_productos) {
    int id;
    printf("Ingrese el ID del producto a eliminar (0 - %d): ", *total_productos - 1);
    scanf("%d", &id);
    if (id < 0 || id >= *total_productos) {
        printf("ID invalido.\n");
        return;
    }
    for (int i = id; i < *total_productos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    (*total_productos)--;
    printf("Producto eliminado exitosamente.\n");
}
void verificarCumplimiento(Producto productos[], int total_productos, int tiempoLimite, int recursosLimite) {
    int tiempo_total = 0;
    int recursos_totales[MAX_RECURSOS] = {0};

    for (int i = 0; i < total_productos; i++) {
        tiempo_total += productos[i].tiempo_fabricacion * productos[i].cantidad; // Tiempo total
        for (int j = 0; j < productos[i].total_recursos; j++) {
            recursos_totales[j] += productos[i].cantidad_recursos[j] * productos[i].cantidad; // Recursos totales
        }
    }
    
    printf("Tiempo total de fabricacion requerido: %d\n", tiempo_total);
    printf("Tiempo limite de fabricacion: %d\n", tiempoLimite);
    printf("Recursos necesarios:\n");
    int recursos_suficientes = 1;
    for (int j = 0; j < MAX_RECURSOS; j++) {
        if (recursos_totales[j] > 0) {
            printf("   - Recurso %d: %d\n", j + 1, recursos_totales[j]);
            if (recursos_totales[j] > recursosLimite) {
                recursos_suficientes = 0;
            }}}
    // Comparación con el tiempo límite ingresado
    if (tiempo_total <= tiempoLimite && recursos_suficientes) {
        printf("La fabrica puede cumplir con la demanda.\n");
    } else {
        printf("La fabrica NO puede cumplir con la demanda.\n");
        if (tiempo_total > tiempoLimite) {
            printf("   - Excede el tiempo de producción disponible. Tiempo total: %d, Tiempo límite: %d\n", tiempo_total, tiempoLimite);
        }
        if (!recursos_suficientes) {
            printf("   - No hay suficientes recursos disponibles.\n");}}}