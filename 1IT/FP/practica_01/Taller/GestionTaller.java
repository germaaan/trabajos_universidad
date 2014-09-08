//Clase necesaria para crear un flujo basico de entrada de datos.

import java.io.InputStreamReader;
//Clase necesaria para poder realizar la lectura de lineas desde teclado.
import java.io.BufferedReader;
//Clase necesaria para gestionar las excepciones posibles producidas en la entrada/salida de datos.
import java.io.IOException;
//Clase necesaria para poder trabajar con listas ArrayList.
import java.util.ArrayList;
//Clases necesarias para las formas en las que trabajaremos con las fechas,
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
//Clase necesaria para generar numeros aleatorios.
import java.util.Random;
//Clase necesaria para obtener la salida de una fecha con un determinado formato.
import java.text.SimpleDateFormat;

/**
 * Clase gestionadora de todas las operaciones de entrada/salida y de todos los
 * menus.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 22/02/10
 */
public class GestionTaller {

    //Creamos un nuevo objeto Taller para guardar en el las listas de clientes, vehiculos y partes de reparacion.
    private Taller taller = new Taller();

    /**
     * Array con opciones del menu principal.
     */
    private static final String menuPrincipal[] = {
        "0. Salir del programa",
        "1. Gestion de clientes",
        "2. Gestion de vehiculos",
        "3. Gestion de partes de reparacion",
        "4. Estado general del taller"
    };

    /**
     * Array con opciones del menu de clientes.
     */
    private static final String menuCliente[] = {
        "0. Volver al menu principal",
        "1. Alta de nuevo cliente",
        "2. Baja de cliente existente",
        "3. Mostrar datos de un cliente",
        "4. Mostrar datos de todos los clientes",
        "5. Modificar datos de un cliente"
    };

    /**
     * Array con opciones del menu de vehiculos.
     */
    private static final String menuVehiculo[] = {
        "0. Volver al menu principal",
        "1. Alta de nuevo vehiculo",
        "2. Baja de vehiculo existente",
        "3. Mostrar datos de un vehiculo",
        "4. Mostrar datos de todos los vehiculos",
        "5. Modificar datos de un vehiculo",
        "6. Mostrar historial de reparacion de un vehiculo"
    };

    /**
     * Array con opciones del menu de partes de reparacion.
     */
    private static final String menuParteReparacion[] = {
        "0. Volver al menu principal",
        "1. Crear nuevo parte de reparacion pendiente",
        "2. Finalizar la reparacion de un vehiculo",
        "3. Generar listado de partes de reparacion pendientes",
        "4. Generar listado de partes de reparacion de un mismo cliente",
        "5. Calcular numero medio de horas de reparacion reales de partes finalizados",
        "6. Modificar numero de horas estimadas de reparacion de un vehiculo",};

    /**
     * Flujo basico de entrada de datos.
     */
    InputStreamReader isr = new InputStreamReader(System.in);
    /**
     * Almacen temporal de la lectura de lineas desde teclado.
     */
    BufferedReader br = new BufferedReader(isr);

    /**
     * Metodo que nos permitira leer desde teclado un valor numerico entero.
     *
     * @param mensaje Mensaje que mostraremos antes de la lectura de los datos.
     * @return El valor del numero entero que hayamos introducido desde teclado.
     * @exception IOException Excepcion de entrada/salida.
     * @exception NumberFormatException El valor introducido no es numerico.
     */
    public int setEntero(String mensaje) {
        //Declaramos el entero que almacenara el valor entero introducido por teclado.
        int entero;
        //Y tambien declaramos una variable booleana para utilizarla como control.
        boolean error = false;

        //Iniciamos un bucle do while que se estara ejecutando mientras que el valor del booleano de control sea verdadero.
        do {
            //Mostramos el mensaje de la peticion de datos por teclado.
            System.out.println(mensaje);

            //Realizamos un bloque try/catch para realizar la entrada de datos controlando las posibles excepciones.
            try {
                //Introducimos el valor y se cambia el valor del booleano a falso.
                entero = Integer.parseInt(br.readLine());
                error = false;
            } //Acciones que realizaremos en caso de que se produzca una excepcion de entrada/salida.
            catch (IOException exception) {
                //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
                entero = 0;
                //Mostramos un mensaje de aviso.
                System.out.println("Error en la lectura de datos");
                //Mostramosn los detalles de la excepcion producida.
                exception.printStackTrace();
                //Y finalizamos la ejecucion.
                System.exit(0);
            } //Acciones que realizaremos en caso de que se produzca una excepcion de formato numerico, es decir, que el valor introducido no sea numerico.
            catch (NumberFormatException nfe) {
                //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
                entero = 0;
                //Cambiamos el valor del booleano a verdadero para que el bucle se vuelva a ejecutar y se muestra un mensaje indicando el error que se ha producido.
                error = true;
                System.out.println("Error en la lectura del valor. El valor introducido no es numerico");
            }

            //Si el numero negativo, esto tambien sera considerado como un error para que se vuelve a ejecutar el bucle.
            if (entero < 0) {
                error = true;
            }
        } while (error == true);

        //Devolvemos el valor entero introducido por teclado.
        return entero;
    }

    /**
     * Metodo que nos permitira leer desde teclado un valor numerico real.
     *
     * @param mensaje Mensaje que mostraremos antes de la lectura de los datos.
     * @return El valor del numero real que hayamos introducido por teclado.
     * @exception IOException Excepcion de entrada/salida.
     * @exception NumberFormatException El valor introducido no es numerico.
     */
    public double setDouble(String mensaje) {
        //Declaramos un una variable numerica real que almacenara el valor real introducido por teclado.
        double numero;
        //Y tambien declaramos una variable booleana para utilizarla como control.
        boolean error = false;

        //Iniciamos un bucle do while que se estara ejecutando mientras que el booleano de control sea verdadero.
        do {
            //Mostramos el mensaje de la peticion de datos por teclado.
            System.out.println(mensaje);

            //Realizamos un bloque try/catch para realizar la entrada de datos controlando las posibles excepciones.
            try {
                //Introducimos el valor y se cambia el valor de la variable a falso.
                numero = Double.parseDouble(br.readLine());
                error = false;
            } //Acciones que realizaremos en caso de que se produzca una excepcion de entrada/salida.
            catch (IOException exception) {
                //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
                numero = 0.0;
                //Mostramos un mensaje de aviso.
                System.out.println("Error en la lectura de datos");
                //Mostramosn los detalles de la excepcion producida.
                exception.printStackTrace();
                //Y finalizamos la ejecucion.
                System.exit(0);
            } //Acciones que realizaremos en caso de que se produzca una excepcion de formato numerico, es decir, que el valor introducido no sea numerico.
            catch (NumberFormatException nfe) {
                //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
                numero = 0.0;
                //Cambiamos el valor del booleano a verdadero para que el bucle se vuelva a ejecutar y se muestra un mensaje indicando el error que se ha producido.
                error = true;
                System.out.println("Error en la lectura del valor. El valor introducido no es numerico");
            }

            //Si el numero negativo, esto tambien sera considerado como un error para que se vuelve a ejecutar el bucle.
            if (numero <= 0.0) {
                error = true;
            }

        } while (error == true);

        //Devolvemos el valor real introducido por teclado.
        return numero;
    }

    /**
     * Metodo que nos permitira leer desde teclado un valor booleano.
     *
     * @param mensaje Mensaje que mostraremos antes de la lectura de los datos.
     * @return El valor del booleano que hayamos introducido por teclado.
     * @exception IOException Excepcion de entrada/salida.
     */
    public boolean setBooleano(String mensaje) {
        //Declaramos la variable que almacenara el valor booleano que se quiere introdudir en forma de cadena de texto introducido por teclado.
        String aux;
        //Declaramos un booleano para utilizarlo como control.
        boolean error = false;
        //Y tambien declaramos la variable que almacenara el valor booleano que devolveremos en funcion del valor introducido por teclado almacenado en la cadena de texto.
        boolean valor;

        //Mostramos el mensaje de la peticion de datos por teclado.
        System.out.println(mensaje);

        //Iniciamos un bucle do while que se estara ejecutando mientras que el valor del booleano de control sea verdadero.
        do {
            //Mostramos uno mensaje u otro dependiendo del valor de la variable de control.
            getSalidaCondicional(error == false,
                    "Introduzca SI o NO:",
                    "Opcion no valida. Introduzca SI o NO:");

            //Realizamos un bloque try/catch para realizar la entrada de datos controlando las posibles excepciones.
            try {
                //Introducimos el valor de la cadena de texto.
                aux = br.readLine().toUpperCase();
            } //Acciones que realizaremos en caso de que se produzca una excepcion de entrada/salida.
            catch (IOException exception) {
                //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
                aux = "";
                //Mostramos un mensaje de aviso.
                System.out.println("Error en la lectura de datos");
                //Mostramosn los detalles de la excepcion producida.
                exception.printStackTrace();
                //Y finalizamos la ejecucion.
                System.exit(0);
            }

            //Comprobamos que el valor introducido por teclado sea el pedido para decidir que valor toma el booleano.
            if ((aux.equals("SI")) || (aux.equals("NO"))) {
                error = false;
            } else {
                error = true;
            }
        } while (error == true);

        //Asignamos un valor al booleano en funcion al valor de la cadena de texto introducida por teclado.
        if (aux.equals("SI")) {
            valor = true;
        } else {
            valor = false;
        }

        //Devolvemos el valor booleano.
        return valor;
    }

    /**
     * Metodo que nos permitira leer desde teclado una cadena de texto.
     *
     * @param mensaje Mensaje que mostraremos antes de la lectura de los datos.
     * @return La cadena de texto que hayamos introducido por teclado.
     * @exception IOException Excepcion de entrada/salida.
     */
    public String setCadena(String mensaje) {
        //Declaramos la variable que almacenara la cadena de texto introducida por teclado.
        String valor;

        //Mostramos el mensaje de la peticion de datos por teclado.
        System.out.println(mensaje);

        //Realizamos un bloque try/catch para realizar la entrada de datos controlando las posibles excepciones.
        try {
            //Introducimos el valor de la cadena de texto.
            valor = br.readLine().toUpperCase();
        } //Acciones que realizaremos en caso de que se produzca una excepcion de entrada/salida.
        catch (IOException exception) {
            //Asignamos un valor por defecto para poder devolver un valor y poder realizar la comprobacion posterior al bucle.
            valor = "";
            //Mostramos un mensaje de aviso.
            System.out.println("Error en la lectura de datos");
            //Mostramosn los detalles de la excepcion producida.
            exception.printStackTrace();
            //Y finalizamos la ejecucion.
            System.exit(0);
        }

        //Devolvemos la cadena de texto introducida por teclado.
        return valor;
    }

    /**
     * Metodo que nos permitira mostrar un mensaje u otro dependiendo del valor
     * booleano recibido como parametro.
     *
     * @param condicion Condicion de la que dependera la visualizacion de un
     * mensaje u otro.
     * @param mensajeSi Mensaje que se mostrara en el caso de que el valor
     * booleano sea positivo.
     * @param mensajeNo Mensaje que se mostrara en el caso de que el valor
     * booleano sea negativo.
     */
    public void getSalidaCondicional(boolean condicion, String mensajeSi, String mensajeNo) {
        //Dependiendo del valor booleano recibido como parametro se mostrara uno u otro mensaje,
        if (condicion == true) {
            System.out.println(mensajeSi);
        } else {
            System.out.println(mensajeNo);
        }
    }

    /**
     * Metodo que recibira una cadena de texto correspondiente a los primeros 8
     * caracteres de un D.N.I. para determinar si sus valores son numericos.
     *
     * @param cadena Cadena de texto correspondiente a los 8 primeros caracteres
     * de un D.N.I.
     * @return Verdadero si alguno de los caracteres de los cadena no es un
     * valor numerico y falso en caso contrario.
     */
    public boolean comprobarEntero(String cadena) {
        //Realizamos un bloque try/catch para realizar la comprobacion de que todos las posiciones de un String son numericos controlando las posibles excepciones.
        try {
            //Convertimos la cadena de texto recibida a un valor entero.
            int aux = Integer.parseInt(cadena);
            //Si el valor obtenido es completamente numerico, se devolvera un valor verdadero.
            return false;
        } catch (NumberFormatException nfe) {
            //En caso de que algunas de las posiciones contuviera un valor que no se puede convertir a numerico, se producira una excepcion de formato numerico y se devolvera un valor verdadero.
            return true;
        }
    }

    /**
     * Metodo que comprobara si el D.N.I. recibido como parametro tiena la forma
     * de un D.N.I. velido.
     *
     * @param dni D.N.I. a comprobar.
     * @return Verdadero si no es velido, falso si lo es.
     */
    public boolean comprobarDni(String dni) {
        //Declaramos una booleano para utilizarlo como control.
        boolean error = false;
        //Declaramos una cadena de texto vacia en la que se iran almacenando los que deberian ser los valores numericos del D.N.I para su posterior comprobacion de que son numericos realmente.
        String numeros = "";
        //Declaramos un caracter que tendra como valor la letra del D.N.I. recibido para comprobar que es valida.
        char letra = dni.charAt(8);

        //Iniciamos un bucle for para que se vayan almacenando todos los valores numericos del D.N.I. recibido.
        for (int i = 0; i < dni.length() - 1; i++) {
            numeros = numeros + dni.charAt(i);
        }

        //La variable booleana de control recibira como valor el resultado de la comprobacion de que todos las posiciones del D.N.I. que deben contener numeros, contienen realmente numeros.
        error = comprobarEntero(numeros);

        //Si todos los numeros son numeros se comprobara que la letra del D.N.I. es valida.
        if (error == false) {
            if ((letra != 'A') && (letra != 'B') && (letra != 'C') && (letra != 'D') && (letra != 'E') && (letra != 'F') && (letra != 'G') && (letra != 'H') && (letra != 'I') && (letra != 'J') && (letra != 'K') && (letra != 'L') && (letra != 'M') && (letra != 'N') && (letra != 'O') && (letra != 'P') && (letra != 'Q') && (letra != 'R') && (letra != 'S') && (letra != 'T') && (letra != 'V') && (letra != 'W') && (letra != 'X') && (letra != 'Y')
                    && (letra != 'Z')) {
                error = true;
            }
        }

        //Devolvemos un valor booleano indicando si el D.N.I. es completamente velido o no.
        return error;
    }

    /**
     * Metodo que nos hara introducir un D.N.I. y automaticamente comprobara si
     * tiene una forma valida.
     *
     * @return Un D.N.I. con forma valida.
     */
    public String setDniValido() {
        //Declaramos una cadena de texto que almacenara el D.N.I. leido de teclado.
        String dni = "";
        //Y declaramos un booleano de control.
        boolean error = false;

        //Iniciamos un bucle do while que se seguira ejecutando mientras el valor del booleano de control sea verdadero.
        do {
            //Mostramos un mensaje u otro dependiendo del valor de la variable de control.
            getSalidaCondicional(error == false,
                    "El D.N.I. del cliente tiene que estar compuesto por 8 numeros y 1 letra.",
                    "El D.N.I. introducido no es velido, tiene que estar compuesto por 8 numeros y 1 letra solamente.");

            //Leemos de teclado el valor del D.N.I.
            dni = (setCadena("Introduzca el D.N.I. del cliente:")).toUpperCase();

            //Si el tamaño del D.N.I. introducido es diferente de 9, no sera velido, en caso contrario comprobaremos si el D.N.I. introducido es uno velido.
            if (dni.length() != 9) {
                error = true;
            } else {
                error = comprobarDni(dni);
            }
        } while (error == true);

        //Devolvemos el D.N.I. ya comprobado como velido.
        return dni;
    }

    /**
     * Metodo que nos hara introducir un D.N.I. velido y automaticamente
     * comprobara si existe en la lista de clientes.
     *
     * @return Un D.N.I. con forma valida y que ademas existira en la lista de
     * clientes.
     */
    public String setDniValidoExistente() {
        //Declaramos una cadena de texto que almacenara el D.N.I. leido de teclado.
        String dni;
        //Y declaramos una variable booleana de control.
        boolean error = false;

        //Iniciamos un bucle do while que se seguira ejecutando mientras el valor del booleano de control sea verdadero.
        do {
            //Mostramos uno mensaje u otro dependiendo del valor de la variable de control.
            getSalidaCondicional(error == false,
                    "El D.N.I. a introducir debe existir en la base de datos.",
                    "El D.N.I. introducido no existe en la base de datos.");

            //Para que el D.N.I. que introduzcamos siempre sea velido, usamos el metodo anterior.
            dni = setDniValido();

            //Comprobamos si el D.N.I. existe en el taller.
            if (taller.comprobarDni(dni) == false) {
                error = true;
            } else {
                error = false;
            }
        } while (error == true);

        //Devolvemos un D.N.I. velido y existente en el taller.
        return dni;
    }

    /**
     * Metodo que nos hara introducir una matricula y automaticamente comprobara
     * si existe en la lista de vehiculos.
     *
     * @return Una matricula que existira en la lista de vehiculos.
     */
    public String setMatriculaExistente() {
        //Declaramos una cadena de texto que almacenara la matricula leida de teclado.
        String matricula;
        //Y declaramos un booleano de control.
        boolean error = false;

        //Iniciamos un bucle do while que se seguira ejecutando mientras el valor del booleano de control sea verdadero.
        do {
            //Dependiendo de como haya finalizado la ultima iteracion del bucle, pediremos la introduccion de la matricula con un mensaje diferente.
            if (error == false) {
                matricula = (setCadena("Introduzca matricula del vehiculo (matricula debe existir en la base de datos):"));
            } else {
                matricula = (setCadena("La matricula introducida no existe en la base de datos. Introduzca una matricula que si exista en la base de datos:"));
            }

            //Comprobamos si la matricula existe en el taller.
            if (taller.comprobarMatricula(matricula) == false) {
                error = true;
            } else {
                error = false;
            }
        } while (error == true);

        //Devolemos una matricula que existe en el taller.
        return matricula;
    }

    /**
     * Metodo que asignara a un vehiculo su tipo en funcion de lo que
     * introduzcamos por teclado.
     *
     * @return Un tipo de vehiculo velido, este solo puede ser alguna de las
     * constantes estaticas que definimos en la clase Vehiculo.
     */
    public char setTipoVehiculo() {
        //Declaramos la variable que almacenara el tipo de vehiculo que se quiere introdudir en forma de cadena de texto introducido por teclado.
        String auxTipo = "";
        //Declaramos la variable que almacenara el valor del tipo de vehiculo en funcion del valor introducido por teclado almacenado en la cadena de texto.
        char tipo = ' ';
        //Y tambien declaramos un booleano para utilizarlo como control.
        boolean error = false;

        //Iniciamos un bucle do while que se seguira ejecutando mientras el valor del booleano de control sea verdadero.
        do {
            //Pedimos la introduccion del tipo de vehiculo, indicando que solo hay tres tipos velidos.
            auxTipo = (setCadena("Introduzca el tipo de vehiculo, las unicas opciones validas son: TURISMO, FURGONETA o MOTOCICLETA: "));

            //El valor del tipo de vehiculo sera uno de los tres dependiendo de lo introducido por teclado.
            if (auxTipo.equals("TURISMO")) {
                tipo = Vehiculo.TIPO_TURISMO;
                error = false;
            } else {

                if (auxTipo.equals("FURGONETA")) {
                    tipo = Vehiculo.TIPO_FURGONETA;
                    error = false;
                } else {

                    if (auxTipo.equals("MOTOCICLETA")) {
                        tipo = Vehiculo.TIPO_MOTOCICLETA;
                        error = false;
                    } else {
                        error = true;
                    }
                }
            }
        } while (error == true);

        //Devolvemos un tipo de vehiculo velido.
        return tipo;
    }

    /**
     * Metodo que devolvera en forma de cadena de texto el tipo del vehiculo.
     *
     * @param tipo Tipo del vehiculo del que devolvemos la cadena de texto.
     * @return Cadena de texto con el tipo del vehiculo.
     */
    public String getTipoCadena(char tipo) {
        //Declaramos una cadena de texto que almacenara el tipo del vehiculo recibido como parametro.
        String cadena = "";

        ///Dependiendo del tipo del vehiculo, se almacenara un valor u otros en la cadena de texto.
        if (tipo == Vehiculo.TIPO_TURISMO) {
            cadena = "Turismo";
        } else {

            if (tipo == Vehiculo.TIPO_FURGONETA) {
                cadena = "Furgoneta";
            } else {

                if (tipo == Vehiculo.TIPO_MOTOCICLETA) {
                    cadena = "Motocicleta";
                }
            }
        }

        //Devolvemos la cadena de texto con el tipo del vehiculo.
        return cadena;
    }

    /**
     * Metodo que devolvera en forma de cadena de texto el valor de un booleano.
     *
     * @param condicion El booleano del que devolvemos su valor en una cadena de
     * texto.
     * @return Un tipo de vehiculo velido, este solo puede ser alguna de las
     * constantes estaticas que definimos en la clase Vehiculo.
     */
    public String getBooleanoCadena(boolean condicion) {
        //Declaramos una cadena de texto que almacenara el valor del booleano pasado como parametro.
        String cadena;

        //La cadena de texto tomara uno u otro valor dependiendo del booleano.
        if (condicion == true) {
            cadena = "Si";
        } else {
            cadena = "No";
        }

        //Devolvemos la cadena de texto con el valor del booleano.
        return cadena;
    }

    /**
     * Metodo que nos permite introducir una fecha y automaticamente comprobar
     * si esta es valida.
     *
     * @param mensaje Mensaje que indica la fecha que se esta pidiendo.
     * @return Fecha valida del tipo GregorianCalendar.
     */
    public GregorianCalendar setFechaValida(String mensaje) {
        //Declaramos una fecha GregorianCalendar con la fecha actual.
        GregorianCalendar actual = new GregorianCalendar();
        //Declaramos tambien los valores enteros que usaremos para años, meses, dias, calcular años bisiestos y una variable auxiliar que nos indique el numero que de dias maximos que podemos introducir.
        int anio, mes, dia, anioBi, auxDias = 0;
        //Tambien declaramos dos cadenas de texto que almacenaran el mes introducido y mostrara los dias maximos que se pueden introducir.
        String mensajeMes = "", mensajeDias;
        //Por ultimo declaramos una variable booleana de control.
        boolean error = false;

        //Mostramos el mensaje de la fecha que estamos pidiendo, este mensaje es el recibido como parametro.
        System.out.println(mensaje);

        //Iniciamos un bucle do while que se estara ejecutando mientras que el valor del booleano del control sea verdadero.
        do {
            //Realizamos la peticion del año con un mensaje diferente dependiendo del valor del booleano de control.
            if (error == false) {
                anio = setEntero("Introduzca año:");
            } else {
                anio = setEntero("El año introducido es posterior al año actual. Introduzca año igual o inferior al año actual:");
            }

            //Creamos una fecha GregorianCalendar con el año que hemos introducido.
            GregorianCalendar auxAnio = new GregorianCalendar(anio, Calendar.JANUARY, 1);

            //Si el año introducido es posterior al actual, deberemos volver a pedirlo.
            if (auxAnio.get(Calendar.YEAR) > actual.get(Calendar.YEAR)) {
                error = true;
            } else {
                error = false;
            }
        } while (error == true);

        //Iniciamos otro bucle do while que se tambien se estara ejecutando mientras que el valor del booleano del control sea verdadero.
        do {
            //Pedimos que se introduzca un mes velido.
            mes = setEntero("Introduzca mes (1-12):");

            //El mes tiene que ser un valor entero entre 1 y 12.
            if ((mes == 0) || (mes > 12)) {
                error = true;
            } else {
                error = false;
            }
        } while (error == true);

        //Finalmente volvemos a iniciar otro bucle do while para la introduccion de un dia velido.
        do {
            //Comprobamos si el año es bisiesto o no.
            anioBi = anio % 4;

            //Dependendiendo del mes introducido guardamos el mes en una cadena texto y el numero de dias maximos permitidos.
            switch (mes) {
                case 1:
                    mensajeMes = "Enero";
                    auxDias = 31;
                    break;

                case 2:
                    mensajeMes = "Febrero";
                    //En el caso de este mes deberemos tener en cuenta si el año es bisiesto para determinar su maximo numero de dias.
                    if (anioBi != 0) {
                        auxDias = 28;
                    } else {
                        auxDias = 29;
                    }
                    break;

                case 3:
                    mensajeMes = "Marzo";
                    auxDias = 31;
                    break;

                case 4:
                    mensajeMes = "Abril";
                    auxDias = 30;
                    break;

                case 5:
                    mensajeMes = "Mayo";
                    auxDias = 31;
                    break;

                case 6:
                    mensajeMes = "Junio";
                    auxDias = 30;
                    break;

                case 7:
                    mensajeMes = "Julio";
                    auxDias = 31;
                    break;

                case 8:
                    mensajeMes = "Agosto";
                    auxDias = 31;
                    break;

                case 9:
                    mensajeMes = "Septiembre";
                    auxDias = 30;
                    break;

                case 10:
                    mensajeMes = "Octubre";
                    auxDias = 31;
                    break;

                case 11:
                    mensajeMes = "Noviembre";
                    auxDias = 30;
                    break;

                case 12:
                    mensajeMes = "Diciembre";
                    auxDias = 31;
                    break;
            }

            //Almacenamos el mensaje para mostrar en la peticion de los dias usando el mes y el numero de dias almacenados.
            mensajeDias = ("Introduzca dia (como mes es " + mensajeMes + ", el dia introducido tiene que ser menor a " + auxDias + "):");

            //Realizamos la peticion de dias usando el mensaje almacenado.
            dia = setEntero(mensajeDias);

            //Si introducimos un numero de dias mayor al indicado esto provocara que el numero de dias no sea velido.
            if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
                if (dia > 31) {
                    error = true;
                } else {
                    error = false;
                }
            } else {
                if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
                    if (dia > 30) {
                        error = true;
                    } else {
                        error = false;
                    }
                } else {
                    if (anioBi == 0) {
                        if (dia > 29) {
                            error = true;
                        } else {
                            error = false;
                        }
                    } else {
                        if (dia > 28) {
                            error = true;
                        } else {
                            error = false;
                        }
                    }
                }
            }
        } while (error == true);

        //Creamos una fecha GregorianCalendar y hacemos sus valores de años, mes y dia sean los que hemos introducimos a lo largo del metodo.
        GregorianCalendar fecha = new GregorianCalendar();

        fecha.set(Calendar.YEAR, anio);
        fecha.set(Calendar.MONTH, mes - 1);
        fecha.set(Calendar.DAY_OF_MONTH, dia);

        //Devolvemos la fecha generada.
        return fecha;
    }

    /**
     * Metodo que devolvera en forma de cadena de texto una fecha con un formato
     * predeterminado. Sera usado para las fechas de los partes de reparacion.
     *
     * @param fecha Fecha tipo GregorianCalendar que devolveremos en forma de
     * cadena de texto.
     * @return Cadena de texto de la fecha pasada como argumento.
     */
    public String getFechaCadenaParte(GregorianCalendar fecha) {
        //Lo primero sera declarar el formato de fecha con el que queremos devolverlo dentro de una cadena de texto.
        SimpleDateFormat formaFecha = new SimpleDateFormat("dd/MM/yyyy HH:mm");

        //Declaramos una fecha de tipo Date que es la unica que le podemos aplicar el formato declarado.
        Date auxDate = new Date();
        //Almacenamos dentro de la fecha Date declarada la fecha GregorianCalendar recibida como parametro.
        auxDate = fecha.getTime();

        //Dentro de una cadena de texto almacenamos la fecha con el formato definido.
        String auxFecha = formaFecha.format(auxDate);

        //Devolvemos la cadena de texto con la fecha con formato para partes de reparacion.
        return auxFecha;
    }

    /**
     * Metodo que devolvera en forma de cadena de texto una fecha con un formato
     * predeterminado. Sera usado para las fechas de los vehiculos.
     *
     * @param fecha Fecha tipo GregorianCalendar que devolveremos en forma de
     * cadena de texto.
     * @return Cadena de texto de la fecha pasada como argumento.
     */
    public String getFechaCadenaVehiculo(GregorianCalendar fecha) {
        //Lo primero sera volver a declarar el formato de fecha con el que queremos devolverlo dentro de una cadena de texto.
        SimpleDateFormat formaFecha = new SimpleDateFormat("dd/MM/yyyy");

        //Igualmente al metodo anterior, declaramos una fecha de tipo Date que es la unica que le podemos aplicar el formato declarado.
        Date auxDate = new Date();
        //Almacenamos dentro de la fecha Date declarada la fecha GregorianCalendar recibida como parametro.
        auxDate = fecha.getTime();

        //Dentro de una cadena de texto almacenamos la fecha con el formato definido.
        String auxFecha = formaFecha.format(auxDate);

        //Devolvemos la cadena de texto con la fecha con formato para vehiculos.
        return auxFecha;
    }

    /**
     * Metodo que devolvera la diferencia en horas laborales de un intervalo de
     * tiempo correspondiente a los dos fechas pasadas.
     *
     * @param fechaEntrada La fecha de entrada de un vehiculo en el taller y un
     * parte de reparacion es creado.
     * @param fechaSalida La fecha en la que un parte de reparacion es
     * finalizado y un vehiculo sale del taller.
     * @return Numero de horas laborales invertidas en la reparacion del
     * vehiculo.
     */
    public int getDiferenciaHoras(GregorianCalendar fechaEntrada, GregorianCalendar fechaSalida) {
        //Declaramos dos enteros largos para almacenar los valores de las fechas recibidas como parametros en milisegundos.
        long milisegundosEntrada = fechaEntrada.getTimeInMillis();
        long milisegundosSalida = fechaSalida.getTimeInMillis();

        //Calculamos la diferencia entre ambas fechas.
        long milisegundosDif = milisegundosSalida - milisegundosEntrada;

        //Calculamos el correspondiente en horas laborales de la diferencia entre las dos fechas, convirtiendo el resultado directamente en un entero normal.
        int horasReales = (int) (milisegundosDif / (24 * 60 * 60 * 1000)) * 8;

        //Si el resultado de las horas fuera cero, cambiamos su valor por uno.
        if (horasReales == 0) {
            horasReales = 1;
        }

        //Devolvemos las horas calculadas.
        return horasReales;
    }

    /**
     * Metodo que devuelve una cadena de texto como forma de selida estandar
     * para mostrar los datos de un cliente.
     *
     * @param cliente Cliente del que se generara la cadena de texto con sus
     * datos.
     * @return Cadena de texto con los datos del cliente.
     */
    public String getSalidaCliente(Cliente cliente) {
        //Declaramos una cadena de texto en la que almacenamos todos los datos de un cliente de la siguiente forma:
        String cadena = ("\nDatos del cliente con el D.N.I.: " + cliente.getDni()
                + "\n\tApellidos: " + cliente.getApellidos()
                + "\n\tNombre: " + cliente.getNombre()
                + "\n\tDireccion: " + cliente.getDireccion());
        //Devolvemos la cadena de texto.
        return cadena;
    }

    /**
     * Metodo que devuelve una cadena de texto como forma de selida estandar
     * para mostrar los datos de un vehiculo.
     *
     * @param vehiculo Vehiculo del que se generara la cadena de texto con sus
     * datos.
     * @return Cadena de texto con los datos del vehiculo.
     */
    public String getSalidaVehiculo(Vehiculo vehiculo) {
        //Declaramos una cadena de texto en la que almacenamos todos los datos de un vehiculo de la siguiente forma:
        String cadena = ("\nDatos del vehiculo con la matricula: " + vehiculo.getMatricula()
                + "\n\tModelo: " + vehiculo.getModelo()
                + "\n\tTipo de Vehiculo: " + getTipoCadena(vehiculo.getTipo())
                + "\n\tFecha de compra: " + getFechaCadenaVehiculo(vehiculo.getFechaCompra())
                + "\n\t¿Siendo reparado actualmente en el taller?: " + getBooleanoCadena(vehiculo.getEnReparacion()));
        //Devolvemos la cadena de texto
        return cadena;
    }

    /**
     * Metodo que devuelve una cadena de texto como forma de selida estandar
     * para mostrar los datos de un parte de reparacion pendiente.
     *
     * @param parte Parte de reparacion finalizado del que se generara la cadena
     * de texto con sus datos.
     * @return Cadena de texto con los datos del parte de reparacion pendiente.
     */
    public String getSalidaPartePendientes(ParteReparacion parte) {
        //Declaramos una cadena de texto en la que almacenamos todos los datos de un parte de reparacion pendiente de la siguiente forma:
        String cadena = ("\nDatos del parte de reparacion pendiente: "
                + "\n\tCodigo: " + parte.getCodigo()
                + "\n\tD.N.I. del cliente: " + parte.getDniCliente()
                + "\n\tMatricula del vehiculo: " + parte.getMatriculaVehiculo()
                + "\n\tFecha de entrada en el taller: " + getFechaCadenaParte(parte.getFechaEntrada())
                + "\n\tNumero de horas de mano de obra estimadas: " + parte.getHorasEstimadas()
                + "\n\t¿Parte finalizado?: " + getBooleanoCadena(parte.getEstadoReparacion())
                + "\n\tTipo de averia: " + parte.getTipoAveria());
        //Devolvemos la cadena de texto.
        return cadena;
    }

    /**
     * Metodo que devuelve una cadena de texto como forma de selida estandar
     * para mostrar los datos de un parte de reparacion finalizado.
     *
     * @param parte Parte de reparacion finalizado del que se generara la cadena
     * de texto con sus datos.
     * @return Cadena de texto con los datos del parte de reparacion finalizado.
     */
    public String getSalidaParte(ParteReparacion parte) {
        //Declaramos una cadena de texto en la que almacenamos todos los datos de un parte de reparacion finalizados de la siguiente forma:
        String cadena = ("\nDatos del parte de reparacion con codigo: " + parte.getCodigo()
                + "\n\tD.N.I. del cliente: " + parte.getDniCliente()
                + "\n\tMatricula del vehiculo: " + parte.getMatriculaVehiculo()
                + "\n\tFecha de entrada en el taller: " + getFechaCadenaParte(parte.getFechaEntrada())
                + "\n\t¿Parte finalizado?: " + getBooleanoCadena(parte.getEstadoReparacion())
                + "\n\tNumero de horas de mano de obra estimadas: " + parte.getHorasEstimadas()
                + "\n\tNumero de horas de mano de obra reales: " + parte.getHorasReales()
                + "\n\tFecha de salida del taller: " + getFechaCadenaParte(parte.getFechaSalida())
                + "\n\tCuantia de la reparacion (en euros): " + parte.getCuantiaReparacion()
                + "\n\tTipo de averia: " + parte.getTipoAveria());
        //Devolvemos la cadena de texto.
        return cadena;
    }

    /**
     * Metodo para dar de alta a un nuevo cliente.
     */
    public void altaCliente() {
        //Declaramos las cadenas de texto que almacenaran los datos del cliente.
        String nombre, apellidos, direccion, dni;

        //Pedimos la introduccion de cada uno de los datos del cliente.
        nombre = setCadena("Introduzca el nombre del cliente:");
        apellidos = setCadena("Introduzca el apellido del cliente:");
        direccion = setCadena("Introduzca la direccion del cliente:");
        dni = setDniValido();

        //Preguntamos si se quiere seguir con la creacion del cliente.
        if (setBooleano("\n¿Esta seguro de que quiere dar de alta a este cliente en la base de datos?") == false) {
            System.out.println("\nAlta de usuario abortada por el usuario.");
        } else {
            //Finalmente, le pasamos al metodo de creacion de clientes los datos del cliente, para que compruebe si ya existe un cliente con el mismo D.N.I., informando por pantalla del resultado.
            getSalidaCondicional(taller.addCliente(nombre, apellidos, direccion, dni),
                    "\nEl cliente con el D.N.I. " + dni + " ha sido dado de alta en la base de datos correctamente.",
                    "\nEl cliente con el D.N.I. " + dni + " no ha sido dado de alta en la base de datos porque ya existia en la misma.");
        }

        //Se vuelve a cargar el menu de clientes.
        this.gestionMenuCliente();
    }

    /**
     * Metodo para dar de baja a un cliente existente.
     */
    public void bajaCliente() {
        //Primero, se comprueba que sigan quedando clientes en el taller, dependiendo de esto se mostrara un mensaje de advertencia o se pedira que se introduzca el D.N.I, del cliente a dar de baja.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo hay clientes en la base de datos.");
        } else {
            //Se pide el D.N.I. del cliente a borrar.
            String dni = setDniValido();

            //Si el cliente no existe, se avisara por pantalla, sino se mostraran los datos del cliente correspondiente al D.N.I. introducido.
            if (taller.comprobarDni(dni) == false) {
                System.out.println("\nNo existe ningun cliente con el D.N.I. " + dni + " introducido no existe en la base de datos.");
            } else {
                System.out.println(getSalidaCliente(taller.getCliente(dni)));

                //Por ultimo, se pedira la confirmacion para proceder con el borrado del cliente.
                if (setBooleano("\n¿Esta seguro de que quiere dar de baja a este cliente de la base de datos?") == false) {
                    System.out.println("\nBaja de cliente con el D.N.I. " + dni + " abortada por usuario.");
                } else {
                    //Si se confirma el borrado del cliente, se llama al metodo de taller encargado de tal accion pasandole el D.N.I. del cliente como argumento.
                    taller.removeCliente(dni);
                    System.out.println("\nEl cliente con el D.N.I. " + dni + " ha sido dado de baja de la base de datos.");
                }
            }
        }

        //Se vuelve a cargar el menu de clientes.
        this.gestionMenuCliente();
    }

    /**
     * Metodo para consultar los datos de un cliente.
     */
    public void consultarCliente() {
        //Primero, se comprueba que sigan quedando clientes en el taller.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo hay clientes en la base de datos.");
        } else {
            //Se pide el D.N.I. del cliente a consultar.
            String dni = setDniValido();

            //Si el cliente existe se muestran sus datos, sino, se muestra un aviso por pantalla.
            getSalidaCondicional(taller.comprobarDni(dni) == true,
                    getSalidaCliente(taller.getCliente(dni)),
                    "\nNo existe ningun cliente con el D.N.I. " + dni + " en la base de datos.");
        }

        //Se vuelve a cargar el menu de clientes.
        this.gestionMenuCliente();
    }

    /**
     * Metodo para consultar los datos de todos los clientes.
     */
    public void consultarTodosCliente() {
        //Primero, se comprueba que sigan quedando clientes en el taller.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo hay clientes en la base de datos.");
        } else {
            //En caso afirmativo, se van mostrados los datos de cada cliente uno por uno.
            for (int i = 0; i < taller.getTodosCliente().size(); i++) {
                System.out.println(getSalidaCliente(taller.getTodosCliente().get(i)));
            }
        }

        //Se vuelve a cargar el menu de clientes.
        this.gestionMenuCliente();
    }

    /**
     * Metodo para modificar todos los datos de un cliente menos su D.N.I.
     */
    public void modificarCliente() {
        boolean opcion;
        //Comprobamos que sigan quedando clientes en el taller.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo hay clientes en la base de datos.");
        } else {
            //Se pide el D.N.I. del cliente a consultar.
            String dni = setDniValido();

            //Si el cliente no existe se muestra un aviso por pantalla.
            if (taller.comprobarDni(dni) == false) {
                System.out.println("\nNo existe ningun cliente con el D.N.I. " + dni + " introducido no existe en la base de datos.");
            } else {
                //Si existe, se muestran sus datos.
                System.out.println(getSalidaCliente(taller.getCliente(dni)));

                //Y se comienza a preguntar si quiere modificar sus datos uno por uno.
                if (setBooleano("\n¿Quiere modificar el nombre de este cliente?:") == true) {
                    taller.getCliente(dni).setNombre(setCadena("Introduzca el nuevo nombre del cliente:"));
                }

                if (setBooleano("\n¿Quiere modificar el apellido del cliente?:") == true) {
                    taller.getCliente(dni).setApellidos(setCadena("Introduzca el nuevo apellido del cliente:"));
                }

                if (setBooleano("\n¿Quiere modificar la direccion del cliente:") == true) {
                    taller.getCliente(dni).setDireccion(setCadena("Introduzca la nueva direccion del cliente:"));
                }

                //Mostrando al final un mensaje de que los datos del cliente han sido modificados.
                System.out.println("\nDatos del cliente con el D.N.I. " + dni + " modificados.");
            }
        }

        //Se vuelve a cargar el menu de clientes.
        this.gestionMenuCliente();
    }

    /**
     * Metodo para dar de alta un nuevo vehiculo.
     */
    public void altaVehiculo() {
        //Declaramos las cadenas de texto que almacenaran la matricula y el modelo del vehiculo.
        String matricula, modelo;
        //El caracter que almacenara el tipo de vehiculo.
        char tipo;
        //La fecha GregorianCalendar que almacenara la fecha de compra del vehiculo.
        GregorianCalendar fechaCompra;
    //El valor booleano que indicara si el vehiculo esta siendo reparado en el taller o no. Este valor solo se modificara cuando el vehiculo sea relacionado con un parte de reparacion 
        //y este sea creado o finalizado.
        boolean enReparacion = false;

        //Pedimos la introduccion de los datos del vehiculo.
        matricula = setCadena("Introduzca la matricula del vehiculo:");
        modelo = setCadena("Introduzca el modelo del vehiculo:");
        tipo = setTipoVehiculo();
        fechaCompra = setFechaValida("Fecha de compra del vehiculo:");

        //Preguntamos si se quiere seguir con la creacion del vehiculo.
        if (setBooleano("\n¿Esta seguro de que quiere dar de alta a este vehiculo en la base de datos?") == false) {
            System.out.println("\nAlta de vehiculo abortada por el usuario.");
        } else {
            //Finalmente, le pasamos al metodo de creacion de vehiculos los datos del vehiculos, para que compruebe si ya existe un vehiculo con la misma matricula, informando por pantalla del resultado.
            getSalidaCondicional(taller.addVehiculo(matricula, modelo, tipo, fechaCompra, enReparacion),
                    "\nEl vehiculo con la matricula " + matricula + " ha sido dado de alta en la base de datos correctamente.",
                    "\nEl vehiculo con la matricula " + matricula + " no ha sido dado de alta en la base de datos porque ya existia en la misma.");
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para dar de baja un vehiculo existente.
     */
    public void bajaVehiculo() {
        //Primero, se comprueba que sigan quedando vehiculos en la lista del taller.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos.");
        } else {
            //Se pide la matricula del vehiculo a borrar.
            String matricula = setCadena("Introduzca la matricula del vehiculo a dar de baja en la base de datos:");

            //Si el vehiculo no existe, se avisara por pantalla, sino se mostraran los datos del vehiculo correspondiente a la matricula introducida.
            if (taller.comprobarMatricula(matricula) == false) {
                System.out.println("\nNo existe ningun vehiculo con la matricula " + matricula + " en la base de datos.");
            } else {
                System.out.println(getSalidaVehiculo(taller.getVehiculo(matricula)));

                //Por ultimo, se pedira la confirmacion para proceder con el borrado del vehiculo.
                if (setBooleano("\n¿Esta seguro de que quiere dar de baja a este vehiculo de la base de datos?") == false) {
                    System.out.println("\nBaja de vehiculo con la matricula " + matricula + " abortada por usuario.");
                } else {
                    //Si se confirma el borrado del vehiculo, se llama al metodo de taller encargado de tal accion pasandole la matricula del vehiculo como argumento.
                    taller.removeVehiculo(matricula);
                    System.out.println("\nEl vehiculo con la matricula " + matricula + " ha sido dado de baja de la base de datos.");
                }
            }
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para consultar los datos de un vehiculo.
     */
    public void consultarVehiculo() {
        //Primero, se comprueba que sigan quedando vehiculos en la lista del taller.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos.");
        } else {
            //Se pide la matricula del vehiculo a consultar.
            String matricula = setCadena("Introduzca la matricula del vehiculo del que consultar los datos:");

            //Si el vehiculo existe se muestran sus datos, sino, se muestra un aviso por pantalla.
            getSalidaCondicional(taller.comprobarMatricula(matricula) == true,
                    getSalidaVehiculo(taller.getVehiculo(matricula)),
                    "\nNo existe ningun vehiculo con la matricula " + matricula + " en la base de datos.");
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para consultar los datos de todos los vehiculos.
     */
    public void consultarTodosVehiculo() {
        //Primero, se comprueba que sigan quedando vehiculos en la lista del taller.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos");
        } else {
            //En caso afirmativo, se van mostrados los datos de cada vehiculo uno por uno.
            for (int i = 0; i < taller.getTodosVehiculo().size(); i++) {
                System.out.println(getSalidaVehiculo(taller.getTodosVehiculo().get(i)));
            }
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para modificar todos los datos de un vehiculo menos su matricula.
     */
    public void modificarVehiculo() {
        //Primero, se comprueba que sigan quedando vehiculos en la lista del taller.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos.");
        } else {
            //Se pide la matricula del vehiculo a consultar.
            String matricula = setCadena("Introduzca la matricula del vehiculo al que se modificaran los datos:");

            //Si el vehiculo no existe, se muestra un aviso por pantalla.
            if (taller.comprobarMatricula(matricula) == false) {
                System.out.println("\nNo existe ningun vehiculo con la matricula " + matricula + " en la base de datos.");
            } else {
                //Si existe, se muestran sus datos.
                System.out.println(getSalidaVehiculo(taller.getVehiculo(matricula)));

                //Y se comienza a preguntar si quiere modificar sus datos uno por uno.
                if (setBooleano("\n¿Quiere modificar el modelo del vehiculo?") == true) {
                    taller.getVehiculo(matricula).setModelo(setCadena("Introduzca el nuevo modelo del vehiculo:"));
                }

                if (setBooleano("\n¿Quiere modificar el tipo del vehiculo:") == true) {
                    taller.getVehiculo(matricula).setTipo(setTipoVehiculo());
                }

                if (setBooleano("\n¿Quiere modificar la fecha de compra del vehiculo:") == true) {
                    taller.getVehiculo(matricula).setFechaCompra(setFechaValida("Introduzca fecha de compra del vehiculo:"));
                }

                //Mostrando al final un mensaje de que los datos del vehiculo han sido modificados.
                System.out.println("\nDatos del vehiculo con la matricula " + matricula + " modificados.");
            }
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para mostrar todas las reparaciones que han sido realizadas a un
     * mismo vehiculo.
     */
    public void historialVehiculo() {
        //Primero, se comprueba que sigan quedando vehiculos en la lista del taller.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos.");
        } else {
            //Se pide la matricula del vehiculo a consultar historial.
            String matricula = setCadena("Introduzca la matricula del vehiculo del que quiere obtener su historial de reparaciones:");

            //Si no existen ningun vehiculo con esa matricula se muestra un aviso.
            if (taller.comprobarMatricula(matricula) == false) {
                System.out.println("\nNo existe ningun vehiculo con la matricula " + matricula + " en la base de datos.");
            } else {

                //Si no existe ningun parte de reparacion de ese vehiculo, se mostrara un aviso.
                if (taller.getHistorialVehiculo(matricula).size() == 0) {
                    System.out.println("\nEl vehiculo con la matricula " + matricula + " nunca ha sido reparado en el taller.");
                } else {
                    //Si existen partes de reparacion, se mostraran sus datos.
                    System.out.println("\nReparaciones del vehiculo con la matricula " + matricula + ":");

                    for (int i = 0; i < taller.getHistorialVehiculo(matricula).size(); i++) {
                        //Dependiendo de si el parte de reparacion esta finalizado, se mostrara de una o otro forma.
                        getSalidaCondicional(taller.getHistorialVehiculo(matricula).get(i).getEstadoReparacion() == false,
                                getSalidaPartePendientes(taller.getHistorialVehiculo(matricula).get(i)),
                                getSalidaParte(taller.getHistorialVehiculo(matricula).get(i)));
                    }
                }
            }
        }

        //Se vuelve a cargar el menu de vehiculos.
        this.gestionMenuVehiculo();
    }

    /**
     * Metodo para crear un parte de reparacion.
     */
    public void crearParte() {
        //Declaramos un entero que almacenara el valor correspondiente al siguiente codigo de parte de reparacion, este sera generado automaticamente.
        int codigo = taller.getCodigoParteReparacion();
        //Cadenas de texto del D.N.I. del cliente, matricula del vehiculo y descripcion de la averia.
        String dniCliente, matriculaVehiculo, tipoAveria;
        //Fecha GregorianCalendar de la fecha de entrada en el taller del vehiculo.
        GregorianCalendar fechaEntrada = new GregorianCalendar();
        //Como la fecha de salida del taller del vehiculo es todavia desconocida, declaramos una fecha GregorianCalendar con contenido nulo.
        GregorianCalendar fechaSalida = new GregorianCalendar();
        //Variable booleana que indique si el parte de reparacion esta finalizado o no.
        boolean estadoReparacion = false;
        //Variables enteras para las horas estimas y reales de reparacion.
        int horasEstimadas, horasReales = 0;
        //Variable real para el coste de la reparacion.
        double cuantiaReparacion = 0.0;
        //Objeto de la clase Random para poder generar un numero aleatorio para las horas estimadas.
        Random aleatorio = new Random();

        //Primero, se comprueba que sigan quedando clientes en la lista del taller.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo se pueden crear nuevos partes de reparacion porque no existen cliente en la base de datos.");
        } else {

            //Luego, se comprueba que sigan quedando vehiculos en la lista del taller.
            if (taller.getTodosVehiculo().size() == 0) {
                System.out.println("\nNo se pueden crear nuevos partes de reparacion porque no existen vehiculos en la base de datos.");
            } else {

                horasEstimadas = 0;
                //Se asigna un valor aleatorio para las horas estimadas que tiene que estar entre 1 y 100.
                do {
                    horasEstimadas = aleatorio.nextInt(101);
                } while (horasEstimadas == 0);

                //Mostramos el codigo del parte que se esta creando.
                System.out.println("\nParte de reparacion Nº: " + codigo + "\n");

                //Pedimos la introduccion del D.N.I. del cliente y la matricula del vehiculo, pero teniendo en cuenta que estos deben existir en el taller.
                dniCliente = setDniValidoExistente();
                matriculaVehiculo = setMatriculaExistente();

                //Introducimos una breve descripcion sobre la averia.
                tipoAveria = setCadena("Introduzca el tipo de averia: ");

                System.out.println("\n_________________________________________________________________\n");

                //Mostramos la fecha y hora de entrada en el taller y el numero de horas estimadas para la reparacion del vehiculo.
                System.out.println("Fecha de entrada del vehiculo en el taller: " + getFechaCadenaParte(fechaEntrada));
                System.out.println("Numero de horas de mano de obra estimadas: " + horasEstimadas);

                //Pedimos la confirmacion de que el parte de reparacion sea creado.
                if (setBooleano("\n¿Esta seguro de que quiere crear este parte de reparacion en la base de datos?") == false) {
                    System.out.println("\nCreacion de parte de reparacion abortada por el usuario.");
                } else {

                    //Aunque a un vehiculo se le realicen varias reparaciones en el taller en una misma visita, cada visita de un vehiculo solo podra ser representada por un unico parte de reparacion.
                    if (taller.getListadoPartePendientesMatriculas(matriculaVehiculo) == false) //Por lo tanto, si ya hay un vehiculo con esa misma matricula siendo reparado en el taller, no se le puede crear un nuevo parte de reparacion.
                    {
                        System.out.println("\nEl parte de reparacion con el codigo " + codigo + " no ha sido añadido a la base de datos porque el vehiculo con la matricula " + matriculaVehiculo + " esta siendo"
                                + " reparado actualmente en el taller.");
                    } else {
                        //En caso contrario, el parte de reparacion sera creado con los valores introducidos y se mostrara un aviso de que el parte ha sido creado.
                        taller.addParte(codigo, dniCliente, matriculaVehiculo, fechaEntrada, estadoReparacion, horasEstimadas, horasReales, fechaSalida, cuantiaReparacion, tipoAveria);
                        System.out.println("\nEl parte de reparacion con el codigo " + codigo + " ha sido añadido a la base de datos.");

                        //El valor booleano que indica que el vehiculo esta siendo reparado en el taller, cambiara a positivo.
                        taller.getVehiculo(matriculaVehiculo).setEnReparacion(true);
                    }
                }
            }
        }

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para finalizar un parte de reparacion pendiente.
     */
    public void finalizarParte() {
        //Primero, se comprueba que sigan quedando partes de reparacion pendientes en la lista del taller.
        if (taller.getListadoPartePendientes().size() == 0) {
            System.out.println("\nNo hay partes de reparacion pendientes de finalizar.");
        } else {
            //Se declara un entero que almacenara el codigo del primer parte de reparacion pendiente de finalizar.
            int codigo = taller.getListadoPartePendientes().get(0).getCodigo();

            //Se muestran los datos del parte de reparacion a finalizar.
            System.out.println("\nProximo parte de reparacion a finalizar:");
            System.out.println(getSalidaPartePendientes(taller.getParte(codigo)));

            //Y se pide la confirmacion de la finalizacion del parte.
            if (setBooleano("\n¿Quiere finalizar este parte?") == false) {
                System.out.println("\nFinalizacion de parte de reparacion abortada por usuario.");
            } else {
                //Se genera una fecha GregorianCalendar con la fecha actual que corresponderia a la finalizacion de la reparacion.
                GregorianCalendar fechaSalida = new GregorianCalendar();

                //La fecha de salida se modifica a la generada como actual.
                taller.getParte(codigo).setFechaSalida(fechaSalida);

                //Las horas reales se calculan con la funcion creada para tal fin, pasandole como parametros las fechas de entrada y salida.
                taller.getParte(codigo).setHorasReales(getDiferenciaHoras(taller.getParte(codigo).getFechaEntrada(), taller.getParte(codigo).getFechaSalida()));

                //Se cambia el estado del parte de reparacion a finalizado.
                taller.getParte(codigo).setEstadoReparacion(true);

                //Pedimos que se introduzca la cuantia correspondiente a la reparacion del vehiculo.
                taller.getParte(codigo).setCuantiaReparacion(setDouble("Introduzca la cuantia de la reparacion (en euros y centimos):"));

                //La descripcion final de las reparaciones realizadas al vehiculo.
                taller.getParte(codigo).setTipoAveria(setCadena("Introduzca el tipo de averia reparada:"));

                //El valor booleano que indica que el vehiculo esta siendo reparado en el taller, cambiara a negativo.
                taller.getVehiculo(taller.getParte(codigo).getMatriculaVehiculo()).setEnReparacion(false);

                //Se muestra mensaje de que parte de reparacion ha sido finalizado mostrando la fecha y hora actual.
                System.out.println("\nEl parte de reparacion ha sido finalizado con fecha y hora: " + getFechaCadenaParte(fechaSalida));
            }
        }

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para consultar todos los partes de reparacion pendientes.
     */
    public void consultarPartePendientes() {
        //Primero, se comprueba que sigan quedando partes de reparacion pendientes en la lista del taller.
        if (taller.getListadoPartePendientes().size() == 0) {
            System.out.println("\nNo hay partes de reparacion pendientes de finalizar.");
        } else {
            for (int i = 0; i < taller.getListadoPartePendientes().size(); i++) //En caso afirmativo, se van mostrados los datos de cada parte de reparacion pendiente uno por uno.
            {
                System.out.println(getSalidaPartePendientes(taller.getListadoPartePendientes().get(i)));
            }
        }

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para consultar todos los partes de reparacion de un mismo cliente.
     */
    public void consultarParteCliente() {
        //Se pide el D.N.I. del cliente a consultar partes de reparacion.
        String dni = setDniValido();

        //Si el cliente no existe se muestra un aviso.
        if (taller.getListadoParteCliente(dni).size() == 0) {
            System.out.println("\nEl cliente con el D.N.I. " + dni + " nunca ha reparado un vehiculo en el taller.");
        } else {
            //Si existe, se muestran los datos de todos sus partes de reparacion.
            System.out.println("\nEl cliente con el D.N.I. " + dni + " tiene los siguientes partes de reparacion asociados: ");

            for (int i = 0; i < taller.getListadoParteCliente(dni).size(); i++) {
                getSalidaCondicional(taller.getListadoParteCliente(dni).get(i).getEstadoReparacion() == false,
                        getSalidaPartePendientes(taller.getListadoParteCliente(dni).get(i)),
                        getSalidaParte(taller.getListadoParteCliente(dni).get(i)));
            }
        }

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para consultar el numero de horas totales invertidas en las
     * reparaciones de vehiculos finalizadas.
     */
    public void consultarMediaHoras() {
        //Declaramos un entero que almacenara el resultado del celculo del numero total de partes de reparacion finalizados.
        int partesFinalizados = (taller.getDimensionListaParteReparacion()) - (taller.getListadoPartePendientes().size());

        //Y mostramos el numero de partes de reparacion finalizados, el numero de horas reales totales y la media de horas reales por partes finalizados.
        System.out.println("\nNumero de partes de reparacion finalizados: " + partesFinalizados);
        //La horas reales las obtenemos de la llamada a una funcion de taller creada para tal fin.
        System.out.println("Numero de horas reales totales de reparaciones: " + taller.getHorasRealesParteFinalizados());
        //La horas medias las obtenemos realizando un sencillo celculo entre horas reales totales y total de partes finalizados.
        System.out.println("\nNumero de horas reales medias por parte finalizado: " + taller.getHorasRealesParteFinalizados() / partesFinalizados);

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para modificar las horas de reparacion estimadas del parte de
     * reparacion de un mismo cliente y vehiculo.
     */
    public void modificarHorasEstimadas() {
        //Declaramos las cadenas de texto para la introduccion del D.N.I. del cliente y la matricula del vehiculo del parte de reparacion pendiente al que se le modificaran las horas estimadas.
        String dni, matricula;

        //Primero, se comprueba que sigan quedando partes de reparacion pendientes en la lista del taller.
        if (taller.getListadoPartePendientes().size() == 0) {
            System.out.println("\nNo existen partes de reparacion pendientes en la base de datos.");
        } else {

            //Si siguen quedando, se pide el D.N.I. del cliente.
            dni = setDniValido();
            //Si no existe ningun cliente con el D.N.I. introducido, se muestra un aviso por pantalla.
            if (taller.comprobarDni(dni) == false) {
                System.out.println("\nNo existe ningun cliente con el D.N.I. " + dni + " en la base de datos.");
            } else {

                //Sino, se mostrara un aviso en caso de que el cliente no tenga actualmente ningun vehiculo siendo reparado en el taller.
                if (taller.getListadoPartePendientesCliente(dni).size() == 0) {
                    System.out.println("\nEl cliente con el D.N.I. " + dni + " no tiene actualmente ningun vehiculo pendiente de reparar en el taller.");
                } else {
                    //Sino, se pedira la matricula del vehiculo
                    matricula = setMatriculaExistente();

                    //Si no existen ningun parte de reparacion con ese D.N.I. y esa matricula, se mostrara un aviso.
                    if (taller.getListadoPartePendientesVehiculo(taller.getListadoPartePendientesCliente(dni), matricula).size() == 0) {
                        System.out.println("\nEl cliente con el D.N.I. " + dni + " no tiene actualmente ningun vehiculo con la matricula " + matricula + " pendiente de ser reparado en el taller.");
                    } else {
                        //Sino, se mostraran los datos del parte de reparacion pendiente.
                        System.out.println("\nParte de reparacion pendiente del cliente con el D.N.I. " + matricula + " y el vehiculo con la matricula " + matricula + " :");

                        System.out.println(getSalidaPartePendientes(taller.getParte(taller.getListadoPartePendientesVehiculo(
                                taller.getListadoPartePendientesCliente(dni), matricula).get(0).getCodigo())));

                        //Y se pedira confirmacion de la modificacion de la horas estimadas de reparacion.
                        if (setBooleano("\n¿Quiere modificar las horas de reparacion estimadas de este parte de reparacion?") == false) {
                            System.out.println("\nModificacion de las horas de reparacion estimadas del parte de reparacion abortada por usuario.");
                        } else {
                            //Se piden que se introduzcan las horas estimadas para el parte de reparacion con el codigo del parte de reparacion pendiente del D.N.I. y matricula introducidos.
                            taller.getParte(taller.getListadoPartePendientesVehiculo(taller.getListadoPartePendientesCliente(dni), matricula).get(0).getCodigo()).setHorasEstimadas(setEntero(
                                    "Introduzca las horas estimadas correctas"
                                    + " para este parte de reparacion pendiente"));
                            //Se muestra un aviso de que las horas estimadas del parte de reparacion han sido modificadas.
                            System.out.println("\nLas horas de reparacion estimadas del parte de reparacion con codigo "
                                    + taller.getListadoPartePendientesVehiculo(taller.getListadoPartePendientesCliente(dni), matricula).get(0).getCodigo() + " han sido actualizadas.");
                        }
                    }
                }
            }
        }

        //Se vuelve a cargar el menu de partes de reparacion.
        this.gestionMenuParteReparacion();
    }

    /**
     * Metodo para generar la salida por pantalla de todos los clientes,
     * vehiculos y partes de reparacion existentes en el taller.
     */
    public void generarEstadoGeneral() {
        System.out.println("\nCLIENTES CONTENIDOS EN LA BASE DE DATOS: ");
        //Se comprueba que existen clientes, si existen, se muestran los datos de todos, uno por uno.
        if (taller.getTodosCliente().size() == 0) {
            System.out.println("\nNo hay clientes en la base de datos.");
        } else {
            for (int i = 0; i < taller.getTodosCliente().size(); i++) {
                System.out.println(getSalidaCliente(taller.getTodosCliente().get(i)));
            }
        }

        System.out.println("\n\nVEHICULOS CONTENIDOS EN LA BASE DE DATOS: ");
        //Se comprueba que existen vehiculos, si existen, se muestran los datos de todos, uno por uno.
        if (taller.getTodosVehiculo().size() == 0) {
            System.out.println("\nNo hay vehiculos en la base de datos");
        } else {
            for (int i = 0; i < taller.getTodosVehiculo().size(); i++) {
                System.out.println(getSalidaVehiculo(taller.getTodosVehiculo().get(i)));
            }
        }

        System.out.println("\n\nPARTES DE REPARACION CONTENIDOS EN LA BASE DE DATOS: ");
        //Se muestran los datos de todos los partes de reparacion.
        for (int i = 0; i < taller.getTodosParte().size(); i++) {
            getSalidaCondicional(taller.getTodosParte().get(i).getEstadoReparacion() == false,
                    getSalidaPartePendientes(taller.getTodosParte().get(i)),
                    getSalidaParte(taller.getTodosParte().get(i)));
        }

        System.out.println("\n\n\n\n");

        //Se vuelve a cargar el menu principal.
        this.gestionMenuPrincipal();
    }

    /**
     * Metodo para crear los clientes, vehiculos y partes de reparacion
     * predeterminados del taller.
     */
    public void generarDatosIniciales() {
        //Creamos los clientes predeterminados.
        this.taller.addCliente("Josechu", "Leton", "", "23457698K");
        this.taller.addCliente("Carmelo", "Coton", "", "13789745F");
        this.taller.addCliente("Encarna", "Vales", "", "20943218X");

        //Ahora, los vehiculos predeterminados.
        this.taller.addVehiculo("GR-9999-XY", "Seat Anda", Vehiculo.TIPO_TURISMO, new GregorianCalendar(1990, Calendar.JANUARY, 1), true);
        this.taller.addVehiculo("1234 BCD", "Ferrari Lentini", Vehiculo.TIPO_TURISMO, new GregorianCalendar(2008, Calendar.NOVEMBER, 12), false);
        this.taller.addVehiculo("4321 DCB", "Locar Gatodo", Vehiculo.TIPO_FURGONETA, new GregorianCalendar(2005, Calendar.JANUARY, 4), true);
        this.taller.addVehiculo("GR-0000-A", "Troncomovil Cicleta++", Vehiculo.TIPO_MOTOCICLETA, new GregorianCalendar(1834, Calendar.MARCH, 2), false);

        //Y finalmente, los partes de reparacion predeterminados.
        this.taller.addParte(1, "23457698K", "1234 BCD", new GregorianCalendar(2009, Calendar.MAY, 10), true, 10, 8, new GregorianCalendar(2009, Calendar.MAY, 12), 250.0, "Embrague roto");
        this.taller.addParte(2, "23457698K", "GR-0000-A", new GregorianCalendar(2009, Calendar.JULY, 1), true, 56, 64, new GregorianCalendar(2009, Calendar.JULY, 8), 2500.0, "Chapa y pintura completo");
        this.taller.addParte(3, "13789745F", "GR-9999-XY", new GregorianCalendar(2009, Calendar.OCTOBER, 22), false, 15, 0, new GregorianCalendar(), 0.0, "Fallo general de la electricidad. Se ha cambiado la dinamo."
                + " Continuamos con las pruebas.");
        this.taller.addParte(4, "20943218X", "4321 DCB", new GregorianCalendar(2010, Calendar.JANUARY, 5), false, 100, 0, new GregorianCalendar(), 0.0, "Este coche esta hecho polvo. Le fallan hasta los tapones de las"
                + " velvulas de las ruedas. Yo que el dueño le pedia uno nuevo a los Reyes porque vale mas el arreglo que uno nuevo.");
    }

    /**
     * Metodo para mostrar las opciones de un menu.
     *
     * @param titulo Titulo del menu del que mostrar las opciones.
     * @param menu Opciones del menu a mostrar.
     */
    private void mostrarMenu(String titulo, String menu[]) {
        //Muestra el titulo del menu y cada una de sus opciones.
        System.out.println(titulo);
        for (int i = 0; i < menu.length; i++) {
            System.out.println(menu[i]);
        }
    }

    /**
     * Metodo para obtener una seleccion valida de opcion de menu.
     *
     * @param titulo Titulo del menu del que seleccionar una opcion.
     * @param menu Opciones del menu que pueden ser seleccionadas.
     */
    private int elegirOpcionMenu(String titulo, String menu[]) {
        //Declaramos dos enteros, uno para la seleccion de la opcion del menu y otro que representara la maxima opcion valida.
        int opcion, maxOpcion;
        //Asignamos la maxima opcion valida en funcion del tamaño del array de opciones de menu recibido como parametro.
        maxOpcion = menu.length - 1;

        //Mostramos el menu y sus opciones, y realizamos la peticion de una opcion, mientras que la opcion introducida no sea valida.
        do {
            mostrarMenu(titulo, menu);
            opcion = setEntero("\nElige una opcion (0 - " + maxOpcion + "):");
        } while (opcion < 0 || opcion > maxOpcion);

        //Devolvemos la opcion seleccionada.
        return opcion;
    }

    /**
     * Metodo para gestionar las opciones del menu principal.
     */
    public void gestionMenuPrincipal() {
        //Declaramos un entero con el que pedir la opcion del menu a seleccionar, pasando el nombre del menu y las opciones como parametros.
        int opcion = this.elegirOpcionMenu("MENU PRINCIPAL TALLER:\n", menuPrincipal);

        //En funcion de la opcion seleccionada, saldremos del programa, entraremos en uno de los submenus o generaremos el listado con el estado general del taller.
        switch (opcion) {
            case 0:
                System.out.println("\nSaliendo del programa...");
                System.exit(0);
                break;

            case 1:
                this.gestionMenuCliente();
                break;

            case 2:
                this.gestionMenuVehiculo();
                break;

            case 3:
                this.gestionMenuParteReparacion();
                break;

            case 4:
                this.generarEstadoGeneral();
                break;
        }
    }

    /**
     * Metodo para gestionar las opciones del menu de clientes.
     */
    public void gestionMenuCliente() {
        //Declaramos un entero con el que pedir la opcion del menu a seleccionar, pasando el nombre del menu y las opciones como parametros.
        int opcion = this.elegirOpcionMenu("\n\n\n\nMENU CLIENTES:\n", menuCliente);

        //En funcion de la opcion seleccionada, volveremos la menu principal o llamaremos a una de las funciones principales.
        switch (opcion) {
            case 0:
                System.out.print("\n\n\n\n");
                this.gestionMenuPrincipal();
                break;

            case 1:
                System.out.println("\n\n\n\nALTA DE NUEVO CLIENTE:");
                this.altaCliente();
                break;

            case 2:
                System.out.println("\n\n\n\nBAJA DE CLIENTE EXISTENTE:");
                this.bajaCliente();
                break;

            case 3:
                System.out.println("\n\n\n\nCONSULTAR DATOS DE CLIENTE:");
                this.consultarCliente();
                break;

            case 4:
                System.out.println("\n\n\n\nCONSULTAR DATOS DE TODOS LOS CLIENTES EXISTENTES:");
                this.consultarTodosCliente();
                break;

            case 5:
                System.out.println("\n\n\n\nMODIFICAR DATOS DE UN CLIENTE:");
                this.modificarCliente();
                break;
        }
    }

    /**
     * Metodo para gestionar las opciones del menu de vehiculos.
     */
    public void gestionMenuVehiculo() {
        //Declaramos un entero con el que pedir la opcion del menu a seleccionar, pasando el nombre del menu y las opciones como parametros.
        int opcion = this.elegirOpcionMenu("\n\n\n\nMENU VEHICULOS:\n", menuVehiculo);

        //En funcion de la opcion seleccionada, volveremos la menu principal o llamaremos a una de las funciones principales.
        switch (opcion) {
            case 0:
                System.out.print("\n\n\n\n");
                this.gestionMenuPrincipal();
                break;

            case 1:
                System.out.println("\n\n\n\nALTA DE NUEVO VEHICULO:");
                this.altaVehiculo();
                break;

            case 2:
                System.out.println("\n\n\n\nBAJA DE VEHICULOS EXISTENTES:");
                this.bajaVehiculo();
                break;

            case 3:
                System.out.println("\n\n\n\nCONSULTAR DATOS DE VEHICULO:");
                this.consultarVehiculo();
                break;

            case 4:
                System.out.println("\n\n\n\nCONSULTAR DATOS DE TODOS LOS VEHICULOS EXISTENTES:");
                this.consultarTodosVehiculo();
                break;

            case 5:
                System.out.println("\n\n\n\nMODIFICAR DATOS DE UN VEHICULO:");
                this.modificarVehiculo();
                break;

            case 6:
                System.out.println("\n\n\n\nHISTORIAL DE REPARACIONES DE UN VEHICULO: ");
                this.historialVehiculo();
                break;
        }
    }

    /**
     * Metodo para gestionar las opciones del menu de partes de reparacion.
     */
    public void gestionMenuParteReparacion() {
        //Declaramos un entero con el que pedir la opcion del menu a seleccionar, pasando el nombre del menu y las opciones como parametros.
        int opcion = this.elegirOpcionMenu("\n\n\n\nMENU PARTES DE REPARACION", menuParteReparacion);

        //En funcion de la opcion seleccionada, volveremos la menu principal o llamaremos a una de las funciones principales.
        switch (opcion) {
            case 0:
                System.out.print("\n\n\n\n");
                this.gestionMenuPrincipal();
                break;

            case 1:
                System.out.println("\n\n\n\nCREACION DE NUEVO PARTE DE REPARACION:");
                this.crearParte();
                break;

            case 2:
                System.out.println("\n\n\n\nFINALIZACION DE PARTE DE REPARACION PENDIENTE:");
                this.finalizarParte();
                break;

            case 3:
                System.out.println("\n\n\n\nLISTADO DE TODOS LOS PARTES PENDIENTES DE FINALIZAR:");
                this.consultarPartePendientes();
                break;

            case 4:
                System.out.println("\n\n\n\nLISTADO DE TODOS LOS PARTES DE UN CLIENTE:");
                this.consultarParteCliente();
                break;

            case 5:
                System.out.println("\n\n\n\nPROMEDIO DE HORAS REALES EN PARTES DE REPARACION:");
                this.consultarMediaHoras();
                break;

            case 6:
                System.out.println("\n\n\n\nMODIFICAR NºMERO DE HORAS ESTIMADAS EN PARTE DE REPARACION:");
                this.modificarHorasEstimadas();
                break;
        }
    }

    /**
     * Metodo principal de la clase.
     */
    public static void main(String args[]) {
        //Creamos un objeto de esta misma clase para poder usar los metodos creados.
        GestionTaller gestionador = new GestionTaller();
        //Generamos los datos predeterminados.
        gestionador.generarDatosIniciales();
        //Mostramos el menu principal.
        gestionador.gestionMenuPrincipal();
    }
}
