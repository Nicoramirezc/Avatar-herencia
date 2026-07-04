/**
 * @file VistaConsola.cpp
 * @brief Implementación de la clase VistaConsola.
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

#include "VistaConsola.h"
#include "Ficha.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#if defined(__unix__) || defined(__APPLE__)
    #define VISTA_CONSOLA_POSIX 1
    #include <termios.h>
    #include <unistd.h>
#endif

VistaConsola::VistaConsola(ITablero* tablero, IPersonaje* avatar)
    : tablero(tablero), avatar(avatar) {
    // La semilla del generador aleatorio se fija UNA sola vez (aquí),
    // no en cada refresco de pantalla como en la versión original:
    // reiniciar rand() en cada llamada reduce la calidad de la
    // aleatoriedad y es un antipatrón conocido.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void VistaConsola::limpiarPantalla() {
#ifdef _WIN32
    if (std::system("cls") != 0) { /* no crítico: se ignora el resultado */ }
#else
    if (std::system("clear") != 0) { /* no crítico: se ignora el resultado */ }
#endif
}

void VistaConsola::mostrarTablero() {
    limpiarPantalla();
    std::cout << "Fil--Col\t";
    for (int i = 0; i < tablero->getSize(); i++) std::cout << i << "\t";
    std::cout << "\n";

    for (int i = 0; i < tablero->getSize(); i++) {
        std::cout << i << "\t\t";
        for (int j = 0; j < tablero->getSize(); j++) {
            Ficha* ficha = tablero->getFicha(i, j);
            std::cout << (ficha != nullptr ? ficha->getTipo() : '?') << "\t";
        }
        std::cout << "\n";
    }
}

void VistaConsola::dibujarFicha(const Ficha* ficha) const {
    if (ficha == nullptr) {
        std::cout << "??????" << "\t";
        return;
    }

    switch (ficha->getTipo()) {
        case '1': {
            int randomValue = std::rand() % 2;
            std::cout << (randomValue == 0 ? "🟫🟫🟩🟨🟫🟫" : "🟫🟫🟨🟩🟫🟫") << "\t";
            break;
        }
        case '0':
            std::cout << "🟫🟫🟦🟦🟫🟫" << "\t";
            break;
        case 'S':
            std::cout << "🟫🟫💰💰🟫🟫" << "\t";
            break;
        default:
            std::cout << "??????" << "\t";
            break;
    }
}

void VistaConsola::mostrarJuego() {
    limpiarPantalla();
    for (int i = 0; i < tablero->getSize(); i++) {
        for (int j = 0; j < tablero->getSize(); j++) {
            if (avatar->getPosicionFila() == i && avatar->getPosicionColumna() == j) {
                std::cout << "🟫🟫🟩🧝🟫🟫" << "\t";
            } else {
                dibujarFicha(tablero->getFicha(i, j));
            }
        }
        std::cout << "\n";
    }
}

void VistaConsola::mostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << "\n";
}

char VistaConsola::getEntradaConsola() {
    char entrada = '\0';
    bool entradaValida = false;

    do {
        std::cout << "Ingrese una opcion [aA-Izquierda] [wW-Arriba] [sS-Abajo] [dD-Derecha]: ";

#ifdef VISTA_CONSOLA_POSIX
        // Modo "raw" temporal: permite leer una tecla sin esperar Enter.
        struct termios oldt{}, newt{};
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        int leido = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        std::cout << "\n";

        if (leido == EOF) {
            // Se cerró la entrada estándar (p. ej. redirección de archivo
            // agotada): no hay forma de obtener una tecla válida, así que
            // se corta aquí en lugar de girar en un bucle infinito.
            std::cout << "Entrada terminada (EOF). Cerrando el juego.\n";
            return '\0';
        }
        entrada = static_cast<char>(leido);
#else
        // Alternativa portable: requiere presionar Enter.
        if (!(std::cin >> entrada)) {
            std::cout << "Entrada terminada (EOF). Cerrando el juego.\n";
            return '\0';
        }
#endif

        char entradaMin = static_cast<char>(std::tolower(static_cast<unsigned char>(entrada)));
        if (entradaMin == 'w' || entradaMin == 'a' || entradaMin == 's' || entradaMin == 'd') {
            entradaValida = true;
        } else {
            std::cout << "Entrada invalida. Por favor, introduce wW, aA, sS o dD.\n";
        }
    } while (!entradaValida);

    return entrada;
}