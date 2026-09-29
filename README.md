# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
Calculadora basica
1) Suma  2) Resta  3) Multiplicacion  4) Division
Elige una opcion (1-4): 4
Primer numero: 12
Segundo numero: 0
No se puede dividir entre cero
Segundo numero (distinto de 0): 

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | std::cout << "Calculadora basica\n";
                         std::cout << "1) Suma  2) Resta  3) Multiplicacion  4) Division\n"; 

| 3. Leer y validar la opción | Ciclo do { ... } while (opcion < 1 || opcion > 4); con std::cin >>                              opcion; y un if dentro que muestra el mensaje de error|

| 4 y 5. Leer `a` y `b` | double a, b; seguido de std::cin >> a; y std::cin >> b; |

| 6. Validar el divisor | if (opcion == 4) { while (b == 0) { ... std::cin >> b; } } |

| 7. Decisión múltiple (un `case`) | switch (opcion) { case 1: resultado = a + b; simbolo = '+'; break; ... }                                (por ejemplo, case 4: resultado = a / b; simbolo = '/'; break;) |

| 8. Mostrar el resultado | std::cout << a << " " << simbolo << " " << b << " = " << resultado << std::endl; |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
std me marcaba errores 

## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
Con 8 + 5 salió 8 - 5 = 3 en vez de 13. El compilador no marcó error. Pasó porque sin break el programa no se detiene y sigue con el siguiente caso (la resta), que borra el resultado de la suma.

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
Con 5 / 0 salió inf (infinito). No tiene sentido, porque no se puede dividir entre cero. Por eso hay que validarlo en el Paso 6.

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
_____

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | 13 | si |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | -2 | si |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 |10| si |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | -12 | si |
| División | 4, 7, 2 | 7 / 2 = 3.5 | 3.5 | si |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | 0 | si |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | 2.5 | si |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | 5 | si |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | 13 | si |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | 13|si |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | -2 | si |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | 13 | si |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | 13 | si|
| Caso propio 1 | 12 * 0 | 0 | 0 | si |
| Caso propio 2 | 123 + 45 | 168 | 168 | si |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Puse un ; de más después del if y del while.El mensaje de error salía siempre y el programase quedaba trabado con b = 0 | Quité los ; sobrantes: if (...) { y while (b == 0) {.|Sí. Ahora el mensaje solo sale cuando la opción es inválida y el programa vuelve a pedir el número.
| 2 | Faltaban ;, std:: en endl, comillas simples en el char y un <<. Además, el #include "utilerias.h" daba error. |                |Corregí cada línea y borré el   #include "utilerias.h"._ |Sí. El programa compila y calcula bien.|
**¿Encontré algo que la receta no contemplaba? ¿Qué?**
_____

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a convertir un pseudocódigo en código C++ paso a paso. También aprendí que un ; de más después de un if o un while cambia todo el programa, y que sin break el switch sigue con el siguiente caso.
**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Revisaría el código con más cuidado antes de ejecutarlo, sobre todo los ;, las comillas y el std::. También mantendría el código bien alineado para ver los errores más fácil.
**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue encontrar los errores que no marcaba el compilador, como los ; sobrantes. Los resolví leyendo el código línea por línea y comparándolo con el pseudocódigo.
**¿Qué pregunta me quedó sin responder?**
¿Cómo evito que el programa falle si el usuario escribe letras en vez de números?
**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
Dificl, ya que tengo que buscar pensar de manera parecida a la receta y no a una forma que a mi me hiciera mas sentido 
**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
una opción para repetir la calculadora sin cerrar el programa.
## 14. Lista de verificación antes de entregar (Fase 5)

- [/] Llené las secciones 7 a 13 (no quedan `_____`)
- [/] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [/] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [/] Mi programa compila sin advertencias
- [/] Probé todos los casos de la tabla
- [/] Hice los Experimentos A y B y dejé el código correcto al terminar
- [/] No modifiqué `utilerias.h`
- [/] Hice al menos 4 commits con mensajes claros
- [/] Hice `git push` y verifiqué mi fork en GitHub
- [/] Entregué el enlace de mi fork en Classroom
