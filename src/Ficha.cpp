/**
 * @file Ficha.cpp
 * @brief Implementación de la clase base Ficha.
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

#include "Ficha.h"

Ficha::Ficha(int fila, int columna, char tipo)
    : fila(fila), columna(columna), tipo(tipo) {}

int Ficha::getFila() const {
    return fila;
}

int Ficha::getColumna() const {
    return columna;
}

char Ficha::getTipo() const {
    return tipo;
}
