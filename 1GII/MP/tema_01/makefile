GCC = g++

SRC 	= src
OBJ 	= obj
BIN 	= bin

objetos = $(OBJ)/ejercicio_03.o $(OBJ)/ejercicio_04.o $(OBJ)/ejercicio_05.o $(OBJ)/ejercicio_07.o $(OBJ)/ejercicio_08.o $(OBJ)/ejercicio_09.o $(OBJ)/ejercicio_10.o $(OBJ)/ejercicio_11.o

ejecutables = $(BIN)/ejercicio_03 $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_07 $(BIN)/ejercicio_08 $(BIN)/ejercicio_09 $(BIN)/ejercicio_10 $(BIN)/ejercicio_11

todo: directorios $(ejecutables)

directorios: 
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	@echo "\nGenerando ejecutables de los ejercicios...\n"

$(objetos): $(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) -c $< $(INCLUDE) -o $@

$(ejecutables): $(BIN)/%: $(OBJ)/%.o
	$(GCC) -o $@ $<

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
