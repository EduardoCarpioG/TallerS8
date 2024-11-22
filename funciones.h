#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 200
#define MAX_CANTIDAD 200 // Límite máximo para cantidad
#define MAX_TIEMPO 200 // Límite máximo para tiempo de fabricación
#define NOMBRE_LEN 50
#define MAX_RECURSOS 10

typedef struct {
    char nombre[NOMBRE_LEN];
    int cantidad;
    int tiempo_fabricacion;
    char nombre_recursos[MAX_RECURSOS][NOMBRE_LEN];
    int cantidad_recursos[MAX_RECURSOS];
    int total_recursos;
} Producto;
// Declaraciones de funciones
void ingresarProductos(Producto productos[], int *total_productos);
void editarProducto(Producto productos[], int total_productos);
void eliminarProducto(Producto productos[], int *total_productos);
void mostrarProductos(Producto productos[], int total_productos);
void verificarCumplimiento(Producto productos[], int total_productos, int tiempoLimite, int recursosLimite);


#endif // FUNCIONES_H
