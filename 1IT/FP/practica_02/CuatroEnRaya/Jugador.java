package cuatroenraya;

//Clase necesario para realizar la serializacion de un objeto.
import java.io.Serializable;

/**
 * Clase que representa los usuarios que podran ser almacenados por el programa.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class Jugador implements Serializable {

    //Declaramos dos cadenas de texto correspondientes al nombre del jugador y su password.
    private String nombre, password;
    //Declaramos varios enteros que corresponderan a la cantidad de los diferentes
    //resultados de las partidas realizadas.
    private int partidasJugadas, partidasGanadas, partidasPerdidas, partidasEmpatadas;

    /**
     * Constructor, crea un nuevo usuario con los parametros recibidos como
     * argumentos y sus estadisticas a 0.
     *
     * @param nombre Nombre del usuario.
     * @param password Password del usuario.
     */
    public Jugador(String nombre, String password) {
        //Nombre del jugador recibido.
        this.nombre = nombre;
        //Password del jugador recibido.
        this.password = password;
        //Por defecto, todos los contadores de partidas se inician a 0.
        this.partidasJugadas = 0;
        this.partidasGanadas = 0;
        this.partidasPerdidas = 0;
        this.partidasEmpatadas = 0;
    }

    /**
     * Metodo que devuelve el nombre de un jugador.
     *
     * @return Nombre del usuarios.
     */
    public String getNombre() {
        //Devuelve el nombre del jugador.
        return this.nombre;
    }

    /**
     * Metodo que devuelve el password de un jugador.
     *
     * @return Password del usuario.
     */
    public String getPassword() {
        //Devuelve el password del jugador.
        return this.password;
    }

    /**
     * Metodo que devuelve el numero de partidas jugadas de un jugador.
     *
     * @return Partidas jugadas por el usuario.
     */
    public int getPartidasJugadas() {
        //Devuelve la partidas jugadas por el jugador.
        return this.partidasJugadas;
    }

    /**
     * Metodo que devuelve el numero de partidas ganadas de un jugador.
     *
     * @return Partidas ganadas por el usuario.
     */
    public int getPartidasGanadas() {
        //Devuelve las partidas ganadas por el jugador.
        return this.partidasGanadas;
    }

    /**
     * Metodo que devuelve el numero de partidas perdidas de un jugador.
     *
     * @return Partidas perdidas por el usuario.
     */
    public int getPartidasPerdidas() {
        //Devuelve las partidas perdidas por el jugador.
        return this.partidasPerdidas;
    }

    /**
     * Metodo que devuelve el numero de partidas empatadas de un jugador.
     *
     * @return Partidas empatadas por el usuario.
     */
    public int getPartidasEmpatadas() {
        //Devuelve las partidas empatadas por el jugador.
        return this.partidasEmpatadas;
    }

    /**
     * Metodo que incrementa en 1 el numero de partidas jugadas y ganadas de un
     * jugador.
     */
    public void incrementarPartidasGanadas() {
        //Incrementa en 1 las partidas jugadas y ganadas por el jugador.
        this.partidasJugadas++;
        this.partidasGanadas++;
    }

    /**
     * Metodo que incrementa en 1 el numero de partidas jugadas y perdidas de un
     * jugador.
     */
    public void incrementarPartidasPerdidas() {
        //Incrementa en 1 las partidas jugadas y perdidas por el jugador.
        this.partidasJugadas++;
        this.partidasPerdidas++;
    }

    /**
     * Metodo que incrementa en 1 el numero de partidas jugadas y empatadas de
     * un jugador.
     */
    public void incrementarPartidasEmpatadas() {
        //Incrementa en 1 las partidas jugadas y empatadas por el jugador.
        this.partidasJugadas++;
        this.partidasEmpatadas++;
    }

    /**
     * Metodo que reinicia todas las estadisticas de un jugador a 0.
     */
    public void reiniciarPartidas() {
        //Reinicia a 0 todas las partidas del jugador.
        this.partidasJugadas = 0;
        this.partidasGanadas = 0;
        this.partidasPerdidas = 0;
        this.partidasEmpatadas = 0;
    }
}
