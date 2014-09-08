GCC = g++

SRC 	= src
INCLUDE = include
OBJ 	= obj
BIN 	= bin

objetos = $(OBJ)/ejercicio_01.o $(OBJ)/ejercicio_02.o $(OBJ)/ejercicio_03.o $(OBJ)/ejercicio_04.o $(OBJ)/ejercicio_05.o $(OBJ)/ejercicio_06.o $(OBJ)/ejercicio_09.o $(OBJ)/ejercicio_10.o $(OBJ)/ejercicio_11.o

ejecutables = $(BIN)/ejercicio_01 $(BIN)/ejercicio_02 $(BIN)/ejercicio_03 $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_06 $(BIN)/ejercicio_09 $(BIN)/ejercicio_10 $(BIN)/ejercicio_11  

todo: directorios $(ejecutables) $(BIN)/ejercicio_07

directorios: 
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	mkdir -p $(INCLUDE)
	@echo "\nGenerando ejecutables de los ejercicios...\n"

$(objetos): $(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) -c $< -o $@

$(ejecutables): $(BIN)/%: $(OBJ)/%.o
	$(GCC) -o $@ $<

$(OBJ)/Pila.o : $(SRC)/Pila.cpp $(INCLUDE)/Pila.h
	$(GCC) -c $(SRC)/Pila.cpp -I $(INCLUDE) -o $(OBJ)/Pila.o

$(OBJ)/ejercicio_07.o: $(SRC)/ejercicio_07.cpp $(INCLUDE)/Pila.h
	$(GCC) -c $(SRC)/ejercicio_07.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_07.o

$(BIN)/ejercicio_07: $(OBJ)/ejercicio_07.o $(OBJ)/Pila.o
	$(GCC) -o $(BIN)/ejercicio_07 $(OBJ)/Pila.o $(OBJ)/ejercicio_07.o

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
