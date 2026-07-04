/**
 * @file ITablero.h
 * @brief Interfaz que define el contrato de acceso al tablero del juego.
 *
 * @details
 * Responsabilidades:
 * - Desacoplar la lógica del juego de la representación concreta del tablero (archivo de texto, matriz, etc.).
 * - Declarar las operaciones de carga desde archivo y consulta de fichas por posición.
 * - Permitir que distintas implementaciones de tablero sean intercambiables sin afectar al resto del sistema.
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

#ifndef ITABLERO_H
#define ITABLERO_H

#include <string>
#include "Ficha.h"

class ITablero {
public:
    virtual ~ITablero() = default;

    // Cargar el tablero desde un archivo
    virtual void cargarDesdeArchivo(const std::string& archivo) = 0;

    // Obtener una ficha en una posición específica
    virtual Ficha* getFicha(int fila, int columna) const = 0;
    virtual int getSize() const = 0;
};

#endif // ITABLERO_H
