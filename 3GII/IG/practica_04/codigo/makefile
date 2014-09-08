EJECUTABLE= practica4

MODULOS:= main.o\
         lata-coca.o esfera-mundo.o tetera.o objeto-ply.o\
         objetos-4.o\
         objetos-3.o\
         materiales.o\
         jpg_imagen.o file_ply_stl.o\
         jpg_readwrite.o jpg_memsrc.o\
         sbs_tetera.o sbs_sbspline.o sbs_utils.o

LIBS:= -lglut -ljpeg -lGLU -lGL

CPPFLAGS:= -Wall  -g

CC= g++

x: $(EJECUTABLE)
	./$(EJECUTABLE) beethoven marmol.jpg

$(EJECUTABLE): $(MODULOS)	
	$(CC) -o $(EJECUTABLE) $(LDFLAGS) $(MODULOS) $(LIBS) 
	
clean:
	rm -rf *.o $(EJECUTABLE) *.tgz

