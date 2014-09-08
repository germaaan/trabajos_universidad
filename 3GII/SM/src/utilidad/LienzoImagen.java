package utilidad;

import formas.GArco;
import formas.GElipse;
import formas.GTrazoLibre;
import formas.GLinea;
import formas.GRectangulo;
import formas.GFigura;
import formas.GRectRedondeado;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Point2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

/**
 * Panel donde se pintaran todo tipo de imágenes.
 *
 * @author German Martínez Maldonado
 */
public class LienzoImagen extends javax.swing.JPanel {

    /**
     * Figura de pintado "punto".
     */
    public final static int PUNTO = 0;
    /**
     * Figura de pintado "línea".
     */
    public final static int LINEA = 1;
    /**
     * Figura de pintado "rectángulo".
     */
    public final static int RECTANGULO = 2;
    /**
     * Figura de pintado "elipse".
     */
    public final static int ELIPSE = 3;
    /**
     * Figura de pintado "trazo libre".
     */
    public final static int TRAZO_LIBRE = 4;
    /**
     * Figura de pintado "rectángulo redondeado".
     */
    public final static int RECT_REDONDEADO = 5;
    /**
     * Figura de pintado "arco".
     */
    public final static int ARCO = 6;
    /**
     * Color de pintado de trazo o frente de degradado.
     */
    public final static int COLOR_TRAZO_FRENTE = 10;
    /**
     * Color de pintado de relleno o fondo de degradado.
     */
    public final static int COLOR_RELLLENO_FONDO = 11;
    /**
     * Interpolación de imagen "Bicubic"
     */
    public final static int INTER_BICUBICA = 20;
    /**
     * Interpolación de imagen "Bilinear"
     */
    public final static int INTER_BILINEAL = 21;
    /**
     * Interpolación de imagen "Nearest Neighbor"
     */
    public final static int INTER_VECINO = 22;
    
    private static int herramienta;
    private static Color colorTrazoFrente;
    private static Color colorRellenoFondo;
    private static float valorGrosor;
    private static boolean trazoContinuo;
    private static int tipoRelleno;
    
    private static boolean editar;
    private static boolean antialiasing;
    private static boolean alphaInterpolation;
    private static boolean colorRendering;
    private static boolean dithering;
    private static boolean rendering;
    private static boolean strokeNormalization;
    private static int imageInterpolation;
    
    private Point2D punto;
    private GFigura figura;
    private ArrayList<GFigura> vGShape = new ArrayList<>();
    private BufferedImage img;
    private boolean dibujo;

    /**
     * Constructor del panel de pintado de imágenes.
     */
    public LienzoImagen() {
        initComponents();
        dibujo = false;
    }

    /**
     * Pintado de las figuras creadas o imágenes existentes.
     *
     * @param g Graphics donde se pintarán las figuras.
     */
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;

        if (img != null) {
            g2d.drawImage(img, 0, 0, this);
        } else {
            this.setOpaque(false);
            img = new BufferedImage(getWidth(), getHeight(), java.awt.image.BufferedImage.TYPE_INT_ARGB);
            dibujo = true;
        }

        for (GFigura s : vGShape) {
            s.getDibujante().draw(g2d);
        }
    }

    /**
     * Establece el tipo de figura a dibujar.
     *
     * @param herramienta Tipo de figura a dibujar.
     */
    public static void setHerramienta(int herramienta) {
        LienzoImagen.herramienta = herramienta;
    }

    /**
     * Establece el color de trazo o frente de degradado a utilizar.
     *
     * @param colorTrazoFrente Color de trazo o frente de degradado a utilizar.
     */
    public static void setColorTrazoFrente(Color colorTrazoFrente) {
        LienzoImagen.colorTrazoFrente = colorTrazoFrente;
    }

    /**
     * Establece el color de relleno o fondo de degradado a utilizar.
     *
     * @param colorRellenoFondo Color de relleno o fondo de degradado a
     * utilizar.
     */
    public static void setColorRellenoFondo(Color colorRellenoFondo) {
        LienzoImagen.colorRellenoFondo = colorRellenoFondo;
    }

    /**
     * Establece el grosor del trazo con el que dibujar las figuras.
     *
     * @param valorGrosor Grosor del trazo con el que dibujar las figuras.
     */
    public static void setValorGrosor(float valorGrosor) {
        LienzoImagen.valorGrosor = valorGrosor;
    }

    /**
     * Establace la continuidad del trazo con el que dibujar las figuras.
     *
     * @param trazoContinuo Continuidad del trazo: verdadero si es continuo,
     * falso en caso contrario.
     */
    public static void setTrazoContinuo(boolean trazoContinuo) {
        LienzoImagen.trazoContinuo = trazoContinuo;
    }

    /**
     * Establece el tipo de relleno con el que pintar las figuras a dibujar.
     *
     * @param tipoRelleno Tipo de relleno con el que pintar las figuras a
     * dibujar.
     */
    public static void setTipoRelleno(int tipoRelleno) {
        LienzoImagen.tipoRelleno = tipoRelleno;
    }

    /**
     * Establece si está activo el modo de dibujo de figuras o de edición de las
     * mismas.
     *
     * @param editar Modo activado: falso si modo dibujo, verdadero si modo
     * edición.
     */
    public static void setEditar(boolean editar) {
        LienzoImagen.editar = editar;
    }

    /**
     * Establece si está activado la opción de rendering "Antialiasing".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setAntialiasing(boolean valor) {
        LienzoImagen.antialiasing = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Alpha Interpolation".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setAlphaInterpolation(boolean valor) {
        LienzoImagen.alphaInterpolation = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Color Rendering".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setColorRendering(boolean valor) {
        LienzoImagen.colorRendering = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Dithering".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setDithering(boolean valor) {
        LienzoImagen.dithering = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Rendering".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setRendering(boolean valor) {
        LienzoImagen.rendering = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Stroke Normalization".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setStrokeNormalization(boolean valor) {
        LienzoImagen.strokeNormalization = valor;
    }

    /**
     * Establece si está activado la opción de rendering "Imagen Interpolation".
     *
     * @param valor Verdadero si activado, falso en caso contrario.
     */
    public static void setImageInterpolation(int valor) {
        LienzoImagen.imageInterpolation = valor;
    }

    /**
     * Establece la imagen del panel de dibujado.
     *
     * @param imagen Imagen del panel de dibujado.
     */
    public void setImage(BufferedImage imagen) {
        img = imagen;
        setPreferredSize(new Dimension(img.getWidth(), img.getHeight()));
    }

    /**
     * Devuelve el color de trazo o frente de degradado.
     *
     * @return Color de trazo o frente de degradado.
     */
    public static Color getColorTrazoFrente() {
        return LienzoImagen.colorTrazoFrente;
    }

    /**
     * Devuelve el color de relleno o fondo de degradado.
     *
     * @return Color de relleno o fondo de degradado.
     */
    public static Color getColorRellenoFondo() {
        return LienzoImagen.colorRellenoFondo;
    }

    /**
     * Devuelve el grosor del trazo con el que dibujar las figuras.
     *
     * @return Grosor del trazo con el que dibujar las figuras.
     */
    public static float getValorGrosor() {
        return LienzoImagen.valorGrosor;
    }

    /**
     * Devuelve la continuidad del trazo con el que dibujar las figuras.
     *
     * @return Continuidad del trazo: verdadero si es continuo, falso en caso
     * contrario.
     */
    public static boolean getTrazoContinuo() {
        return LienzoImagen.trazoContinuo;
    }

    /**
     * Devuelve el tipo de relleno con el que pintar las figuras a dibujar.
     *
     * @return Tipo de relleno con el que pintar las figuras a dibujar.
     */
    public static int getTipoRelleno() {
        return LienzoImagen.tipoRelleno;
    }

    /**
     * Devuelve si está activado la opción de rendering "Antialiasing".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getAntialiasing() {
        return LienzoImagen.antialiasing;
    }

    /**
     * Devuelve si está activado la opción de rendering "Alpha Interpolation".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getAlphaInterpolation() {
        return LienzoImagen.alphaInterpolation;
    }

    /**
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getColorRendering() {
        return LienzoImagen.colorRendering;
    }

    /**
     * Devuelve si está activado la opción de rendering "Color Rendering".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getDithering() {
        return LienzoImagen.dithering;
    }

    /**
     * Devuelve si está activado la opción de rendering "Dithering".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getRendering() {
        return LienzoImagen.rendering;
    }

    /**
     * Devuelve si está activado la opción de rendering "Rendering".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static boolean getStrokeNormalization() {
        return LienzoImagen.strokeNormalization;
    }

    /**
     * Devuelve si está activado la opción de rendering "Stroke Normalization".
     *
     * @return Verdadero si activado, falso en caso contrario.
     */
    public static int getImageInterpolation() {
        return LienzoImagen.imageInterpolation;
    }

    /**
     * Devuelve la figura seleccionada actualmente.
     *
     * @return Figura seleccionada actualmente.
     */
    public GFigura getFigura() {
        return figura;
    }

    /**
     * Devuelve la imagen del panel de dibujado.
     *
     * @return Imagen del panel de dibujado.
     */
    public BufferedImage getImage() {
        if (dibujo) {
            Graphics2D graphics = img.createGraphics();
            this.print(graphics);
            graphics.dispose();
        }

        return img;
    }

    /**
     * Devuelve si hay una imagen en panel de dibujado.
     *
     * @return Verdadero si solo hay figuras en el panel, falso si hay una
     * imagen asignada al panel.
     */
    public boolean getDibujo() {
        return dibujo;
    }

    /**
     * Obtiene la figura correspondiente a un punto concreto.
     *
     * @param p Punto de la figura a buscar.
     * @return Figura a la que pertenece el punto, "null" si el punto no
     * pertenece a ninguna figura.
     */
    private GFigura getSelectedShape(Point2D p) {
        for (GFigura s : vGShape) {
            if (s.contiene(p)) {
                return s;
            }
        }

        return null;
    }

    /**
     * Crea una figura en un punto.
     *
     * @param point Punto en el que crear la figura.
     */
    private void createShape(Point2D point) {
        switch (LienzoImagen.herramienta) {
            case LienzoImagen.PUNTO:
            case LienzoImagen.LINEA:
                figura = new GLinea(point, point);
                break;
            case LienzoImagen.RECTANGULO:
                figura = new GRectangulo(point, point);
                break;
            case LienzoImagen.ELIPSE:
                figura = new GElipse(point, point);
                break;
            case LienzoImagen.TRAZO_LIBRE:
                figura = new GTrazoLibre(point, point);
                break;
            case LienzoImagen.RECT_REDONDEADO:
                figura = new GRectRedondeado(point, point);
                break;
            case LienzoImagen.ARCO:
                figura = new GArco(point, point);
                break;
        }
    }

    /**
     * Actualizar una figura en referencia a un punto.
     *
     * @param point Punto en torno al que actualizar la figura.
     */
    private void updateShape(Point2D point) {
        if (editar) {
            figura = getSelectedShape(point);

            if (figura != null) {
                figura.setPosicion(point);
            }
        } else {
            figura.setCoordenadas(point, point);
            switch (LienzoImagen.herramienta) {
                case LienzoImagen.PUNTO:
                    figura.setCoordenadas(point, point);
                    break;
                default:
                    figura.setCoordenadas(punto, point);
                    break;
            }

            figura.getPropiedades().setPropiedades(colorTrazoFrente, colorRellenoFondo,
                    valorGrosor, trazoContinuo, tipoRelleno);

            vGShape.add(figura);
        }

        repaint();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setMaximumSize(null);
        setMinimumSize(new java.awt.Dimension(200, 200));
        setPreferredSize(new java.awt.Dimension(400, 400));
        addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                LienzoImagenMousePressed(evt);
            }
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                LienzoImagenMouseReleased(evt);
            }
        });
        addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                LienzoImagenMouseDragged(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Acción que nos permite crear una nueva figura.
     *
     * @param evt Evento que produce el inicio de la acción (pulsar el botón del
     * ratón sobre el lienzo).
     * @see #createShape(java.awt.geom.Point2D) Método que crea la figura.
     */
    private void LienzoImagenMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LienzoImagenMousePressed
        punto = evt.getPoint();
        createShape(evt.getPoint());
    }//GEN-LAST:event_LienzoImagenMousePressed

    /**
     * Acción que nos permite actualizar una figura existente.
     *
     * @param evt Evento que produce el inicio de la acción (arrastrar sobre el
     * lienzo el ratón con un botón pulsado).
     * @see #updateShape(java.awt.geom.Point2D) Método que actualiza la figura.
     */
    private void LienzoImagenMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LienzoImagenMouseDragged
        updateShape(evt.getPoint());
    }//GEN-LAST:event_LienzoImagenMouseDragged

    /**
     * Acción que nos permite actualizar una figura existente. En el caso de un
     * figura de trazo libre cerrado, cerrará dicho trazo libre.
     *
     * @param evt Evento que produce el inicio de la acción (soltar el botón del
     * ratón pulsado).
     * @see #updateShape(java.awt.geom.Point2D) Método que actualiza la figura.
     */
    private void LienzoImagenMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LienzoImagenMouseReleased
        updateShape(evt.getPoint());
        if (LienzoImagen.tipoRelleno != GFigura.SIN_RELLENO) {
            if ((figura != null) && (figura instanceof GTrazoLibre)) {
                ((GTrazoLibre) figura).closePath();
                repaint();
            }
        }
    }//GEN-LAST:event_LienzoImagenMouseReleased
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
