package cuatroenraya;

//Clases necesarias para crear un flujo hacia un buffer para la entrada/salida de datos.
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
//Clase necesaria para generar ventanas de seleccion de archivos.
import javax.swing.JFileChooser;
//Clase necesaria para mostrar mensajes y/o introducir valores a traves ventanas emergentes.
import javax.swing.JOptionPane;

/**
 * Clase encargada gestionar las entrada/salida relacionadas con las partidas.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class GestionPartidas {

    /**
     * Metodo para cargar una partida guardada previamente.
     *
     * @param nombre Nombre del usuario que esta intentando cargar la partida.
     * @return El tablero que representa a la partida cargada desde un archivo.
     */
    public TableroLogico cargarTablero(String nombre) {
        //Declaramos una cadena de texto con la ruta de la carpeta personal del jugador.
        String userDir = System.getProperty("user.dir") + java.io.File.separatorChar + nombre;
        //Declaramos un archivo con dicha ruta.
        File rutaCarpetaJugador = new File(userDir);
        //Creamos un nuevo tablero logico sin dimensiones, para luego copiar el tablero cargado.
        TableroLogico tableroLogico = new TableroLogico(0, 0);

        //Si por alguna causa, no existiese la ruta anterior, la ruta a utilizar seria
        //la del directorio de trabajo.
        if (rutaCarpetaJugador.exists() == false) {
            userDir = System.getProperty("user.dir");
        }

        //Creamos una nueva interfaz de seleccion de archivos, lo utilizaremos para
        //seleccionar la partidad a cargar.
        JFileChooser jFileChooser = new JFileChooser(userDir);
        //Declaramos un entero que guarde la opcion seleccionada en la interfaz de seleccion.
        int returnValue = jFileChooser.showOpenDialog(null);

        //Si despues de seleccionar un archivo, pulsamos el boton de aceptar:
        if (returnValue == JFileChooser.APPROVE_OPTION) {
            //Declaramos un entero que almacenara la respuesta a la opcion de cargar el
            //archivo seleccionado.
            int opcion = JOptionPane.showConfirmDialog(null,
                    "¿Desea cargar el archivo \"" + jFileChooser.getSelectedFile().getName() + "\"?",
                    "¿Desea cargar el archivo \"" + jFileChooser.getSelectedFile().getName() + "\"?",
                    JOptionPane.YES_NO_OPTION);

            //Si la opcion seleccionada es afirmatica, se copiara en el tablero declarado
            //al principio del metodo el tablero devuelto por el metodo que realiza el
            //cargado del tablero guardado.
            if (opcion == JOptionPane.YES_OPTION) {
                tableroLogico = cargado(jFileChooser.getSelectedFile());
            }
        }

        //Devolvemos el tablero cargado.
        return tableroLogico;
    }

    /**
     * Metodo para grabar la partida actual.
     *
     * @param tableroLogico El tablero que representa a la partida que se quiere
     * guardar en un archivo.
     */
    public void grabarTablero(TableroLogico tableroLogico) {
        //Declaramos una cadena de texto con la ruta de la carpeta personal del jugador.
        String userDir = System.getProperty("user.dir") + java.io.File.separatorChar
                + tableroLogico.getNombreJugador();
        //Declaramos un archivo con dicha ruta.
        File rutaCarpetaJugador = new File(userDir);

        //Si la ruta indicada no existiese, se procederia con su creacion.
        if (rutaCarpetaJugador.exists() == false) {
            rutaCarpetaJugador.mkdir();
        }

        //Creamos una nueva interfaz de seleccion de archivos, lo utilizaremos para
        //seleccionar donde guardar la partida.
        JFileChooser jFileChooser = new JFileChooser(userDir);

        //Declaramos un entero que guarde la opcion seleccionada en la interfaz de seleccion.
        int returnValue = jFileChooser.showSaveDialog(null);

        //Si despues de seleccionar un archivo, pulsamos el boton de aceptar:
        if (returnValue == JFileChooser.APPROVE_OPTION) {
            //Si el archivo seleccionado ya existiera:
            if (jFileChooser.getSelectedFile().exists()) {

                //Declaramos un entero para que guarde la respuesta sobre si queremos
                //sobrescribir el archivo o no.
                int opcion = JOptionPane.showConfirmDialog(null,
                        "¿Desea sobreescribir el archivo \"" + jFileChooser.getSelectedFile().getName() + "\"?",
                        "¿Desea sobreescribir el archivo \"" + jFileChooser.getSelectedFile().getName() + "\"?",
                        JOptionPane.YES_NO_OPTION);

                //Si la respuesta es afirmativa, llamamos al metodo encargado de
                //guardar las partidas.
                if (opcion == JOptionPane.YES_OPTION) {
                    guardado(jFileChooser.getSelectedFile(), tableroLogico);
                }

            } else {
                //Si el archivo seleccionado no existe ya, directamente llamamos al
                //metodo que se encargar de guardar las partidas.
                guardado(jFileChooser.getSelectedFile(), tableroLogico);
            }
        }
    }

    /**
     * Metodo auxiliar que realiza la parte especifica de la carga de una
     * partida.
     *
     * @param selectedFile El archivo seleccionado para ser cargado como tablero
     * de la partida guardada.
     * @return Tablero logico que representa la partida que se va a cargar.
     * @exception Exception Excepcion en la recuperacion de los datos.
     */
    private TableroLogico cargado(File selectedFile) {
        //Declaramos un tablero logico sin dimensiones, en este tablero sera
        //en el que copiemos el tablero cargado desde un archivo.
        TableroLogico tableroLogico = new TableroLogico(0, 0);
        //Declaramos un flujo que realice las acciones de lectura.
        FileInputStream fis = null;
        //Declaramos un flujo haga un buffer para la entrada de datos.
        BufferedInputStream bis = null;
        //Declaramos un flujo que cargue los objetos serializados.
        ObjectInputStream ois = null;

        //Abrimos un bloque try/catch para gestionar las diferentes excepciones que
        //se pudiesen producir durante el proceso.
        try {
            //Creamos un nuevo flujo para que realice la lectura de la ruta del archivo recibido.
            fis = new FileInputStream(selectedFile);
            //Creamos un nuevo flujo para que cree un buffer de entrada de datos con el flujo anterior.
            bis = new BufferedInputStream(fis);
            //Creamos un nuevo flujo que cargue los objetos serializados con el flujo anterior.
            ois = new ObjectInputStream(bis);
            //Copiamos en el tablero declarado al principio del metodo el tablero obtenido
            //a traves de los flujos creados.
            tableroLogico = (TableroLogico) ois.readObject();
        } catch (Exception e) {
            //Si se produce una excepcion, se muestra un aviso en la consola.
            System.out.println("Error al cargar la partida.");
            //Y se imprime donde se ha producido el error.
            e.printStackTrace();
        }

        return tableroLogico;
    }

    /**
     * Metodo auxiliar que realiza la parte especifica del guardado de una
     * partida.
     *
     * @param selectedFile El archivo seleccionado para ser guardado como
     * tablero de la partida a guardar.
     * @param tableroLogico El tablero a guardar.
     * @exception Exception Excepcion en el guardado de los datos.
     */
    private void guardado(File selectedFile, TableroLogico tableroLogico) {
        //Declaramos un flujo que realice las acciones de escritura.
        FileOutputStream fos = null;
        //Declaramos un flujo haga un buffer para la salida de datos.
        BufferedOutputStream bos = null;
        //Declaramos un flujo que guarde los objetos serializados.
        ObjectOutputStream oos = null;

        //Abrimos un bloque try/catch para gestionar las diferentes excepciones que
        //se pudiesen producir durante el proceso.
        try {
            //Creamos un nuevo flujo para que realice la escritura en la ruta del archivo recibido.
            fos = new FileOutputStream(selectedFile);
            //Creamos un nuevo flujo para que cree un buffer de salida de datos con el flujo anterior.
            bos = new BufferedOutputStream(fos);
            //Creamos un nuevo flujo que guarde los objetos serializados con el flujo anterior.
            oos = new ObjectOutputStream(bos);
            //Indicamos que el tablero logico sera lo que se va a guardar.
            oos.writeObject(tableroLogico);
            //Vaciamos el flujo serializador.
            oos.flush();
            //Y finalmente, lo cerramos para que se guarden los cambios.
            oos.close();
            //Mostramos una ventana emergente con el mensaje de que se realizado el guardado.
            JOptionPane.showMessageDialog(null, "Partida guardada correctamente.");
        } catch (Exception e) {
            //Si se produce una excepcion, se muestra un aviso en la consola.
            System.out.println("Error al guardar la partida.");
            //Y se imprime donde se ha producido el error.
            e.printStackTrace();
        }
    }
}
