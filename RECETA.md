# Receta: Ticket de compra

## Receta del programa principal (`main`)

```text
1. MOSTRAR "Bienvenido al generador de tickets"
2. PEDIR Y VALIDAR LOS DATOS
   2.1 nombre ← leerCadena("Nombre del producto: ")
   2.2 precio ← leerDecimal("Precio: ")
       MIENTRAS precio <= 0 HACER
         MOSTRAR "El precio debe ser mayor que 0"
         precio ← leerDecimal("Precio: ")
       FIN MIENTRAS
   2.3 cantidad ← leerEntero("Cantidad: ")
       MIENTRAS cantidad <= 0 HACER
         MOSTRAR "La cantidad debe ser mayor que 0"
         cantidad ← leerEntero("Cantidad: ")
       FIN MIENTRAS
   2.4 descuento ← leerDecimalEnRango("Descuento (%): ", 0, 100)
3. CALCULAR LOS IMPORTES
   3.1 subtotal ← calcularSubtotal(precio, cantidad)
   3.2 montoDescuento ← calcularDescuento(subtotal, descuento)
   3.3 iva ← calcularIVA(subtotal - montoDescuento)
   3.4 total ← subtotal - montoDescuento + iva
4. LLAMAR imprimirTicket(nombre, precio, cantidad, subtotal, montoDescuento, iva, total)
```

## Recetas de los módulos

### `calcularIVA`

```text
MODULO calcularIVA(base)
  DEVOLVER calcularPorcentaje(base, TASA_IVA)
FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, precio, cantidad, subtotal, montoDescuento, iva, total)
  MOSTRAR el encabezado "TICKET DE COMPRA" entre líneas
  MOSTRAR producto, precio y cantidad
  MOSTRAR subtotal, descuento e IVA
  MOSTRAR total
  MOSTRAR "Le atendio:" y VENDEDOR
  MOSTRAR la línea final
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(cantidad, porcentaje)
  DEVOLVER cantidad * (porcentaje / 100)
FIN MODULO
```

### Otros módulos que agregué (reto 2)

```text
MODULO leerDecimalEnRango(mensaje, minimo, maximo)
  valor ← leerDecimal(mensaje)
  MIENTRAS valor < minimo O valor > maximo HACER
    MOSTRAR "El valor debe estar entre minimo y maximo"
    valor ← leerDecimal(mensaje)
  FIN MIENTRAS
  DEVOLVER valor
FIN MODULO
```