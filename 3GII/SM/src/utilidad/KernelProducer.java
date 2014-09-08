package utilidad;

import java.awt.image.Kernel;

/**
 *
 * @author Jesus Chamorro
 */
public class KernelProducer {

    //Tipos de máscaras
    public final static int TYPE_MEDIA_3x3 = 0;
    public final static int TYPE_BINOMIAL_3x3 = 1;
    public final static int TYPE_ENFOQUE_3x3 = 2;
    public final static int TYPE_RELIEVE_3x3 = 3;
    public final static int TYPE_LAPLACIANA_3x3 = 4;

    /**
     * Crea objetos Kernel a partir de máscaras predefinidas
     */
    public static Kernel createKernel(int type) {
        switch (type) {
            case TYPE_MEDIA_3x3:
                return new Kernel(3, 3, MASCARA_MEDIA_3x3);
            case TYPE_BINOMIAL_3x3:
                return new Kernel(3, 3, MASCARA_BINOMIAL_3x3);
            case TYPE_ENFOQUE_3x3:
                return new Kernel(3, 3, MASCARA_ENFOQUE_3x3);
            case TYPE_RELIEVE_3x3:
                return new Kernel(3, 3, MASCARA_RELIEVE_3x3);
            case TYPE_LAPLACIANA_3x3:
                return new Kernel(3, 3, MASCARA_LAPLACIANA_3x3);
            default:
                return null;
        }
    }

    /**
     * Constructor privado
     */
    private KernelProducer() {
    }
    // Máscaras de convolución
    static float MASCARA_MEDIA_3x3[] = {
        0.1f, 0.1f, 0.1f,
        0.1f, 0.2f, 0.1f,
        0.1f, 0.1f, 0.1f
    };
    static float MASCARA_BINOMIAL_3x3[] = {
        0.0625f, 0.125f, 0.0625f,
        0.125f, 0.25f, 0.125f,
        0.0625f, 0.125f, 0.0625f
    };
    static float MASCARA_ENFOQUE_3x3[] = {
        0.0f, -1.0f, 0.0f,
        -1.0f, 5.0f, -1.0f,
        0.0f, -1.0f, 0.0f
    };
    static float MASCARA_LAPLACIANA_3x3[] = {
        1.0f, 1.0f, 1.0f,
        1.0f, -8.0f, 1.0f,
        1.0f, 1.0f, 1.0f
    };
    static float MASCARA_RELIEVE_3x3[] = {
        -2.0f, -1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 2.0f
    };
    // Fin máscaras de convolución 
}
