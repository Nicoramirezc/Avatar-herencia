/**
 * @file VistaConsola.h
 * @brief Declaración de la clase VistaConsola, implementación concreta de IVistaJuego.
 *
 * @details
 * Responsabilidades:
 * - Implementar IVistaJuego dibujando el tablero y el avatar en la terminal.
 * - Relacionarse con ITablero e IPersonaje por composición (los usa, no es dueña de ellos).
 * - Encapsular el detalle de representación visual de cada tipo de ficha.
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

#ifndef VISTA_CONSOLA_H
#define VISTA_CONSOLA_H

#include "IVistaJuego.h"
#include "ITablero.h"
#include "IPersonaje.h"
#include <string>

class VistaConsola : public IVistaJuego {
private:
    ITablero* tablero;
    IPersonaje* avatar;

    // Dibuja el símbolo correspondiente a una ficha del tablero.
    void dibujarFicha(const Ficha* ficha) const;

public:
    VistaConsola(ITablero* tablero, IPersonaje* avatar);
    ~VistaConsola() override = default;

    void mostrarTablero() override;
    void mostrarJuego() override;
    void limpiarPantalla() override;
    void mostrarMensaje(const std::string& mensaje) override;
    char getEntradaConsola() override;
};

#endif // VISTA_CONSOLA_H
