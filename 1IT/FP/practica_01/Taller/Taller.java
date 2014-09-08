//Importamos la siguiente clase para poder trabajar con listas ArrayList

import java.util.ArrayList;
//Importamos la siguiente clase para poder trabajar con fechas tipo GregorianCalendar
import java.util.GregorianCalendar;

/**
 * Clase que representa las listas de clientes, vehiculos y partes de reparacion
 * disponibles en el taller.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 22/02/10
 */
public class Taller {

    //DeclaraciOn de las listas como ArrayList.
    private ArrayList<ParteReparacion> listaParte;
    private ArrayList<Cliente> listaCliente;
    private ArrayList<Vehiculo> listaVehiculo;

    /**
     * Hacemos la reserva de espacio para los ArrayList.
     */
    public Taller() {
        listaParte = new ArrayList<ParteReparacion>();
        listaCliente = new ArrayList<Cliente>();
        listaVehiculo = new ArrayList<Vehiculo>();
    }

    /**
     * Metodo que recibe un D.N.I. de un cliente como parametro y compruba si
     * existe algun otro cliente con ese mismo D.N.I. en la lista de los
     * clientes.
     *
     * @param dni El D.N.I. a comprobar.
     * @return Verdadero si existe algun cliente con el mismo D.N.I o falso en
     * caso contrario.
     */
    public boolean comprobarDni(String dni) {
        //Declaramos un entero que almacenara la posicion del cliente con D.N.I. buscado.
        int i;

        //Iniciamos un bucle que recorra toda la lista de clientes, parando si encuentra un cliente con el mismo D.N.I. que se buscaba.
        for (i = 0; i < listaCliente.size(); i++) {
            if (dni.equals(listaCliente.get(i).getDni())) {
                break;
            }
        }

        //Si el entero que se declaro antes tiene un valor inferior que el tamaño de la lista, significa que el D.N.I. buscado ha sido encontrado.
        if (i < listaCliente.size()) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Metodo que recibe como parametros los datos para crear un nuevo cliente.
     *
     * @param nombre El nombre del cliente.
     * @param apellidos Los apellidos del cliente.
     * @param direccion La direccion del cliente.
     * @param dni El D.N.I. del cliente.
     * @return Verdadero si no existe ningun cliente con ese mismo D.N.I., en
     * cuyo caso se ha creado el nuevo cliente, y falso en caso contrario.
     */
    public boolean addCliente(String nombre, String apellidos, String direccion, String dni) {
        //Declaramos un entero que almacenara la posicion del cliente con el D.N.I. buscado, para comprobar si el cliente ya esta dado de alta en el taller.
        int i;

        //Iniciamos un bucle que recorra toda la lista de clientes, parando si encuentra un cliente con el mismo D.N.I. que se buscaba.
        for (i = 0; i < listaCliente.size(); i++) {
            if (dni.equals(listaCliente.get(i).getDni())) {
                break;
            }
        }

        //El cliente solo sera dado de alta, si el entero tiene un valor mayor que el tamaño de la lista, porque eso significara que no existe un cliente con ese D.N.I. en el taller.
        if (i < listaCliente.size()) {
            return false;
        } else {
            listaCliente.add(new Cliente(apellidos, nombre, direccion, dni));
            return true;
        }
    }

    /**
     * Metodo que recibe como parametro el D.N.I. de un cliente para borrarlo de
     * la lista de clientes.
     *
     * @param dni El D.N.I. del cliente a borrar.
     */
    public void removeCliente(String dni) {
        //Declaramos un entero que almacenara la posicion del cliente a borrar.
        int i;

        //Iniciamos un bucle que recorra toda la lista de clientes, parando si encuentra un cliente con el mismo D.N.I. que se buscaba.
        for (i = 0; i < listaCliente.size(); i++) {
            if (dni.equals(listaCliente.get(i).getDni())) {
                break;
            }
        }

        //Se borra de la lista al cliente de la posicion que se encuentre en el entero.
        listaCliente.remove(i);
    }

    /**
     * Metodo que recibe como parametro el D.N.I. de un cliente para obtener el
     * resto de datos del mismo.
     *
     * @param dni El D.N.I. del cliente a buscar.
     * @return El cliente al que pertenece dicho D.N.I.
     */
    public Cliente getCliente(String dni) {
        //Declaramos un entero que almacenara la posicion del cliente del que queremos obtener los datos.
        int i;

        //Iniciamos un bucle que recorra toda la lista de clientes, parando si encuentra un cliente con el mismo D.N.I. que se buscaba.
        for (i = 0; i < listaCliente.size(); i++) {
            if (dni.equals(listaCliente.get(i).getDni())) {
                break;
            }
        }

        //Devolvemos los datos del cliente con el D.N.I. buscado.
        return listaCliente.get(i);
    }

    /**
     * Metodo que devuelve la lista completa con los datos de todos los clientes
     *
     * @return Lista completa de los clientes.
     */
    public ArrayList<Cliente> getTodosCliente() {
        //Devolvemos la lista completa de los clientes.
        return this.listaCliente;
    }

    /**
     * Metodo que recibe una matricula de un vehiculo como parametro y compruba
     * si existe algun otro vehiculo con esa misma matricula en la lista de los
     * vehiculos.
     *
     * @param matricula La matricula a comprobar.
     * @return Verdadero si existe algun vehiculo con la misma matricula o falso
     * en caso contrario.
     */
    public boolean comprobarMatricula(String matricula) {
        //Declaramos un entero que almacenara la posicion del vehiculo con la matricula buscada.
        int i;

        //Iniciamos un bucle que recorra toda la lista de vehiculos, parando si encuentra un vehiculo con la misma matricula que se buscaba.
        for (i = 0; i < listaVehiculo.size(); i++) {
            if (matricula.equals(listaVehiculo.get(i).getMatricula())) {
                break;
            }
        }

        //Si el entero que se declaro antes tiene un valor inferior que el tamaño de la lista, significa que la matricula buscada ha sido encontrada.
        if (i < listaVehiculo.size()) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Metodo que intercambia las posiciones de dos vehiculos en la lista de los
     * vehiculos.
     *
     * @param posOrigen Posicion de uno de los vehiculos a intercambiar de
     * posicion.
     * @param posDestino Posicion del otro de los vehiculos a intercambiar de
     * posicion.
     */
    private void intercambiar(int posOrigen, int posDestino) {
        //Creamos un nuevo vehiculo en el que guardaremos temporalmente los datos del vehiculo de la primera posicion.
        Vehiculo temp = new Vehiculo(listaVehiculo.get(posOrigen));
        //Al vehiculo que se encuentra en la primera posicion, le asignamos los valores del vehiculo de la segunda posicion.
        listaVehiculo.set(posOrigen, listaVehiculo.get(posDestino));
        //Finalmente, al vehiculo de la segunda posicion, le asignamos los valores que guardamos en el vehiculo temporal.
        listaVehiculo.set(posDestino, temp);
    }

    /**
     * Metodo que ordena los vehiculos segun su matricula por el metodo de la
     * burbuja.
     */
    private void ordenarVehiculo() {
        //Declaramos una variable entera para marcar el inicio de la parte desodernada.
        int inicioDesorden = 0;

        //Iniciamos un bucle que se estara ejecutando mientras que el inicio de la parte desordenada no sea la ultima posicion de la lista.
        while (inicioDesorden < listaVehiculo.size()) {

            //Iniciamos otro bucle que a lo largo de toda la lista, ira comprobando que la matricula de un vehiculo previo no sea mayor que la matricula de un vehiculo posterior.
            for (int j = (listaVehiculo.size() - 1); j > inicioDesorden; j--) {
                //En caso de que se cumpla lo anteriormente descrito, los valores de los vehiculos seran intercambiados de posicion.
                if (listaVehiculo.get(j - 1).getMatricula().compareTo(listaVehiculo.get(j).getMatricula()) > 0) {
                    intercambiar(j - 1, j);
                }
            }

            //Una vez comprobado lo anterior, el inicio de la parte desordenada sera aumentado.
            inicioDesorden++;
        }
    }

    /**
     * Metodo que recibe como parametros los datos para crear un nuevo vehiculo.
     *
     * @param matricula La matricula del vehiculo.
     * @param modelo El modelo del vehiculo.
     * @param tipo El tipo del vehiculo.
     * @param fechaCompra La fecha de compra del vehiculo.
     * @param enReparacion El valor booleano que indica si el vehiculo sta
     * siendo reparado en el taller.
     * @return Verdadero si no existe ningun vehiculo con esa misma matricula,
     * en cuyo caso se ha creado el nuevo vehiculo, y falso en caso contrario.
     */
    public boolean addVehiculo(String matricula, String modelo, char tipo, GregorianCalendar fechaCompra, boolean enReparacion) {
        //Declaramos un entero que almacenara la posicion del vehiculo con la matricula buscada, para comprobar si el vehiculo ya esta dado de alta en el taller.
        int i;

        //Iniciamos un bucle que recorra toda la lista de vehiculos, parando si encuentra un vehiculo con la misma matricula que se buscaba.
        for (i = 0; i < listaVehiculo.size(); i++) {
            if (matricula.equals(listaVehiculo.get(i).getMatricula())) {
                break;
            }
        }

        //El vehiculo solo sera dado de alta, si el entero tiene un valor mayor que el tamaño de la lista, porque eso significara que no existe un vehiculo con esa matricula en el taller.
        if (i < listaVehiculo.size()) {
            return false;
        } else {
            listaVehiculo.add(new Vehiculo(matricula, modelo, tipo, fechaCompra, enReparacion));
            ordenarVehiculo();
            return true;
        }
    }

    /**
     * Metodo que recibe como parametro la matricula de un vehiculo para
     * borrarlo de la lista de vehiculos.
     *
     * @param matricula La matricula del vehiculo a borrar.
     */
    public void removeVehiculo(String matricula) {
        //Declaramos una variable que almacenara la posicion del vehiculo a borrar.
        int i;

        //Iniciamos un bucle que recorra toda la lista de vehiculos, parando si encuentra un vehiculo con la misma matricula que se buscaba.
        for (i = 0; i < listaVehiculo.size(); i++) {
            if (matricula.equals(listaVehiculo.get(i).getMatricula())) {
                break;
            }
        }

        //Se borra de la lista al vehiculo de la posicion que se encuentre en la variable.
        listaVehiculo.remove(i);
    }

    /**
     * Metodo que recibe como parametro la matricula de un vehiculo para obtener
     * el resto de datos del mismo.
     *
     * @param matricula La matricula del vehiculo a buscar.
     * @return El vehiculo al que pertenece dicha matricula.
     */
    public Vehiculo getVehiculo(String matricula) {
        //Declaramos una variable que almacenara la posicion del vehiculo del que queremos obtener los datos.
        int i;

        //Iniciamos un bucle que recorra toda la lista de vehiculos, parando si encuentra un vehiculo con la misma matricula que se buscaba.
        for (i = 0; i < listaVehiculo.size(); i++) {
            if (matricula.equals(listaVehiculo.get(i).getMatricula())) {
                break;
            }
        }

        //Devolvemos los datos del vehiculo con la matricula buscada.
        return listaVehiculo.get(i);
    }

    /**
     * Metodo que devuelve la lista completa con los datos de todos los
     * vehiculos.
     *
     * @return Lista completa de los vehiculos.
     */
    public ArrayList<Vehiculo> getTodosVehiculo() {
        //Devolvemos la lista completa de los vehiculos.
        return this.listaVehiculo;
    }

    /**
     * Metodo que recibe como parametro la matricula de un vehiculo para obtener
     * su historial de reparaciones.
     *
     * @param matricula La matricula del vehiculo del que se quiere buscar el
     * historial.
     * @return Lista con los datos de todas las reparaciones llevadas a cabo al
     * vehiculo buscado.
     */
    public ArrayList<ParteReparacion> getHistorialVehiculo(String matricula) {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion de un mismo vehiculo.
        ArrayList<ParteReparacion> listaParteVehiculo = new ArrayList<ParteReparacion>();

        //Iniciamos un bucle que recorra toda la lista de partes de reparacion, si encuentra un parte con un vehiculo con la misma matricula que se buscaba, añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaParte.size(); i++) {
            if (matricula.equals(listaParte.get(i).getMatriculaVehiculo())) {
                listaParteVehiculo.add(listaParte.get(i));
            }
        }

        //Devolvemos la lista creada antes con los partes de reparacion de un mismo vehiculo.
        return listaParteVehiculo;
    }

    /**
     * Metodo que genera el codigo identificador de los partes de reparacion
     *
     * @return El codigo correspondiente al proximo parte a ser creado.
     */
    public int getCodigoParteReparacion() {
        //Declaramos una variable que almacenara un valor mayor en un numero al numero de partes de reparacion existentes, esto es para que no exista ningun parte con el codigo "0".
        int codigo = listaParte.size() + 1;
        //Devolvemos la variable declarara con el codigo almacenado.
        return codigo;
    }

    /**
     * Metodo que recibe como parametros los datos para crear un nuevo parte de
     * reparacion.
     *
     * @param codigo Codigo identificador del parte de reparacion.
     * @param dniCliente El D.N.I. del cliente que lleva el vehiculo al taller.
     * @param matriculaVehiculo La matricula del vehiculo que es llevado al
     * taller.
     * @param fechaEntrada La fecha de entrada del vehiculo en el taller.
     * @param estadoReparacion Valor booleano que sera verdadero si el parte de
     * reparacion esta finalizado y falso en caso contrario.
     * @param horasEstimadas Numero de horas que al llegar el vehiculo al taller
     * son estimadas que seran necesarias para repararlo.
     * @param horasReales Numero de horas reales que han sido necesarias para
     * reparar el vehiculo.
     * @param cuantiaReparacion Cantidad en euros que debera pagar el cliente
     * por la reparacion del vehiculo.
     * @param tipoAveria Indicacion de la averia que puede tener el coche, asi
     * como su posible reparacion realizada.
     */
    public void addParte(int codigo, String dniCliente, String matriculaVehiculo, GregorianCalendar fechaEntrada, boolean estadoReparacion, int horasEstimadas, int horasReales,
            GregorianCalendar fechaSalida, double cuantiaReparacion, String tipoAveria) {
        //Creamos un nuevo parte de reparacion con los valores pasados como parametros.
        listaParte.add(new ParteReparacion(codigo, dniCliente, matriculaVehiculo, fechaEntrada, estadoReparacion, horasEstimadas, horasReales, fechaSalida, cuantiaReparacion, tipoAveria));
    }

    /**
     * Metodo que recibe como parametro la matricula de un vehiculo y busca si
     * hay partes de reparacion pendientes de ese mismo vehiculo.
     *
     * @param matricula Matricula del vehiculo del que buscar todos los partes
     * de reparacion pendiente.
     * @return Verdadero si no hay ningun parte de reparacion pendiente con esa
     * misma matricula y falso en caso contrario.
     */
    public boolean getListadoPartePendientesMatriculas(String matricula) {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion pendientes de un mismo vehiculo.
        ArrayList<ParteReparacion> listaPartePendientesMatriculas = new ArrayList<ParteReparacion>();

    //Iniciamos un bucle que recorra toda la lista de partes de reparacion, si encuentra un parte con un vehiculo con la misma matricula que se buscaba y cuyo estado de reparacion sea pendiente,
        //añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaParte.size(); i++) {
            if (matricula.equals(listaParte.get(i).getMatriculaVehiculo()) && listaParte.get(i).getEstadoReparacion() == false) {
                listaPartePendientesMatriculas.add(listaParte.get(i));
            }
        }

        //Devolvemos un valor booleano verdadero si la lista tiene elementos y uno falso en caso contrario.
        if (listaPartePendientesMatriculas.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Metodo que recibe el codigo de un parte de reparacion como argumento y
     * devuelve los datos del mismo.
     *
     * @param codigo Codigo del parte del que obtener los datos.
     * @return Parte de reparacion correspondiente al codigo pasado como
     * argumento.
     */
    public ParteReparacion getParte(int codigo) {
        //Devolvemos el parte de reparacion de la posicion del codigo pasado como parametro.
        return this.listaParte.get(codigo - 1);
    }

    /**
     * Metodo que devuelve una lista con los datos de todos los partes de
     * reparacion pendientes.
     *
     * @return Lista con todos los partes de reparacion pendientes.
     */
    public ArrayList<ParteReparacion> getListadoPartePendientes() {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion pendientes.
        ArrayList<ParteReparacion> listaPartePendientes = new ArrayList<ParteReparacion>();

        //Iniciamos un bucle que recorra toda la lista de partes de reparacion, si encuentra un parte con un vehiculo con el estado de reparacion pendiente, añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaParte.size(); i++) {
            if (listaParte.get(i).getEstadoReparacion() == false) {
                listaPartePendientes.add(listaParte.get(i));
            }
        }

        //Devolvemos la lista creada antes con los partes de reparacion pendientes.
        return listaPartePendientes;
    }

    /**
     * Metodo que devuelve una lista con los datos de todos los partes de
     * reparacion de un mismo cliente.
     *
     * @param dni D.N.I. del cliente del que buscar los partes de reparacion.
     * @return Lista con todos los partes de reparacion del cliente.
     */
    public ArrayList<ParteReparacion> getListadoParteCliente(String dni) {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion de un cliente.
        ArrayList<ParteReparacion> listaParteCliente = new ArrayList<ParteReparacion>();

        //Iniciamos un bucle que recorra toda la lista de partes de reparacion, si encuentra un parte con un cliente con el mismo D.N.I. que se buscaba, añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaParte.size(); i++) {
            if (dni.equals(listaParte.get(i).getDniCliente())) {
                listaParteCliente.add(listaParte.get(i));
            }
        }

        //Devolvemos la lista creada antes con los partes de reparacion de un mismo cliente.
        return listaParteCliente;
    }

    /**
     * Metodo que devuelve el tamaño de la lista de todos partes de reparacion.
     *
     * return Cantidad de partes de reparacion existentes en la lista de partes
     * de reparacion.
     */
    public int getDimensionListaParteReparacion() {
        int dimension = listaParte.size();
        //Devolvemos el tamaño de la lista de partes de reparacion.
        return dimension;
    }

    /**
     * Metodo que devuelve la suma de las horas reales empleadas en la
     * reparacion de todos los vehiculos reparados en el taller.
     *
     * return Suma de las horas reales de reparacion de todos los partes de
     * reparacion finalizados.
     */
    public int getHorasRealesParteFinalizados() {
        //Declaramos una variable que ira almacenando la suma de las horas reales.
        int suma = 0;

    //Iniciamos un bucle que recorra toda la lista de partes de reparacion, cada vez que se encuentre un parte de reparacion cuyo estado de reparacion sea finalizado, se sumara a la variable 
        //declarada el numero de horas reales del parte de reparacion.
        for (int i = 0; i < listaParte.size(); i++) {
            if (listaParte.get(i).getEstadoReparacion() == true) {
                suma = suma + listaParte.get(i).getHorasReales();
            }
        }

        //Devolvemos el entero con la suma de las horas reales de los partes finalizados.
        return suma;
    }

    /**
     * Metodo que devuelve una lista con los datos de todos los partes de
     * reparacion pendientes de un mismo cliente.
     *
     * @param dni D.N.I. del cliente del que buscar los partes de reparacion
     * pendientes.
     * @return Lista con todos los partes de reparacion pendientes del cliente.
     */
    public ArrayList<ParteReparacion> getListadoPartePendientesCliente(String dni) {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion pendiente de un cliente.
        ArrayList<ParteReparacion> listaPartePendientesCliente = new ArrayList<ParteReparacion>();

    //Iniciamos un bucle que recorra toda la lista de partes de reparacion, si encuentra un parte con un cliente con el mismo D.N.I. que se buscaba y con el estado de la reparacion pendiente,
        //añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaParte.size(); i++) {
            if (dni.equals(listaParte.get(i).getDniCliente()) && listaParte.get(i).getEstadoReparacion() == false) {
                listaPartePendientesCliente.add(listaParte.get(i));
            }
        }

        //Devolvemos la lista creada antes con los partes de reparacion pendientes de un mismo cliente.
        return listaPartePendientesCliente;
    }

    /**
     * Metodo que devuelve una lista con los datos de todos los partes de
     * reparacion pendientes para un mismo cliente con un mismo vehiculo.
     *
     * @param listaPartePendientesCliente Lista con todos los partes de
     * reparacion de un mismo cliente.
     * @param matricula Matricula del vehiculo del que se buscan los partes de
     * reparacion pendientes.
     * @return Lista con todos los partes de reparacion pendientes para un mismo
     * cliente con un mismo vehiculo.
     */
    public ArrayList<ParteReparacion> getListadoPartePendientesVehiculo(ArrayList<ParteReparacion> listaPartePendientesCliente, String matricula) {
        //Declaramos una nueva lista en la que iran guardando los partes de reparacion pendientes de un mismo cliente con un mismo vehiculo.
        ArrayList<ParteReparacion> listaPartePendientesVehiculo = new ArrayList<ParteReparacion>();

    //Iniciamos un bucle que recorra toda la lista de partes de reparacion pendientes de un cliente, si encuentra un parte con un vehiculo con la misma matricula que se buscaba, 
        //añadimos dicho parte a la lista creada antes.
        for (int i = 0; i < listaPartePendientesCliente.size(); i++) {
            if (matricula.equals(listaPartePendientesCliente.get(i).getMatriculaVehiculo())) {
                listaPartePendientesVehiculo.add(listaPartePendientesCliente.get(i));
            }
        }

        //Devolvemos la lista creada antes con los partes de reparacion pendientes de un mismo cliente con un mismo vehiculo.
        return listaPartePendientesVehiculo;
    }

    /**
     * Metodo que devuelve la lista completa con los datos de todos los partes
     * de reparacion.
     *
     * @return Lista completa de los partes de reparacion.
     */
    public ArrayList<ParteReparacion> getTodosParte() {
        //Devolvemos la lista completa de los partes de reparacion.
        return this.listaParte;
    }
}
