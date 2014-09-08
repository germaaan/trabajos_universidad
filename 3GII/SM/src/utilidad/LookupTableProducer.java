package utilidad;

import java.awt.image.LookupTable;
import java.awt.image.ShortLookupTable;

/**
 *
 * @author Jesus Chamorro
 */
public class LookupTableProducer {

    //Tipos de funciones
    public final static int TYPE_NEGATIVE = 0;
    public final static int TYPE_SFUNCION = 1;
    public final static int TYPE_LOGARITHM = 2;
    public final static int TYPE_POWER = 3;
    public final static int TYPE_ROOT = 4;
    public final static int TYPE_GAMMA_CORRECTION = 5;
    //Constantes
    public final static int MAX_LEVEL = 255;
    public final static double DEFAULT_M_SFUNCTION = 128.0;
    public final static double DEFAULT_E_SFUNCTION = 4.0;
    public final static double DEFAULT_POWER = 2.0;
    public final static double DEFAULT_ROOT = 3.0;
    public final static double DEFAULT_A_GAMMA = 1.0;
    public final static double DEFAULT_GAMMA = 0.4;
    private final static boolean ECHO = false;

    /**
     * Crea objetos LookupTable usando valores por defecto
     */
    public static LookupTable createLookupTable(int type) {
        switch (type) {
            case TYPE_NEGATIVE:
                return negativeFuction();
            case TYPE_SFUNCION:
                return sFuction(DEFAULT_M_SFUNCTION, DEFAULT_E_SFUNCTION);
            case TYPE_LOGARITHM:
                return logarithmFuction();
            case TYPE_POWER:
                return powerFuction(DEFAULT_POWER);
            case TYPE_ROOT:
                return rootFuction(DEFAULT_ROOT);
            case TYPE_GAMMA_CORRECTION:
                return gammaCorrection(DEFAULT_A_GAMMA, DEFAULT_GAMMA);
            default:
                return null;
        }
    }

    /**
     * Función negativo
     */
    public static LookupTable negativeFuction() {
        short lt[] = new short[MAX_LEVEL + 1];
        for (int l = 0; l <= MAX_LEVEL; l++) {
            lt[l] = (short) (MAX_LEVEL - l);
        }
        ShortLookupTable slt = new ShortLookupTable(0, lt);
        if (ECHO) {
            plot(lt);
        }
        return slt;
    }

    /**
     * Función "S". Util para contrastar una imagen
     */
    public static LookupTable sFuction(double m, double e) {
        // K: constante de normalización 
        double K = ((double) MAX_LEVEL) / (1.0 / (1.0 + Math.pow(m / ((double) MAX_LEVEL), e)));
        short lt[] = new short[MAX_LEVEL + 1];
        lt[0] = 0;
        for (int l = 1; l <= MAX_LEVEL; l++) {
            lt[l] = (short) (K * (1.0 / (1.0 + Math.pow(m / (float) l, e))));
        }
        ShortLookupTable slt = new ShortLookupTable(0, lt);
        if (ECHO) {
            plot(lt);
        }
        return slt;
    }

    /**
     * Función logaritmo. Util para iluminar una imagen
     */
    public static LookupTable logarithmFuction() {
        // K: constante de normalización 
        double K = ((double) MAX_LEVEL) / Math.log(1.0 + ((double) MAX_LEVEL));
        short lt[] = new short[MAX_LEVEL + 1];
        for (int l = 0; l <= MAX_LEVEL; l++) {
            lt[l] = (short) (K * Math.log(1.0 + (double) l));
        }
        ShortLookupTable slt = new ShortLookupTable(0, lt);
        if (ECHO) {
            plot(lt);
        }
        return slt;
    }

    /**
     * Función potencia. Util para oscurecer una imagen
     */
    public static LookupTable powerFuction(double n) {
        // K: constante de normalización 
        double K = ((double) MAX_LEVEL) / Math.pow(((double) MAX_LEVEL), n);
        short lt[] = new short[MAX_LEVEL + 1];
        for (int l = 0; l <= MAX_LEVEL; l++) {
            lt[l] = (short) (K * Math.pow((double) l, n));
        }
        ShortLookupTable slt = new ShortLookupTable(0, lt);
        if (ECHO) {
            plot(lt);
        }
        return slt;
    }

    /**
     * Función raíz. Util para iluminar una imagen
     */
    public static LookupTable rootFuction(double n) {
        return powerFuction(1.0 / n);
    }

    /**
     * Corrección gamma. Si 0<gamma<1 ilumina, si gamma>1 oscurece
     */
    public static LookupTable gammaCorrection(double cteA, double gamma) {
        if (gamma <= 0) {
            return null;
        }
        // K: constante de normalización 
        double K = ((double) MAX_LEVEL) / (cteA * Math.pow(((double) MAX_LEVEL), gamma));
        short lt[] = new short[MAX_LEVEL + 1];
        for (int l = 0; l <= MAX_LEVEL; l++) {
            lt[l] = (short) (K * cteA * Math.pow((double) l, gamma));
        }
        ShortLookupTable slt = new ShortLookupTable(0, lt);
        if (ECHO) {
            plot(lt);
        }
        return slt;
    }

    /**
     * Constructor privado
     */
    private LookupTableProducer() {
    }

    /**
     * Muestra la tabla en consola
     */
    private static void plot(short lt[]) {
        for (int l = 0; l <= MAX_LEVEL; l++) {
            System.out.print(lt[l] + " ");
        }
        System.out.println();
    }
}
