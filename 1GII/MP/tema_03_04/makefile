GCC = g++

SRC = src
BIN = bin
INCLUDE = include
OBJ = obj

todo: directorios ejercicio_01 ejercicio_02 ejercicio_03 ejercicio_04 ejercicio_05 ejercicio_06 ejercicio_07 ejercicio_08

directorios: 
	mkdir -p $(SRC)
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	mkdir -p $(INCLUDE)
	@echo "\nGenerando ejecutables de los ejercicios...\n"

ejercicio_01 : $(OBJ)/Racional.o $(OBJ)/ejercicio_01.o
	$(GCC) -o $(BIN)/ejercicio_01 $(OBJ)/Racional.o $(OBJ)/ejercicio_01.o

$(OBJ)/Racional.o : $(SRC)/Racional.cpp $(INCLUDE)/Racional.h
	$(GCC) -c $(SRC)/Racional.cpp -I $(INCLUDE) -o $(OBJ)/Racional.o

$(OBJ)/ejercicio_01.o : $(SRC)/ejercicio_01.cpp $(INCLUDE)/Racional.h
	$(GCC) -c $(SRC)/ejercicio_01.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_01.o

ejercicio_02 : $(OBJ)/VectorDinamico.o $(OBJ)/ejercicio_02.o
	$(GCC) -o $(BIN)/ejercicio_02 $(OBJ)/VectorDinamico.o $(OBJ)/ejercicio_02.o

$(OBJ)/VectorDinamico.o : $(SRC)/VectorDinamico.cpp $(INCLUDE)/VectorDinamico.h $(INCLUDE)/Conjunto.h
	$(GCC) -c $(SRC)/VectorDinamico.cpp -I $(INCLUDE) -o $(OBJ)/VectorDinamico.o

$(OBJ)/ejercicio_02.o : $(SRC)/ejercicio_02.cpp $(INCLUDE)/VectorDinamico.h
	$(GCC) -c $(SRC)/ejercicio_02.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_02.o

ejercicio_03 : $(OBJ)/Matriz2D-1.o $(OBJ)/ejercicio_03.o
	$(GCC) -o $(BIN)/ejercicio_03 $(OBJ)/Matriz2D-1.o $(OBJ)/ejercicio_03.o

$(OBJ)/Matriz2D-1.o : $(SRC)/Matriz2D-1.cpp $(INCLUDE)/Matriz2D-1.h
	$(GCC) -c $(SRC)/Matriz2D-1.cpp -I $(INCLUDE) -o $(OBJ)/Matriz2D-1.o

$(OBJ)/ejercicio_03.o : $(SRC)/ejercicio_03.cpp $(INCLUDE)/Matriz2D-1.h
	$(GCC) -c $(SRC)/ejercicio_03.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_03.o

ejercicio_04 : $(OBJ)/Matriz2D-2.o $(OBJ)/ejercicio_04.o
	$(GCC) -o $(BIN)/ejercicio_04 $(OBJ)/Matriz2D-2.o $(OBJ)/ejercicio_04.o

$(OBJ)/Matriz2D-2.o : $(SRC)/Matriz2D-2.cpp $(INCLUDE)/Matriz2D-2.h
	$(GCC) -c $(SRC)/Matriz2D-2.cpp -I $(INCLUDE) -o $(OBJ)/Matriz2D-2.o

$(OBJ)/ejercicio_04.o : $(SRC)/ejercicio_04.cpp $(INCLUDE)/Matriz2D-2.h
	$(GCC) -c $(SRC)/ejercicio_04.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_04.o

ejercicio_05 : $(OBJ)/Lista.o $(OBJ)/ejercicio_05.o
	$(GCC) -o $(BIN)/ejercicio_05 $(OBJ)/Lista.o $(OBJ)/ejercicio_05.o

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
	$(GCC) -c $(SRC)/Lista.cpp -I $(INCLUDE) -o $(OBJ)/Lista.o

$(OBJ)/ejercicio_05.o : $(SRC)/ejercicio_05.cpp $(INCLUDE)/Lista.h
	$(GCC) -c $(SRC)/ejercicio_05.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_05.o

ejercicio_06 : $(OBJ)/Pila.o $(OBJ)/ejercicio_06.o
	$(GCC) -o $(BIN)/ejercicio_06 $(OBJ)/Pila.o $(OBJ)/ejercicio_06.o

$(OBJ)/Pila.o : $(SRC)/Pila.cpp $(INCLUDE)/Pila.h
	$(GCC) -c $(SRC)/Pila.cpp -I $(INCLUDE) -o $(OBJ)/Pila.o

$(OBJ)/ejercicio_06.o : $(SRC)/ejercicio_06.cpp $(INCLUDE)/Pila.h
	$(GCC) -c $(SRC)/ejercicio_06.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_06.o

ejercicio_07 : $(OBJ)/Cola.o $(OBJ)/ejercicio_07.o
	$(GCC) -o $(BIN)/ejercicio_07 $(OBJ)/Cola.o $(OBJ)/ejercicio_07.o

$(OBJ)/Cola.o : $(SRC)/Cola.cpp $(INCLUDE)/Cola.h
	$(GCC) -c $(SRC)/Cola.cpp -I $(INCLUDE) -o $(OBJ)/Cola.o

$(OBJ)/ejercicio_07.o : $(SRC)/ejercicio_07.cpp $(INCLUDE)/Cola.h
	$(GCC) -c $(SRC)/ejercicio_07.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_07.o

ejercicio_08 : $(OBJ)/Conjunto.o $(OBJ)/ejercicio_08.o
	$(GCC) -o $(BIN)/ejercicio_08 $(OBJ)/Conjunto.o $(OBJ)/ejercicio_08.o

$(OBJ)/Conjunto.o : $(SRC)/Conjunto.cpp $(INCLUDE)/Conjunto.h $(INCLUDE)/VectorDinamico.h
	$(GCC) -c $(SRC)/Conjunto.cpp -I $(INCLUDE) -o $(OBJ)/Conjunto.o

$(OBJ)/ejercicio_08.o : $(SRC)/ejercicio_08.cpp $(INCLUDE)/Conjunto.h $(INCLUDE)/VectorDinamico.h
	$(GCC) -c $(SRC)/ejercicio_08.cpp -I $(INCLUDE) -o $(OBJ)/ejercicio_08.o

clean :
	@echo "\nBorrando ficheros de codigo objeto y ejecutables...\n"
	rm $(OBJ)/* $(BIN)/* 
