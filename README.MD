# Compilacion desde terminal

## Compilar

```
$ g++ nombre_del_programa.cpp -o nombre_del_programa `pkg-config --cflags --libs opencv4`
```

## Ejecutar

```
$ ./nombre_del_programa imagen_entrada.jpg imagen_salida.jpg
```

# Compilacion desde Makefile

## Compilar

```
$ make
```

## Ejecutar

```
./nombre_del_programa.exe imagen_entrada.jpg imagen_salida.jpg
```

# Compilacion desde terminal Para Programa Multithreding

```
$ g++ -o programa programa.cpp -std=c++11 -pthread `pkg-config --cflags --libs opencv`

```

# Crear Makefile

```
# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Nombre de tu archivo ejecutable
TARGET = mi_programa_ejecutable

# Archivos fuente
SRCS = mi_codigo_fuente.cpp

# Comando predeterminado
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Comando para ejecutar
run: $(TARGET)

# Comando para limpiar
clean:
	del $(TARGET).exe
```