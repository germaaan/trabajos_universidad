package formas;

import java.awt.Graphics2D;
import java.awt.geom.Point2D;

/**
 * Interfaz que define el comportamiento que tienen que tener todas las figuras.
 *
 * @author German Martinez Maldonado
 */
public interface GFigura {

    /**
     * Tipo de relleno vacio.
     */
    public final static int SIN_RELLENO = 0;
    /**
     * Tipo de relleno liso.
     */
    public final static int RELLENO_LISO = 1;
    /**
     * Tipo de relleno con degradado horizontal.
     */
    public final static int DEGRADADO_HORIZONTAL = 2;
    /**
     * Tipo de relleno con degradado vertical.
     */
    public final static int DEGRADADO_VERTICAL = 3;
    /**
     * Tipo de relleno con degradado radial.
     */
    public final static int DEGRADADO_RADIAL = 4;
    /**
     * Tipo de relleno basado en un patrón de imágenes predeterminadas.
     */
    public final static int IMAGEN = 5;

    /**
     * Devuelve el conjunto de propiedades de pintado de la figura.
     *
     * @return Conjunto de propiedades de pintado de la figura.
     */
    public AtribCompuesto getPropiedades();

    /**
     * Devuelve del dibujante de la figura.
     * 
     * @return Dibujante de la figura.
     */
    public Dibujante getDibujante();
    
    /**
     * Devuelve anchura de la figura.
     *
     * @return Anchura de la figura.
     */
    public double getAnchura();

    /**
     * Devuelve altura de la figura.
     *
     * @return Altura de la figura.
     */
    public double getAltura();

    /**
     * Devuelve el eje X de la posición del dentro de la figura.
     *
     * @return Eje X de la posición del centro de la figura.
     */
    public double getCentroX();

    /**
     * Devuelve el eje Y de la posición del dentro de la figura.
     *
     * @return Eje Y de la posición del centro de la figura.
     */
    public double getCentroY();

    /**
     * Devuelve el radio de la figura.
     *
     * @return Radio de la figura.
     */
    public double getRadio();

    /**
     * Establece las coordenadas de la figura.
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    public void setCoordenadas(Point2D p1, Point2D p2);

    /**
     * Devuelve si un punto está contenido en el interior de la zona ocupada por
     * una figura pintada.
     *
     * @param p Punto a comprobar si se encuentra en el interior de una figura.
     * @return Verdadero si el punto se encuentra en el interior de la figura,
     * falso en caso contrario.
     */
    public boolean contiene(Point2D p);

    /**
     * Establece una nueva posición para la figura.
     *
     * @param p Punto de nueva posición para la figura.
     */
    public void setPosicion(Point2D p);
}
