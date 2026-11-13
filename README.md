# Sistema de control de calificaciones - La Nueva Escuela

**Estudiante:** Víctor Hamlet Peguero Márquez
**Matrícula:** 2025-2843
**Asignatura:** Lógica de Programación
**Profesor:** Gamalier Reyes del Carmen

## Descripción del programa

Programa de consola en C++ que registra las calificaciones de un grupo de estudiantes, calcula el promedio de cada uno, indica si está Aprobado (70 o más) o Reprobado y muestra un resumen del grupo. Al finalizar permite procesar otro grupo.

## Datos de entrada

- Cantidad de estudiantes (entero mayor que 0).
- Por cada estudiante: nombre y 4 calificaciones (entre 0 y 100).
- Respuesta `s` o `n` para procesar otro grupo.

## Proceso

1. Se valida la cantidad de estudiantes (se repite la solicitud si es inválida).
2. Para cada estudiante se leen 4 calificaciones, validando el rango 0-100.
3. Se acumulan las notas y se calcula el promedio.
4. Con contadores se cuentan aprobados y reprobados; con un acumulador se suman los promedios.
5. Se actualiza el mejor promedio y el nombre del estudiante correspondiente.

## Salida

- Promedio y estado (Aprobado/Reprobado) de cada estudiante.
- Resumen: aprobados, reprobados, promedio del grupo y mejor estudiante (todo con 2 decimales).

## Capturas de pantalla

**Ejecución normal:** un estudiante aprobado, uno reprobado y el resumen del grupo.

![Ejecución normal](imagenes/captura1.png)

**Validaciones:** el programa rechaza una cantidad de estudiantes inválida (0 y -3) y calificaciones fuera de rango (150 y -5).

![Validación de datos](imagenes/captura2.png)

**Repetición del programa:** respuesta inválida en la pregunta final (`x`), procesamiento de un segundo grupo con `s` y cierre con `n`.

![Procesar otro grupo](imagenes/captura3.png)

## Uso de bucles

| Bucle | Dónde | Por qué |
|---|---|---|
| `do-while` | Repetición de todo el programa | Debe ejecutarse al menos una vez y repetirse mientras el usuario responda `s`. |
| `while` | Validación de la cantidad de estudiantes | No se sabe cuántas veces el usuario ingresará un valor inválido. |
| `for` | Recorrer los estudiantes | Se conoce la cantidad de repeticiones (`cantidadEstudiantes`). |
| `for` | Recorrer las 4 calificaciones | Siempre son exactamente 4 por estudiante. |
| `while` | Validación de cada calificación | Se repite la solicitud mientras la nota esté fuera de 0-100. |
| `while` | Validación de la respuesta s/n | Se repite la pregunta mientras la respuesta no sea `s` o `n`. |

## Contadores y acumuladores

- `aprobados` y `reprobados`: contadores.
- `sumaNotas`: acumulador de las 4 notas de cada estudiante.
- `sumaPromedios`: acumulador de los promedios, para calcular el promedio del grupo.

## Compilación

```
g++ control_calificaciones.cpp -o control_calificaciones
./control_calificaciones
```
