/**
 * @file IJuegoLogica.h
 * @brief Interfaz de la lógica de negocio del juego.
 *
 * @details
 * Responsabilidades:
 * - Declarar el contrato de la lógica del juego, independiente de cómo se muestre en pantalla.
 * - Definir las operaciones de control de partida: iniciar, mover al avatar, puntuar y jugar un movimiento.
 * - Permitir que la vista dependa únicamente de esta abstracción, no de una implementación concreta.
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

#ifndef IJUEGOLOGICA_H
#define IJUEGOLOGICA_H

class IJuegoLogica {
public:
    virtual ~IJuegoLogica() = default;
    virtual void moverAvatar(char direccion) = 0;
    virtual void iniciar() = 0;
    virtual void puntuar() = 0;
    virtual int getPuntaje() = 0;
    virtual void play(char movimiento) = 0;
};

#endif // IJUEGOLOGICA_H
