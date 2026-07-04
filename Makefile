CXX = g++
CXXFLAGS = -std=c++17 -I./include -Wall
LDFLAGS = -lcurl

SRC = src/main.cpp \
      src/Abismo.cpp \
      src/Avatar.cpp \
      src/Camino.cpp \
      src/Ficha.cpp \
      src/Juego.cpp \
      src/LogicaDeMovimiento.cpp \
      src/Personaje.cpp \
      src/Salida.cpp \
      src/Tablero.cpp \
      src/VistaConsola.cpp 

OBJ = $(SRC:.cpp=.o)
TARGET = nutricion

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run