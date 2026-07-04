/**
 * @file IPersonaje.h
 * @brief Interfaz que define el contrato de todo personaje del juego.
 *
 * @details
 * Responsabilidades:
 * - Declarar el comportamiento mínimo (obtener y establecer posición, moverse) que debe cumplir cualquier personaje.
 * - Desacoplar la lógica de movimiento de una implementación concreta, permitiendo futuras variantes (PersonajeCPU, PersonajeAtajo, etc.).
 * - No heredar estado, solo comportamiento, favoreciendo el principio abierto/cerrado (OCP).
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

// IPersonaje.h
#ifndef IPERSONAJE_H
#define IPERSONAJE_H

class IPersonaje {
public:
    virtual int getPosicionFila() const = 0;
    virtual int getPosicionColumna() const = 0;
    virtual void mover(char direccion) = 0;

    virtual void setPosicionFila(int fila) = 0;
    virtual void setPosicionColumna(int columna) = 0;

    virtual ~IPersonaje() = default;
};

#endif // IPERSONAJE_H
