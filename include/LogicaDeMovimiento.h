/**
 * @file LogicaDeMovimiento.h
 * @brief Declaración de la clase LogicaDeMovimiento.
 *
 * @details
 * Responsabilidades:
 * - Calcular e interpretar el movimiento de un personaje según la dirección indicada (w/a/s/d).
 * - Operar exclusivamente contra la interfaz IPersonaje, en una relación de composición/colaboración, no de herencia.
 * - Mantener la lógica de movimiento desacoplada de la implementación concreta del personaje.
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

#ifndef LOGICA_DE_MOVIMIENTO_H
#define LOGICA_DE_MOVIMIENTO_H

#include "IPersonaje.h"

class LogicaDeMovimiento {
public:
    // Mueve al personaje según la dirección dada: 'w'/'W' arriba,
    // 's'/'S' abajo, 'a'/'A' izquierda, 'd'/'D' derecha.
    void mover(IPersonaje& personaje, char direccion);
};

#endif // LOGICA_DE_MOVIMIENTO_H
