/**
 * @file Salida.h
 * @brief Declaración de la clase Salida, ficha objetivo del juego.
 *
 * @details
 * Responsabilidades:
 * - Representar en el tablero la casilla de salida/objetivo ('S').
 * - Heredar de Ficha en una relación "es-un" estricta, sin atributos ni métodos adicionales.
 * - Delegar en el constructor de Ficha la inicialización de fila, columna y tipo.
 *
 * -----------------------------------------------------------------------------
 * @author Victor Bucheli
 * @email victor.bucheli@correounivalle.edu.co
 *
 * @author Douglas Velez Monginaite | Código 202516737-3743
 * @email douglas.velez@correounivalle.edu.co
 *
 * @author Juan Diego Lopez Gomez | Código 202519861-3743
 * @email juan.lopez.g@correounivalle.edu.co
 *
 * @author Nicolas Andres Ramirez | Código 202415510-3743
 * @email nicolas.andres.ramirez@correounivalle.edu.co
 *
 */

#ifndef SALIDA_H
#define SALIDA_H

#include "Ficha.h"

class Salida : public Ficha {
public:
    Salida(int fila, int columna, char tipo);
};

#endif // SALIDA_H
