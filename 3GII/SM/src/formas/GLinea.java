package formas;

import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

/**
 * Figura "Línea".
 * @author German Martinez Maldonado
 */
public class GLinea extends Line2D.Double implements GFigura {

    private AtribCompuesto propiedades;
        private Dibujante dibujante;

    /**
     * Constructor de figura "Línea".
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    public GLinea(Point2D p1, Point2D p2) {
        super(p1, p2);
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
     * Establece las coordenadas de la figura.
     *
     * @param p1 Punto de origen de la figura.
     * @param p2 Punto final de la figura.
     */
    @Override
    public void setCoordenadas(Point2D p1, Point2D p2) {
        setLine(p1, p2);
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
        return ptLineDist(p) <= 5.0;
    }

    /**
     * Establece una nueva posición para la figura.
     *
     * @param pos Punto de nueva posición para la figura.
     */
    @Override
    public void setPosicion(Point2D pos) {
        double dx = pos.getX() - getX1();
        double dy = pos.getY() - getY1();

        Point2D newp2 = new Point2D.Double(getX2() + dx, getY2() + dy);
        setLine(pos, newp2);
    }

    /**
     * Método abstracto obligatorio por la interfaz GFigura. Sin aplicación para
     * una figura de tipo "línea".
     *
     * @return
     * @see formas.GFigura Interfaz que implementa esta clase y declara dicho
     * método abstracto.
     */
    @Override
    public double getAnchura() {
        return 0.0d;
    }

    /**
     * Método abstracto obligatorio por la interfaz GFigura. Sin aplicación para
     * una figura de tipo "línea".
     *
     * @return
     * @see formas.GFigura Interfaz que implementa esta clase y declara dicho
     * método abstracto.
     */
    @Override
    public double getAltura() {
        return 0.0d;
    }

    /**
     * Método abstracto obligatorio por la interfaz GFigura. Sin aplicación para
     * una figura de tipo "línea".
     *
     * @return
     * @see formas.GFigura Interfaz que implementa esta clase y declara dicho
     * método abstracto.
     */
    @Override
    public double getCentroX() {
        return 0.0d;
    }

    /**
     * Método abstracto obligatorio por la interfaz GFigura. Sin aplicación para
     * una figura de tipo "línea".
     *
     * @return
     * @see formas.GFigura Interfaz que implementa esta clase y declara dicho
     * método abstracto.
     */
    @Override
    public double getCentroY() {
        return 0.0d;
    }

    /**
     * Método abstracto obligatorio por la interfaz GFigura. Sin aplicación para
     * una figura de tipo "línea".
     *
     * @return
     * @see formas.GFigura Interfaz que implementa esta clase y declara dicho
     * método abstracto.
     */
    @Override
    public double getRadio() {
        return 0.0d;
    }
}
