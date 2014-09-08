package cuatroenraya;

//Clase necesaria para gestionar la distribucion de los componentes en la interfaz grafica.
import java.awt.BorderLayout;
//Clases necesarias para ejecutar acciones segun eventos de raton.
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
//Clase necesaria para ejectuar acciones segun eventos de teclado.
import java.awt.event.KeyEvent;
//Clase necesaria para representar un archivo con el que el programa trabajara.
import java.io.File;
//Clase necesaria para crear una interfaz grafica del tipo frame.
import javax.swing.JFrame;
//Clases necesarias para agregar diferentes elementos graficos a la interfaz grafica.
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;
//Clases necesarias para crear campos de texto en los que introducir texto que sera usado posteriormente.
import javax.swing.JTextField;
import javax.swing.JPasswordField;
//Clase necesaria para mostrar mensajes y/o introducir valores a traves ventanas emergentes.
import javax.swing.JOptionPane;
//Clase necesaria para obtener la letra pulsada en el teclado.
import javax.swing.KeyStroke;

/**
 * Clase encargada de crear el interfaz grafico del programa y sus menus.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class CuatroEnRaya extends JFrame implements ActionListener {

    /**
     * Constante que indica los pixeles que hay que añadir horizontalmente de
     * forma adicionar cuando se especifique el tamaño de la interfaz grafica.
     */
    private static int offsetHorizontal = 7;
    /**
     * Constante que indica los pixeles que hay que añadir verticalmente de
     * forma adicionar cuando se especifique el tamaño de la interfaz grafica.
     */
    private static int offsetVertical = 55;
    private JFrame jFTablero;
    private TableroLogico tableroLogico;
    private PanelTablero panelTablero;
    private GestionPartidas gestionPartidas;

    /**
     * Constructor, inicializa la interfar grafica y demás componentes de la
     * clase.
     *
     * @param filas Numero de filas que tendra el tablero.
     * @param columnas Numero de columnas que tendra el tablero.
     */
    public CuatroEnRaya(int filas, int columnas) {
        //Creamos el frame que servira de contenedor para toda la interfaz grafica.
        this.jFTablero = new JFrame("Cuatro en raya // German Martinez Maldonado");
        //Con los enteros recibidos como argumentos, creamos el tablero logico sobre
        //el que de forma logica se realizaran los movimientos.
        this.tableroLogico = new TableroLogico(filas, columnas);
        //Creamos el panel que graficamente representara el tablero de juego pasandole
        //el tablero logico.
        this.panelTablero = new PanelTablero(this.tableroLogico);
        //Creamos el gestionador del guardado/cargado de las partidas.
        this.gestionPartidas = new GestionPartidas();
        //Llamamos al metodo que se encarga del acceso/registro de jugadores.
        entradaJugadores();
    }

    /**
     * Metodo que ejecuta la accion asociada a un elemento del programa. Como
     * todas las acciones estan implementadas junto a sus elementos
     * correspondientes, este metodo no es necesario pero es obligatoria su
     * implementacion porque la clase implementa ActionListener.
     *
     * @param e Evento que ha desencadenado que se ejecute la accion.
     */
    public void actionPerformed(ActionEvent e) {
    }

    /**
     * Metodo que controla el acceso de los jugadores al programa.
     */
    private void accesoJugadores() {
        //Declaramos un entero que almacenara el valor de la opcion seleccionada.
        int opcion = 0;
        //Declaramos dos booleanos que serviran como condicion de parada para los
        //bucles necesario para el acceso de un jugador.
        boolean parada = false, error = false;
        //Declaramos dos cadenas de texto para almacenar los valores del nombre de
        //jugador y su password.
        String nombre = "", password = "";
        //Declaramos un campo de texto para introducir el nombre del jugador.
        JTextField campoNombre = new JTextField();
        //Declaramos un campo de password para introducir el password del jugadores.
        JPasswordField campoPassword = new JPasswordField();
        //Declaramos un array de Object en el que incluiremos todo lo que se mostrara
        //en la ventana emergente de acceso de jugadores.
        Object[] contenido = {"Introduzca su nombre de jugador y password: ", " ", "Nombre:",
            campoNombre, "Password:", campoPassword};
        //Declaramos un array de Object en el que incluiremos las opciones que se mostraran
        //en la ventana emergente de acceso de jugadores.
        Object acciones[] = {"Aceptar", "Volver"};

        //Iniciamos un bucle para realizar un correcto acceso de jugadores.
        do {
            //Iniciamos un bucle para realizar una correcta introduccion del nombre
            //del jugador y su password.
            do {
                //Si en la anterior iteracion del bucle se ha producido un error, se muestra
                //un mensaje de advertencia.
                if (error == true) {
                    JOptionPane.showMessageDialog(null, "Es obligatorio rellenar todos los campos.");
                }

                //Aparece una ventana en la que se podra acceder mediante un nombre de jugador
                //y un password validos o volver al menu principal.
                opcion = JOptionPane.showOptionDialog(null, contenido, "Acceso de jugadores",
                        JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, acciones, contenido);

                //Si pulsamos la opcion de "Volver" o cerramos la ventana, volvemos al menu principal.
                if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                    this.entradaJugadores();
                    break;
                }

                //Almacenamos en las cadenas de texto declaradas al principio del metodo los valores
                //introducidos como nombre de jugador y password.
                nombre = campoNombre.getText().toString();
                password = campoPassword.getText().toString();

                //Si el campo de nombre o el de password estan vacios, esto significara que se ha
                //producido un error.
                if ((nombre.isEmpty()) || (password.isEmpty())) {
                    error = true;
                } else {
                    error = false;
                }
            } while (error == true);

            //Comprobamos si el jugador con el que estamos intentando acceder existe o no en
            //la base de datos. Si no existe, se mostrara una mensaje por pantalla.
            if (this.tableroLogico.getGestionJugadores().comprobarJugadores(nombre) == false) {
                JOptionPane.showMessageDialog(null, "El jugador \"" + nombre + "\" no existe.");
            } else {

                //Si existe, se procedera a comprobar si el password introducido es el correspondiente
                //a dicho jugador. Volviendose a mostrar un mensaje en caso contrario.
                if (this.tableroLogico.getGestionJugadores().comprobarPassword(password) == false) {
                    JOptionPane.showMessageDialog(null, "El password no corresponde al jugador \""
                            + nombre + "\".");
                } else {

                    //Mostramos las estadisticas de las partidas jugadas por el jugador, dando opcion
                    //de ser reiniciadas.
                    int seleccion = JOptionPane.showOptionDialog(null,
                            this.tableroLogico.getGestionJugadores().obtenerEstadisticas(nombre)
                            + "\n\n¿Desea borrar estas estadisticas?", "Estadisticas",
                            JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                            new Object[]{"Si", "No"}, "No");

                    //Si las estadisticas son borradas:
                    if (seleccion == JOptionPane.YES_OPTION) {
                        //Reiniciamos las estadisticas del jugador introducido.
                        this.tableroLogico.getGestionJugadores().reiniciarPartidas(nombre);
                        //Mostramos un mensaje informando de lo que hemos hecho.
                        JOptionPane.showMessageDialog(null, "Estadisticas del jugador \"" + nombre + "\" borradas."
                                + "\nSuerte en la proxima partida.");
                        //Indicamos que la nueva partida va a ser jugada por el jugador introducido.
                        this.tableroLogico.setNombreJugador(nombre);
                        //Y finalmente creamos la interfaz grafica del programa y salimos.
                        crearInterfaz();
                        break;
                    } else {
                        //Si las estadisticas no son borradas:
                        if ((seleccion == JOptionPane.NO_OPTION) || (seleccion == JOptionPane.CLOSED_OPTION)) {
                            //Indicamos que la nueva partida va a ser jugada por el jugador introducido.
                            this.tableroLogico.setNombreJugador(nombre);
                            //Y creamos la interfaz grafica del programa y salimos.
                            crearInterfaz();
                            break;
                        }
                    }
                }
            }
        } while (parada == false);
    }

    /**
     * Metodo que carga partidas previamente guardadas.
     *
     * @return Verdadero si se ha cargado la partida o falso en caso contrario.
     */
    private boolean cargarTablero() {
        //Declaramos un booleano que indicara si la partida ha sido cargada correctamente.
        boolean estado = false;
        //Declaramos un tablero logico que sera el que recibira el tablero guardado.
        TableroLogico tableroCargado = null;

        //No podremos cargar una partida mientras que sea el turno del ordenador.
        if (this.tableroLogico.getJugadorActual() == TableroLogico.JUGADOR_ORDENADOR) {
            JOptionPane.showMessageDialog(null, "Espere a que termine el turno del ordenador para cargar.");
        } else {
            //Cargamos un tablero desde un archivo, pasandole el nombre del jugador actual para poder
            //comprobar si el tablero a cargar pertenece al jugador.
            tableroCargado = this.gestionPartidas.cargarTablero(this.tableroLogico.getNombreJugador());

            //Si el tablero cargado es un tablero vacio, se informara de que no se ha cargado la partida.
            if ((tableroCargado.getFilas() == 0) && (tableroCargado.getColumnas() == 0)) {
                JOptionPane.showMessageDialog(null, "No se ha cargado ningun tablero.");
            } else {
                //Si se ha obtenido un tablero valido, habra que comprobar que perternece al jugador
                //que ha mandado cargar dicho tablero. Si no le pertenece, no se cargara.
                if (this.tableroLogico.getNombreJugador().equals(tableroCargado.getNombreJugador()) == false) {
                    JOptionPane.showMessageDialog(null, "La partida seleccionada pertenece a otro jugador."
                            + "\n\nSolo se pueden cargar partidas guardadas por"
                            + "\nel propio jugador.");
                    return estado;
                } else {
                    //En caso de que pertenezca al jugador, primero se vuelven a pintar las lineas del tablero,
                    //por si este fuera de una dimensiones diferentes al anterior.
                    this.panelTablero.recrearLineas(tableroCargado.getFilas(), tableroCargado.getColumnas());
                    //Copiamos todos el tablero logico cargado en el tablero logico actual.
                    this.tableroLogico.recrearTablero(tableroCargado);
                    //Indicamos que el tablero se ha cargado correctamente.
                    estado = true;
                    //Indicamos que es una partida nueva, para que al cargar sea el turno de tirar del jugador.
                    this.tableroLogico.setTipoPartida(TableroLogico.PARTIDA_NUEVA);
                }
            }
        }
        //Devolvemos si el tablero se ha cargado correctamente o no.
        return estado;
    }

    /**
     * Metodo que crea la interfaz del programa y sus menus.
     */
    private void crearInterfaz() {
        //Declaramos todos los componentes necesarios para crear la interfaz grafica de los menus.
        //Barra de menu.
        JMenuBar barraMenu;
        //Menus.
        JMenu menuArchivo, menuAyuda;
        //Opciones de menu.
        JMenuItem nuevo, guardar, cargar, redimensionar, dificultad, salir, explicacion, acercaDe;
        //Separadores de opciones.
        JSeparator separador1, separador2;

        //Inicializamos una nueva barra de menu.
        barraMenu = new JMenuBar();

        //Inicializamos un nuevo menu, el menu "Archivo".
        menuArchivo = new JMenu("Archivo");
        //Indicamos la tecla de acceso rapido.
        menuArchivo.setMnemonic(KeyEvent.VK_A);
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicho menu.
        menuArchivo.getAccessibleContext().setAccessibleDescription("Menú principal del programa.");
        //Insertamos el menu creado a la barra de menus.
        barraMenu.add(menuArchivo);

        //Inicializamos un nuevo menu, el menu "Ayuda".
        menuAyuda = new JMenu("Ayuda");
        //Indicamos la tecla de acceso rapido.
        menuAyuda.setMnemonic(KeyEvent.VK_Y);
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicho menu.
        menuAyuda.getAccessibleContext().setAccessibleDescription(
                "Menú que proporciona información sobre el programa.");
        //Insertamos el menu creado en la barra de menus.
        barraMenu.add(menuAyuda);

        //Inicializamos una nueva opcion de menu, la opcion "Nuevo".
        nuevo = new JMenuItem("Nuevo", KeyEvent.VK_N);
        //Indicamos las teclas de acceso rapido.
        nuevo.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        nuevo.getAccessibleContext().setAccessibleDescription("Inicia una partida nueva.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        nuevo.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Si el tablero no tiene dimensiones, se le dara una nuevas dimensiones.
                if ((tableroLogico.getFilas() == 0) && (tableroLogico.getColumnas() == 0)) {
                    redimensionarTablero();
                } else {
                    //En caso contrario, se dara la opcion de iniciar una nueva partida.
                    int opcionNuevo = JOptionPane.showConfirmDialog(null,
                            "¿Iniciar una nueva partida?",
                            "Partida nueva",
                            JOptionPane.YES_NO_OPTION);
                    //Si la respuesta es afirmativa, se reiniciara el tablero.
                    if (opcionNuevo == JOptionPane.YES_OPTION) {
                        reiniciarTablero();
                    }
                }
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(nuevo);

        //Inicializamos una nueva opcion de menu, la opcion "Guardar".
        guardar = new JMenuItem("Guardar", KeyEvent.VK_G);
        //Indicamos las teclas de acceso rapido.
        guardar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_G, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        guardar.getAccessibleContext().setAccessibleDescription("Guarda la partida actual.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        guardar.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Guarda el tablero actual en un archivo.
                grabarTablero();
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(guardar);

        //Inicializamos una nueva opcion de menu, la opcion "Cargar".
        cargar = new JMenuItem("Cargar", KeyEvent.VK_C);
        //Indicamos las teclas de acceso rapido.
        cargar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.0
        cargar.getAccessibleContext().setAccessibleDescription("Carga una partida anterior.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        cargar.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Carga un tablero guardado anteriormente.
                cargarTablero();
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(cargar);

        //Inicializamos un nuevo separador de opciones.
        separador1 = new JSeparator();
        //Lo insertamos en el menu "Archivo".
        menuArchivo.add(separador1);

        //Inicializamos una nueva opcion de menu, la opcion "Redimensionar tablero".
        redimensionar = new JMenuItem("Redimensionar tablero", KeyEvent.VK_R);
        //Indicamos las teclas de acceso rapido.
        redimensionar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        redimensionar.getAccessibleContext().setAccessibleDescription(
                "Redimensiona el tablero actual de juego.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        redimensionar.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Redimensiona el tablero actual.
                redimensionarTablero();
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(redimensionar);

        //Inicializamos una nueva opcion de menu, la opcion "Cambiar dificultad".
        dificultad = new JMenuItem("Cambiar dificultad", KeyEvent.VK_D);
        //Indicamos las teclas de acceso rapido.
        dificultad.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        dificultad.getAccessibleContext().setAccessibleDescription(
                "Cambia la dificultad actual de juego.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        dificultad.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Cambia la dificultad del juego actual.
                seleccionarDificultad();
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(dificultad);

        //Inicializamos un nuevo separador de opciones.
        separador2 = new JSeparator();
        //Lo insertamos en el menu "Archivo".
        menuArchivo.add(separador2);

        //Inicializamos una nueva opcion de menu, la opcion "Salir".
        salir = new JMenuItem("Salir", KeyEvent.VK_S);
        //Indicamos las teclas de acceso rapido.
        salir.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        salir.getAccessibleContext().setAccessibleDescription("Cierra el programa.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        salir.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Cierra el programa.
                salir();
            }
        });
        //Insertamos la opcion en el menu "Archivo".
        menuArchivo.add(salir);

        //Inicializamos una nueva opcion de menu, la opcion "Explicacion".
        explicacion = new JMenuItem("Explicacion", KeyEvent.VK_E);
        //Indicamos las teclas de acceso rapido.
        explicacion.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_E, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        explicacion.getAccessibleContext().setAccessibleDescription(
                "Explica el funcionamiento del juego.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        explicacion.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Muestra una ventana emergente con la explicacion del juego.
                JOptionPane.showMessageDialog(null,
                        "Explicacion de Cuatro en Raya"
                        + "\n\nEs un juego para dos jugadores en el que se turnan para dejar caer sus fichas de "
                        + "\ncolores desde la parte superior en una de las columnas. Las piezas caen hacia "
                        + "\nabajo, ocupando el espacio vacio mas bajo de la columna. El objetivo del juego "
                        + "\nes conectar cuatro de una de las fichas propias del mismo color junto a la otra "
                        + "\nvertical, horizontal o diagonal antes de un oponente puede hacerlo.");
            }
        });
        //Insertamos la opcion en el menu "Ayuda".
        menuAyuda.add(explicacion);

        //Inicializamos una nueva opcion de menu, la opcion "Acerca de".
        acercaDe = new JMenuItem("Acerca de", KeyEvent.VK_D);
        //Indicamos las teclas de acceso rapido.
        acercaDe.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D, ActionEvent.CTRL_MASK));
        //Indicamos el mensaje que se mostrara si nos detenemos sobre dicha opcion.
        acercaDe.getAccessibleContext().setAccessibleDescription(
                "Proporciona información sobre la aplicación y el autor.");
        //Indicamos que acciones se realizaran cuando se seleccion esta opcion.
        acercaDe.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                //Muestra una ventana emergente con informacion sobre el programa y su creador.
                JOptionPane.showMessageDialog(null, "Cuatro en raya. Version en desarrollo"
                        + "\n\nDesarrollado por German Martinez Maldonado."
                        + "\n2010 ®");
            }
        });
        //Insertamos la opcion en el menu "Ayuda".
        menuAyuda.add(acercaDe);

        //Declaramos e inicializamos un nuevo gestor de la distribucion de los elementos.
        setLayout(new BorderLayout());

        //Insertamos la barra de menu en la zona norte.
        this.jFTablero.getContentPane().add(barraMenu, BorderLayout.NORTH);
        //Insertamos el panel de juego de forma que ocupe el resto del espacio.
        this.jFTablero.getContentPane().add(this.panelTablero, BorderLayout.CENTER);

        //Empaquetamos todos los componentes para que se le de al frame la dimension adecuada.
        this.jFTablero.pack();
        //Indicamos que el frame sea visible.
        this.jFTablero.setVisible(true);
        //Su tamaño por defecto sea maximizado a pantalla completa.
        this.jFTablero.setExtendedState(MAXIMIZED_BOTH);
        //No se puede redimensionar.
        this.jFTablero.setResizable(false);
        //No se pueda cerrar desde el boton "X" de la esquina superior derecha.
        this.jFTablero.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);

        //Llamamos al metodo para iniciar el juego.
        iniciarJuego();

        //Se informa de que el primero en tirar es el jugador.
        JOptionPane.showMessageDialog(null, "Turno de mover del jugador.");
    }

    /**
     * Metodo que da las opciones que puede realizar el jugador al iniciar el
     * programa.
     */
    private void entradaJugadores() {
        //Declaramos un entero que almacenara el valor de la opcion seleccionada para
        //iniciar al juego.
        int opcion = JOptionPane.showOptionDialog(null, "Bienvenido al juego del Cuatro en Raya. "
                + "\n\nEs necesario estar registrado en la base de datos para poder acceder. "
                + "\nAcceda con su nombre de jugador o registrese.",
                "Bienvenido", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                new Object[]{"Acceder", "Registrarse", "Salir"}, "Acceder");

        //Si seleccionamos la opcion de "Acceder", se llamara al metodo para iniciar el juego
        //mediante un nombre de jugador y password existentes en la base de datos.
        if (opcion == JOptionPane.YES_OPTION) {
            accesoJugadores();
        } else {
            //Si la opcion es "Registrarse", se llamara al metodo para iniciar el juego mediante
            //el registro de un nuevo nombre de jugador y password.
            if (opcion == JOptionPane.NO_OPTION) {
                registroJugadores();
            } else {
                //Declaramos un entero para almacenar en el si decidimos salir del juego o no.
                int opcionNuevo = JOptionPane.showConfirmDialog(null,
                        "¿Salir del juego?",
                        "Salir",
                        JOptionPane.YES_NO_OPTION);

                //Si aceptamos el salir del juego, se saldra de la aplicacion.
                if (opcionNuevo == JOptionPane.YES_OPTION) {
                    System.exit(0);
                } else {
                    //Si no se acepta, se vuelve a repetir todo el proceso anterior.
                    entradaJugadores();
                }
            }
        }
    }

    /**
     * Metodo que guarda la partidas en curso.
     */
    private void grabarTablero() {
        //No podremos guardar una partida mientras que sea el turno del ordenador.
        if (this.tableroLogico.getJugadorActual() == TableroLogico.JUGADOR_ORDENADOR) {
            JOptionPane.showMessageDialog(null, "Espere a que termine el turno del ordenador para guardar.");
        } else {
            //En caso contrario, llamaremos al metodo que se encarga de guardar las partidas,
            //pasandole el tablero logico para que lo guarde.
            this.gestionPartidas.grabarTablero(this.tableroLogico);
        }
    }

    /**
     * Metodo que da las opciones que puede realizar el jugador al iniciar una
     * nueva partida.
     */
    private void iniciarJuego() {
        //Declaramos un entero que almacenara el valor de la opcion seleccionada.
        int opcion = 0;
        //Declaramos un booleano que indicara si se ha cargado la partida o no.
        boolean carga = false;
        //Declaramos un array de Object en el que incluiremos las opciones que se mostraran
        //en la ventana emergente de inicio del juego.
        Object acciones[] = {"Nueva partida", "Cargar Partida", "Salir"};

        //Aparece una ventana en la que se nos daran las opciones de iniciar una nueva partida,
        //cargar una partida existente o salir del juego.
        opcion = JOptionPane.showOptionDialog(null,
                "Bienvenido a Cuatro en Raya.\n¿Que desea hacer?", "Inicio",
                JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                acciones, "Nueva partida");

        //Si iniciamos una nueva partida, se llamara al metodo para seleccionar el nivel de dificultad,
        //necesario para iniciar una nueva partida.
        if (opcion == JOptionPane.YES_OPTION) {
            seleccionarDificultad();
        } else {

            //En caso contrario, si seleccionamos cargar una partida guardada anteriormente.
            if (opcion == JOptionPane.NO_OPTION) {
                //Almacenaremos en el booleano el resultado de si ha sido posible cargar la partida.
                carga = cargarTablero();
                //Si no se ha podido cargar la partida, volvera a aparecer la misma ventana con las
                //opciones anteriores.
                if (carga == false) {
                    iniciarJuego();
                }
            } else {

                //Se seleccionamos salir del juego o cerramos la ventana, nos preguntara si
                //queremos salir de la aplicacion.
                if ((opcion == JOptionPane.CANCEL_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                    int opcionNuevo = JOptionPane.showConfirmDialog(null,
                            "¿Salir del juego?",
                            "Salir",
                            JOptionPane.YES_NO_OPTION);

                    //Si aceptamos, saldremos de la aplicacion.
                    if (opcionNuevo == JOptionPane.YES_OPTION) {
                        System.exit(0);
                    } else {
                        //Si no aceptamos, volveremos a obtener la ventana con las opciones anteriores.
                        iniciarJuego();
                    }
                }
            }
        }
    }

    /**
     * Metodo para redimensionar el tablero de juego.
     *
     * @exception NumberFormatException El valor introducido no es numerico.
     */
    private void redimensionarTablero() {
        //Declaramos un booleano que almacenara el valor necesario para comprobar si se ha
        //producido algun error al introducir las dimensiones del tablero.
        boolean error = false;
        //Declaramos cuatro enteros, los dos primeros seran usador para almacenar las opciones
        //seleccionadas por el jugador y los dos ultimos para indicar las dimensiones del tablero.
        int opcion = 0, seleccion = 0, filas = 0, columnas = 0;
        //Declaramos un campo de texto para introducir las filas.
        JTextField campoFilas = new JTextField();
        //Declaramos un campo de texto para introducir las columnas.
        JTextField campoColumnas = new JTextField();
        //Declaramos un array de Object en el que incluiremos todo lo que se mostrara
        //en la ventana emergente de redimensionamiento del tablero.
        Object[] valorDimension = {"Introduzca las nuevas dimensiones del tablero"
            + "\n(el tablero mas comun para jugar es de 6x7):"
            + "\n\n\tLas filas deben tener un valor entre 6 y 8: ", campoFilas,
            "\tLas columnas deben tener un valor entre 7 y 10: ", campoColumnas};
        //Declaramos un array de Object en el que incluiremos las opciones que se mostraran
        //en la ventana emergente de redimensionamiento del tablero.
        Object acciones[] = {"Aceptar", "Volver"};

        //No podremos redimensionar el tablero mientras que sea el turno del ordenador.
        if (this.tableroLogico.getJugadorActual() == TableroLogico.JUGADOR_ORDENADOR) {
            JOptionPane.showMessageDialog(null, "Espere a que termine el turno del ordenador para redimensionar.");
        } else {
            //Dependiendo de si el tablero tiene unas dimensiones distintas a 0 o no, se indicara de una
            //forma distinta que se va a redimensionar el tablero.
            if ((this.tableroLogico.getFilas() != 0) && (this.tableroLogico.getColumnas() != 0)) {
                opcion = JOptionPane.showOptionDialog(null,
                        "¿Redimensionar el tablero?",
                        "Redimensionar tablero",
                        JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                        new Object[]{"Si", "No"}, "No");
            } else {
                opcion = JOptionPane.showOptionDialog(null,
                        "Para comenzar a jugar debe indicar"
                        + "\nlas dimensiones del tablero.", "Iniciar tablero",
                        JOptionPane.YES_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                        new Object[]{"Continuar"}, "Continuar");
            }

            //Como el tablero tiene que tener unas dimensiones minimas, si se cierra la ventana sin
            //introducir las dimensiones, se advertira y se volveran a pedir las dimensiones.
            if (opcion == JOptionPane.CLOSED_OPTION) {
                JOptionPane.showMessageDialog(null, "Es necesario indicar las dimensiones del"
                        + "\ntablero para iniciar la partida.");
                redimensionarTablero();
            } else {

                //Si se procede a redimensionar el tablero, se iniciara un bucle para solo se
                //puedan introducir unas dimensiones validas.
                if (opcion == JOptionPane.YES_OPTION) {
                    do {
                        //Abrimos un bloque try-catch, para que no haya problema con la introduccion
                        //de caracteres en lugar de numeros.
                        try {
                            //Aparece una nueva ventana en la que se deben introducir las dimensiones
                            //nuevas del tablero.
                            seleccion = JOptionPane.showOptionDialog(null, valorDimension,
                                    "Redimensionando tablero", JOptionPane.YES_NO_OPTION,
                                    JOptionPane.QUESTION_MESSAGE, null, acciones, valorDimension);

                            //Si se cierra la ventana o no se acepta la introduccion de las dimensiones,
                            //volvera a aparecer la ventana anterior realizando la peticion.
                            if ((seleccion == JOptionPane.NO_OPTION) || (seleccion == JOptionPane.CLOSED_OPTION)) {
                                redimensionarTablero();
                                break;
                            } else {

                                //Si las dimensiones son aceptadas:
                                if (seleccion == JOptionPane.YES_OPTION) {
                                    //Se convierten los valores introducidos en valores enteros.
                                    filas = Integer.parseInt(campoFilas.getText());
                                    columnas = Integer.parseInt(campoColumnas.getText());
                                    //Se comprueba que las filas y las columnas introducidas se
                                    //encuentren en el intervalo indicado.
                                    if ((filas < 6) || (filas > 8)) {
                                        error = true;
                                    } else {
                                        if ((columnas < 7) || (columnas > 10)) {
                                            error = true;
                                        } else {
                                            error = false;
                                        }
                                    }

                                    //Si no se ha producido ningun error en el tramo anterior:
                                    if (error == false) {
                                        //Se modifica la dimension de la ventana de la interfaz grafica.
                                        this.jFTablero.setSize((columnas * PanelTablero.dimensionCasilla)
                                                + CuatroEnRaya.offsetHorizontal,
                                                (filas * PanelTablero.dimensionCasilla)
                                                + CuatroEnRaya.offsetVertical);
                                        //Cambian las dimensiones del tablero logico.
                                        this.tableroLogico.cambiarDimensiones(filas, columnas);
                                        //Se vuelven a pintar las lineas del tablero con las nuevas dimensiones.
                                        this.panelTablero.recrearLineas(filas, columnas);
                                        break;
                                    }
                                }
                            }
                            //En caso que se produzca un error en el momento de la conversion de los
                            //valores introducidos a enteros:
                        } catch (NumberFormatException nfe) {
                            //Almacenamos que se ha cometido un error.
                            error = true;
                            //Y se avisa al jugador por pantalla.
                            JOptionPane.showMessageDialog(null, "El valor introducido en al menos uno"
                                    + "\nde los campos, no es numerico");
                        }
                    } while (error == true);
                }
            }
        }
    }

    /**
     * Metodo para realizar el registro de nuevos jugador, necesario para que
     * puedan acceder al programa.
     */
    private void registroJugadores() {
        //Declaramos un entero que almacenara el valor de la opcion seleccionada.
        int opcion = 0;
        //Declaramos dos booleanos que serviaran como condicion de parada para los
        //bucles necesario para el registro de un jugador.
        boolean parada = false, error = false;
        //Declaramos tres cadenas de texto para almacenar los valores del nombre de
        //jugador, su password y la comprobacion de su password.
        String nombre = "", password = "", password2 = "";
        //Declaramos un campo de texto para introducir el nombre del jugador.
        JTextField campoNombre = new JTextField();
        //Declaramos un campo de password para introducir el password del jugador.
        JPasswordField campoPassword = new JPasswordField();
        //Declaramos un campo de password para introducir la comprobacion del password.
        JPasswordField campoPassword2 = new JPasswordField();
        //Declaramos un array de Object en el que incluiremos todo lo que se mostrara
        //en la ventana emergente de registro de jugadores.
        Object[] contenido = {"Introduzca su nombre de jugador y password",
            "(minimo 4 y maximo 8 caracteres cada uno):", " ", "Nombre: ", campoNombre, " ", "Password: ",
            campoPassword, "Verificacion de password: ", campoPassword2};
        //Declaramos un array de Object en el que incluiremos las opciones que se mostraran
        //en la ventana emergente de registro de jugadores.
        Object acciones[] = {"Aceptar", "Volver"};

        //Iniciamos un bucle para realizar un correcto registro de jugadores.
        do {
            //Iniciamos un bucle para realizar una correcta introduccion del nombre
            //del jugador, su password y la comprobacion de su password.
            do {
                //Si en la anterior iteracion del bucle se ha producido un error, se muestra
                //un mensaje de advertencia.
                if (error == true) {
                    JOptionPane.showMessageDialog(null, "Es obligatorio rellenar todos los campos y"
                            + "\nninguno de los valores introducidos puede"
                            + "\nser menor de 4 o mayor de 8 caracteres.");
                }

                //Aparece una ventana en la que se podremos realizar el registro del jugador o bien,
                //volver al menu principal.
                opcion = JOptionPane.showOptionDialog(null, contenido, "Registro de jugadores",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.QUESTION_MESSAGE, null, acciones, contenido);

                //Si pulsamos la opcion de "Volver" o cerramos la ventana, volvemos al menu principal.
                if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                    this.entradaJugadores();
                    break;
                }

                //Almacenamos en las cadenas de texto declaradas al principio del metodo los valores
                //introducidos como nombre de jugador, password y comprobacion del password.
                nombre = campoNombre.getText().toString();
                password = campoPassword.getText().toString();
                password2 = campoPassword2.getText().toString();

                //Si alguno de los campos se encuentra vacio, significara que se habra producido
                //un error.
                if ((nombre.isEmpty()) || (password.isEmpty()) || (password2.isEmpty())) {
                    error = true;
                } else {

                    //Comprobamos que los valores introducidos tenga una longitud valida.
                    if ((nombre.length() < 4) || (password.length() < 4) || (password2.length() < 4)) {
                        error = true;
                    } else if ((nombre.length() > 8) || (password.length() > 8) || (password2.length() > 8)) {
                        error = true;
                    } else {
                        error = false;
                    }
                }
            } while (error == true);

            //Si los password introducidos no coinciden, se mostrara una advertencia por pantalla.
            if (password.equals(password2) == false) {
                JOptionPane.showMessageDialog(null, "Los password introducidos no coinciden.");
            } else {

                //Comprobamos si el nombre de jugador que estamos intentando registrar, existe o no
                //en la base de datos. Si existe, se advertira al usuario por pantalla.
                if (this.tableroLogico.getGestionJugadores().comprobarJugadores(nombre) == true) {
                    JOptionPane.showMessageDialog(null, "Ya existe el jugador \"" + nombre + "\".");
                } else {
                    //En caso de que no exista, agregamos el jugador con los datos introducidos a la
                    //base de datos.
                    this.tableroLogico.getGestionJugadores().addJugador(new Jugador(nombre, password));
                    //Creamos una carpeta con su nombre en el directorio de trabajo, para que tenga
                    //mayor facilidad a la hora de organizar sus partidas guardadas.
                    //Declaramos una cadena de texto con la ruta que tendra la carpeta.
                    String path = System.getProperty("user.dir") + java.io.File.separatorChar + nombre;
                    //Declaramos un archivo que contendra dicha ruta.
                    File rutaCarpetaJugador = new File(path);
                    //Finalmente creamos la carpeta en la ruta indicada.
                    rutaCarpetaJugador.mkdir();
                    //Realizamos un guardado de la base de datos.
                    this.tableroLogico.getGestionJugadores().guardarJugadores();
                    //Damos la bienvenida al jugador creado antes de que se inicie su partida.
                    JOptionPane.showMessageDialog(null, "Bienvenido, " + nombre
                            + ".\nSuerte en la primera partida.");
                    //Indicamos que la nueva partida va a ser jugada por el jugador introducido.
                    this.tableroLogico.setNombreJugador(nombre);
                    //Y finalmente creamos la interfaz grafica del programa y salimos.
                    crearInterfaz();
                    break;
                }
            }
        } while (parada == false);
    }

    /**
     * Metodo para reiniciar la partida.
     */
    private void reiniciarTablero() {
        //No podremos reiniciar una partida mientras que sea el turno del ordenador.
        if (this.tableroLogico.getJugadorActual() == TableroLogico.JUGADOR_ORDENADOR) {
            JOptionPane.showMessageDialog(null, "Espere a que termine el turno del ordenador para redimensionar.");
        } else {
            //En caso contrario, llamamos al metodo de reiniciar el tablero.
            this.tableroLogico.vaciarTablero();
            //Mostramos por pantalla que es el turno del jugador.
            JOptionPane.showMessageDialog(null, "Turno de mover del jugador.");
        }
    }

    /**
     * Metodo para salir del programa.
     */
    private void salir() {
        //Declaramos un entero que almacenara la respuesta a la pregunta de si queremos
        //salir del juego.
        int opcionNuevo = JOptionPane.showConfirmDialog(null,
                "¿Salir del juego?",
                "Salir",
                JOptionPane.YES_NO_OPTION);

        //Si la opcion eligida ha sido si.
        if (opcionNuevo == JOptionPane.YES_OPTION) {
            //Realizamos un guardado de la base de datos.
            this.tableroLogico.getGestionJugadores().guardarJugadores();
            //Salimos de la aplicacion.
            System.exit(0);
        }
    }

    /**
     * Metodo para seleccionar la dificultad de la partida actual.
     */
    private void seleccionarDificultad() {
        //Declaramos dos enteros que almaceran las opciones seleccionadas.
        int opcion = 0, seleccion = 0;
        //Declaramos una array de Object con las diferentes tipo de dificultades
        //que se podran seleccionar.
        Object acciones[] = {"Iniciado", "Medio", "Avanzado"};

        //No podremos cambiar la dificultad del juego, mientras que sea el turno del ordenador.
        if (this.tableroLogico.getJugadorActual() == TableroLogico.JUGADOR_ORDENADOR) {
            JOptionPane.showMessageDialog(null, "Espere a que termine el turno del ordenador para cambiar "
                    + "la dificultad.");
        } else {
            //En caso contrario, comprobamos si es el tablero sin dimensiones de una partida nueva.
            //Esto es para mostrar un mensaje diferente dependiendo del tipo de partida en juego.
            if ((this.tableroLogico.getFilas() == 0) && (this.tableroLogico.getColumnas() == 0)) {
                //Aparece una ventana con las diferentes dificultades que podemos seleccionar para el juego.
                opcion = JOptionPane.showOptionDialog(null,
                        "Seleccione la dificultad que tendra la partida contra el ordenador:", "Seleccion "
                        + "dificultad",
                        JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                        acciones, "Medio");

                //En caso que cerremos la ventana sin seleccionar ninguna dificultad:
                if (opcion == JOptionPane.CLOSED_OPTION) {
                    //Se muestra la advertencia por pantalla al jugador.
                    JOptionPane.showMessageDialog(null, "Es obligatorio seleccionar uno de los niveles de "
                            + "dificultad.");
                    //Se vuelve a iniciar la seleccion de dificultad.
                    seleccionarDificultad();
                } else if (opcion == JOptionPane.YES_OPTION) {
                    //Si se ha seleccionado la primera opcion, esta corresponde el nivel mas facil.
                    this.tableroLogico.setDificultad(TableroLogico.NIVEL_INICIADO);
                    //Y se llama al redimensionador, para darle una dimension al tablero y asi
                    //poder iniciar la partida.
                    redimensionarTablero();

                } else {

                    if (opcion == JOptionPane.NO_OPTION) {
                        //Si se ha seleccionado la segunda opcion, esta corresponde el nivel intermedio.
                        this.tableroLogico.setDificultad(TableroLogico.NIVEL_MEDIO);
                        //Y se llama al redimensionador, para darle una dimension al tablero y asi
                        //poder iniciar la partida.
                        redimensionarTablero();
                    } else {
                        //Por eliminacion, la opcion seleccionada sera la tercera, esta corresponde
                        //el nivel mas dificil.
                        this.tableroLogico.setDificultad(TableroLogico.NIVEL_AVANZADO);
                        //Y se llama al redimensionador, para darle una dimension al tablero y asi
                        //poder iniciar la partida.
                        redimensionarTablero();
                    }
                }

            } else {
                //Preguntamos si queremos cambiar el nivel de dificultad.
                seleccion = JOptionPane.showOptionDialog(null,
                        "¿Cambiar el nivel de dificultad?",
                        "Seleccionar dificultad",
                        JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                        new Object[]{"Si", "No"}, "No");

                //Si la opcion seleccionada es "Si":
                if (seleccion == JOptionPane.YES_OPTION) {
                    //Aparece una ventana con las diferentes dificultades que podemos seleccionar para el juego.
                    opcion = JOptionPane.showOptionDialog(null,
                            "Seleccione la dificultad que tendra la partida contra el ordenador:", "Seleccion "
                            + "dificultad",
                            JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null,
                            acciones, "Medio");

                    //Si se ha seleccionado la primera opcion, esta corresponde el nivel mas facil.
                    if (opcion == JOptionPane.YES_OPTION) {
                        this.tableroLogico.setDificultad(TableroLogico.NIVEL_INICIADO);
                        //Y se llama al redimensionador, para darle una dimension al tablero y asi
                        //poder iniciar la partida.
                        reiniciarTablero();

                    } else {

                        //Si se ha seleccionado la segunda opcion, esta corresponde el nivel intermedio.
                        if (opcion == JOptionPane.NO_OPTION) {
                            this.tableroLogico.setDificultad(TableroLogico.NIVEL_MEDIO);
                            //Y se llama al redimensionador, para darle una dimension al tablero y asi
                            //poder iniciar la partida.
                            reiniciarTablero();
                        } else {
                            //Por eliminacion, la opcion seleccionada sera la tercera, esta corresponde
                            //el nivel mas dificil.
                            this.tableroLogico.setDificultad(TableroLogico.NIVEL_AVANZADO);
                            //Y se llama al redimensionador, para darle una dimension al tablero y asi
                            //poder iniciar la partida.
                            reiniciarTablero();
                        }
                    }
                }
            }
        }
    }

    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 312, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Metodo principal del proyecto.
     *
     * @param args Argumentos que recibe el metodo principal justo en su momento
     * de ejecucion.
     */
    public static void main(String args[]) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {

            public void run() {
                //Creamos un objeto de clase CuatroEnRaya para que se comience la aplicacion.
                CuatroEnRaya juego = new CuatroEnRaya(0, 0);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
