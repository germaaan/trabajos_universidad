
/**
 * Clase que representa los clientes de un taller.
 *
 * @author German Martinez Maldonado
 * @version 1.0, 22/02/10
 */
public class Cliente {

    //DeclaraciOn de los datos miembros como privados para que no puedan ser modificados directamente desde fuera de la clase.
    private String apellidos;
    private String nombre;
    private String direccion;
    private String dni;

    /**
     * Crea un cliente a partir de los parametros pasados.
     *
     * @param apellidos Apellidos del cliente.
     * @param nombre Nombre del cliente.
     * @param direccion Direccion del cliente.
     * @param dni D.N.I. del cliente. No habra dos clientes como el mismo D.N.I.
     */
    public Cliente(String apellidos, String nombre, String direccion, String dni) {
        //Se almacenan en cada uno de los datos miembros los valores pasados como parametros.
        this.apellidos = apellidos;
        this.nombre = nombre;
        this.direccion = direccion;
        this.dni = dni;
    }

    /**
     * Metodo que devuelve los apellidos del cliente.
     *
     * @return Devuelve los apellidos del cliente.
     */
    public String getApellidos() {
        return this.apellidos;
    }

    /**
     * Metodo que modifica los apellidos del cliente.
     *
     * @param apellidos Nuevos apellidos del cliente que se quieren guardar.
     */
    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    /**
     * Metodo que devuelve el nombre del cliente.
     *
     * @return Devuelve el nombre del cliente.
     */
    public String getNombre() {
        return this.nombre;
    }

    /**
     * Metodo que modifica el nombre del cliente.
     *
     * @param nombre Nuevo nombre del cliente que se quiere guardar.
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * Metodo que devuelve la direccion del cliente.
     *
     * @return Devuelve la direccion del cliente.
     */
    public String getDireccion() {
        return this.direccion;
    }

    /**
     * Metodo que modifica la direccion del cliente.
     *
     * @param direccion Nueva direccion del cliente que se quiere guardar.
     */
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    /**
     * Metodo que devuelve el D.N.I. del cliente.
     *
     * @return Devuelve el D.N.I. del cliente.
     */
    public String getDni() {
        return this.dni;
    }

    /**
     * Metodo que modifica el D.N.I. del cliente.
     *
     * @param dni Nuevo D.N.I. del cliente que se quiere guardar.
     */
    public void setDni(String dni) {
        this.dni = dni;
    }
}
