//Importamos la siguiente clase para poder trabajar con fechas tipo GregorianCalendar

import java.util.GregorianCalendar;

/**
 * Clase que representa los vehiculos que pueden ser reparados en un taller.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 22/02/10
 */
public class Vehiculo {

    //DeclaraciOn de los datos miembros como privados para que no puedan ser modificados directamente desde fuera de la clase.
    private String matricula;
    private String modelo;
    private char tipo;
  //Como el valor del dato miembro "tipo" solo podra ser uno de los tres siguientes, almacenamos dichos valores en tres constantes estaticas, ya que no cambiaran su valor durante toda la ejecucion.
    //Y ademas al ser estaticas, estaran vinculadas a la clase, y no a una instancia concreta de la misma.
    /**
     * Constante estatica que representa uno de los posibles tipos de vehiculo:
     * turismo.
     */
    public static final char TIPO_TURISMO = 't';
    /**
     * Constante estatica que representa uno de los posibles tipos de vehiculo:
     * furgoneta.
     */
    public static final char TIPO_FURGONETA = 'f';
    /**
     * Constante estatica que representa uno de los posibles tipos de vehiculo:
     * motocicleta.
     */
    public static final char TIPO_MOTOCICLETA = 'm';
    //Todas las fechas seran del tipo GregorianCalendar.
    private GregorianCalendar fechaCompra;
    //El valor del booleano sera "true" cuando el vehiculo se encuentre en reparacion y "false" cuando no.
    private boolean enReparacion;

    /**
     * Crea un vehiculo a partir de los parametros pasados.
     *
     * @param matricula Matricula del vehiculo. No habra dos vehiculos con la
     * misma matricula.
     * @param modelo Modelo del vehiculo.
     * @param tipo Tipo del vehiculo. Puede ser <b>turismo, furgoneta o
     * motocicleta</b>.
     * @param fechaCompra Fecha de compra del vehiculo.
     * @param enReparacion Valor booleano que indica si el vehiculo esta siendo
     * reparado actualmente o no.
     */
    public Vehiculo(String matricula, String modelo, char tipo, GregorianCalendar fechaCompra, boolean enReparacion) {
        //Se almacenan en cada uno de los datos miembros los valores pasados como parametros.
        this.matricula = matricula;
        this.modelo = modelo;
        this.tipo = tipo;
        this.fechaCompra = fechaCompra;
        this.enReparacion = enReparacion;
    }

    /**
     * Crea un vehiculo a partir de los datos de otro vehiculo pasado como
     * argumento. Aunque por lo general siempre se usara el constructor
     * anterior, para simplificar la tarea de ordenar los vehiculos por sus
     * matriculas, usaremos este constructor cuando haya que hacer la copia de
     * los valores un vehiculo a otro vehiculo de forma temporal, para realizar
     * el intercambio de posiciones. Como este constructor solo se usara para
     * tal fin, solo sera usado por el metodo <b>intercambiar()</b> de la clase
     * <b>Taller</b>.
     *
     * @param vehiculo Vehiculo del que obtendremos los valores para crear el
     * nuevo vehiculo.
     */
    public Vehiculo(Vehiculo vehiculo) {
        //Se almacenan en cada uno de los datos miembros los valores de los datos miembros de la instancia de la misma clase pasada como argumento.
        this.matricula = vehiculo.matricula;
        this.modelo = vehiculo.modelo;
        this.tipo = vehiculo.tipo;
        this.fechaCompra = vehiculo.fechaCompra;
        this.enReparacion = vehiculo.enReparacion;
    }

    /**
     * Metodo que devuelve la matricula del vehiculo.
     *
     * @return Devuelve la matricula del vehiculo.
     */
    public String getMatricula() {
        return this.matricula;
    }

    /**
     * Metodo que modifica la matricula del vehiculo.
     *
     * @param matricula Nuevo matricula del vehiculo que se quiere guardar.
     */
    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    /**
     * Metodo que devuelve el modelo del vehiculo.
     *
     * @return Devuelve el modelo del vehiculo.
     */
    public String getModelo() {
        return this.modelo;
    }

    /**
     * Metodo que modifica el modelo del vehiculo.
     *
     * @param modelo Nuevo modelo del vehiculo que se quiere guardar.
     */
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    /**
     * Metodo que devuelve el tipo de vehiculo.
     *
     * @return Devuelve el tipo de vehiculo.
     */
    public char getTipo() {
        return this.tipo;
    }

    /**
     * Metodo que modifica el tipo de vehiculo.
     *
     * @param tipo Nuevo tipo de vehiculo que se quiere guardar. Este siempre
     * sera una de las tres constantes estaticas definidas en la clase.
     */
    public void setTipo(char tipo) {
        this.tipo = tipo;
    }

    /**
     * Metodo que devuelve la fecha de compra del vehiculo.
     *
     * @return Devuelve la fecha de compra del vehiculo.
     */
    public GregorianCalendar getFechaCompra() {
        return this.fechaCompra;
    }

    /**
     * Metodo que modifica la fecha de compra del vehiculo.
     *
     * @param fechaCompra Nuevo fecha de compra del vehiculo que se quiere
     * guardar.
     */
    public void setFechaCompra(GregorianCalendar fechaCompra) {
        this.fechaCompra = fechaCompra;
    }

    /**
     * Metodo que devuelve si el vehiculo esta siendo reparado actualmente en el
     * taller o no.
     *
     * @return Devuelve un valor booleano que indica si el vehiculo esta siendo
     * reparado actualmente en el taller o no.
     */
    public boolean getEnReparacion() {
        return this.enReparacion;
    }

    /**
     * Metodo que modifica si el vehiculo esta siendo reparado actualmente en el
     * taller o no.
     *
     * @param enReparacion Nuevo valor booleano que indica si el coche esta
     * siendo reparado en el taller o no, que se quiere guardar.
     */
    public void setEnReparacion(boolean enReparacion) {
        this.enReparacion = enReparacion;
    }
}
