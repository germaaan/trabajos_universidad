package formas;

import utilidad.LienzoImagen;
import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics2D;
import java.awt.RadialGradientPaint;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.TexturePaint;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;

/**
 * Dibujante de cualquier tipo de figura.
 * @author German Martinez Maldonado
 */
public class Dibujante {

    private GFigura figura;
    
    /**
     * Constructor del dibujante de figuras.
     * @param figura Figura a la que está asociado el dibujante.
     */
    public Dibujante(GFigura figura){
        this.figura = figura;
    }
    
    /**
     * Método de clase que nos permitirá pintar cualquier tipo de figura
     * independientemente del tipo que sea y de sus propiedades.
     *
     * @param g2d Graphics2D en el que pintar la figura.
     */
    public void draw(Graphics2D g2d) {
        AtribCompuesto propiedades = figura.getPropiedades();
        RenderingHints rha, rhai, rhcr, rhf, rhr, rhsn, rhii = null;

        if (LienzoImagen.getAntialiasing()) {
            rha = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        } else {
            rha = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_OFF);
        }

        if (LienzoImagen.getAlphaInterpolation()) {
            rhai = new RenderingHints(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
        } else {
            rhai = new RenderingHints(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_SPEED);
        }

        if (LienzoImagen.getColorRendering()) {
            rhcr = new RenderingHints(RenderingHints.KEY_COLOR_RENDERING, RenderingHints.VALUE_COLOR_RENDER_QUALITY);
        } else {
            rhcr = new RenderingHints(RenderingHints.KEY_COLOR_RENDERING, RenderingHints.VALUE_COLOR_RENDER_SPEED);
        }

        if (LienzoImagen.getDithering()) {
            rhf = new RenderingHints(RenderingHints.KEY_DITHERING, RenderingHints.VALUE_DITHER_ENABLE);
        } else {
            rhf = new RenderingHints(RenderingHints.KEY_DITHERING, RenderingHints.VALUE_DITHER_DISABLE);
        }

        if (LienzoImagen.getRendering()) {
            rhr = new RenderingHints(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
        } else {
            rhr = new RenderingHints(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_SPEED);
        }

        if (LienzoImagen.getStrokeNormalization()) {
            rhsn = new RenderingHints(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_NORMALIZE);
        } else {
            rhsn = new RenderingHints(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
        }

        switch (LienzoImagen.getImageInterpolation()) {
            case LienzoImagen.INTER_BILINEAL:
                rhii = new RenderingHints(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR);
                break;
            case LienzoImagen.INTER_VECINO:
                rhii = new RenderingHints(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);
                break;
            default:
                rhii = new RenderingHints(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BICUBIC);
                break;
        }

        g2d.setRenderingHints(rha);
        g2d.setRenderingHints(rhai);
        g2d.setRenderingHints(rhcr);
        g2d.setRenderingHints(rhf);
        g2d.setRenderingHints(rhr);
        g2d.setRenderingHints(rhsn);
        g2d.setRenderingHints(rhii);

        if (figura instanceof GLinea) {
            g2d.setPaint(propiedades.getColorTrazoFrente());
            g2d.setStroke(propiedades.getTrazo());
        } else {
            double ancho = figura.getAnchura();
            double alto = figura.getAltura();
            double centroX = figura.getCentroX();
            double centroY = figura.getCentroY();
            double radio = figura.getRadio();

            g2d.setStroke(propiedades.getTrazo());

            switch (propiedades.getRelleno()) {
                case GFigura.RELLENO_LISO:
                    g2d.setPaint(propiedades.getColorRellenoFondo());
                    g2d.fill((Shape) figura);
                case GFigura.SIN_RELLENO:
                    g2d.setPaint(propiedades.getColorTrazoFrente());
                    break;
                case GFigura.DEGRADADO_HORIZONTAL:
                    GradientPaint horizontal = new GradientPaint(0, 0, (Color) propiedades.getColorTrazoFrente(),
                            (float) ancho, 0, (Color) propiedades.getColorRellenoFondo());
                    g2d.setPaint(horizontal);
                    g2d.fill((Shape) figura);
                    break;
                case GFigura.DEGRADADO_VERTICAL:
                    GradientPaint vertical = new GradientPaint(0, 0, (Color) propiedades.getColorTrazoFrente(),
                            0, (float) alto, (Color) propiedades.getColorRellenoFondo());
                    g2d.setPaint(vertical);
                    g2d.fill((Shape) figura);
                    break;
                case GFigura.DEGRADADO_RADIAL:
                    Color[] colores = {(Color) propiedades.getColorTrazoFrente(), (Color) propiedades.getColorRellenoFondo()};
                    float[] distribucion = {0.0f, 0.5f};
                    RadialGradientPaint radial = new RadialGradientPaint((float) centroX, (float) centroY,
                            (float) radio, distribucion, colores);
                    g2d.setPaint(radial);
                    g2d.fill((Shape) figura);
                    break;
                case GFigura.IMAGEN:
                    try {
                        BufferedImage img = ImageIO.read(new File("./lib/icon/smiley.png"));
                        Rectangle2D tam = new Rectangle2D.Double(0.0d, 0.0d, 25.0d, 25.0d);
                        g2d.setPaint(new TexturePaint(img, tam));
                        g2d.fill((Shape) figura);
                    } catch (Exception ex) {
                        System.err.println("Error: Error al abrir el patrón de relleno. " + ex.getMessage());
                    }

                    break;
            }
        }

        g2d.draw((Shape) figura);
    }
}
