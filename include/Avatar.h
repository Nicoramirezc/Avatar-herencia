/**
 * @file Avatar.h
 * @brief Declaración de la clase Avatar, especialización jugable de Personaje.
 *
 * @details
 * Responsabilidades:
 * - Representar al personaje controlado por el jugador dentro del tablero.
 * - Heredar de Personaje en una relación "es-un" estricta, sin atributos ni métodos adicionales.
 * - Reutilizar íntegramente el comportamiento y estado definidos en Personaje.
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

// Avatar.h
#ifndef AVATAR_H
#define AVATAR_H

#include "Personaje.h"

class Avatar : public Personaje {
public:
    Avatar();
};

#endif // AVATAR_H
