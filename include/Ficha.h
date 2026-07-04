/**
 * @file Ficha.h
 * @brief Declaración de la clase base Ficha.
 *
 * @details
 * Responsabilidades:
 * - Encapsular los atributos comunes a toda casilla del tablero (fila, columna, tipo).
 * - Servir de clase base polimórfica para Abismo, Camino y Salida (relación "es-un" estricta).
 * - Exponer getters de solo lectura sobre la posición y el tipo de la ficha.
 * - Declarar destructor virtual para permitir liberación segura vía punteros base.
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

#ifndef FICHA_H
#define FICHA_H

class Ficha {
protected:
    int fila;
    int columna;
    char tipo;

public:
    Ficha(int fila, int columna, char tipo);
    virtual ~Ficha() = default;

    // Getters
    int getFila() const;
    int getColumna() const;
    char getTipo() const;
};

#endif // FICHA_H
