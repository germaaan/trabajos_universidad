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
    private ArrayList<Tesoro> tesorosVisibles;
    private ArrayList<Tesoro> tesorosOcultos;

    public Jugador(String unNombre) {
        this.nombre = unNombre;
        this.nivel = 1;
        this.tesorosVisibles = new ArrayList<Tesoro>();
        this.tesorosOcultos = new ArrayList<Tesoro>();
    }

    public String obtenerNombre() {
        return this.nombre;
    }

    public int obtenerNivel() {
        return this.nivel;
    }

    public void modificarNivel(int incDec) {
        this.nivel += incDec;
    }

    public int nivelDeCombate() {
        int nivelDeCombate = this.nivel;

        Iterator<Tesoro> iteraTesoros = tesorosVisibles.iterator();
        while (iteraTesoros.hasNext()) {
            Tesoro elemento = iteraTesoros.next();
            nivelDeCombate += elemento.obtenerBonus();
        }

        return nivelDeCombate;
    }

    public void robarTesoro(Tesoro tesoro) {
        this.tesorosOcultos.add(tesoro);
    }

    public void incluirTesorosVisibles(Tesoro tesoro) {
        this.tesorosVisibles.add(tesoro);
    }

    public boolean eliminarTesorosVisibles(Tesoro tesoro) {
        boolean eliminado = this.tesorosVisibles.remove(tesoro);
        return eliminado;
    }

    public boolean eliminarTesorosOcultos(Tesoro tesoro) {
        boolean eliminado = this.tesorosOcultos.remove(tesoro);
        return eliminado;
    }

    public boolean puedoEquipar(Tesoro tesoro) {
        boolean puedo = true;
        int contManos = 0;
        Tesoro unTesoro;

        Iterator<Tesoro> iteraTesoros = this.tesorosVisibles.iterator();
        while ((iteraTesoros.hasNext()) && (contManos < 2)) {
            unTesoro = iteraTesoros.next();

            if (unTesoro.obtenerTipo() == Tesoro.UNA_MANO) {
                contManos++;
            }
        }

        iteraTesoros = this.tesorosVisibles.iterator();
        while ((iteraTesoros.hasNext()) && puedo) {
            unTesoro = iteraTesoros.next();

            if (tesoro.obtenerTipo() == unTesoro.obtenerTipo()) {
                if (tesoro.obtenerTipo() != Tesoro.UNA_MANO) {
                    puedo = false;
                } else if (tesoro.obtenerTipo() == Tesoro.UNA_MANO) {

                    if (contManos < 2) {
                        return true;
                    } else {
                        puedo = false;
                    }
                }
            }
        }

        return puedo;
    }

    /* No le encuentro sentido a este método, porque se puede hacer directamente todos
     * desde el método equiparseJugador de la clase Munchkin.
     */
    ArrayList<Tesoro> equiparse(ArrayList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        ArrayList<Tesoro> tesorosNoEquipados = new ArrayList<Tesoro>();

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            if (!this.puedoEquipar(tesoro)) {
                tesorosNoEquipados.add(tesoro);
            }
        }

        return tesorosNoEquipados;
    }

    public ArrayList<Tesoro> muerte() {
        Tesoro tesoro;
        ArrayList<Tesoro> tesorosPerdidos = new ArrayList<Tesoro>();

        Iterator<Tesoro> iteraTesoros = this.tesorosOcultos.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();
            tesorosPerdidos.add(tesoro);
        }

        iteraTesoros = this.tesorosVisibles.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();
            tesorosPerdidos.add(tesoro);
        }

        this.nivel = 1;
        this.tesorosOcultos.clear();
        this.tesorosVisibles.clear();

        return tesorosPerdidos;
    }

    public boolean terminarTurno() {
        return (this.tesorosOcultos.size() > 4);
    }
}
