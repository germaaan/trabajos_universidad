# Nombre archivo: crearmakefile
# Uso: make 
# Descripción: Ultimo ejercicio de la sesion 8

CC=g++
LDFLAGS=
INCLUDE_DIR=./includes
SOURCE_MODULES=programa.cpp ordenacion.cpp array.cpp impresion.cpp
OBJECT_MODULES=$(SOURCE_MODULES:.cpp=.o)

programa.o: programa.cpp ordenacion.cpp array.cpp impresion.cpp
	$(CC) -L$(INCLUDE_DIR) $^ -o $@

ordenacion.o: ordenacion.cpp array.cpp
	$(CC) -L$(INCLUDE_DIR) $^ -o $@

impresion.o: impresion.cpp
	$(CC) -L$(INCLUDE_DIR) $< -o $@

array.o: array.cpp
	$(CC) -c $<

programa: $(OBJECT_MODULES)
	$(CC) $(LDFLAGS) $^ -o $@
