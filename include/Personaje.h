/**
 * @file Personaje.h
 * @brief Declaración de la clase Personaje, implementación concreta de IPersonaje.
 *
 * @details
 * Responsabilidades:
 * - Implementar el contrato definido por IPersonaje (posición y movimiento básico en el tablero).
 * - Servir de clase base para especializaciones jugables como Avatar.
 * - Encapsular los atributos posicionFila y posicionColumna con visibilidad protegida.
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

// Personaje.h
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "IPersonaje.h"

class Personaje : public IPersonaje {
protected:
    int posicionFila;
    int posicionColumna;

public:
    Personaje();
    virtual ~Personaje() = default;

    // Métodos de la interfaz IPersonaje
    virtual int getPosicionFila() const override;
    virtual int getPosicionColumna() const override;
    virtual void mover(char direccion) override;

    virtual void setPosicionFila(int fila) override;
    virtual void setPosicionColumna(int columna) override;
};

#endif // PERSONAJE_H
