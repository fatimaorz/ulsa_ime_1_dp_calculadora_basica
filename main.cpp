// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

#include <iostream>
#include "utilerias.h"

int main() {
    int opcion = 0;
    double a = 0.0;
    double b = 0.0;
    double resultado = 0.0;
    char simbolo = ' ';

    std::cout << "Calculadora basica\n";
    std::cout << "1) Suma  2) Resta  3) Multiplicacion  4) Division\n";

    do {
        opcion = leerEntero("Elige una opcion (1-4): ");
        if (opcion < 1 || opcion > 4) {
            std::cout << "Opcion no valida, elige un numero del 1 al 4\n";
        }
    } while (opcion < 1 || opcion > 4);

    a = leerDecimal("Primer numero: ");
    b = leerDecimal("Segundo numero: ");

    if (opcion == 4) {
        while (b == 0) {
            std::cout << "No se puede dividir entre cero\n";
            b = leerDecimal("Segundo numero (distinto de 0): ");
        }
    }

    switch (opcion) {

        case 1:
            resultado = a + b;
            simbolo = '+';
            break;
        case 2:
            resultado = a - b;
            simbolo = '-';
            break;
        case 3:
            resultado = a * b;
            simbolo = '*';
            break;
        case 4:
            resultado = a / b;
            simbolo = '/';
            break;

    }
    std::cout << a << " " << simbolo << " " << b << " = " << resultado << '\n';

    return 0;
}