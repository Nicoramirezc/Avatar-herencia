/**
 * @file Tablero.h
 * @brief Declaración de la clase Tablero, implementación concreta de ITablero.
 *
 * @details
 * Responsabilidades:
 * - Implementar ITablero mediante una matriz dinámica de Ficha* cargada desde un archivo de texto plano.
 * - Administrar la propiedad y el ciclo de vida de las fichas dinámicas (creación y liberación de memoria).
 * - Deshabilitar explícitamente el constructor de copia y el operador de asignación para evitar copias superficiales inseguras (regla de las 3/5).
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

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <string>
#include "ITablero.h"

class Tablero : public ITablero {
private:
    std::vector<std::vector<Ficha*>> tablero;

    void limpiarTablero();

public:
    Tablero() = default;
    ~Tablero() override;

    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;

    void cargarDesdeArchivo(const std::string& archivo) override;
    Ficha* getFicha(int fila, int columna) const override;
    int getSize() const override;
};

#endif
