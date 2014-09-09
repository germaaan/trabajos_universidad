package encriptacion;

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author Jose Manuel Castillo Perez
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */
public class Vigenere {

    private ArrayList<Character> mensaje = new ArrayList();
    private String clave;
    private ArrayList<Character> codificada = new ArrayList();
    private ArrayList<Character> decodificada = new ArrayList();
    private char[] alfabeto = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
        'x', 'y', 'z'};

    public Vigenere(ArrayList<Character> mensaje, String clave) {
        this.mensaje = mensaje;
        this.clave = clave;
    }

    public void codVigenere() {
        int posicion_nuevo_caracter;
        char nuevo_caracter;
        int posicion_alfabeto_mensaje;
        int posicion_alfabeto_clave;
        Iterator<Character> it = mensaje.iterator();
        char c;
        int j = 0;

        while (it.hasNext()) {
            c = it.next();

            posicion_alfabeto_mensaje = obtenerPosicion(c);
            posicion_alfabeto_clave = obtenerPosicion(this.clave.charAt(j));
            posicion_nuevo_caracter = mod((posicion_alfabeto_mensaje + posicion_alfabeto_clave), this.alfabeto.length);
            nuevo_caracter = alfabeto[posicion_nuevo_caracter];
            this.codificada.add(nuevo_caracter);

            if (j == this.clave.length() - 1) {
                j = 0;
            } else {
                j++;
            }
        }
    }

    public void decodVigenere() {
        int posicion_nuevo_caracter;
        char nuevo_caracter;
        int posicion_alfabeto_mensaje;
        int posicion_alfabeto_clave;
        Iterator<Character> it = mensaje.iterator();
        char c;
        int j = 0;

        while (it.hasNext()) {
            c = it.next();

            posicion_alfabeto_mensaje = obtenerPosicion(c);
            posicion_alfabeto_clave = obtenerPosicion(this.clave.charAt(j));
            posicion_nuevo_caracter = mod((posicion_alfabeto_mensaje - posicion_alfabeto_clave), this.alfabeto.length);
            nuevo_caracter = alfabeto[posicion_nuevo_caracter];
            this.decodificada.add(nuevo_caracter);

            if (j == this.clave.length() - 1) {
                j = 0;
            } else {
                j++;
            }
        }
    }

    public int obtenerPosicion(char c) {
        for (int i = 0; i < this.alfabeto.length; i++) {
            if (c == this.alfabeto[i]) {
                return i;
            }
        }
        
        return -1;
    }

    public int mod(int a, int b) {
        int res = a % b;
        return res >= 0 ? res : res + b;
    }

    public ArrayList<Character> getCodificada() {
        return codificada;
    }

    public ArrayList<Character> getDecodificada() {
        return decodificada;
    }
}
