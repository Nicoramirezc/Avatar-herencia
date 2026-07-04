/**
 * @file main.cpp
 * @brief Punto de entrada del programa: ensambla e inicia la partida.
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

#include <iostream>
#include <string>
#include "Tablero.h"
#include "Avatar.h"
#include "LogicaDeMovimiento.h"
#include "Juego.h"
#include "VistaConsola.h"

int main() {
    // Crear y cargar el tablero desde archivo
    Tablero tablero;
    try {
        tablero.cargarDesdeArchivo("dataTablero.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error al cargar el tablero: " << e.what() << std::endl;
        return 1;
    }

    // Crear el avatar en una posición inicial
    Avatar avatar;
    avatar.setPosicionFila(2);
    avatar.setPosicionColumna(2);

    // Crear la lógica de movimiento (colaborador, no dueño de nadie)
    LogicaDeMovimiento logicaDeMovimiento;

    // Crear el juego (usa tablero, avatar y lógica de movimiento por composición)
    Juego juego(&tablero, &avatar, &logicaDeMovimiento, true);
    juego.iniciar();

    // Crear la vista de consola
    VistaConsola vista(&tablero, &avatar);

    bool entradaCerrada = false;
    do {
        vista.mostrarJuego();
        vista.mostrarMensaje("Digite su movimiento:");
        char movimiento = vista.getEntradaConsola();
        if (movimiento == '\0') {
            // No hay más entrada disponible (EOF): se termina la partida
            // sin declarar ni victoria ni derrota.
            entradaCerrada = true;
            break;
        }
        juego.play(movimiento);
    } while (!juego.getWin() && juego.getEstado());

    if (entradaCerrada) {
        vista.mostrarMensaje("Juego finalizado por falta de entrada.");
    } else if (juego.getWin()) {
        vista.mostrarMensaje("Ganaste el juego, el total de puntos es: " +
                              std::to_string(juego.getPuntaje()));
    } else {
        vista.limpiarPantalla();
        vista.mostrarMensaje("Perdiste el juego, el total de puntos es: 0");
    }

    return 0;
}
