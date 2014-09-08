package formas;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Paint;

/**
 * Atributos de pintado de las figuras dibujadas.
 *
 * @author German Martinez Maldonado
 */
public class AtribCompuesto {

    private Paint colorTrazoFrente;
    private Paint colorRellenoFondo;
    private BasicStroke trazo;
    private float grosorTrazo;
    private boolean trazoContinuo;
    private int relleno;

    /**
     * Constructor de atributos de pintado de las figuras dibujadas.
     */
    public AtribCompuesto() {
        colorTrazoFrente = Color.BLACK;
        colorRellenoFondo = Color.BLACK;
        trazo = new BasicStroke(1.0f);
        grosorTrazo = 1.0f;
        trazoContinuo = true;
        relleno = GFigura.SIN_RELLENO;
    }

    /**
     * Establece el conjunto de propiedades de pintado de la figura.
     *
     * @param colorTrazoFrente Color de trazo o frente de degradado.
     * @param colorRellenoFondo Color de relleno o fondo de degradado.
     * @param valorGrosor Valor del grosor del trazo de las figuras.
     * @param trazoContinuo Verdadero si el trazo de la figura es continuo,
     * falso en caso contrario.
     * @param tipoRelleno Tipo de relleno con el que se pintará la figura.
     */
    public void setPropiedades(Color colorTrazoFrente, Color colorRellenoFondo, float valorGrosor, boolean trazoContinuo, int tipoRelleno) {
        setColorTrazoFrente(colorTrazoFrente);
        setColorRellenoFondo(colorRellenoFondo);
        setGrosorTrazo(valorGrosor);
        setContinuidadTrazo(trazoContinuo);
        setRelleno(tipoRelleno);
    }

    /**
     * Devuelve color de trazo o frente de degradado.
     *
     * @return Color de trazo o frente de degradado.
     */
    public Paint getColorTrazoFrente() {
        return colorTrazoFrente;
    }

    /**
     * Devuelve color de relleno o fondo de degradado.
     *
     * @return Color de fondo o frente de degradado.
     */
    public Paint getColorRellenoFondo() {
        return colorRellenoFondo;
    }

    /**
     * Devuelve trazo de pintado de la figura.
     *
     * @return Trazo de pintado de la figura.
     */
    public BasicStroke getTrazo() {
        return trazo;
    }

    /**
     * Devuelve grosor del trazo de pintado de la figura.
     *
     * @return Grosor del trazo de pintado de la figura.
     */
    public float getGrosorTrazo() {
        return grosorTrazo;
    }

    /**
     * Devuelve si el trazo es continuo o no.
     *
     * @return Verdadero si el trazo es continuo, falso en caso contrario.
     */
    public boolean getTrazoContinuo() {
        return trazoContinuo;
    }

    /**
     * Devuelve el tipo de relleno.
     *
     * @return Valor que representa el tipo de relleno con el que se pintarán
     * las imagenes.
     * @see formas.GFigura Interfaz que define los diferentes tipos de relleno
     * posibles.
     */
    public int getRelleno() {
        return relleno;
    }

    /**
     * Asigna color de trazo o frente de degradado.
     *
     * @param colorTrazoFrente Color de trazo o frente de degradado.
     */
    public void setColorTrazoFrente(Paint colorTrazoFrente) {
        this.colorTrazoFrente = colorTrazoFrente;
    }

    /**
     * Asigna color de relleno o fondo de degradado.
     *
     * @param colorRellenoFondo Color de relleno o fondo de degradado.
     */
    public void setColorRellenoFondo(Paint colorRellenoFondo) {
        this.colorRellenoFondo = colorRellenoFondo;
    }

    /**
     * Asigna grosor al trazo con el que se pintarán las figuras.
     *
     * @param grosorTrazo Grosor del trazo.
     */
    public void setGrosorTrazo(float grosorTrazo) {
        this.grosorTrazo = grosorTrazo;

        if (trazoContinuo) {
            trazo = new BasicStroke(grosorTrazo);
        } else {
            trazo = new BasicStroke(grosorTrazo, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND,
                    10.0f, new float[]{10.0f}, 0.0f);
        }
    }

    /**
     * Asigna si el trazo con el que se pintarán las figuras es continuo o no.
     *
     * @param trazoContinuo Valor verdadero para trazo continuo, valor falso
     * para trazo punteado.
     */
    public void setContinuidadTrazo(boolean trazoContinuo) {
        this.trazoContinuo = trazoContinuo;

        if (trazoContinuo) {
            trazo = new BasicStroke(grosorTrazo);
        } else {
            trazo = new BasicStroke(grosorTrazo, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND,
                    1.0f, new float[]{10.0f}, 1.0f);
        }
    }

    /**
     * Asigna el tipo de relleno con el que se pintará la figura.
     *
     * @param tipoRelleno Tipo de relleno seleccionado.
     * @see formas.GFigura Interfaz que define los diferentes tipos de relleno
     * posibles.
     */
    public void setRelleno(int tipoRelleno) {
        relleno = tipoRelleno;
    }
}
