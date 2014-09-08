package cuatroenraya;

//Clase necesario para realizar la serializacion de un objeto.
import java.io.Serializable;
//Clase necesaria para poder utilizar listas ArrayList.
import java.util.ArrayList;
//Clase necesaria para mostrar mensajes y/o introducir valores a traves ventanas emergentes.
import javax.swing.JOptionPane;

/**
 * Clase que representa el tablero dentro del cual se desarrollara el juego de
 * forma logica.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class TableroLogico implements Serializable, Cloneable {

    /**
     * Constante que representa el nivel de dificultad mas bajo.
     */
    public final static int NIVEL_INICIADO = 3;
    /**
     * Constante que representa el nivel de dificultad medio.
     */
    public final static int NIVEL_MEDIO = 7;
    /**
     * Constante que representa el nivel de dificultad mas alto.
     */
    public final static int NIVEL_AVANZADO = 10;
    /**
     * Constante que representa logicamente a una posicion vacia.
     */
    public final static int FICHA_VACIA = 0;
    /**
     * Constante que representa logicamente a un ficha roja.
     */
    public final static int FICHA_ROJA = 1;
    /**
     * Constante que representa logicamente a un ficha azul.
     */
    public final static int FICHA_AZUL = 2;
    /**
     * Constante que representa logicamente al jugador.
     */
    public final static int JUGADOR_HUMANO = 1;
    /**
     * Constante que representa logicamente al ordenador.
     */
    public final static int JUGADOR_ORDENADOR = 2;
    /**
     * Constante que representa logicamente a una partida nueva.
     */
    public final static int PARTIDA_NUEVA = 0;
    /**
     * Constante que representa logicamente a una partida cargada.
     */
    public final static int PARTIDA_CONTINUADA = 1;
    /**
     * Constante que representa que una columna tiene casillas vacias.
     */
    private final static int COLUMNA_INCOMPLETA = 0;
    /**
     * Constante que representa que una columna no tiene casillas vacias.
     */
    private final static int COLUMNA_COMPLETA = 1;
    //Declaramos una lista de las vistas del tablero.
    private ArrayList<Vista> vistas;
    //Declaramos enteros que indiquen numero de filas, numero de columnas, dificultad de
    //la partida, el jugar con el turno de tirar y el tipo de partida.
    private int filas, columnas, dificultad, jugadorActual, tipoPartida;
    //Declaramos enteros que seran contadores de la cantidad de movimientos realizados
    //por cada uno de los participantes.
    private int contHumano, contOrdenador;
    //Declaramos una cadena de texto con el nombre del jugador que esta jugando.
    private String nombreJugador;
    //Declaramos un array bidimensional de enteros que representara el tablero con las
    //fichas tiradas.
    private int[][] tablero;
    //Declaramos un array de enteros que represente las columnas que ya estan completas
    //de fichas.
    private int[] columnasCompletas;
    //Declaramos un gestionador de jugadores que realizara las operaciones relaciones con
    //la gestion de los datos de los jugadores.
    private GestionJugadores gestionJugadores;

    /**
     * Constructor, crea el tablero logico sobre el que se realizaran los
     * movimientos con las dimension recibidas como argumentos.
     *
     * @param filas Cantidad de filas del tablero.
     * @param columnas Cantidad de columnas del tablero.
     */
    public TableroLogico(int filas, int columnas) {
        //Se crea una nueva lista de vistas.
        this.vistas = new ArrayList<Vista>();

        //Se asignan las filas.
        this.filas = filas;
        //Se asignan las columnas.
        this.columnas = columnas;
        //Se inicia a 0 la dificultad.
        this.dificultad = 0;
        //Se indica el jugador que va a empezar a jugar.
        this.jugadorActual = TableroLogico.JUGADOR_HUMANO;
        //Se indica el tipo de partida que se va a empezar a jugar.
        this.tipoPartida = TableroLogico.PARTIDA_NUEVA;

        //Se inicializa el nombre a vacio del jugador.
        this.nombreJugador = "";

        //Se inicializan los contadores de movimientos de ambos participantes.
        this.contHumano = 0;
        this.contOrdenador = 0;

        //Se crean el tablero de las fichas.
        this.tablero = new int[this.filas][this.columnas];
        //Se crea el array de columnas completas.
        this.columnasCompletas = new int[this.columnas];

        //Se recorren todas las casillas del tablero para inicializar sus posiciones
        //a fichas vacias.
        for (int i = 0; i < this.tablero.length; i++) {
            for (int j = 0; j > this.tablero[i].length; j++) {
                this.tablero[i][j] = TableroLogico.FICHA_VACIA;
            }
        }

        //Se recorre el array de columnas completas para inicializar todas las
        //columnas como incompletas.
        for (int i = 0; i < this.columnasCompletas.length; i++) {
            this.columnasCompletas[i] = TableroLogico.COLUMNA_INCOMPLETA;
        }

        //Se crea el gestionador de jugadores.
        this.gestionJugadores = new GestionJugadores();
    }

    /**
     * Metodo para obtener las columnas del tablero.
     *
     * @return Numero de columnas del tablero.
     */
    public int getColumnas() {
        //Devolvemos el numero de columnas del tablero.
        return this.columnas;
    }

    /**
     * Metodo par obtener la dificultad de la partida actual.
     *
     * @return Dificultad de la partida actual.
     */
    public int getDificultad() {
        //Devolvemos la dificultad del partido actual.
        return this.dificultad;
    }

    /**
     * Metodo para obtener las filas del tablero.
     *
     * @return Numero de filas del tablero.
     */
    public int getFilas() {
        //Devolvemos el numero de filas del tablero.
        return this.filas;
    }

    /**
     * Metodo para obtener el gestionador con la base de datos de jugadores.
     *
     * @return Gestionador con la base de datos de jugadores.
     */
    public GestionJugadores getGestionJugadores() {
        //Devolvemos el gestionador con la base de datos de jugadores.
        return this.gestionJugadores;
    }

    /**
     * Metodo para obtener el jugador al que pertenece el turno de tirar.
     *
     * @return Jugador al que pertenece el turno de tirar.
     */
    public int getJugadorActual() {
        //Devolvemos el jugador al que pertenece el turno de tirar.
        return this.jugadorActual;
    }

    /**
     * Metodo para obtener el nombre del usuario que actualmente esta jugando.
     *
     * @return Nombre del usuario que actualmente esta jugando.
     */
    public String getNombreJugador() {
        //Devolvemos el nombre del usuario que actualmente esta jugando.
        return this.nombreJugador;
    }

    /**
     * Metodo para obtener el array con las posiciones logicas de los
     * movimientos realizados en el tablero.
     *
     * @return Array con las posiciones logicas de los movimientos realizados en
     * el tablero.
     */
    public int[][] getTablero() {
        //Devolvemos el array con las posiciones logicas de los movimientos realizados
        //en el tablero.
        return this.tablero;
    }

    /**
     * Metodo para obtener si una partida ha sido cargado previamente o es
     * nueva.
     *
     * @return Si una partida ha sido cargado previamente o es nueva.
     */
    public int getTipoPartida() {
        //Devolvemos si la partida ha sido cargado previamente o es nueva.
        return this.tipoPartida;
    }

    /**
     * Metodo para cambiar la dificultad actual de la partida.
     *
     * @param dificultad Dificultad a la que se cambiara la partida actual.
     */
    public void setDificultad(int dificultad) {
        //Indicamos la dificultad a la que se cambiara la partida actual.
        this.dificultad = dificultad;
    }

    /**
     * Metodo para cambiar el jugador al que pertenece el turno actual de
     * tirada.
     *
     * @param jugadorActual Jugador al que se cambiara el turno actual de
     * tirada.
     */
    public void setJugadorActual(int jugadorActual) {
        //Indicamos al que se cambiara el turno actual de tirada.
        this.jugadorActual = jugadorActual;
    }

    /**
     * Metodo para cambiar el nombre del jugador actual.
     *
     * @param nombre Nombre del jugador actual al que se cambiara.
     */
    public void setNombreJugador(String nombre) {
        //Indicamos el nombre del jugador actual al que se cambiara.
        this.nombreJugador = nombre;
    }

    /**
     * Metodo para cambiar el tipo de partida en curso.
     *
     * @param tipoPartida Tipo de partida a la que se cambiara.
     */
    public void setTipoPartida(int tipoPartida) {
        //Indicamos el tipo de partida a la que se cambiara.
        this.tipoPartida = tipoPartida;
    }

    /**
     * Metodo para agregar una instancia a una interfaz Vista en una lista de
     * Vistas.
     *
     * @param vista Instancia a una interfaz Vista que se agregara a una lista
     * de Vistas.
     */
    public void addVista(Vista vista) {
        //Añadimos la vista recibida a la lista de vistas.
        this.vistas.add(vista);
    }

    /**
     * Metodo para cambiar el valor de una de las casillas del tablero logico.
     *
     * @param fila Fila de la casilla de la que cambiar el valor.
     * @param columna Columna de la casilla de la que cambiar el valor.
     */
    public void cambiarValorCasilla(int fila, int columna) {
        //Si el jugador actual es el jugador humano.
        if (this.jugadorActual == TableroLogico.JUGADOR_HUMANO) {
            //La casilla correspondiente pasara a tener el valor de ficha roja.
            this.tablero[fila][columna] = TableroLogico.FICHA_ROJA;
        } else {
            //Si no, la casilla correspondiente pasara a tener el valor de ficha azul.
            this.tablero[fila][columna] = TableroLogico.FICHA_AZUL;
        }
    }

    /**
     * Metodo para cambiar las dimension del tablero logico.
     *
     * @param filas Nueva cantidad de filas que tendra el tablero.
     * @param columnas Nueva cantidad de columnas que tendra el tablero.
     */
    public void cambiarDimensiones(int filas, int columnas) {
        //Asignamos el valor de las filas.
        this.filas = filas;
        //Asignamos el valor de las columnas.
        this.columnas = columnas;
        //Asignamos el jugador con el turno actual de tirar.
        this.jugadorActual = TableroLogico.JUGADOR_HUMANO;

        //Reiniciamos los contadores de movimientos de ambos jugadores.
        this.contHumano = 0;
        this.contOrdenador = 0;

        //Volvemos a crear el array bidimensional con las casillas del tablero.
        this.tablero = new int[this.filas][this.columnas];
        //Volvemos a crear el array con las columnas completas.
        this.columnasCompletas = new int[this.columnas];

        //Iniciamos un bucle que recorra todas las casillas del tablero.
        for (int i = 0; i < this.tablero.length; i++) {
            for (int j = 0; j > this.tablero[i].length; j++) {
                //Reiniciando cada una de las casillas a valor de ficha vacia.
                this.tablero[i][j] = TableroLogico.FICHA_VACIA;
            }
        }

        //Iniciamos un bucle que recorra el array de las columnas incompletas.
        for (int i = 0; i < this.columnasCompletas.length; i++) {
            //Reiniciando cada una a valor de columna incompleta.
            this.columnasCompletas[i] = TableroLogico.COLUMNA_INCOMPLETA;
        }

        //Llamamos al metodo para actualizar la vista del tablero.
        this.notificarVistas();
    }

    /**
     * Metodo para realizar un movimiento sobre el tablero logico.
     *
     * @param movimiento Movimiento que se realizara sobre el tablero.
     * @return Verdarero si el movimiento de ha podido realizar correctamente o
     * falso en caso contrario.
     */
    public boolean mover(Movimiento movimiento) {
        //Declaramos un booleano para devolver si el movimiento se ha realizado correctamente o no.
        boolean estado = false;
        //Declaramos un entero al que asignamos el valor de columna del movimiento recibido.
        int columna = movimiento.getColumna();

        //Si el movimiento se ha hecho dentro de un columna dentro del tablero.
        if (columna <= this.tablero[0].length - 1) {
            //Obtenemos el valor de la fila para la tirada realizada.
            int fila = obtenerFilaTirada(columna);
            //Obtenemos el jugador que ha realizado la tirada.
            int jugador = movimiento.getJugador();

            //Si la columna del movimiento cuenta como incompleta:
            if (this.columnasCompletas[columna] == TableroLogico.COLUMNA_INCOMPLETA) {
                //Si la fila del movimiento es la ultima de arriba:
                if (fila == 0) {
                    //La columna pasara a considerarse como una columna completa.
                    this.columnasCompletas[columna] = TableroLogico.COLUMNA_COMPLETA;
                }

                //Cambiamos el valor de la casilla en la que se haya realizado la tirada.
                cambiarValorCasilla(fila, columna);

                //Aumentamos el contador de movimientos del jugador que haya realizado
                //el movimiento.
                if (movimiento.getJugador() == 1) {
                    this.contHumano++;
                } else {
                    this.contOrdenador++;
                }

                //Llamamos al metodo para actualizar la vista del tablero.
                this.notificarVistas();

                //Indicamos que el movimiento se ha realizado correctamente.
                estado = true;

                //Comprobamos si el tableor esta completo, para declarar un empate.
                if (comprobarTableroCompleto() == true) {
                    //Se llama al metodo de finalizar un tablero que esta completo.
                    finalizarTableroCompleto();
                } else {

                    //Si no, comprobamos si se ha producido un cuatro en raya.
                    if (comprobarRaya(fila, columna, jugador) == true) {
                        //En cuyo caso, se llamaria al metodo de finalizar una partida.
                        finalizarPartida(jugador);
                    }
                }
            }
        }

        //Devolvemos si el movimiento se ha realizado correctamente o no.
        return estado;
    }

    /**
     * Metodo para obtener la fila correspondiente a un movimiento.
     *
     * @param columna Columna en la que realiza el movimiento.
     * @return Fila en la que se realiza el movimiento.
     */
    public int obtenerFilaTirada(int columna) {
        //Declaramos un entero que correspondera a la fila en la que se realizara la tirada.
        int i;

        //Recorremos la columna de tirada en el tablero.
        for (i = this.tablero.length - 1; i > 0; i--) {
            //Si se encuentra una casilla vacia, esa fila sera en la que se realizara la tirada.
            if (this.tablero[i][columna] == TableroLogico.FICHA_VACIA) {
                break;
            }
        }

        //Devolvemos el valor de la fila con la casilla vacia en la columna de tirada.
        return i;
    }

    /**
     * Metodo para obtener todos los movimientos posibles de realizar en el
     * tablero actual.
     *
     * @return Lista con todos los movimientos posibles.
     */
    public ArrayList<Movimiento> obtenerMovientosPosibles() {
        //Creamos una nueva lista de movimientos.
        ArrayList<Movimiento> movimientosPosibles = new ArrayList<Movimiento>();

        //Iniciamos un bucle para recorrer las columnas.
        for (int i = 0; i < this.columnasCompletas.length; i++) {
            //Si una columna esta marcada como incompleta:
            if (this.columnasCompletas[i] == TableroLogico.COLUMNA_INCOMPLETA) {
                //Insertamos en la lista de movimientos un movimiento para esa columna.
                movimientosPosibles.add(new Movimiento(i, TableroLogico.JUGADOR_ORDENADOR));
            }
        }

        //Devolvemos la lista de movimientos.
        return movimientosPosibles;
    }

    /**
     * Metodo para recrear un tablero logico a partir de otro cargado de un
     * archivo.
     *
     * @param tableroCargado Tablero cargado desde un archivo previamente
     * guardado.
     */
    public void recrearTablero(TableroLogico tableroCargado) {
        //Asignamos las filas del tablero.
        this.filas = tableroCargado.filas;
        //Asignamos las columnas del tablero.
        this.columnas = tableroCargado.columnas;
        //Asignamos la dificultad del tablero.
        this.dificultad = tableroCargado.dificultad;
        //Asiganamos el jugador al que pertenece el turno actual de tirada.
        this.jugadorActual = tableroCargado.jugadorActual;
        //Indicamos que la partida es una partida continuada.
        this.tipoPartida = TableroLogico.PARTIDA_CONTINUADA;

        //Asignamos los valores de los contadores de ambos participantes.
        this.contHumano = tableroCargado.contHumano;
        this.contOrdenador = tableroCargado.contOrdenador;

        //Volvemos a crear el array bidimensional de enteros correspondiente a las
        //casillas del tablero.
        this.tablero = new int[tableroCargado.filas][tableroCargado.columnas];
        //Volvemos a crear el array de enteros correspondiente a las columnas completas.
        this.columnasCompletas = new int[tableroCargado.columnas];

        //Realizamos una copia del array bidimensional de enteros correspondiente a las
        //casillas del tablero recibido.
        for (int i = 0; i < this.tablero.length; i++) {
            System.arraycopy(tableroCargado.tablero[i], 0, this.tablero[i], 0, tableroCargado.tablero[i].length);
        }

        //Realizamos una copia del array de enteros correspondiente a las columnas completas.
        System.arraycopy(tableroCargado.columnasCompletas, 0, this.columnasCompletas, 0,
                tableroCargado.columnasCompletas.length);

        //Llamamos al metodo para actualizar la vista del tablero.
        this.notificarVistas();
    }

    /**
     * Metodo para cambiar el valor logico de todas las casillas del tablero a
     * vacio.
     */
    public void vaciarTablero() {
        //Indicamos que el jugador cuyo turno actual de tirar es el jugador humano.
        this.jugadorActual = TableroLogico.JUGADOR_HUMANO;

        //Reiniciamos a 0 los contadores de movimietos de ambos participantes.
        this.contHumano = 0;
        this.contOrdenador = 0;

        //Recorremos el tablero reiniciando el valor de sus casillas a ficha vacia.
        for (int i = 0; i < this.tablero.length; i++) {
            for (int j = 0; j < this.tablero[i].length; j++) {
                this.tablero[i][j] = TableroLogico.FICHA_VACIA;
            }
        }

        //Recorremos el array de columnas completas reiniciando todas las columnas
        //a columnas incompletas.
        for (int i = 0; i < this.columnasCompletas.length; i++) {
            this.columnasCompletas[i] = TableroLogico.COLUMNA_INCOMPLETA;
        }

        //Llamamos al metodo para actualizar la vista del tablero.
        this.notificarVistas();
    }

    /**
     * Metodo para comprobar si un movimiento ha conseguido realizar un cuatro
     * en raya en su linea diagonal inversa.
     *
     * @param fila Fila del movimiento a comprobar si ha hecho cuatro en raya.
     * @param columna Columnas del movimiento a comprobar si ha hecho cuatro en
     * raya.
     * @param jugador Jugador que ha realizado el movimiento del que comprobar
     * si ha hecho cuatro en raya.
     * @return Verdadero si el movimiento ha producido cuatro en raya en la
     * diagonal inversa o falso en caso contrario.
     * @exception ArrayIndexOutOfBoundsException Excepcion que se producira
     * cuando se intente obtener el valor de una posicion que no se encuentre
     * dentro de las definidas en un array.
     */
    private boolean comprobarDiagonalInversa(int fila, int columna, int jugador) {
        //Declaramos un booleano que indique se produce cuatro en raya.
        boolean raya = false;
        //Declaramos varios enteros uno como contador para comprobar si se produce cuatro
        //en raya y los demas como auxiliares para indicar la columna a comprobar.
        int contDiagonalI = 0, aux1 = 0, aux2 = 0, auxFila = fila, auxColumna = columna;

        //Iniciamos un bucle que se iterara las veces necesarias para comprobar si se
        //produce cuatro en raya.
        while (aux1 < 4) {
            //Iniciamos un bucle para ir cambiando la posicion en la que comprobar si
            //hay cuatro en raya.
            while (aux2 < 4) {
                //Iniciamos un bloque try/catch para gestionar las excepciones que
                //puedan surgir.
                try {
                    //Si es el jugador humano:
                    if (jugador == TableroLogico.JUGADOR_HUMANO) {
                        //Se comprueba que el valor de la casilla sea el de su ficha, ficha roja.
                        if (this.tablero[auxFila - aux2][auxColumna - aux2] == TableroLogico.FICHA_ROJA) {
                            //Aumentando el contador para cuatro en raya.
                            contDiagonalI++;
                            //Si el contador llega a 4:
                            if (contDiagonalI == 4) {
                                //Se producira cuatro en raya.
                                raya = true;
                                //Se sale del bucle.
                                break;
                            } else {
                                //Si no, se reinicia a 0 el contador.
                                contDiagonalI = 0;
                            }
                        }
                    } else {
                        //Si es el jugador ordenador, se comprueba que el valor de la casilla sea el de
                        //su ficha, ficha azul.
                        if (this.tablero[auxFila - aux2][auxColumna - aux2] == TableroLogico.FICHA_AZUL) {
                            //Aumentando el contador para cuatro en raya.
                            contDiagonalI++;
                            //Si el contador llega a 4:
                            if (contDiagonalI == 4) {
                                //Se producira cuatro en raya.
                                raya = true;
                                //Se sale del bucle.
                                break;
                            } else {
                                //Si no, se reinicia a 0 el contador.
                                contDiagonalI = 0;
                            }
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    //Si se produce una excepcion por intentar acceder a una posicion que se
                    //encuentra fuera del tablero, se reinicia a 0 el contador.
                    contDiagonalI = 0;
                }
                //Aumenta el contador 2.
                aux2++;
            }
            //Aumentan las contadores 1, filas y columnas.
            aux1++;
            auxFila++;
            auxColumna++;
            //Se reinicia el contador de cuatro en raya a 0.
            contDiagonalI = 0;
        }

        //Devolvemos si se ha producido cuatro en raya o no.
        return raya;
    }

    /**
     * Metodo para comprobar si un movimiento ha conseguido realizar un cuatro
     * en raya en su linea diagonal principal.
     *
     * @param fila Fila del movimiento a comprobar si ha hecho cuatro en raya.
     * @param columna Columnas del movimiento a comprobar si ha hecho cuatro en
     * raya.
     * @param jugador Jugador que ha realizado el movimiento del que comprobar
     * si ha hecho cuatro en raya.
     * @return Verdadero si el movimiento ha producido cuatro en raya en la
     * diagonal principal o falso en caso contrario.
     * @exception ArrayIndexOutOfBoundsException Excepcion que se producira
     * cuando se intente obtener el valor de una posicion que no se encuentre
     * dentro de las definidas en un array.
     *
     */
    private boolean comprobarDiagonalPrincipal(int fila, int columna, int jugador) {
        //Declaramos un booleano que indique se produce cuatro en raya.
        boolean raya = false;
        //Declaramos varios enteros uno como contador para comprobar si se produce cuatro
        //en raya y los demas como auxiliares para indicar la columna a comprobar.
        int contDiagonalP = 0, aux1 = 0, aux2 = 0, auxFila = fila, auxColumna = columna;

        //Iniciamos un bucle que se iterara las veces necesarias para comprobar si se
        //produce cuatro en raya.
        while (aux1 < 4) {
            //Iniciamos un bucle para ir cambiando la posicion en la que comprobar si
            //hay cuatro en raya.
            while (aux2 < 4) {
                //Iniciamos un bloque try/catch para gestionar las excepciones que
                //puedan surgir.
                try {
                    //Si es el jugador humano:
                    if (jugador == TableroLogico.JUGADOR_HUMANO) {
                        //Se comprueba que el valor de la casilla sea el de su ficha, ficha roja.
                        if (this.tablero[auxFila - aux2][auxColumna + aux2] == TableroLogico.FICHA_ROJA) {
                            //Aumentando el contador para cuatro en raya.
                            contDiagonalP++;
                            //Si el contador llega a 4:
                            if (contDiagonalP == 4) {
                                //Se producira cuatro en raya.
                                raya = true;
                                //Se sale del bucle.
                                break;
                            } else {
                                //Si no, se reinicia a 0 el contador.
                                contDiagonalP = 0;
                            }
                        }
                    } else {
                        //Si es el jugador ordenador, se comprueba que el valor de la casilla sea el de
                        //su ficha, ficha azul.
                        if (this.tablero[auxFila - aux2][auxColumna + aux2] == TableroLogico.FICHA_AZUL) {
                            //Aumentando el contador para cuatro en raya.
                            contDiagonalP++;
                            //Si el contador llega a 4:
                            if (contDiagonalP == 4) {
                                //Se producira cuatro en raya.
                                raya = true;
                                //Se sale del bucle.
                                break;
                            } else {
                                //Si no, se reinicia a 0 el contador.
                                contDiagonalP = 0;
                            }
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    //Si se produce una excepcion por intentar acceder a una posicion que se
                    //encuentra fuera del tablero, se reinicia a 0 el contador.
                    contDiagonalP = 0;
                }
                //Aumenta el contador 2.
                aux2++;
            }
            //Aumentan el contador 1 y el de filas.
            aux1++;
            auxFila++;
            //Disminuye el contador de columnas.
            auxColumna--;
            //Se reinicia el contador de cuatro en raya a 0.
            contDiagonalP = 0;
        }
        //Devolvemos si se ha producido cuatro en raya o no.
        return raya;
    }

    /**
     * Metodo para comprobar si un movimiento ha conseguido realizar un cuatro
     * en raya en su linea horizontal.
     *
     * @param fila Fila del movimiento a comprobar si ha hecho cuatro en raya.
     * @param columna Columnas del movimiento a comprobar si ha hecho cuatro en
     * raya.
     * @param jugador Jugador que ha realizado el movimiento del que comprobar
     * si ha hecho cuatro en raya.
     * @return Verdadero si el movimiento ha producido cuatro en raya en la
     * horizontal o falso en caso contrario.
     */
    boolean comprobarHorizontal(int fila, int jugador) {
        //Declaramos un booleano que indique se produce cuatro en raya.
        boolean raya = false;
        //Declaramos dos enteros, uno como contador para comprobar si se produce cuatro
        //en raya y otro para ir movimiendo el valor de columna a comprobar.
        int contHorizontal = 0, aux = 0;

        //Mientras que el contador auxiliar sea menor a las columnas del tablero:
        while (aux < (this.tablero[0].length)) {
            //Si es el jugador humano:
            if (jugador == TableroLogico.JUGADOR_HUMANO) {
                //Se comprueba que el valor de la casilla sea el de su ficha, ficha roja.
                if (this.tablero[fila][aux] == TableroLogico.FICHA_ROJA) {
                    //Aumentando el contador para cuatro en raya.
                    contHorizontal++;
                    //Si el contador llega a 4:
                    if (contHorizontal == 4) {
                        //Se producira cuatro en raya.
                        raya = true;
                        //Se sale del bucle.
                        break;
                    }

                } else {
                    //Si no, se reinicia a 0 el contador.
                    contHorizontal = 0;
                }

            } else {

                //Si es el jugador ordenador, se comprueba que el valor de la casilla sea el de
                //su ficha, ficha azul.
                if (this.tablero[fila][aux] == TableroLogico.FICHA_AZUL) {
                    //Aumentando el contador para cuatro en raya.
                    contHorizontal++;
                    //Si el contador llega a 4:
                    if (contHorizontal == 4) {
                        //Se producira cuatro en raya.
                        raya = true;
                        //Se sale del bucle.
                        break;
                    }

                } else {
                    //Si no, se reinicia a 0 el contador.
                    contHorizontal = 0;
                }
            }
            //Se aumenta el contador auxiliar.
            aux++;
        }

        //Devolvemos si se ha producido cuatro en raya o no.
        return raya;
    }

    /**
     * Metodo para comprobar si un tablero tiene todas sus casillas ocupadas.
     *
     * @return Verdadero si el tablero esta completo o falso en caso contrario.
     */
    private boolean comprobarTableroCompleto() {
        //Declaramos un contador para ir contando el numero de casillas no vacias.
        int cont = 0;

        //Recorremos todas las casillas del tablero.
        for (int i = 0; i < this.tablero.length; i++) {
            for (int j = 0; j < this.tablero[i].length; j++) {
                //Si el valor de la casilla es diferente al de ficha vacia, se
                //aumenta el contador.
                if (this.tablero[i][j] != TableroLogico.FICHA_VACIA) {
                    cont++;
                }
            }
        }

        //Si el contador es el igual al numero total de casillas del tablero.
        if (cont == this.tablero.length * this.tablero[0].length) {
            //Se devuelve verdadero, porque el tablero esta completo.
            return true;
        } else {
            //En caso contratio, se devolvera falso.
            return false;
        }
    }

    /**
     * Metodo para comprobar si un movimiento ha conseguido realizar un cuatro
     * en raya en su linea vertical.
     *
     * @param fila Fila del movimiento a comprobar si ha hecho cuatro en raya.
     * @param columna Columnas del movimiento a comprobar si ha hecho cuatro en
     * raya.
     * @param jugador Jugador que ha realizado el movimiento del que comprobar
     * si ha hecho cuatro en raya.
     * @return Verdadero si el movimiento ha producido cuatro en raya en la
     * vertical o falso en caso contrario.
     */
    private boolean comprobarVertical(int columna, int jugador) {
        //Declaramos un booleano que indique se produce cuatro en raya.
        boolean raya = false;
        //Declaramos dos enteros, uno como contador para comprobar si se produce cuatro
        //en raya y otro para ir movimiendo el valor de fila a comprobar.
        int contVertical = 0, aux = 0;

        //Mientras que el contador auxiliar sea menor a las filas del tablero:
        while (aux < (this.tablero.length)) {
            //Si es el jugador humano:
            if (jugador == TableroLogico.JUGADOR_HUMANO) {
                //Se comprueba que el valor de la casilla sea el de su ficha, ficha roja.
                if (this.tablero[aux][columna] == TableroLogico.FICHA_ROJA) {
                    //Aumentando el contador para cuatro en raya.
                    contVertical++;
                    //Si el contador llega a 4:
                    if (contVertical == 4) {
                        //Se producira cuatro en raya.
                        raya = true;
                        //Se sale del bucle.
                        break;
                    }

                } else {
                    //Si no, se reinicia a 0 el contador.
                    contVertical = 0;
                }

            } else {

                //Si es el jugador ordenador, se comprueba que el valor de la casilla sea el de
                //su ficha, ficha azul.
                if (this.tablero[aux][columna] == TableroLogico.FICHA_AZUL) {
                    //Aumentando el contador para cuatro en raya.
                    contVertical++;
                    //Si el contador llega a 4:
                    if (contVertical == 4) {
                        //Se producira cuatro en raya.
                        raya = true;
                        //Se sale del bucle.
                        break;
                    }

                } else {
                    //Si no, se reinicia a 0 el contador.
                    contVertical = 0;
                }
            }
            //Se aumenta el contador auxiliar.
            aux++;
        }

        //Devolvemos si se ha producido cuatro en raya o no.
        return raya;
    }

    /**
     * Metodo que comprobara si un movimiento produce cuatro en raya llamando a
     * otros metodos auxiliares.
     *
     * @param fila Fila del movimiento a comprobar si ha hecho cuatro en raya.
     * @param columna Columnas del movimiento a comprobar si ha hecho cuatro en
     * raya.
     * @param jugador Jugador que ha realizado el movimiento del que comprobar
     * si ha hecho cuatro en raya.
     * @return Verdadero si el movimiento ha producido cuatro en raya de alguna
     * de las formas posibles.
     */
    private boolean comprobarRaya(int fila, int columna, int jugador) {
        //Declaramos un booleano para devolver si se produce un cuatro en raya o no
        //en el tablero.
        boolean raya = false;

        //Si se produce cuatro en raya horizontal:
        if (comprobarHorizontal(fila, jugador) == true) {
            //Indicamos que se ha producido cuatro en raya.
            raya = true;
        } else {

            //Si no, si se produce cuatro en raya vertical:
            if (comprobarVertical(columna, jugador) == true) {
                //Indicamos que se ha producido cuatro en raya.
                raya = true;
            } else {

                //Si no, si se produce cuatro en raya en la diagonal principal:
                if (comprobarDiagonalPrincipal(fila, columna, jugador) == true) {
                    //Indicamos que se ha producido cuatro en raya.
                    raya = true;
                } else {

                    //Si no, si se produce cuatro en raya en la diagonal inversa:
                    if (comprobarDiagonalInversa(fila, columna, jugador) == true) {
                        //Indicamos que se ha producido cuatro en raya.
                        raya = true;
                    }
                }
            }
        }

        //Se devuelve el booleano que indica si se ha producido cuatro en raya o no.
        return raya;
    }

    /**
     * Metodo que en caso de cuatro en raya, finaliza la partida.
     *
     * @param jugador Jugador que ha finalizado la partida ganandola.
     */
    private void finalizarPartida(int jugador) {
        //Declaramos un entero que almacenara la opcion seleccionada al finalizar la partida.
        int opcion = 0;
        //Declaramos un array de Object con las opciones a mostrar en la ventana de finalizar
        //partida.
        Object acciones[] = {"Nueva partida", "Salir"};

        //Esta partida pasa a ser una partida continuada.
        this.tipoPartida = TableroLogico.PARTIDA_CONTINUADA;

        //Si es el jugador humano:
        if (jugador == TableroLogico.JUGADOR_HUMANO) {
            //Incrementamos las partidas ganadas del jugador.
            this.gestionJugadores.incrementarPartidasGanadas(this.nombreJugador);
            //Mostramos una ventana emergente indicando que el jugador ha ganado y preguntando
            //si se que quiere iniciar una nueva partida o salir.
            opcion = JOptionPane.showOptionDialog(null, "El jugador \"" + this.nombreJugador
                    + "\" ha realizado el cuatro"
                    + "\nen raya en " + this.contHumano + " movimientos."
                    + "\n\n¿Iniciar una nueva partida o salir del juego?", "Selector de opciones",
                    JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                    acciones, "Nueva partida");
        } else {
            //Incrementamos las partidas ganadas del jugador.
            this.gestionJugadores.incrementarPartidasPerdidas(this.nombreJugador);
            //Mostramos una ventana emergente indicando que el ordenador ha ganado y preguntando
            //si se que quiere iniciar una nueva partida o salir.
            opcion = JOptionPane.showOptionDialog(null,
                    "El ordenador ha realizado el cuatro"
                    + "\nen raya en " + this.contOrdenador + " movimientos."
                    + "\n\n¿Iniciar una nueva partida o salir del juego?", "Selector de opciones",
                    JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                    acciones, "Nueva partida");
        }

        //Si se ha seleccionado la opcion de "Nueva partida":
        if (opcion == JOptionPane.YES_OPTION) {
            //Llamamos al metodo para reiniciar el tablero y empezar una partida nueva.
            vaciarTablero();
        } else {
            //Si no, si se cierra la ventana o se selecciona "Salir":
            if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                //Se guarda los datos actuales de los jugadores en la base de datos.
                this.gestionJugadores.guardarJugadores();
                //Se sale de la aplicacion.
                System.exit(0);
            }
        }
    }

    /**
     * Metodo que en caso de que se completen todas las casillas del tablero,
     * finaliza la partidad.
     */
    private void finalizarTableroCompleto() {
        //Declaramos un entero que almacenara la opcion seleccionada al finalizar la partida.
        int opcion = 0;
        //Declaramos un array de Object con las opciones a mostrar en la ventana de finalizar
        //partida.
        Object acciones[] = {"Nueva partida", "Salir"};

        //Esta partida pasa a ser una partida continuada.
        this.tipoPartida = TableroLogico.PARTIDA_CONTINUADA;

        //Incrementamos las partidas empatadas del jugador.
        this.gestionJugadores.incrementarPartidasEmpatadas(this.nombreJugador);
        //Mostramos una ventana emergente informando de que el tablero esta lleno y
        //se ha producido un empate.
        JOptionPane.showMessageDialog(null, "El tablero esta lleno, la partida termina en empate.");

        //En una nueva ventana emergente, se pregunta si se quiere iniciar una nueva partida o
        //salir del juego.
        opcion = JOptionPane.showOptionDialog(null, "¿Iniciar una nueva partida o salir del juego?",
                "Selector de opciones", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,
                null, acciones, "Nueva partida");

        //Si se escoge la opcion de "Nueva partida":
        if (opcion == JOptionPane.YES_OPTION) {
            //Llamamos al metodo para reiniciar el tablero y empezar una partida nueva.
            vaciarTablero();
        } else {
            //Si no, si se cierra la ventana o se selecciona "Salir":
            if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                //Se guarda los datos actuales de los jugadores en la base de datos.
                this.gestionJugadores.guardarJugadores();
                //Se sale de la aplicacion.
                System.exit(0);
            }
        }
    }

    /**
     * Metodo se actualicen los movimientos realizados, repintandose asi en el
     * tablero.
     */
    private void notificarVistas() {
        //Recorremos la lista de vistas.
        for (Vista vista : vistas) {
            //Actualizamos las vistas del tablero.
            vista.modelChanged();
        }
    }

    /**
     * Metodo para realizar una copia en un espacio de memoria diferente del
     * tablero logico.
     *
     * @return Instancia de TableroLogico copia del TableroLogico original.
     * @exception CloneNotSupportedException Excepcion que se producira si el
     * objeto a clonar, no permite la clonacion.
     */
    @Override
    protected TableroLogico clone() {
        //Declaramos un tablero logico nulo para clonar en el, este tablero logico.
        TableroLogico tableroLogico = null;

        //Iniciamos un bloque try/catch para gestionar las posibles excepciones
        //que se puedan producir durante la clonacion.
        try {
            //El tablero logico declarado sera una copia exacta pero en una zona diferente
            //de memoria de este tablero logico.
            tableroLogico = (TableroLogico) super.clone();
            //Creamos un array bidimensional para copiar tambien el tablero con las casillas
            //del tablero original.
            tableroLogico.tablero = new int[this.filas][this.columnas];
            //Creamos un array para copiar tambien las columnas completas del tablero original.
            tableroLogico.columnasCompletas = new int[this.columnas];

            //Recorremos todo el array copiando los valores del tablero original al clonado.
            for (int i = 0; i < tableroLogico.tablero.length; i++) {
                System.arraycopy(this.tablero[i], 0, tableroLogico.tablero[i], 0, this.tablero[i].length);
            }

            //Copiamos el array de columnas del original al clonado.
            System.arraycopy(this.columnasCompletas, 0, tableroLogico.columnasCompletas, 0,
                    this.columnasCompletas.length);

        } catch (CloneNotSupportedException e) {
            //Si se produce una excepcion porque el tablero no puede ser clonado, mostramos
            //un mensaje en consola.
            System.out.println("Error al clonar tablero.");
            //Imprimimos el error producido.
            e.printStackTrace();
        }

        //Devolvemos el tablero logico clonado.
        return tableroLogico;
    }
}
