/**
 * @file Abismo.h
 * @brief Declaración de la clase Abismo, ficha de tipo obstáculo/peligro.
 *
 * @details
 * Responsabilidades:
 * - Representar en el tablero una casilla de tipo abismo ('0').
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

#ifndef ABISMO_H
#define ABISMO_H

#include "Ficha.h"

class Abismo : public Ficha {
public:
    Abismo(int fila, int columna, char tipo);
};

#endif // ABISMO_H
