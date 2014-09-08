package cuatroenraya;

//Clases necesarias para ejecutar acciones segun eventos de raton.
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
//Clase necesario para realizar la serializacion de un objeto.
import java.io.Serializable;
//Clase necesaria para mostrar mensajes y/o introducir valores a traves ventanas emergentes.
import javax.swing.JOptionPane;

/**
 * Clase encargada de gestionar los movimientos realizados en el juego.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class Controlador implements MouseListener, Serializable {

    //Declaramos el tablero logico a controlar sobre el que se realizaran los movimientos.
    private TableroLogico tableroLogico;

    /**
     * Constructor, crea un controlador de los movimientos a partir de los
     * parametros recibidos.
     *
     * @param tableroLogico Tablero logico sobre el que se realizaran los
     * movimientos.
     */
    public Controlador(TableroLogico tableroLogico) {
        //El tablero logico recibido, que es el creado al comienzo de la ejecucion de la
        //aplicacion, sera el tablero que controlaremos para realizar sobre el los
        //movimientos que se vayan ejecutando.
        this.tableroLogico = tableroLogico;
    }

    /**
     * Metodo que cuando recibe el evento de un click de raton sobre el tablero,
     * lo transforma en un movimiento en el mismo.
     *
     * @param evento Evento de raton que representa el click del mismo en una
     * posicion.
     */
    public void mouseClicked(MouseEvent evento) {
        //Obtenemos que de que jugador es el turno actual de tirada.
        int turnoJugador = this.tableroLogico.getJugadorActual();

        //Si es el turno del ordenador, no podremos realizar ningun movimiento, hasta
        //que este no finalice el suyo.
        if (turnoJugador == TableroLogico.JUGADOR_ORDENADOR) {
            //Si intentamos realizar un movimiento en el turno del ordenador, la aplicacion
            //nos informara de que no es nuestro turno.
            JOptionPane.showMessageDialog(null, "Es el turno del ordenador.");
        } else {
            //Declaramos un variable booleana que almacenara si el movimiento se ha podido
            //realizar o no.
            boolean estado;
            //Obtenemos la posicion del pixel en el eje horizontal del movimiento realizado.
            int posx = evento.getX();
            //Teniendo en cuenta el numero de pixeles de los que esta compuesto una casilla,
            //obtener el valor de la columna en la que se he realizado el movimiento.
            int columna = posx / PanelTablero.dimensionCasilla;

            //Creamos el movimiento ha realizar indicando la columna de tirada y que ha sido
            //realizado por el jugador.
            Movimiento movimiento = new Movimiento(columna, TableroLogico.JUGADOR_HUMANO);

            //Realizamos el movimiento, almacenando si el movimiento se ha podido realizar o no.
            estado = this.tableroLogico.mover(movimiento);

            //Si el movimiento se ha realizado correctamente en una partida que no acaba de ser cargada:
            if ((estado == true) && (this.tableroLogico.getTipoPartida() == TableroLogico.PARTIDA_NUEVA)) {
                //Se avisara de que ha finalizado el turno del jugador.
                JOptionPane.showMessageDialog(null, "El jugador ha realizado su movimiento."
                        + "\nTurno de mover del ordenador.");
                //El ordenador obtiene el turno de tirada.
                this.tableroLogico.setJugadorActual(TableroLogico.JUGADOR_ORDENADOR);
                //Creamos un nuevo hilo de ejecucion en el que generar el movimiento del ordenador.
                new Thread(new Minimax(this.tableroLogico, this)).start();
            } else {
                //En caso contrario, se indicara que a partir del siguiente turno, la partida actual
                //no se considere como una partida recien cargada, para que los turnos de tirada se
                //puedan realizar correctamente.
                this.tableroLogico.setTipoPartida(TableroLogico.PARTIDA_NUEVA);
            }
        }
    }

    /**
     * Metodo que recibe un movimiento generado por el Minimax para ser
     * reflejado en el tablero por el ordenador.
     *
     * @param movimiento Movimiento generado por el Minimax para ser realizado
     * por el ordenador.
     */
    public void movimientoMinimax(Movimiento movimiento) {
        //Declaramos un variable booleana que almacenara si el movimiento se ha podido
        //realizar o no.
        boolean estado = false;
        //Realizamos el movimiento, almacenando si el movimiento se ha podido realizar o no.
        estado = this.tableroLogico.mover(movimiento);
        //Si el movimiento se ha realizado correctamente:
        if (estado == true) {
            //Se avisara de que ha finalizado el turno del ordenador.
            JOptionPane.showMessageDialog(null, "El ordenador ha realizado su movimiento."
                    + "\nTurno de mover del jugador.");
            //El jugador obtiene el turno de tirada.
            this.tableroLogico.setJugadorActual(TableroLogico.JUGADOR_HUMANO);
        }
    }

    /**
     * Metodo que recibe un evento de raton cuando este entra en un componente.
     * No se usa en esta aplicacion, pero es obligatoria su implementacion
     * porque la clase implementa MouseListener.
     *
     * @param evento Evento de raton que representa la entrada del mismo en un
     * componente.
     */
    public void mouseEntered(MouseEvent evento) {
    }

    /**
     * Metodo que recibe un evento de raton cuando este sale de un componente.
     * No se usa en esta aplicacion, pero es obligatoria su implementacion
     * porque la clase implementa MouseListener.
     *
     * @param evento Evento de raton que representa la salida del mismo de un
     * componente.
     */
    public void mouseExited(MouseEvent evento) {
    }

    /**
     * Metodo que recibe un evento de raton cuando se presiona el boton
     * izquierdo. No se usa en esta aplicacion, pero es obligatoria su
     * implementacion porque la clase implementa MouseListener.
     *
     * @param evento Evento de raton que representa el que el boton izquierdo
     * esta siendo presionado.
     */
    public void mousePressed(MouseEvent evento) {
    }

    /**
     * Metodo que recibe un evento de raton cuando se deja de presionar el boton
     * izquierdo. No se usa en esta aplicacion, pero es obligatoria su
     * implementacion porque la clase implementa MouseListener.
     *
     * @param evento Evento de raton que representa el que el boton izquierdo ha
     * dejado de ser presionado.
     */
    public void mouseReleased(MouseEvent evento) {
    }
}
