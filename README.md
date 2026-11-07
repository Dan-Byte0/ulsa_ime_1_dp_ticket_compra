# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->
El programa lo que hace es imprimir un ticket de alguna compra realizada, mostrando los datos principales, en la vida real se utiliza para llevar un registro de compras, tanto para lel vendedor como el comprador

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| nombre | std::string | leerCadena |
| precio| double | leerDecimal|
| cantidad| int | leerEntero |
| descuento | double| leerDecimal |

**Salida** (¿qué datos muestra el ticket?):
___Muestra nombre del producto, precio, cantidad, subotal, descuento, IVA, total y quien lo atendió.__

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
___Sobre lo que queda después del descuento, para que así se aplique exactamente sobre cuanto el cliente esá pagando__

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Un texto no vacío, puede tener espacios | un producto que no tiene nombre no se puede identificar en el ticket |
| Precio | mayor que 0, con o sin decimales | un precio de 0 o negativo no tiene sentido en una venta |
| Cantidad | Un entero mayor que 0 | no se pueden comprar 0 piezas, ni negativas, ni media pieza |
| Descuento (%) | de 0 a 100, con o sin decimales | menos de 0 sería un recargo y más de 100 sería negativo |
**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
__Muestra error y pide un dato valido.

**¿Puede el total salir negativo? ¿Por qué?**
No, porque precio y cantidad son mayores que 0, el descuento maximo es 100%, por lo que nunca sera mayor que el subtotal, por eso la base del IVA no baja de 0.

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
_Que siempre sera mayor que 0.

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
total = subtotal - descuento + IVA, y el descuento nunca es mayor que el subtotal.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Caja de colores | 25 | 4 | 0 | 100.00 | 0.00 | 16.00 | 116.00 |
| 2 (con descuento) | Cuaderno| 50 | 2 | 10 | 100.00 | 10.00 | 14.40 | 104.40 |
| 3 (precio con centavos) | Pluma | 19.99 | 1 | 0 | 19.99 | 0.00 | 3.20 | 23.19 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), _____, _____ | calcular su subtotal |
| _____ | _____ | _____ |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
_____

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto (ya existe: leerCadena)
│     ├── 2.2 Pedir el precio (y validar que sea mayor que 0) (ya existe: leerDecimal)
│     ├── 2.3 Pedir la cantidad (y validar que sea entera mayor que 0) (ya existe: leerEntero)
│     └── 2.4 Pedir el descuento (y validar que esté entre 0 y 100) (ya existe: leerDecimal)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal (ya existe: calcularSubtotal)
│     ├── 3.2 Calcular el descuento (ya existe: calcularDescuento)
│     ├── 3.3 Calcular el IVA
│     └── 3.4 Calcular el total
└── 4. Imprimir el ticket
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Ya existían leerCadena, leerDecimal, leerEntero, calcularSubtotal y calcularDescuento.
__

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
Pedir y validar cada dato hacía dos cosas, así que lo dividí en leer y validar con un ciclo while.

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
`calcularIVA` | la base (subtotal − descuento) | el monto del IVA | Función |
| `imprimirTicket` | nombre, precio, cantidad, subtotal, descuento, IVA, total | nada | Procedimiento |


<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí 
**¿Tuve que corregirla? ¿Qué cambié?** __No, solo anotar de forma correcta___

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto): 

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** ___macOS__

## 9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```
Nombre del producto: cuaderno
Precio: 50
Cantidad: 2
Descuento (%): 10
====================================
          TICKET DE COMPRA
====================================
Producto:   cuaderno
Precio:     $50.00
Cantidad:   2
------------------------------------
Subtotal:   $100.00
Descuento:  $10.00
IVA (16%):  $14.40
------------------------------------
TOTAL:      $104.40
Le atendio: Daniel
====================================
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | __std::cout___ |
|2. Pedir y validar los datos | leerCadena, leerDecimal, leerEntero y ciclos while |
| 3. Calcular los importes | calcularSubtotal, calcularDescuento, calcularIVA y la resta/suma del total |
| 4. Imprimir el ticket | imprimirTicket |


**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Los ciclos de validación, sobre todo escribir la condición del descuento.

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
___usé setw(12) porque la etiqueta más larga ("Le atendio:") tiene 11 caracteres. Con un número menor, el texto se pegaría al valor y se movería la alineación.__

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
___No, lo dejé escrito directo en imprimirTicket por falta de tiempo.__

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce | Con descuento de 0 % daba bien, pero con 10 % y subtotal 100 fallaba |
| 2. Aísla | El monto del descuento daba 1000 en lugar de 10 |
| 3. Explica | La función multiplicaba el subtotal por el porcentaje (10) sin dividirlo entre 100 |
| 4. Corrige | Cambié el return a subtotal * (porcentaje / 100) |
| 5. Limpia | No quedó ninguna salida [DEBUG] activa |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
__Que 0 % da 0 con cualquier fórmula, así que hay que intentar con otros valores como 10 %.

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
__Cambié 1 sola línea, la constante `TASA_IVA` en `ticket.h`, porque el valor está en un solo lugar, no mejoraría nada del cálculo, pero sí mejoraría el texto del ticket.
___

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
__Sí, seguía diciendo 16 % porque ese texto está escrito directo en `imprimirTicket`. Lo dejé pendiente; para mejorarlo habría que imprimir `TASA_IVA` en lugar de escribir el 16.
___

**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
___No aplica__

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [Opción marcada] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
Porque el nombre queda en un solo lugar, fuera de las funciones, y cualquier función de `ticket.h` puede usarlo sin repetirlo.

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
Un mensaje de dias de devolución o un mensaje de despedida

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
___En solo uno: la línea de `VENDEDOR` en `ticket.h`.__

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Poco: cambiaría la línea de la constante por una lectura, pero tendría que pasar el nombre a `imprimirTicket` como parámetro, porque una constante global no se puede llenar desde el teclado.

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | _____ | _____ |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | _____ | _____ |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | _____ | _____ |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | _____ | _____ |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | _____ | _____ |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | _____ | _____ |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | _____ | _____ |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | _____ | _____ |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | _____ | _____ |
| 12 | Caso propio 1: _____ | _____ | _____ | _____ |
| 13 | Caso propio 2: _____ | _____ | _____ | _____ |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
_____

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
_____

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
_____

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
_____
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
_____

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
_____

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí / No

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
_____

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | _____ | _____ |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | _____ | _____ |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | _____ | _____ |
| Modular | ¿Cada función hace una sola cosa? | _____ | _____ |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | _____ | _____ |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | _____ | _____ |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | _____ | _____ |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) _____

**¿Por qué lo elegí?**
_____

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
_____

**¿Hice algún otro reto opcional? ¿Cuál?**
_____

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
_____

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
_____

**¿Qué fue lo más difícil y cómo lo resolví?**
_____

**¿Qué pregunta me quedó sin responder?**
_____

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
_____

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
_____

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** _____

**Si hice menos de 3, ¿por qué?**
_____

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
