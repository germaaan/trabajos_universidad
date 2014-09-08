//Importamos la siguiente clase para poder trabajar con fecha tipo GregorianCalendar

import java.util.GregorianCalendar;

/**
 * Clase que representa los partes de reparacion que son creados cada vez que un
 * cliente lleva un vehiculo a reparar al taller.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 22/02/10
 */
public class ParteReparacion {

    //DeclaraciOn de los datos miembros como privados para que no puedan ser modificados directamente desde fuera de la clase.
    private int codigo;
    private String dniCliente;
    private String matriculaVehiculo;
    //Todas las fechas seran del tipo GregorianCalendar.
    private GregorianCalendar fechaEntrada;
    //El valor del booleano sera "true" mientras el parte de reparacion no esta finalizado y "false" desde el momento que el mismo sea finalizado.
    private boolean estadoReparacion;
    private int horasEstimadas;
    private int horasReales;
    private GregorianCalendar fechaSalida;
    private double cuantiaReparacion;
    private String tipoAveria;

    /**
     * Crea un parte de reparacion a partir de los parametros pasados.
     *
     * @param codigo Codigo identificador de un parte de reparacion. No habra
     * dos partes de reparacion con el mismo codigo, ademas sera generado
     * automaticamente.
     * @param dniCliente D.N.I. del cliente que lleva el vehiculo a reparar al
     * taller.
     * @param matriculaVehiculo Matricula del vehiculo que esta siendo reparado
     * en el taller.
     * @param fechaEntrada Fecha de entrada del vehiculo en el taller para su
     * reparacion.
     * @param estadoReparacion Valor booleano que indica si un parte de
     * reparacion esta finalizado o no.
     * @param horasEstimadas Horas que se estiman se tardara en reparar el
     * vehiculo cuando este llega al taller.
     * @param horasReales Horas reales que se ha tardado en reparar el vehiculo.
     * @param fechaSalida Fecha de salida del vehiculo del taller.
     * @param cuantiaReparacion Cantidad en euros que debera pagar el cliente
     * por la reparacion realizada en el vehiculo.
     * @param tipoAveria Indicacion de la averia que puede tener el coche, asi
     * como su posible reparacion realizada.
     */
    public ParteReparacion(int codigo, String dniCliente, String matriculaVehiculo, GregorianCalendar fechaEntrada, boolean estadoReparacion, int horasEstimadas, int horasReales,
            GregorianCalendar fechaSalida, double cuantiaReparacion, String tipoAveria) {
        //Se almacenan en cada uno de los datos miembros los valores pasados como parametros.
        this.codigo = codigo;
        this.dniCliente = dniCliente;
        this.matriculaVehiculo = matriculaVehiculo;
        this.fechaEntrada = fechaEntrada;
        this.estadoReparacion = estadoReparacion;
        this.horasEstimadas = horasEstimadas;
        this.horasReales = horasReales;
        this.fechaSalida = fechaSalida;
        this.cuantiaReparacion = cuantiaReparacion;
        this.tipoAveria = tipoAveria;
    }

    /**
     * Metodo que devuelve el codigo identificador de un parte de reparacion.
     *
     * @return Devuelve el codigo identificador de un parte de reparacion.
     */
    public int getCodigo() {
        return this.codigo;
    }

    /**
     * Metodo que modifica el codigo identificador de un parte de reparacion.
     *
     * @param codigo Guarda el codigo identificador del parte de reparacion.
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    /**
     * Metodo que devuelve el D.N.I del cliente que lleva el vehiculo al taller.
     *
     * @return Devuelve el D.N.I del cliente que lleva el vehiculo al taller.
     */
    public String getDniCliente() {
        return this.dniCliente;
    }

    /**
     * Metodo que modifica el D.N.I del cliente que lleva el vehiculo al taller.
     *
     * @param dniCliente Nuevo D.N.I. del cliente que lleva el vehiculo al
     * taller que se quiere guardar.
     */
    public void setDniCliente(String dniCliente) {
        this.dniCliente = dniCliente;
    }

    /**
     * Metodo que devuelve la matricula del vehiculo que es llevado al taller
     * para ser reparado.
     *
     * @return Devuelve la matricula del vehiculo que es llevado al taller para
     * ser reparado.
     */
    public String getMatriculaVehiculo() {
        return this.matriculaVehiculo;
    }

    /**
     * Metodo que modifica la matricula del vehiculo que es llevado al taller
     * para ser reparado.
     *
     * @param matriculaVehiculo Nueva matricula del vehiculo llevado al taller
     * para ser reparado que se quiere guardar.
     */
    public void setMatriculaVehiculo(String matriculaVehiculo) {
        this.matriculaVehiculo = matriculaVehiculo;
    }

    /**
     * Metodo que devuelve la fecha en la que es llevado el vehiculo al taller.
     *
     * @return Devuelve la fecha en la que es llevado el vehiculo al taller.
     */
    public GregorianCalendar getFechaEntrada() {
        return this.fechaEntrada;
    }

    /**
     * Metodo que modifica la fecha en la que es llevado el vehiculo al taller.
     *
     * @param fechaEntrada Nueva fecha de entrada del vehiculo en el taller que
     * se quiere guardar.
     */
    public void setFechaEntrada(GregorianCalendar fechaEntrada) {
        this.fechaEntrada = fechaEntrada;
    }

    /**
     * Metodo que devuelve si el parte de reparacion esta finalizado o no.
     *
     * @return Devuelve un valor booleano que indica si el parte de reparacion
     * esta finalizado o no.
     */
    public boolean getEstadoReparacion() {
        return this.estadoReparacion;
    }

    /**
     * Metodo que modifica si el parte de reparacion esta finalizado o no.
     *
     * @param estadoReparacion Nuevo valor booleano que indica si el parte de
     * reparacion esta finalizado o no, que se quiere guardar.
     */
    public void setEstadoReparacion(boolean estadoReparacion) {
        this.estadoReparacion = estadoReparacion;
    }

    /**
     * Metodo que devuelve el numero de horas estimadas para la reparacion del
     * vehiculo.
     *
     * @return Devuelve el numero de horas estimadas para la reparacion del
     * vehiculo.
     */
    public int getHorasEstimadas() {
        return this.horasEstimadas;
    }

    /**
     * Metodo que modifica el numero de horas estimas para la reparacion del
     * vehiculo que se quiere guardar.
     *
     * @param horasEstimadas Nuevo numero de horas estimas para la reparacion
     * del vehiculo que se quiere guardar.
     */
    public void setHorasEstimadas(int horasEstimadas) {
        this.horasEstimadas = horasEstimadas;
    }

    /**
     * Metodo que devuelve el numero de horas reales que finalmente son
     * necesarias para reparar el vehiculo.
     *
     * @return Devuelve el numero de horas reales que finalmente son necesarias
     * para reparar el vehiculo.
     */
    public int getHorasReales() {
        return this.horasReales;
    }

    /**
     * Metodo que modifica el numero de horas reales que finalmente son
     * necesarias para reparar el vehiculo.
     *
     * @param horasReales Nuevo numero de horas reales que finalmente son
     * necesarias para reparar el vehiculo que se quiere guardar.
     */
    public void setHorasReales(int horasReales) {
        this.horasReales = horasReales;
    }

    /**
     * Metodo que devuelve la fecha de salida del vehiculo del taller.
     *
     * @return Devuelve la fecha de salida del vehiculo del taller.
     */
    public GregorianCalendar getFechaSalida() {
        return this.fechaSalida;
    }

    /**
     * Metodo que modifica la fecha de salida del vehiculo del taller que se
     * quiere guardar.
     *
     * @param fechaSalida Nueva fecha de salida del vehiculo del taller que se
     * quiere guardar.
     */
    public void setFechaSalida(GregorianCalendar fechaSalida) {
        this.fechaSalida = fechaSalida;
    }

    /**
     * Metodo que devuelve el importe en euros que debera pagar el cliente por
     * la reparacion del vehiculo.
     *
     * @return Devuelve el importe en euros que debera pagar el cliente por la
     * reparacion del vehiculo.
     */
    public double getCuantiaReparacion() {
        return this.cuantiaReparacion;
    }

    /**
     * Metodo que modifica el importe en euros que debera pagar el cliente por
     * la reparacion del vehiculo.
     *
     * @param cuantiaReparacion Nuevo importe en euros de debera pagar el
     * cliente por la reparacion del vehiculo que se quiere guardar.
     */
    public void setCuantiaReparacion(double cuantiaReparacion) {
        this.cuantiaReparacion = cuantiaReparacion;
    }

    /**
     * Metodo que devuelve la indicacion de la averia que puede tener el coche,
     * asi como su posible reparacion.
     *
     * @return Devuelve la indicacion de la averia que puede tener el coche, asi
     * como su posible reparacion.
     */
    public String getTipoAveria() {
        return this.tipoAveria;
    }

    /**
     * Metodo que modifica la indicacion de la averia que puede tener el coche,
     * asi como su posible reparacion.
     *
     * @param tipoAveria Nueva indicacion de la averia que puede tener el coche,
     * asi como su posible reparacion que se quiere guardar.
     */
    public void setTipoAveria(String tipoAveria) {
        this.tipoAveria = tipoAveria;
    }
}
