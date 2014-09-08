GCC = g++

SRC = src
OBJ = obj
BIN = bin

objetos = $(OBJ)/ejercicio_01.o $(OBJ)/ejercicio_06.o
ejecutables = $(BIN)/ejercicio_01 $(BIN)/ejercicio_06

todo: directorios $(objetos) $(ejecutables)

directorios: 
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	@echo "\nGenerando ejecutables de los ejercicios...\n"

$(objetos): $(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) -c $< -o $@

$(ejecutables): $(BIN)/%: $(OBJ)/%.o
	$(GCC) -o $@ $<

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
