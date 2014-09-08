GCC = g++

SRC 	= src
INCLUDE = include
OBJ 	= obj
BIN 	= bin

objetos = $(OBJ)/ejercicio_02.o $(OBJ)/ejercicio_04.o $(OBJ)/ejercicio_05.o $(OBJ)/ejercicio_06.o $(OBJ)/ejercicio_07.o $(OBJ)/ejercicio_08.o

ejecutables = $(BIN)/ejercicio_02 $(BIN)/ejercicio_04 $(BIN)/ejercicio_05 $(BIN)/ejercicio_06 $(BIN)/ejercicio_07 $(BIN)/ejercicio_08

todo: directorios $(ejecutables) $(BIN)/ejercicio_06_celda $(BIN)/ejercicio_06_vector $(BIN)/ejercicio_06_clase $(BIN)/ejercicio_06_v2 $(BIN)/ejercicio_06_v3 $(BIN)/ejercicio_07_v2 $(BIN)/ejercicio_08_v2

directorios: 
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	mkdir -p $(INCLUDE)
	@echo "\nGenerando ejecutables de los ejercicios...\n"

$(OBJ)/celda.o: $(SRC)/celda.cpp $(INCLUDE)/celda.h
	$(GCC) -c $(SRC)/celda.cpp -I $(INCLUDE) -o $(OBJ)/celda.o

$(OBJ)/vector.o: $(SRC)/vector.cpp $(INCLUDE)/vector.h
	$(GCC) -c $(SRC)/vector.cpp -I $(INCLUDE) -o $(OBJ)/vector.o

$(OBJ)/vector_v2.o: $(SRC)/vector_v2.cpp $(INCLUDE)/vector_v2.h
	$(GCC) -c $(SRC)/vector_v2.cpp -I $(INCLUDE) -o $(OBJ)/vector_v2.o

$(OBJ)/vector_v3.o: $(SRC)/vector_v3.cpp $(INCLUDE)/vector_v3.h
	$(GCC) -c $(SRC)/vector_v3.cpp -I $(INCLUDE) -o $(OBJ)/vector_v3.o

$(objetos): $(OBJ)/%.o: $(SRC)/%.cpp
	$(GCC) -w -c $< -o $@

$(OBJ)/ejercicio_06_celda.o: $(SRC)/ejercicio_06_celda.cpp $(INCLUDE)/celda.h
	$(GCC) -c $(SRC)/ejercicio_06_celda.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06_celda.o

$(OBJ)/ejercicio_06_vector.o: $(SRC)/ejercicio_06_vector.cpp $(INCLUDE)/vector_v2.h
	$(GCC) -c $(SRC)/ejercicio_06_vector.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06_vector.o

$(OBJ)/ejercicio_06_clase.o: $(SRC)/ejercicio_06_clase.cpp $(INCLUDE)/vector_v3.h
	$(GCC) -c $(SRC)/ejercicio_06_clase.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06_clase.o

$(OBJ)/ejercicio_06_v2.o: $(SRC)/ejercicio_06_v2.cpp $(INCLUDE)/vector.h
	$(GCC) -c $(SRC)/ejercicio_06_v2.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06_v2.o

$(OBJ)/ejercicio_06_v3.o: $(SRC)/ejercicio_06_v3.cpp $(INCLUDE)/vector.h
	$(GCC) -c $(SRC)/ejercicio_06_v3.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06_v3.o

$(OBJ)/ejercicio_07_v2.o: $(SRC)/ejercicio_07_v2.cpp $(INCLUDE)/vector.h
	$(GCC) -c $(SRC)/ejercicio_07_v2.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_07_v2.o

$(OBJ)/ejercicio_08_v2.o: $(SRC)/ejercicio_08_v2.cpp $(INCLUDE)/vector.h
	$(GCC) -c $(SRC)/ejercicio_08_v2.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_08_v2.o

$(ejecutables): $(BIN)/%: $(OBJ)/%.o
	$(GCC) -o $@ $<

$(BIN)/ejercicio_06_celda: $(OBJ)/ejercicio_06_celda.o $(OBJ)/celda.o
	$(GCC) -o $(BIN)/ejercicio_06_celda $(OBJ)/celda.o $(OBJ)/ejercicio_06_celda.o

$(BIN)/ejercicio_06_vector: $(OBJ)/ejercicio_06_vector.o $(OBJ)/vector_v2.o
	$(GCC) -o $(BIN)/ejercicio_06_vector $(OBJ)/vector_v2.o $(OBJ)/ejercicio_06_vector.o

$(BIN)/ejercicio_06_clase: $(OBJ)/ejercicio_06_clase.o $(OBJ)/vector_v3.o
	$(GCC) -o $(BIN)/ejercicio_06_clase $(OBJ)/vector_v3.o $(OBJ)/ejercicio_06_clase.o

$(BIN)/ejercicio_06_v2: $(OBJ)/ejercicio_06_v2.o $(OBJ)/vector.o
	$(GCC) -o $(BIN)/ejercicio_06_v2 $(OBJ)/vector.o $(OBJ)/ejercicio_06_v2.o

$(BIN)/ejercicio_06_v3: $(OBJ)/ejercicio_06_v3.o $(OBJ)/vector.o
	$(GCC) -o $(BIN)/ejercicio_06_v3 $(OBJ)/vector.o $(OBJ)/ejercicio_06_v3.o

$(BIN)/ejercicio_07_v2: $(OBJ)/ejercicio_07_v2.o $(OBJ)/vector.o
	$(GCC) -o $(BIN)/ejercicio_07_v2 $(OBJ)/vector.o $(OBJ)/ejercicio_07_v2.o

$(BIN)/ejercicio_08_v2: $(OBJ)/ejercicio_08_v2.o $(OBJ)/vector.o
	$(GCC) -o $(BIN)/ejercicio_08_v2 $(OBJ)/vector.o $(OBJ)/ejercicio_08_v2.o

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
