/**
 * @file LogicaDeMovimiento.cpp
 * @brief Implementación de la clase LogicaDeMovimiento.
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

#include "LogicaDeMovimiento.h"
#include <cctype>

void LogicaDeMovimiento::mover(IPersonaje& personaje, char direccion) {
    int nuevaFila = personaje.getPosicionFila();
    int nuevaColumna = personaje.getPosicionColumna();

    switch (std::toupper(static_cast<unsigned char>(direccion))) {
        case 'W': // Arriba
            nuevaFila--;
            break;
        case 'S': // Abajo
            nuevaFila++;
            break;
        case 'A': // Izquierda
            nuevaColumna--;
            break;
        case 'D': // Derecha
            nuevaColumna++;
            break;
        default:
            // Dirección no válida: no se mueve.
            return;
    }

    personaje.setPosicionFila(nuevaFila);
    personaje.setPosicionColumna(nuevaColumna);
}
