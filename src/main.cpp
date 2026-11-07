// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {
    // Variables (siempre inicializadas)
    std::string nombre = "";
    double precio = 0;
    int cantidad = 0;
    double descuento = 0;

    // Paso 1: mensaje de bienvenida
    // TODO

    // Paso 2: pedir y validar los datos
        // Paso 2: pedir y validar los datos
    nombre = leerCadena("Nombre del producto: ");

    precio = leerDecimal("Precio: ");
    while (precio <= 0) {
        std::cout << "El precio debe ser mayor que 0\n";
        precio = leerDecimal("Precio: ");
    }

    cantidad = leerEntero("Cantidad: ");
    while (cantidad <= 0) {
        std::cout << "La cantidad debe ser mayor que 0\n";
        cantidad = leerEntero("Cantidad: ");
    }

    descuento = leerDecimal("Descuento (%): ");
    while (descuento < 0 || descuento > 100) {
        std::cout << "El descuento debe estar entre 0 y 100\n";
        descuento = leerDecimal("Descuento (%): ");
    }

    // Paso 3: calcular los importes llamando a los módulos de ticket.h
    // TODO

    // Paso 4: imprimir el ticket (provisional, solo para comprobar la lectura)
    std::cout << nombre << " " << precio << " " << cantidad << " " << descuento << "\n";

    return 0;
}