#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 200
#define NOMBRE_LEN 50
#define RECURSO_LEN 50

void ingresarProductos(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int *total_productos);
void editarProducto(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int total_productos);
void eliminarProducto(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int cantidadRecursos[], int *total_productos);
void mostrarProductos(char nombres[][NOMBRE_LEN], int cantidades[], int tiempos[], char recursos[][RECURSO_LEN], int total_productos, int cantidadRecursos[]);
void verificarCumplimiento(int cantidades[], int tiempos[], int cantidadRecursos[], char nombres[][NOMBRE_LEN], int total_productos, int tiempoLimite, int recursosLimite);

#endif