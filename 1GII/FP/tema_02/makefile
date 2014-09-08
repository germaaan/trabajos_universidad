GCC = g++

SRC = src
OBJ = obj
BIN = bin

objetos = $(OBJ)/ejercicio_01.o $(OBJ)/ejercicio_02.o $(OBJ)/ejercicio_03.o $(OBJ)/ejercicio_04.o $(OBJ)/ejercicio_05.o $(OBJ)/ejercicio_06.o $(OBJ)/ejercicio_07.o $(OBJ)/ejercicio_08.o $(OBJ)/ejercicio_09.o $(OBJ)/ejercicio_10.o $(OBJ)/ejercicio_11.o $(OBJ)/ejercicio_12.o $(OBJ)/ejercicio_13.o $(OBJ)/ejercicio_14.o $(OBJ)/ejercicio_15.o $(OBJ)/ejercicio_16_a.o $(OBJ)/ejercicio_16_b.o $(OBJ)/ejercicio_18.o $(OBJ)/ejercicio_19.o $(OBJ)/ejercicio_20.o $(OBJ)/ejercicio_21.o $(OBJ)/ejercicio_22.o $(OBJ)/ejercicio_23.o $(OBJ)/ejercicio_24.o 
ejecutables = $(BIN)/ejercicio_01 $(BIN)/ejercicio_02 $(BIN)/ejercicio_03 $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_06 $(BIN)/ejercicio_07 $(BIN)/ejercicio_08 $(BIN)/ejercicio_09 $(BIN)/ejercicio_10 $(BIN)/ejercicio_11 $(BIN)/ejercicio_12 $(BIN)/ejercicio_13 $(BIN)/ejercicio_14 $(BIN)/ejercicio_15 $(BIN)/ejercicio_16a $(BIN)/ejercicio_16b $(BIN)/ejercicio_18 $(BIN)/ejercicio_19 $(BIN)/ejercicio_20 $(BIN)/ejercicio_21 $(BIN)/ejercicio_22 $(BIN)/ejercicio_23 $(BIN)/ejercicio_24

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
