package cuatroenraya;

//Clases necesarias para crear un flujo haga un buffer para la entrada/salida de datos.
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
//Clase necesaria para representar un archivo con el que el programa trabajara.
import java.io.File;
//Clases necesarias para crear un flujo que realice las acciones de lectura/escritura.
import java.io.FileInputStream;
import java.io.FileOutputStream;
//Clases necesarias para crear un flujo que cargue/guarde los objetos serializados.
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
//Clase necesaria para realizar la serializacion de un objeto.
import java.io.Serializable;
//Clase necesaria para poder utilizar listas ArrayList.
import java.util.ArrayList;

/**
 * Clase encargada gestionar las entrada/salida relacionadas con los datos de
 * los usuarios del programa.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class GestionJugadores implements Serializable {

    //Declaramos una lista que servira de base de datos para guardar los datos de los jugadores.
    private ArrayList<Jugador> jugadores;

    /**
     * Constructor, crea un gestionador de la entrada/salida de las operaciones
     * con usuarios.
     */
    public GestionJugadores() {

        //Declaramos una cadena de texto con la ruta de la base de datos de los jugadores.
        String path = System.getProperty("user.dir") + java.io.File.separatorChar + "ListadoDeJugadores";
        //Declaramos un archivo con dicha ruta.
        File listaJugadores = new File(path);
        //Si el archivo existe, cargaremos la base de datos existente.
        if (listaJugadores.exists()) {
            cargarJugadores();
        } else {
            //En caso contrario, crearemos una nueva base de datos.
            this.jugadores = new ArrayList<Jugador>();
        }
    }

    /**
     * Metodo para agregar usuarios a la base de datos.
     *
     * @param jugador Instacia de jugador a agregar a la lista de usuarios.
     */
    public void addJugador(Jugador jugador) {
        //Agregamos un jugador a la base de datos.
        this.jugadores.add(jugador);
    }

    /**
     * Metodo para cargar los usuarios existentes en la base de datos.
     *
     * @exception Exception Excepcion en la recuperacion de los datos.
     */
    public void cargarJugadores() {
        //Declaramos una cadena de texto con la ruta de la base de datos de los jugadores.
        String path = System.getProperty("user.dir") + java.io.File.separatorChar + "ListadoDeJugadores";
        //Declaramos un flujo que realice las acciones de lectura.
        FileInputStream fis = null;
        //Declaramos un flujo haga un buffer para la entrada de datos.
        BufferedInputStream bis = null;
        //Declaramos un flujo que cargue los objetos serializados.
        ObjectInputStream ois = null;

        //Abrimos un bloque try/catch para gestionar las diferentes excepciones que
        //se pudiesen producir durante el proceso.
        try {
            //Creamos un nuevo flujo para que realice la lectura de la ruta indicada.
            fis = new FileInputStream(path);
            //Creamos un nuevo flujo para que cree un buffer de entrada de datos con el flujo anterior.
            bis = new BufferedInputStream(fis);
            //Creamos un nuevo flujo que cargue los objetos serializados con el flujo anterior.
            ois = new ObjectInputStream(bis);
            //Indicamos que la base de datos sera el objeto cargado a traves de los flujos.
            this.jugadores = (ArrayList<Jugador>) ois.readObject();
        } catch (Exception e) {
            //Si se produce una excepcion, se muestra un aviso en la consola.
            System.out.println("Error al cargar la base de datos de jugadores.");
            //Y se imprime donde se ha producido el error.
            e.printStackTrace();
        }
    }

    /**
     * Metodo para comprobar si un usuario existe con un nombre concreto en la
     * base de datos.
     *
     * @param nombre Nombre del usuario buscado.
     * @return Verdadero si ha encontrado algun usuario con ese nombre o falso
     * en caso contrario.
     */
    public boolean comprobarJugadores(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Si el indice final es menor a la dimension de la base de datos, significara que el
        //jugador buscado existia en la base de datos. Devolvera verdadero.
        if (i < this.jugadores.size()) {
            return true;
        } else {
            //Devolviendo falso en caso contrario.
            return false;
        }
    }

    /**
     * Metodo para comprobar si un usuario existe con un password concreto en la
     * base de datos
     *
     * @param password Password del usuario buscado.
     * @return Verdadero si ha encontrado algun usuario con ese password o falso
     * en caso contrario.
     */
    public boolean comprobarPassword(String password) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo password sea igual al recibido como parametro, se detiene la busqueda.
            if (password.equals(this.jugadores.get(i).getPassword())) {
                break;
            }
        }

        //Si el indice final es menor a la dimension de la base de datos, significara que el
        //jugador buscado existia en la base de datos. Devolvera verdadero.
        if (i < this.jugadores.size()) {
            return true;
        } else {
            //Devolviendo falso en caso contrario.
            return false;
        }
    }

    /**
     * Metodo para guardar la base de datos de usuarios.
     *
     * @exception Exception Excepcion en el guardado de los datos.
     */
    public void guardarJugadores() {
        //Declaramos una cadena de texto con la ruta de la base de datos de los jugadores.
        String path = System.getProperty("user.dir") + java.io.File.separatorChar + "ListadoDeJugadores";

        //Declaramos un flujo que realice las acciones de escritura.
        FileOutputStream fos = null;
        //Declaramos un flujo haga un buffer para la salida de datos.
        BufferedOutputStream bos = null;
        //Declaramos un flujo que guarde los objetos serializados.
        ObjectOutputStream oos = null;

        //Abrimos un bloque try/catch para gestionar las diferentes excepciones que
        //se pudiesen producir durante el proceso.
        try {
            //Creamos un nuevo flujo para que realice la escritura en la ruta indicada.
            fos = new FileOutputStream(path);
            //Creamos un nuevo flujo para que cree un buffer de salida de datos con el flujo anterior.
            bos = new BufferedOutputStream(fos);
            //Creamos un nuevo flujo que guarde los objetos serializados con el flujo anterior.
            oos = new ObjectOutputStream(bos);
            //Indicamos que la base de datos sera lo que se va a guardar.
            oos.writeObject(this.jugadores);
            //Vaciamos el flujo serializador.
            oos.flush();
            //Y finalmente, lo cerramos para que se guarden los cambios.
            oos.close();
        } catch (Exception e) {
            //Si se produce una excepcion, se muestra un aviso en la consola.
            System.out.println("Error al guardar el listado de jugadores.");
            //Y se imprime donde se ha producido el error.
            e.printStackTrace();
        }
    }

    /**
     * Metodo para incrementar las partidas empatadas por un usuario en la base
     * de datos.
     *
     * @param nombre Nombre del usuario buscado.
     */
    public void incrementarPartidasEmpatadas(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se incrementaran las partidas empatadas del jugador cuyo indice sea resultante de la busqueda.
        this.jugadores.get(i).incrementarPartidasEmpatadas();
    }

    /**
     * Metodo para incrementar las partidas ganadas por un usuario en la base de
     * datos.
     *
     * @param nombre Nombre del usuario buscado.
     */
    public void incrementarPartidasGanadas(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se incrementaran las partidas ganadas del jugador cuyo indice sea resultante de la busqueda.
        this.jugadores.get(i).incrementarPartidasGanadas();
    }

    /**
     * Metodo para incrementar las partidas perdidas por un usuario en la base
     * de datos.
     *
     * @param nombre Nombre del usuario buscado.
     */
    public void incrementarPartidasPerdidas(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se incrementaran las partidas ganadas del jugador cuyo indice sea resultante de la busqueda.
        this.jugadores.get(i).incrementarPartidasPerdidas();
    }

    /**
     * Metodo para obtener las estadisticas de un usuario almacenadas en la base
     * de datos.
     *
     * @param nombre Nombre del usuario buscado.
     * @return Cadena de texto con las estadisticas del usuario.
     */
    public String obtenerEstadisticas(String nombre) {

        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;
        //Declaramos una serie de enteros que representaran las partidas jugadas, ganadas, perdidas
        //y empatadas por un jugador.
        int partidasJugadas, partidasGanadas, partidasPerdidas, partidasEmpatadas;
        //Declaramos una cadena de texto que almacenara las estadisticas del jugador.
        String cadena;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se almacenan en los enteros las partidas del jugador cuyo indice sea resultante de la busqueda.
        partidasJugadas = this.jugadores.get(i).getPartidasJugadas();
        partidasGanadas = this.jugadores.get(i).getPartidasGanadas();
        partidasPerdidas = this.jugadores.get(i).getPartidasPerdidas();
        partidasEmpatadas = this.jugadores.get(i).getPartidasEmpatadas();

        //Se almacenan en la cadena de texto con el formato adecuado.
        cadena = "Jugador: " + nombre
                + "\n\nPartidas jugadas: " + partidasJugadas
                + "\n\nPartidas ganadas: " + partidasGanadas
                + "\nPartidas perdidas: " + partidasPerdidas
                + "\nPartidas empatadas: " + partidasEmpatadas;

        //Devolvemos la cadena de texto.
        return cadena;
    }

    /**
     * Metodo para obtener una instancia correspondiente a un usuario del
     * programa.
     *
     * @param nombre Nombre del usuario buscado.
     * @return Instancia de Jugador correspondiente al usuarios buscado.
     */
    public Jugador obtenerJugador(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se devuelve la instancia del jugador cuyo indice sea resultante de la busqueda.
        return this.jugadores.get(i);
    }

    /**
     * Metodo para reiniciar a 0 todas las estadisticas de un jugado concreto en
     * la base de datos.
     *
     * @param nombre Nombre del usuario buscado.
     */
    public void reiniciarPartidas(String nombre) {
        //Declaramos un entero que representara el indice de un jugador dentro de la base de datos.
        int i;

        //Recorremos uno a uno, todos los jugadores de la base de datos.
        for (i = 0; i < this.jugadores.size(); i++) {
            //Si encuentra uno cuyo nombre sea igual al recibido como parametro, se detiene la busqueda.
            if (nombre.equals(this.jugadores.get(i).getNombre())) {
                break;
            }
        }

        //Se reiniciaran todas las partidas del jugador cuyo indice sea resultante de la busqueda.
        this.jugadores.get(i).reiniciarPartidas();
    }
}
