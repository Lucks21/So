# Makefile para compilar Programa Secuencial C++

# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Nombre de tu archivo ejecutable
TARGET = mi_programa

# Archivos fuente
SRCS = Main.cpp # Lista todos tus archivos .cpp

# Comando predeterminado
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)


# Comando para ejecutar
run: $(TARGET)

# Comando para limpiar
clean:
	del $(TARGET).exe
