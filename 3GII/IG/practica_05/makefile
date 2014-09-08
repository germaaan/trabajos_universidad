EJECUTABLE= practica5

MODULOS:= practica5.o estructuras.o objetos.o

LIBS:= -lglut -lGLU -lGL

CPPFLAGS:= -Wall  -g

CC= g++

x: $(EJECUTABLE)
	./$(EJECUTABLE)

$(EJECUTABLE): $(MODULOS)	
	$(CC) -o $(EJECUTABLE) $(LDFLAGS) $(MODULOS) $(LIBS) 
	
clean:
	rm -rf *.o $(EJECUTABLE) *.tgz

