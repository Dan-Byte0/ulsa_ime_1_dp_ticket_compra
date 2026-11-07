#pragma once

#include <iostream>
#include <string>
#include <iomanip>

// Recibe: el precio de un producto y la cantidad comprada.
// Devuelve: el subtotal (precio por cantidad).
inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

// Recibe: el subtotal y el porcentaje de descuento (de 0 a 100).
// Devuelve: el monto del descuento en pesos.
// OJO: esta funcion tiene un error escondido a proposito. Lee la Fase 3.
inline double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * (porcentaje / 100);
}


const double TASA_IVA = 16.0;
const std::string VENDEDOR = "Daniel";

inline double calcularIVA(double base) {
    return base * (TASA_IVA / 100);
}


inline void imprimirTicket(std::string nombre, double precio, int cantidad,
                           double subtotal, double montoDescuento,
                           double iva, double total) {
    std::cout << std::fixed << std::setprecision(2) << std::left;

    std::cout << std::string(36, '=') << "\n";
    std::cout << "          TICKET DE COMPRA\n";
    std::cout << std::string(36, '=') << "\n";
    std::cout << std::setw(12) << "Producto:" << nombre << "\n";
    std::cout << std::setw(12) << "Precio:" << "$" << precio << "\n";
    std::cout << std::setw(12) << "Cantidad:" << cantidad << "\n";
    std::cout << std::string(36, '-') << "\n";
    std::cout << std::setw(12) << "Subtotal:" << "$" << subtotal << "\n";
    std::cout << std::setw(12) << "Descuento:" << "$" << montoDescuento << "\n";
    std::cout << std::setw(12) << "IVA (16%):" << "$" << iva<< "\n";
    std::cout << std::string(36, '-') << "\n";
    std::cout << std::setw(12) << "TOTAL:" << "$" << total << "\n";
    std::cout << std::setw(12) << "Le atendio:" << VENDEDOR << "\n";
    std::cout << std::string(36, '=') << "\n";
}
