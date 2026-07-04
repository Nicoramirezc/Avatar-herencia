/**
 * @file Personaje.cpp
 * @brief Implementación de la clase Personaje.
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

// Personaje.cpp
#include "Personaje.h"
#include <cctype>

Personaje::Personaje() : posicionFila(0), posicionColumna(0) {}

int Personaje::getPosicionFila() const {
    return posicionFila;
}

int Personaje::getPosicionColumna() const {
    return posicionColumna;
}

void Personaje::mover(char direccion) {
    // Movimiento básico propio del personaje. En este juego el
    // movimiento "oficial" lo orquesta LogicaDeMovimiento (que solo
    // conoce el contrato IPersonaje), pero Personaje debe ofrecer una
    // implementación real y no un método vacío, ya que forma parte
    // del contrato de IPersonaje.
    switch (std::toupper(static_cast<unsigned char>(direccion))) {
        case 'W':
            posicionFila--;
            break;
        case 'S':
            posicionFila++;
            break;
        case 'A':
            posicionColumna--;
            break;
        case 'D':
            posicionColumna++;
            break;
        default:
            // Dirección no válida: no se modifica la posición.
            break;
    }
}

void Personaje::setPosicionFila(int fila) {
    posicionFila = fila;
}

void Personaje::setPosicionColumna(int columna) {
    posicionColumna = columna;
}
