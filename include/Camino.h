/**
 * @file Camino.h
 * @brief Declaración de la clase Camino, ficha de celda transitable.
 *
 * @details
 * Responsabilidades:
 * - Representar en el tablero una casilla transitable ('1').
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

#ifndef CAMINO_H
#define CAMINO_H

#include "Ficha.h"

class Camino : public Ficha {
public:
    Camino(int fila, int columna, char tipo);
};

#endif // CAMINO_H
