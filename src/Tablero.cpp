/**
 * @file Tablero.cpp
 * @brief Implementación de la clase Tablero.
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

#include "Tablero.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Tablero::~Tablero() {
    limpiarTablero();
}

void Tablero::cargarDesdeArchivo(const std::string& archivo) {
    limpiarTablero();

    std::ifstream file(archivo);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + archivo);
    }

    std::string linea;
    int fila = 0;
    while (std::getline(file, linea)) {
        std::vector<Ficha*> filaActual;
        std::istringstream stream(linea);
        char tipoFicha;
        int columna = 0;

        while (stream >> tipoFicha) {
            if (tipoFicha == '1') {
                filaActual.push_back(new Camino(fila, columna, '1'));
            } else if (tipoFicha == '0') {
                filaActual.push_back(new Abismo(fila, columna, '0'));
            } else if (tipoFicha == 'S') {
                filaActual.push_back(new Salida(fila, columna, 'S'));
            } else {
                // Carácter no reconocido: se ignora la casilla (nullptr).
                filaActual.push_back(nullptr);
            }
            columna++;
        }

        // Solo se agregan filas con contenido real, para evitar filas
        // vacías por líneas en blanco al final del archivo.
        if (!filaActual.empty()) {
            tablero.push_back(std::move(filaActual));
            fila++;
        }
    }

    if (tablero.empty()) {
        throw std::runtime_error("El archivo de tablero está vacío o mal formado: " + archivo);
    }
}

Ficha* Tablero::getFicha(int fila, int columna) const {
    if (fila < 0 || fila >= static_cast<int>(tablero.size()) ||
        columna < 0 || columna >= static_cast<int>(tablero[fila].size())) {
        return nullptr; // Fuera de los límites del tablero
    }
    return tablero[fila][columna];
}

void Tablero::limpiarTablero() {
    for (auto& filaVec : tablero) {
        for (auto* ficha : filaVec) {
            delete ficha;
        }
        filaVec.clear();
    }
    tablero.clear();
}

int Tablero::getSize() const {
    return static_cast<int>(tablero.size());
}
