package formas;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.geom.Dimension2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;

/**
 * Figura "Trazo Libre".
 * @author German Martinez Maldonado
 */
public class GTrazoLibre extends GeneralPath.Double implements GFigura {

    private AtribCompuesto propiedades;
        private Dibujante dibujante;

    /**
     * Constructor de figura "Trazo Libre".
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    public GTrazoLibre(Point2D p1, Point2D p2) {
        super();
        moveTo(p1.getX(), p1.getY());

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
        return getBounds2D().getWidth();
    }

    /**
     * Devuelve altura de la figura.
     *
     * @return Altura de la figura.
     */
    @Override
    public double getAltura() {
        return getBounds2D().getHeight();
    }

    /**
     * Devuelve el eje X de la posición del dentro de la figura.
     *
     * @return Eje X de la posición del centro de la figura.
     */
    @Override
    public double getCentroX() {
        return (getBounds2D().getMaxX() - getBounds2D().getMinX()) / 2;
    }

    /**
     * Devuelve el eje Y de la posición del dentro de la figura.
     *
     * @return Eje Y de la posición del centro de la figura.
     */
    @Override
    public double getCentroY() {
        return (getBounds2D().getMaxY() - getBounds2D().getMinY()) / 2;
    }

    /**
     * Devuelve el radio de la figura.
     *
     * @return Radio de la figura.
     */
    @Override
    public double getRadio() {
        return getBounds2D().getMaxX() - getCentroX();
    }

    /**
     * Establece las coordenadas de la figura.
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    @Override
    public void setCoordenadas(Point2D p1, Point2D p2) {
        lineTo(p2.getX(), p2.getY());
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

        dim.setSize(getBounds2D().getWidth(), getBounds2D().getHeight());

        dx = pos.getX() - getBounds2D().getMinX();
        dy = pos.getY() - getBounds2D().getMinY();

        newp2 = new Point2D.Double(dx, dy);
        getBounds2D().setFrame(newp2, dim);
    }
}
