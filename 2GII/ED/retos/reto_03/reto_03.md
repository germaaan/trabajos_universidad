Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 3: TDA
### Germán Martínez Maldonado
### José Rubén Sánchez Iruela
### Pablo Sánchez Robles

Este reto va a consistir en la explicar las clases que fueran necesarias para realizar la correcta implementación de un juego de Tetris, hemos diseñado una implementación que dispondría de las siguientes clases:

* Una clase Pieza que representaría a las piezas del tablero del Tetris, cuyos atributos serían una matriz bidimensional de enteros que representaría la forma de la pieza, un string que tendría el valor del color de la pieza y un último string que representaría la posición de la ficha en el tablero. Además esta clase contaría con 2 métodos, una para rotar la pieza a la izquierda y otro para rotar la pieza a la derecha, ninguno de estos métodos devolverá ningún valor.

* Una clase Tablero que representará el espacio de juego sobre el que se desarrollará el juego, sus atributos serán un matriz bidimensional de enteros que representarán cada una de las posiciones de juego disponibles en el tablero, un entero que almacene el número de líneas completas, otro que muestre el nivel en el que nos encontramos, y finalmente, otro entero para el número de piezas ya tiradas. Está clase contará con varios métodos:
 * Un método que comprueba si algunas de las columnas está completa, en cuyo caso, el juego se daría por finalizado. Devolverá “true” en caso de que se dé la condición para finalizar el juego, o false en caso contrario.
 * Un método que comprueba si una fila está completa, ya que si una fila está completa, esa fila debe ser borrada y el contador de líneas incrementado. Devolverá el número de la fila a borrar, en caso de que fuera necesario borrar alguna línea, o el valor -1 en caso contrario. Está función sería privada y solo llamada desde la función seguidamente descrita.
 * Un método que llame a la función anterior, y en caso de recibir algún valor que es distinto de -1, incrementará el contador de líneas completadas, borrará la línea correspondiente y se encargará de recolocar las líneas que hayan sido afectadas. Este método no devolverá nada.
 * Un método que compruebe si el próximo movimiento de la pieza es válido y se puede realizar, por ejemplo, una ficha no puede girar si en el proceso “atraviesa” a otra pieza.

* Una clase Cola que representará la forma ordenada en la que se irán lanzando nuevas piezas al tablero, tendrá como atributos un struct que estará compuesto por un objeto de la clase que definiremos a continuación (la clase que constituirá la representación gráfica de las piezas) y un puntero al struct con la imagen de la próxima pieza en la cola, además también tiene un puntero a la primera pieza, que será la próxima en ser lanzada. Esta clase dispondría de un método que sacará la primera pieza de la cola, para lanzarla e hiciera que el resto de las piezas avanzaran en la propia cola.

* Finalmente, una clase imagen, que será la que constituirá la representación gráfica de la pieza, siendo esto representado por un atributo del tipo Bitmap. La clase tendrá un método que recibirá un objeto de la clase Pieza y lo dibujará en su correspondiente lugar del tablero.
