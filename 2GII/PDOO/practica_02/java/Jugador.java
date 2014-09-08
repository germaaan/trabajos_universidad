package munchkin_cthulhu;

import java.util.ArrayList;
import java.util.Iterator;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Jugador {

    private String nombre;
    private int nivel;
    private ArrayList<Tesoro> visibles;
    private ArrayList<Tesoro> ocultos;

    public Jugador(String unNombre) {
        this.nombre = unNombre;
        this.nivel = 1;
        this.visibles = new ArrayList<Tesoro>();
        this.ocultos = new ArrayList<Tesoro>();
    }

    public void modificarNivel(int incDec) {
        this.nivel += incDec;

        //Si un jugador muere, pierde todos sus tesoros y se queda a nivel 1.
        if (this.nivel <= 0) {
            this.visibles.clear();
            this.ocultos.clear();

            this.nivel = 1;
        }
    }

    public int obtenerNivel() {
        return this.nivel;
    }

    public String obtenerNombre() {
        return this.nombre;
    }

    int nivelDeCombate() {
        int nivelDeCombate = nivel;

        //Se suma a su nivel básico el nivel de todos sus tesoros.
        Iterator<Tesoro> itrVisibles = visibles.iterator();
        while (itrVisibles.hasNext()) {
            Tesoro elemento = itrVisibles.next();
            nivelDeCombate += elemento.obtenerBonus();
        }

        return nivelDeCombate;
    }
}
