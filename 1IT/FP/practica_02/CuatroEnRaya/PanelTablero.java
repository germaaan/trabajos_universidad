package cuatroenraya;

//Clase necesaria para utilizar colores en elementos graficos.
import java.awt.Color;
//Clases necesarias para utilizar objetos graficos.
import java.awt.Graphics;
import java.awt.Graphics2D;
//Clase necesaria para generar figuras con forma de elipse de 2 dimensiones.
import java.awt.geom.Ellipse2D;
//Clase necesaria para generar figuras con forma de linea de 2 dimensiones.
import java.awt.geom.Line2D;
//Clase necesaria para poder utilizar listas ArrayList.
import java.util.ArrayList;
//Clase necesaria para crear una interfaz grafica del tipo panel.
import javax.swing.JPanel;

/**
 * Clase que representa el tablero grafico dentro del cual se desarrollara el
 * juego.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class PanelTablero extends JPanel implements Vista {

    /**
     * Constante que indica la dimension en pixeles de una casilla del tablero.
     */
    public final static int dimensionCasilla = 50;
    //Lista que contiene las lineas del tablero de juego.
    private ArrayList<Line2D.Float> lineasDelimitadoras;
    //Tablero en el que se realizaran los movimientos de forma logica.
    private TableroLogico tableroLogico;
    //Controlador con el que se realizaran los movimientos.
    private Controlador controlador;

    /**
     * Constructor, crea el panel sobre el que se pintaran los movimientos que
     * se realicen de forma logica en el tablero contenido.
     *
     * @param tableroLogico Tablero en el que de forma logica se realizaran los
     * movimientos.
     */
    public PanelTablero(TableroLogico tableroLogico) {

        //Fijamos el color de fondo del tablero en gris claro.
        this.setBackground(Color.LIGHT_GRAY);

        //Creamos la lista de las lineas del tablero.
        this.lineasDelimitadoras = new ArrayList<Line2D.Float>();

        //Llamamos al metodo que se encarga de crear las lineas de tablero, pasandole el
        //numero de filas y columnas del tablero logico.
        crearLineasDelimitadoras(tableroLogico.getFilas(), tableroLogico.getColumnas());

        //Llamamos al metodo que gestiona la creacion de los componentes del tablero.
        this.setTablero(tableroLogico);
    }

    /**
     * Metodo para crear las lineas delimitadoras de las casillas del tablero.
     *
     * @param filas Cantidad de filas a pintar.
     * @param columnas Cantidad de columas a pintar.
     */
    private void crearLineasDelimitadoras(int filas, int columnas) {
        //Se declara un objeto grafico de dos dimensiones linea.
        Line2D.Float linea;
        //Declaramos los enteros que seran las coordenadas de las lineas a crear.
        int xp, yp, xl, yl;

        //Hacemos un bucle para crear todas las lineas verticales.
        for (int i = 0; i < columnas + 1; i++) {
            // Posicion de partida: xp valdra tanto como i*dimensionCasilla
            //                      yp valdra siempre 0
            // Posicion de llegada: xl vale igual que xp
            //                      yl valdra siempre filas*dimensionCasilla
            xp = i * PanelTablero.dimensionCasilla;
            yp = 0;
            xl = xp;
            yl = filas * PanelTablero.dimensionCasilla;

            //Creamos una linea con las coordenadas obtenidas.
            linea = new Line2D.Float(xp, yp, xl, yl);

            //Insertamos la linea en la lista de lineas.
            this.lineasDelimitadoras.add(linea);
        }

        //Hacemos otro bucle para crear todas las lineas horizontales.
        for (int i = 0; i < filas + 1; i++) {
            // Posicion de partida: xp valdra siempre 0
            //                      yp valdra i*dimensionCasilla
            // Posicion de llegada: xl valdra columnas*dimensionCasilla
            //                      yl valdra igual que yp
            xp = 0;
            yp = i * PanelTablero.dimensionCasilla;
            xl = columnas * PanelTablero.dimensionCasilla;
            yl = yp;

            //Creamos una linea con las coordenadas obtenidas.
            linea = new Line2D.Float(xp, yp, xl, yl);

            //Insertamos la linea en la lista de lineas.
            this.lineasDelimitadoras.add(linea);
        }
    }

    /**
     * Metodo que actualiza el tablero cuando se realiza un movimiento.
     */
    public void modelChanged() {
        //Se repinta el tablero.
        this.repaint();
    }

    /**
     * Metodo que pinta las fichas en el tablero.
     *
     * @param g Instancia de la clase que permite realizar operaciones graficas
     * como pueden ser pintar circulos.
     */
    public void paint(Graphics g) {
        //Llamamos al metodo de pintar de la clase superior pasandole el objeto grafico.
        super.paint(g);

        //Declaramos un nuevo objeto grafico que sera una copia del objeto grafico recibido.
        Graphics2D g2 = (Graphics2D) g;
        //Indicamos que color de este objeto grafico sera negro.
        g2.setColor(Color.BLACK);
        //Declaramos un nuevo circulo grafico.
        Ellipse2D.Float circulo;

        //Recorremos la lista de las lineas pintandolas todas.
        for (Line2D.Float linea : this.lineasDelimitadoras) {
            g2.draw(linea);
        }

        //Recorremos todas las casillas del tablero logico.
        for (int i = 0; i < this.tableroLogico.getFilas(); i++) {
            for (int j = 0; j < this.tableroLogico.getColumnas(); j++) {
                //Declaramos un entero que tenga el valor de la casilla.
                int casilla = this.tableroLogico.getTablero()[i][j];

                //Declaramos dos enteros con las coordenadas de la casilla.
                int xSupIzq = j * PanelTablero.dimensionCasilla + 5;
                int ySupIzq = i * PanelTablero.dimensionCasilla + 5;

                //Creamos un nuevo circulo con las coordenadadas y dimensiones de la casilla.
                circulo = new Ellipse2D.Float(xSupIzq, ySupIzq, PanelTablero.dimensionCasilla - 10,
                        PanelTablero.dimensionCasilla - 10);

                //Si el valor de la casilla es el de una ficha roja.
                if (casilla == TableroLogico.FICHA_ROJA) {
                    //La ficha a pintar sera roja.
                    g2.setColor(Color.RED);
                } else {
                    //Si la ficha es azul.
                    if (casilla == TableroLogico.FICHA_AZUL) {
                        //La ficha a pintar sera azul.
                        g2.setColor(Color.BLUE);
                    } else {
                        //En cualquier otro caso, sera una ficha vacia que se pintara de blanco.
                        g2.setColor(Color.WHITE);
                    }
                }

                //Se realiza el pintado del circulo.
                g2.fill(circulo);
            }
        }
    }

    /**
     * Metodo para recrear las lineas delimitadoras de las casillas del tablero
     * cuando este es redimensionado.
     *
     * @param filas Cantidad de filas a pintar.
     * @param columnas Cantidad de columas a pintar.
     */
    public void recrearLineas(int filas, int columnas) {
        //Se crea una nueva lista con las lineas del tablero.
        this.lineasDelimitadoras = new ArrayList<Line2D.Float>();

        //Se declara un objeto grafico de dos dimensiones linea.
        Line2D.Float linea;
        //Declaramos los enteros que seran las coordenadas de las lineas a crear.
        int xp, yp, xl, yl;

        //Hacemos un bucle para crear todas las lineas verticales.
        for (int i = 0; i < columnas + 1; i++) {
            // Posicion de partida: xp valdra tanto como i*dimensionCasilla
            //                      yp valdra siempre 0
            // Posicion de llegada: xl vale igual que xp
            //                      yl valdra siempre filas*dimensionCasilla
            xp = i * PanelTablero.dimensionCasilla;
            yp = 0;
            xl = xp;
            yl = filas * PanelTablero.dimensionCasilla;

            //Creamos una linea con las coordenadas obtenidas.
            linea = new Line2D.Float(xp, yp, xl, yl);

            //Insertamos la linea en la lista de lineas.
            this.lineasDelimitadoras.add(linea);
        }

        //Hacemos otro bucle para crear todas las lineas horizontales.
        for (int i = 0; i < filas + 1; i++) {
            // Posicion de partida: xp valdra siempre 0
            //                      yp valdra i*dimensionCasilla
            // Posicion de llegada: xl valdra columnas*dimensionCasilla
            //                      yl valdra igual que yp
            xp = 0;
            yp = i * PanelTablero.dimensionCasilla;
            xl = columnas * PanelTablero.dimensionCasilla;
            yl = yp;

            //Creamos una linea con las coordenadas obtenidas.
            linea = new Line2D.Float(xp, yp, xl, yl);

            //Insertamos la linea en la lista de lineas.
            this.lineasDelimitadoras.add(linea);
        }
    }

    /**
     * Metodo que asigna al panel del tablero y al controlador de los
     * movimientos el tablero logico sobre el que se realizaran los movimientos
     * y sera la base para pintar el panel del tablero.
     *
     * @param tableroLogico Tablero en el que de forma logica se realizaran los
     * movimientos.
     */
    private void setTablero(TableroLogico tableroLogico) {
        //Copiamos en el tablero logico propio, el tablero logico recibido.
        this.tableroLogico = tableroLogico;

        //Creamos un nuevo controlador pasando el tablero logico.
        this.controlador = new Controlador(tableroLogico);
        //Añadimos un oyente del raton al controlador.
        addMouseListener(this.controlador);

        //Añadimo una vista del tablero al tablero logico.
        this.tableroLogico.addVista(this);

        //Y repintamos el tablero.
        this.repaint();
    }

    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
