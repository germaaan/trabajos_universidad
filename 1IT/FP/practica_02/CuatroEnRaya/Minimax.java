package cuatroenraya;

//Clase necesaria para poder utilizar listas ArrayList.
import java.util.ArrayList;

/**
 * Clase encargada de gestionar los movimientos que realice el ordenador durante
 * el juego.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 07/06/10
 */
public class Minimax extends Thread {

    //Declaramos un entero que correspondera al nivel de dificultad de la partida, en este caso
    //al nivel de profundidad al que se hara la busqueda del movimiento mediante minimax.
    private int dificultad;
    //Declaramos un tablero logico que sera en el que se realizara la busqueda.
    private TableroLogico tableroLogico;
    //Declaramos un controlador que sera el usado para realizar el movimiento.
    private Controlador controlador;

    /**
     * Constructor, crea un generador de movimientos Minimax a partir de los
     * parametros recibidos.
     *
     * @param tableroLogico Tablero sobre el que buscar el mejor movimiento para
     * ser realizado por el ordenador.
     * @param controlador Controlador que realizara el movimiento buscado para
     * el ordenador.
     */
    public Minimax(TableroLogico tableroLogico, Controlador controlador) {
        //La dificultad sera la misma que la del tablero logico recibido.
        this.dificultad = tableroLogico.getDificultad();
        //En tablero en el que realizar al busqueda sera el tablero recibido.
        this.tableroLogico = tableroLogico;
        //El controlador para realizar el movimiento sera el controlador recibido.
        this.controlador = controlador;
    }

    /**
     * Metodo que generara el supuesto mejor movimiento para que el ordenador lo
     * realice.
     *
     * @return El supuesto mejor movimiento posible que puede realizar en el
     * tablero actual el ordenador.
     */
    private Movimiento generarMejorMovimiento() {
        //Como el objetivo es obtener el movimiento que nos sea mas valiosa, fijamos un valor muy bajo
        //para que se vaya sustituyendo desde el principio cuando se obtenga un movimiendo con mayor
        //valor. "max" sera el movimiento que mayor puntacion habra obtenido, por lo cual significara
        //que representa al mejor movimiendo. "valorJugada" representa el valor del movimiendo actual.
        //"fila" y "columna" representa la fila y columna del movimiento que se va a comprobar.
        int max = -99999, valorJugada = 0, fila, columna;
        //Declaramos un tablero logico en el que clonaremos el tablero original, pero en una direccion
        //diferente de memoria, esto para no alterar el tablero original durante la busqueda.
        TableroLogico tableroCopia;
        //Declaramos un movimiento que sera con el que iremos comprobando los movimientos posibles.
        Movimiento movimiento;
        //Creamos un movimiento que sera en el que iremos copiando el mejor movimiento resultante de
        //cada comprobacion.
        Movimiento mejorMovimiento = new Movimiento(0, TableroLogico.JUGADOR_ORDENADOR);
        //Creamos una lista con todos los movimientos posibles dado el estado actual del tablero.
        ArrayList<Movimiento> movimientosPosibles = this.tableroLogico.obtenerMovientosPosibles();

        //Recorremos uno por uno todos los movimientos de la lista de posibles movimientos.
        for (int i = 0; i < movimientosPosibles.size(); i++) {
            //Clonamos el tablero original para trabajar con una copia totalmente distinta.
            tableroCopia = this.tableroLogico.clone();

            //Copiamos el primer movimiento de la lista.
            movimiento = movimientosPosibles.get(i);

            //Asignamos los valores correspondientes a columna y fila.
            columna = movimiento.getColumna();
            fila = tableroCopia.obtenerFilaTirada(columna);

            //Realizamos el movimiento sobre el tablero copia.
            tableroCopia.cambiarValorCasilla(fila, columna);

            //Empezamos a realizar la busqueda del mejor movimiento, inicialmente buscando
            //cual seria la respuesta del adversario a nuestro movimiento. Para ello pasamos
            //el tablero copia con nuestro movimiento realizado e indicando que es el primer
            //nivel de busqueda.
            valorJugada = obtenerMin(tableroCopia, 1);

            //Si el valor de la jugada procesada, es mayor al valor de la que hasta ahora se
            //considerada mejor jugada:
            if (valorJugada > max) {
                //Actualizamos el valor de la mejor jugada.
                max = valorJugada;
                //Substituimos la mejor jugada con la nueva mejor jugada.
                mejorMovimiento = movimiento;
            }
        }

        //Finalmente se devolvera el mejor movimiento posible a realizar partiendo desde el
        //estado actual del tablero.
        return mejorMovimiento;
    }

    /**
     * Metodo que recursivamente va generando los posibles movimientos del
     * usuario en respuesta a los del ordenador, esto en busqueda del movimiento
     * de este ultimo.
     *
     * @param tablero Tablero sobre el que realizar la busqueda del movimiento.
     * @param profundidad Numero de niveles que se profundizara en la busqueda.
     * @return El valor del movimiento realizado por el jugador.
     */
    private int obtenerMin(TableroLogico tablero, int profundidad) {
        //Declaramos los enteros, "min" que correspondera al valor de la peor jugada
        //posible a realizar por el adversario, "valorJugada" que correspondera al valor
        //de la actual jugada que esta siendo evaluada, y "fila" y "columna" que
        //corresponderan a los valores de fila y columna del movimiendo que se va
        //a comprobar.
        int min = 0, valorJugada = 0, fila, columna;
        //Declaramos un tablero logico en el que clonaremos el tablero original, pero en una direccion
        //diferente de memoria, esto para no alterar el tablero original durante la busqueda.
        TableroLogico tableroCopia;
        //Declaramos un movimiento que sera con el que iremos comprobando los movimientos posibles.
        Movimiento movimiento;
        //Declaramos una lista para que almacene todos los posibles movimientos a realizar dado
        //el estado actual del tablero.
        ArrayList<Movimiento> movimientosPosibles = new ArrayList<Movimiento>();

        //Si mediante la recursividad se ha llegado al nivel maximo de busqueda:
        if (profundidad == this.dificultad) {
            //Se buscara la ultima jugada que realizara el jugador.
            valorJugada = obtenerMax(tablero, this.dificultad);
            //Se devolvera el valor de la jugada obtenida.
            return valorJugada;
        } else {
            //Como el objetivo es buscar la peor jugada por parte del adversario, iniciamos
            //el valor del peor movimiendo del adversario con un numero muy alto, para que desde
            //el principio en cada comprobacion se vaya cambiando por los posibles movimientos
            //con menor valor.
            min = 99999;

            //Obtenemos la lista de los movimientos posibles a realizar por el adversario.
            movimientosPosibles = tablero.obtenerMovientosPosibles();

            //Recorremos uno por uno todos los movimientos de la lista de posibles movimientos.
            for (int i = 0; i < movimientosPosibles.size(); i++) {
                //Clonamos el tablero original para trabajar con una copia totalmente distinta.
                tableroCopia = tablero.clone();

                //Copiamos el primer movimiento de la lista.
                movimiento = movimientosPosibles.get(i);

                //Asignamos los valores correspondientes a columna y fila.
                columna = movimiento.getColumna();
                fila = tableroCopia.obtenerFilaTirada(columna);

                //Indicamos que el movimiento va a ser realizado por el jugador humano.
                tableroCopia.setJugadorActual(TableroLogico.JUGADOR_HUMANO);
                //Realizamos el movimiento sobre el tablero copia.
                tableroCopia.cambiarValorCasilla(fila, columna);

                //Seguimos realizando la busqueda del mejor movimiento, buscando cual seria
                //la respuesta del jugador ante el movimiento de su adversario. Le pasamos
                //el tablero copia con el movimiento del adversario realizado y, ademas,
                //indicando que la busqueda se encuentra en un nivel mas de profundidad.
                valorJugada = obtenerMax(tableroCopia, profundidad + 1);

                //Si el valor de la jugada procesada, es menor al valor de la que hasta ahora se
                //consideraba peor jugada, actualizamos el valor de la peor jugada.
                if (valorJugada < min) {
                    min = valorJugada;
                } else {
                    //En caso contrario, no haria falta seguir recorriendo esa rama del arbol de
                    //movimientos porque se entiende que todos van a ser mas ventajosos para
                    //el adversario.
                    return min;
                }

            }

            //Devolvemos el valor del peor movimiento.
            return min;
        }
    }

    /**
     * Metodo que recursivamente va generando los posibles movimientos del
     * ordenador en respuesta a los del usuario, esto en busqueda del movimiento
     * del ordenador.
     *
     * @param tablero Tablero sobre el que realizar la busqueda del movimiento.
     * @param profundidad Numero de niveles que se profundizara en la busqueda.
     * @return El valor del movimiento realizado por el ordenador.
     */
    private int obtenerMax(TableroLogico tablero, int profundidad) {
        //Declaramos los enteros, "max" que correspondera al valor de la mejor jugada
        //posible a realizar por el jugador, "valorJugada" que correspondera al valor
        //de la actual jugada que esta siendo evaluada, y "fila" y "columna" que
        //corresponderan a los valores de fila y columna del movimiendo que se va
        //a comprobar.
        int max = 0, valorJugada = 0, fila, columna;
        //Declaramos un tablero logico en el que clonaremos el tablero original, pero en una direccion
        //diferente de memoria, esto para no alterar el tablero original durante la busqueda.
        TableroLogico tableroCopia;
        //Declaramos un movimiento que sera con el que iremos comprobando los movimientos posibles.
        Movimiento movimiento;
        //Declaramos una lista para que almacene todos los posibles movimientos a realizar dado
        //el estado actual del tablero.
        ArrayList<Movimiento> movimientosPosibles = new ArrayList<Movimiento>();

        //Si mediante la recursividad se ha llegado al nivel maximo de busqueda:
        if (profundidad == this.dificultad) {
            //Se llamara al metodo de evaluacion, para que evalua como de valiosa
            //han sido las jugadas iniciadas con el primer movimiento realizado.
            valorJugada = evaluacion(tablero, TableroLogico.JUGADOR_ORDENADOR);
            //Se devolvera el valor final de la jugada.
            return valorJugada;
        } else {
            //Como el objetivo es buscar la mejor jugada por parte del jugador, iniciamos
            //el valor del mejor movimiendo del jugador con un numero muy bajo, para que desde
            //el principio en cada comprobacion se vaya cambiando por los posibles movimientos
            //con mayor valor.
            max = -99999;

            //Obtenemos la lista de los movimientos posibles a realizar por el adversario.
            movimientosPosibles = tablero.obtenerMovientosPosibles();

            //Recorremos uno por uno todos los movimientos de la lista de posibles movimientos.
            for (int i = 0; i < movimientosPosibles.size(); i++) {
                //Clonamos el tablero original para trabajar con una copia totalmente distinta.
                tableroCopia = tablero.clone();

                //Copiamos el primer movimiento de la lista.
                movimiento = movimientosPosibles.get(i);

                //Asignamos los valores correspondientes a columna y fila.
                columna = movimiento.getColumna();
                fila = tableroCopia.obtenerFilaTirada(columna);

                //Indicamos que el movimiento va a ser realizado por el jugador ordenador.
                tableroCopia.setJugadorActual(TableroLogico.JUGADOR_ORDENADOR);
                //Realizamos el movimiento sobre el tablero copia.
                tableroCopia.cambiarValorCasilla(fila, columna);

                //Seguimos realizando la busqueda del mejor movimiento, buscando cual seria
                //la respuesta del adversario ante el movimiento del jugador. Le pasamos
                //el tablero copia con el movimiento del jugador realizado y, ademas,
                //indicando que la busqueda se encuentra en un nivel mas de profundidad.
                valorJugada = obtenerMin(tableroCopia, profundidad + 1);

                //Si el valor de la jugada procesada, es mayor al valor de la que hasta ahora se
                //consideraba mejor jugada, actualizamos el valor de la mejor jugada.
                if (valorJugada > max) {
                    max = valorJugada;
                } else {
                    //En caso contrario, no haria falta seguir recorriendo esa rama del arbol de
                    //movimientos porque se entiende que todos van a ser mas perjudicial para
                    //el jugador.
                    return max;
                }
            }
            return max;
        }
    }

    /**
     * Metodo que dada la ejecucion movimientos de una cierta profundidad de
     * niveles realizados, evalua la efectividad del movimiento para buscar el
     * mejor para realizar por el ordenador.
     *
     * @param tableroLogico El tablero sobre el que se evaluara la efectividad
     * del movimiento seleccionado.
     * @param jugador El jugador que tiene que salir aventajado por el
     * movimiento, que sera el ordenador.
     * @return El valor resultante que en cierto numero de niveles de
     * pronfundidad obtendra el movimiento realizado por el ordenador.
     * @exception ArrayIndexOutOfBoundsException Excepcion que se producira
     * cuando se intente obtener el valor de una posicion que no se encuentre
     * dentro de las definidas en un array.
     */
    private int evaluacion(TableroLogico tableroLogico, int jugador) {
        //Declaramos un entero al que se iran sumando o restando la puntuacion que se va consiguiento.
        int valorJugada = 0;
        //Declaramos un entero que servira de contador para buscar en un rango determinado de casillas.
        int cont = 0;
        //Declaramos los siguientes enteros que corresponderan a las casillas en posicion arriba, abajo,
        //izquierda, derecha, diagonal arriba izquierda, diagonal arriba derecha, diagonal abajo
        //izquierda, diagonal abajo derecha respecto a la casilla actual de comprobacion.
        int arr, aba, izq, der, diaArI, diaArD, diaAbI, diaAbD;
        //Declaramos los siguientes enteros para que sean contadores de los posibles cuatro en raya a
        //realizar por el jugador en cada una de las posiciones indicadas.
        int cArr = 0, cAba = 0, cIzq = 0, cDer = 0, cDiaArI = 0, cDiaArD = 0, cDiaAbI = 0, cDiaAbD = 0;
        //Declaramos los siguientes enteros para que sean contadores de los posibles cuatro en raya a
        //realizar por el adversario en cada una de las posiciones indicadas.
        int cArrC = 0, cAbaC = 0, cIzqC = 0, cDerC = 0, cDiaArIC = 0, cDiaArDC = 0, cDiaAbIC = 0, cDiaAbDC = 0;

        //Iniciamos un bucle para recorrer una por una, todas las casillas del tablero.
        for (int i = 0; i < tableroLogico.getTablero().length; i++) {
            for (int j = 0; j < tableroLogico.getTablero()[i].length; j++) {

                //Si la casilla no esta vacia, se procedera a su comprobacion.
                if (tableroLogico.getTablero()[i][j] != TableroLogico.FICHA_VACIA) {
                    //Se inicia otro bucle para comprobar todas las casillas en un rango suficiente
                    //para poder hacer cuatro en raya en cualquier direccion.
                    while (cont < 5) {
                        //Para comprobar solo por parte del ordenador.
                        if (jugador == TableroLogico.JUGADOR_ORDENADOR) {

                            //Abrimos un bloque try/catch para gestionar posibles excepciones que se
                            //produzcan durante la evaluacion, como el acceso a una casilla que se
                            //encuentra fuera del tablero.
                            try {
                                //Obtenemos la posicion correspondiente, en este caso, una en direccion
                                //ascendente.
                                arr = tableroLogico.getTablero()[i - cont][j];

                                //Si la ficha en esa casilla pertenece al ordenador:
                                if (arr == TableroLogico.FICHA_AZUL) {
                                    //Se aumenta el contador de posible cuatro en raya en esa direccion.
                                    cArr++;
                                    //Se reinicia el mismo contador del adversario.
                                    cArrC = 0;
                                } else {
                                    //En caso contrario, se haria al reves, se aumenta el contador del
                                    //adversario.
                                    cArrC++;
                                    //Y se reinicia el contador propio.
                                    cArr = 0;
                                }

                                //Ahora llega el momento de la evaluacion.
                                //Si hay ya dos fichas para posible cuatro en raya, aumenta en 5 el
                                //valor del movimiento.
                                if (cArr == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                //Si son 3, aumenta en 20.
                                if (cArr == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                //Si se produce cuatro en raya, aumenta en 40.
                                if (cArr == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                //Como es mas importante prevenir un cuatro en raya por parte del
                                //adversario que proyectar uno propio, los proyectos de cuatro en
                                //raya del adversario, disminuyen mas el valor de la jugada de lo
                                //que la aumenta los proyectos propios.
                                //Siendo dos fichas del contrario, resta 40.
                                if (cArrC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                //Si son 3, resta 200.
                                if (cArrC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                //Y se se produce cuatro en raya, resta 400.
                                if (cArrC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                                //Si se produce una excepcion por intentar acceder a una casilla
                                //que se encuentra fuera del tablero, no pasara nada, porque
                                //estamos indicando que no se realice ninguna accion en tal caso.
                            }

                            //CON EL RESTO DE DIRECCIONES LA COMPROBACION SE REALIZARA DE FORMA
                            //EXACTAMENTE IGUAL.
                            try {
                                aba = tableroLogico.getTablero()[i + cont][j];

                                if (aba == TableroLogico.FICHA_AZUL) {
                                    cAba++;
                                    cAbaC = 0;
                                } else {
                                    cAbaC++;
                                    cAba = 0;
                                }

                                if (cAba == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cAba == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cAba == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cAbaC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cAbaC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cAbaC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                izq = tableroLogico.getTablero()[i][j - cont];

                                if (izq == TableroLogico.FICHA_AZUL) {
                                    cIzq++;
                                    cIzqC = 0;
                                } else {
                                    cIzqC++;
                                    cIzq = 0;
                                }

                                if (cIzq == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cIzq == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cIzq == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cIzqC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cIzqC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cIzqC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                der = tableroLogico.getTablero()[i][j + cont];

                                if (der == TableroLogico.FICHA_AZUL) {
                                    cDer++;
                                    cDerC = 0;
                                } else {
                                    cDerC++;
                                    cDer = 0;
                                }

                                if (cDer == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cDer == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cDer == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cDerC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cDerC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cDerC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                diaArI = tableroLogico.getTablero()[i - cont][j - cont];

                                if (diaArI == TableroLogico.FICHA_AZUL) {
                                    cDiaArI++;
                                    cDiaArIC = 0;
                                } else {
                                    cDiaArIC++;
                                    cDiaArI = 0;
                                }

                                if (cDiaArI == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cDiaArI == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cDiaArI == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cDiaArIC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cDiaArIC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cDiaArIC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                diaArD = tableroLogico.getTablero()[i - cont][j + cont];

                                if (diaArD == TableroLogico.FICHA_AZUL) {
                                    cDiaArD++;
                                    cDiaArDC = 0;
                                } else {
                                    cDiaArDC++;
                                    cDiaArD = 0;
                                }

                                if (cDiaArD == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cDiaArD == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cDiaArD == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cDiaArDC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cDiaArDC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cDiaArDC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                diaAbI = tableroLogico.getTablero()[i + cont][j - cont];

                                if (diaAbI == TableroLogico.FICHA_AZUL) {
                                    cDiaAbI++;
                                    cDiaAbIC = 0;
                                } else {
                                    cDiaAbIC++;
                                    cDiaAbI = 0;
                                }

                                if (cDiaAbI == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cDiaAbI == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cDiaAbI == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cDiaAbIC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cDiaAbIC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cDiaAbIC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                            try {
                                diaAbD = tableroLogico.getTablero()[i + cont][j + cont];

                                if (diaAbD == TableroLogico.FICHA_AZUL) {
                                    cDiaAbD++;
                                    cDiaAbDC = 0;
                                } else {
                                    cDiaAbDC++;
                                    cDiaAbD = 0;
                                }

                                if (cDiaAbD == 2) {
                                    valorJugada = valorJugada + 5;
                                }

                                if (cDiaAbD == 3) {
                                    valorJugada = valorJugada + 20;
                                }

                                if (cDiaAbD == 4) {
                                    valorJugada = valorJugada + 40;
                                }

                                if (cDiaAbDC == 2) {
                                    valorJugada = valorJugada - 40;
                                }

                                if (cDiaAbDC == 3) {
                                    valorJugada = valorJugada - 200;
                                }

                                if (cDiaAbDC == 4) {
                                    valorJugada = valorJugada - 400;
                                }

                            } catch (ArrayIndexOutOfBoundsException e) {
                            }

                        }

                        cont++;
                    }
                }
            }
        }

        return valorJugada;
    }

    @Override
    public void run() {
        //Cuando se ejecute un proceso minimax, lo primero sera obtener el mejor
        //movimiento posible.
        Movimiento mejorMovimiento = generarMejorMovimiento();

        //Pero solo si la partida es nueva, se realizara dicho movimiento sobre
        //el tablero.
        if (this.tableroLogico.getTipoPartida() == TableroLogico.PARTIDA_NUEVA) {
            this.controlador.movimientoMinimax(mejorMovimiento);
        }
    }
}
