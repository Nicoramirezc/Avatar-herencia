/**
 * @file Juego.cpp
 * @brief Implementación de la clase Juego.
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

#include "Juego.h"
#include <iostream>

Juego::Juego(ITablero* tablero, IPersonaje* avatar,
             LogicaDeMovimiento* logicaDeMovimiento, bool estado)
    : tablero(tablero), avatar(avatar),
      logicaDeMovimiento(logicaDeMovimiento), estado(estado), puntaje(0) {}

Juego::~Juego() {
    // Juego no es dueño de tablero/avatar/logicaDeMovimiento: no se liberan aquí.
}

void Juego::moverAvatar(char direccion) {
    int filaAnterior = avatar->getPosicionFila();
    int columnaAnterior = avatar->getPosicionColumna();

    logicaDeMovimiento->mover(*avatar, direccion);

    Ficha* ficha = tablero->getFicha(avatar->getPosicionFila(), avatar->getPosicionColumna());

    if (ficha == nullptr) {
        // El movimiento saca al avatar de los límites del tablero:
        // se revierte para que no quede "fuera de mapa".
        avatar->setPosicionFila(filaAnterior);
        avatar->setPosicionColumna(columnaAnterior);
        return;
    }

    if (ficha->getTipo() == '1') {
        estado = true;
    } else if (ficha->getTipo() == '0') {
        estado = false; // Cayó en un abismo: fin del juego (derrota)
    } else if (ficha->getTipo() == 'S') {
        estado = true; // Llegó a la salida: fin del juego (victoria)
    }
}

void Juego::iniciar() {
    std::cout << "El juego ha comenzado." << std::endl;
    puntaje = 100;
    estado = true;
}

bool Juego::getEstado() const {
    return estado;
}

bool Juego::getWin() const {
    Ficha* ficha = tablero->getFicha(avatar->getPosicionFila(), avatar->getPosicionColumna());
    return ficha != nullptr && ficha->getTipo() == 'S';
}

void Juego::puntuar() {
    puntaje -= 2;
}

int Juego::getPuntaje() {
    return puntaje;
}

void Juego::play(char movimiento) {
    moverAvatar(movimiento);
    puntuar();
}
