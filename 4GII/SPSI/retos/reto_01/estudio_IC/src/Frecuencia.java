package encriptacion;

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author Jose Manuel Castillo Perez
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */
public class Frecuencia {

    private ArrayList<Character> mensaje = new ArrayList();
    private char letras[] = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
        'x', 'y', 'z'};
    private double frecuencia[] = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    private double suma = 0.0;

    public Frecuencia(ArrayList<Character> m) {
        mensaje = m;
    }

    private int busquedaPosicion(char elem) {
        int pos = -1;
        boolean encontrado = false;

        for (int i = 0; !encontrado && i < letras.length; i++) {
            if (letras[i] == elem) {
                encontrado = true;
                pos = i;
            }
        }

        return pos;
    }

    private void sumaValores() {
        for (int i = 0; i < frecuencia.length; i++) {
            suma += frecuencia[i];
        }
    }

    public void calcularFrecuencia() {
        Iterator<Character> it = mensaje.iterator();
        char c;
        int buscado;

        while (it.hasNext()) {
            c = it.next();
            buscado = busquedaPosicion(c);
            frecuencia[buscado]++;
        }

        sumaValores();

        for (int i = 0; i < frecuencia.length; i++) {
            frecuencia[i] /= suma;
        }
    }

    public char[] getLetras() {
        return letras;
    }

    public double[] getAparece() {
        return frecuencia;
    }

    public double getSuma() {
        return suma;
    }
}
