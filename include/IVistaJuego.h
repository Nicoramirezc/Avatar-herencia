/**
 * @file IVistaJuego.h
 * @brief Interfaz de la vista del juego.
 *
 * @details
 * Responsabilidades:
 * - Desacoplar la lógica del juego (Juego) de la forma concreta en que se presenta al usuario.
 * - Declarar las operaciones necesarias para mostrar el tablero, el juego, mensajes y capturar la entrada del usuario.
 * - Permitir intercambiar implementaciones de vista (consola, gráfica, etc.) sin modificar la lógica del juego.
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

#ifndef IVISTA_JUEGO_H
#define IVISTA_JUEGO_H

#include <string>

class IVistaJuego {
public:
    virtual ~IVistaJuego() = default;

    virtual void mostrarTablero() = 0;
    virtual void mostrarJuego() = 0;
    virtual void limpiarPantalla() = 0;

    virtual void mostrarMensaje(const std::string& mensaje) = 0;

    virtual char getEntradaConsola() = 0;
};

#endif // IVISTA_JUEGO_H
