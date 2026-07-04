/**
 * @file Juego.h
 * @brief Declaración de la clase Juego, implementación concreta de IJuegoLogica.
 *
 * @details
 * Responsabilidades:
 * - Orquestar la partida: mover al avatar, evaluar el resultado de cada jugada y llevar el puntaje.
 * - Relacionarse con ITablero, IPersonaje y LogicaDeMovimiento por composición/agregación (punteros), no por herencia.
 * - No asumir la propiedad de los objetos inyectados desde main; su destructor no los libera.
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

#ifndef JUEGO_H
#define JUEGO_H

#include "IJuegoLogica.h"
#include "ITablero.h"
#include "IPersonaje.h"
#include "LogicaDeMovimiento.h"

class Juego : public IJuegoLogica {
protected:
    ITablero* tablero;
    IPersonaje* avatar;
    LogicaDeMovimiento* logicaDeMovimiento;
    bool estado;
    int puntaje;

public:
    Juego(ITablero* tablero, IPersonaje* avatar,
          LogicaDeMovimiento* logicaDeMovimiento, bool estado);
    ~Juego() override;

    void moverAvatar(char direccion) override;
    void iniciar() override;
    bool getEstado() const;
    bool getWin() const;
    void puntuar() override;
    int getPuntaje() override;
    void play(char movimiento) override;
};

#endif // JUEGO_H
