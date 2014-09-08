package cuatroenraya;

/**
 * Clase que representa los movimientos que podran ser realizados en el
 * programa.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class Movimiento {

    //Declaramos dos enteros, uno correspondiente a la columna en la que se realiza el movimiento
    //y el otro correspondiente al jugador que realiza el movimiento.
    private int columna, jugador;

    /**
     * Constructor, crea un nuevo movimiento a realizar en el tablero con los
     * parametros recibidos.
     *
     * @param columna Columna en la que se realiza el movimiento.
     * @param jugador Jugador que realiza el movimiento.
     */
    public Movimiento(int columna, int jugador) {
        //Columna en la que se realiza el movimiento recibido.
        this.columna = columna;
        //Jugador que realiza movimiento recibido.
        this.jugador = jugador;
    }

    /**
     * Metodo que devuelve la columna del movimiento.
     *
     * @return Columna en la que se realiza el movimiento.
     */
    public int getColumna() {
        //Devuelve la columna en la que se realiza el movimiento.
        return this.columna;
    }

    /**
     * Metodo que devuelve el jugador al que corresponde el movimiento.
     *
     * @return Jugador que realiza el movimiento.
     */
    public int getJugador() {
        //Devuelve el jugador que realiza el movimiento.
        return this.jugador;
    }

    /**
     * Metodo para cambiar el jugador al que corresponde el movimiento.
     *
     * @param jugador Jugador que realiza el movimiento.
     */
    public void setJugador(int jugador) {
        //Cambia el jugador que realiza el movimiento.
        this.jugador = jugador;
    }
}
