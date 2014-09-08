package formas;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.geom.Dimension2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;

/**
 * Figura "Elipse".
 * @author German Martinez Maldonado
 */
public class GElipse extends Ellipse2D.Double implements GFigura {

    private AtribCompuesto propiedades;
        private Dibujante dibujante;

    /**
     * Constructor de figura "Elipse".
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    public GElipse(Point2D p1, Point2D p2) {
        super(p1.getX(), p1.getY(), 0, 0);
        propiedades = new AtribCompuesto();
        dibujante = new Dibujante(this);       
    }

    /**
     * Devuelve el conjunto de propiedades de pintado de la figura.
     *
     * @return Conjunto de propiedades de pintado de la figura.
     */
    @Override
    public AtribCompuesto getPropiedades() {
        return propiedades;
    }

    /**
     * Devuelve del dibujante de la figura.
     * 
     * @return Dibujante de la figura.
     */
    @Override
    public Dibujante getDibujante(){
        return dibujante;
    }
    
    /**
     * Devuelve anchura de la figura.
     *
     * @return Anchura de la figura.
     */
    @Override
    public double getAnchura() {
        return getWidth();
    }

    /**
     * Devuelve altura de la figura.
     *
     * @return Altura de la figura.
     */
    @Override
    public double getAltura() {
        return getHeight();
    }

    /**
     * Devuelve el eje X de la posición del dentro de la figura.
     *
     * @return Eje X de la posición del centro de la figura.
     */
    @Override
    public double getCentroX() {
        return (getMaxX() - getMinX()) / 2;
    }

    /**
     * Devuelve el eje Y de la posición del dentro de la figura.
     *
     * @return Eje Y de la posición del centro de la figura.
     */
    @Override
    public double getCentroY() {
        return (getMaxY() - getMinY()) / 2;
    }

    /**
     * Devuelve el radio de la figura.
     *
     * @return Radio de la figura.
     */
    @Override
    public double getRadio() {
        return getMaxX() - getCentroX();
    }

    /**
     * Establece las coordenadas de la figura.
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    @Override
    public void setCoordenadas(Point2D p1, Point2D p2) {
        setFrameFromDiagonal(p1, p2);
    }

    /**
     * Devuelve si un punto está contenido en el interior de la zona ocupada por
     * una figura pintada.
     *
     * @param p Punto a comprobar si se encuentra en el interior de una figura.
     * @return Verdadero si el punto se encuentra en el interior de la figura,
     * falso en caso contrario.
     */
    @Override
    public boolean contiene(Point2D p) {
        return contains(p);
    }

    /**
     * Establece una nueva posición para la figura.
     *
     * @param pos Punto de nueva posición para la figura.
     */
    @Override
    public void setPosicion(Point2D pos) {
        Dimension2D dim = new Dimension();
        double dx, dy;
        Point2D newp2;

        dim.setSize(getWidth(), getHeight());

        dx = pos.getX() - getMinX();
        dy = pos.getY() - getMinY();

        newp2 = new Point2D.Double(dx, dy);
        setFrame(newp2, dim);
    }
}