Fundamentos de Ingeniería del Software
======================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Práctica 4: Diseño e implentación
### Jesús Gómez Obregón
### Germán Martínez Maldonado 
### Ramón Rueda Delgado
### José Rubén Sánchez Iruela
### Pablo Sánchez Robles

### Actividades a realizar

A partir de los contratos proporcionados se deben realizar las siguientes actividades:

1. Crear el modelo de interacción de objetos de todas las operaciones especificadas en los contratos, representándolo mediante un conjunto de diagramas de comunicación de UML.
2. Obtener el diagrama de clases del diseño a partir del modelo de interacción de objetos obtenido anteriormente, representándolo mediante un diagrama de clases de UML.
3. Codificar el diagrama de clases del diseño dado.
4. Codificar los diagramas de comunicación dados.
5. Hacer un pequeño main(...) que pruebe el código desarrollado.

### Contratos de las operaciones a diseñar

![pra04_img01](imagenes/pra04_img01.png)

![pra04_img02](imagenes/pra04_img02.png)

![pra04_img03](imagenes/pra04_img03.png)

![pra04_img04](imagenes/pra04_img04.png)

![pra04_img05](imagenes/pra04_img05.png)

![pra04_img06](imagenes/pra04_img06.png)

![pra04_img07](imagenes/pra04_img07.png)

![pra04_img08](imagenes/pra04_img08.png)

![pra04_img09](imagenes/pra04_img09.png)

![pra04_img10](imagenes/pra04_img10.png)

![pra04_img11](imagenes/pra04_img11.png)

![pra04_img12](imagenes/pra04_img12.png)


### Modelo de interacción de objetos

* incluirClub(nombre, nombreEntrenador, pabellon)

![pra04_img23](imagenes/pra04_img23.png)

* nLicencia = altaJugador(dniPas, nombre, fechaNaci, altura, peso, posición, nacionalidad)

![pra04_img24](imagenes/pra04_img24.png)

* infoclub = consultarClub(idClub)

![pra04_img15](imagenes/pra04_img15.png)

* vincularJugadorClub (idClub, idJugador, nuevoDorsal)

![pra04_img16](imagenes/pra04_img16.png)

* desvincularJugadorClub(idClub, idJugador)

![pra04_img14](imagenes/pra04_img14.png)

* infoJugador = consultarJugador(idJugador)

![pra04_img13](imagenes/pra04_img13.png)

* infoJornada = consultarJornada(idJornada)

![pra04_img17](imagenes/pra04_img17.png)

* asignarEquipo(idTemporada, idClub)

![pra04_img18](imagenes/pra04_img18.png)

* definirPartido(idTemporada, idJornada, idFecha, idClubLocal, idClubVisi, hora, TVEmite)

![pra04_img19](imagenes/pra04_img19.png)

* anotarResultadoJugador (idTemporada, IdJornada, idPartido, idJugador, minutosjugados, intentos, puntosConseguidos)

![pra04_img20](imagenes/pra04_img20.png)

* clasificacionClubes = consultarClasificacionClubes (idTemporada, idJornada)

![pra04_img21](imagenes/pra04_img21.png)

* mejorJugador = calcularMVPTemporada(idTemporada)

![pra04_img22](imagenes/pra04_img22.png)


### Apéndice A: Diseño a codificar

#### Diagramas de comunicación

![pra04_img25](imagenes/pra04_img25.png)

![pra04_img26](imagenes/pra04_img26.png)

![pra04_img27](imagenes/pra04_img27.png)

![pra04_img28](imagenes/pra04_img28.png)

![pra04_img29](imagenes/pra04_img29.png)

![pra04_img30](imagenes/pra04_img30.png)

#### Diagramas de clases del diseño

![pra04_img31](imagenes/pra04_img31.png)

### Apendice B: ejemplo de main(...)

```
package GestionEmpresa;
import ModeloLACB.LACB;
import java.io.*;
public class GestionLACB {
    public static void main(String[] args) throws IOException {
        LACB miLiga = LACB.getLACB(); // obtención de la única instancia de LACB.
        //Definición de la variable in que nos va a permitir leer Stgring desde teclado.
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // Ejemplos de lectura desde teclado con in.
        String s = in.readLine();//Lectura de un String
        double d= Double.parseDouble(in.readLine());// lectura de un double
        int i = Integer.parseInt(in.readLine());// lectura de un int
        int opcion = 0; //variable que nos controla la opcion de menu.
        do{ //do-while que controlara todo el menu
            try{
                //mostrar menú(usando System.out.println(...)) con las siguientes opciones
                // 1. Dar de alta un club
                // 2. Dar de alta un jugador
                // 3. Vincular un jugador a un club
                // 4. Desvincular un jugador de un club.
                // 5. Obtener información de un club y sus jugadores
                // 6. Obtener información de un jugador y su club (si lo tiene)
                // 0. Terminar
                opcion = Integer.parseInt(in.readLine()); // lectura de un int.
                // Montar un switch con todas las opciones de menú.
                switch(opcion){
                    case 1: /* todo lo que hay que hacer para dar de alta un club
                            lectura de los valores de inicialización del club
                            mensaje a miLAB para que incluya un nuevo club */
                    case 2:/*todo lo que hay que hacer para dar de alta un jugador
                            lectura de los valores de inicialización mensaje a
                            miLAB para que incluya un nuevo jugador */
                    case 3: /*... y así para todas las opciones de menú */
                }
            }catch(Exception ex){
                System.err.println(ex);
            }//Cada vez que se produzca una excepcion irá hacia aquí
        }while(opcion !=0);
    } // de main(...)
}// fin de la clase
```

* [LACB.java](codigo/ModeloLACB/LACB.java)
* [Club.java](codigo/ModeloLACB/Club.java)
* [Jugador.java](codigo/ModeloLACB/Jugador.java)
* [GestionLACB.java](codigo/gestionempresa/GestionLACB.java)
