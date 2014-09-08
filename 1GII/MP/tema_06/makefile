GCC = g++

SRC 	= src
INCLUDE = include
OBJ 	= obj
BIN 	= bin

objetos = $(OBJ)/ejercicio_01.o $(OBJ)/ejercicio_02.o $(OBJ)/ejercicio_03.o $(OBJ)/ejercicio_04.o $(OBJ)/ejercicio_05.o $(OBJ)/ejercicio_06.o $(OBJ)/ejercicio_07.o $(OBJ)/ejercicio_08.o $(OBJ)/ejercicio_09a.o $(OBJ)/ejercicio_09b.o $(OBJ)/ejercicio_11.o $(OBJ)/ejercicio_12.o $(OBJ)/ejercicio_14.o $(OBJ)/ejercicio_15.o $(OBJ)/ejercicio_16.o $(OBJ)/ejercicio_18.o

ejecutables = $(BIN)/ejercicio_01 $(BIN)/ejercicio_02 $(BIN)/ejercicio_03 $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_06 $(BIN)/ejercicio_07 $(BIN)/ejercicio_08 $(BIN)/ejercicio_09a $(BIN)/ejercicio_09b $(BIN)/ejercicio_11 $(BIN)/ejercicio_12 $(BIN)/ejercicio_14 $(BIN)/ejercicio_15 $(BIN)/ejercicio_16 $(BIN)/ejercicio_18 

todo: directorios $(ejecutables) $(BIN)/ejercicio_17

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

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h
	$(GCC) -c $(SRC)/Matriz2D.cpp -I $(INCLUDE) -o $(OBJ)/Matriz2D.o

$(OBJ)/ejercicio_17.o: $(SRC)/ejercicio_17.cpp $(INCLUDE)/Matriz2D.h
	$(GCC) -c $(SRC)/ejercicio_17.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_17.o

$(BIN)/ejercicio_17: $(OBJ)/ejercicio_17.o $(OBJ)/Matriz2D.o
	$(GCC) -o $(BIN)/ejercicio_17 $(OBJ)/Matriz2D.o $(OBJ)/ejercicio_17.o

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
