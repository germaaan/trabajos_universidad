package munchkin_cthulhu;

import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Jugador {

    private String nombre;
    private int nivel;
    private LinkedList<Tesoro> tesorosVisibles;
    private LinkedList<Tesoro> tesorosOcultos;

    public Jugador(String unNombre) {
        this.nombre = unNombre;
        this.nivel = 1;
        this.tesorosVisibles = new LinkedList<Tesoro>();
        this.tesorosOcultos = new LinkedList<Tesoro>();
    }

    public String obtenerNombre() {
        return this.nombre;
    }

    public int obtenerNivel() {
        return this.nivel;
    }

    LinkedList<Tesoro> getTesorosVisibles() {
        return this.tesorosVisibles;
    }

    LinkedList<Tesoro> getTesorosOcultos() {
        return this.tesorosOcultos;
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

        for (Tesoro unTesoro : this.tesorosVisibles) {
            if (unTesoro.obtenerTipo() == Tesoro.DOS_MANOS) {
                contManos = 2;
                break;
            } else if (unTesoro.obtenerTipo() == Tesoro.UNA_MANO) {
                contManos++;

                if (contManos == 2) {
                    break;
                }
            }
        }

        if (contManos != 0 && tesoro.obtenerTipo() == Tesoro.DOS_MANOS) {
            puedo = false;
        } else if (contManos == 2 && tesoro.obtenerTipo() == Tesoro.UNA_MANO) {
            puedo = false;
        }

        for (Tesoro unTesoro : this.tesorosVisibles) {
            if (unTesoro.obtenerTipo() == tesoro.obtenerTipo()) {
                if (tesoro.obtenerTipo() != Tesoro.UNA_MANO) {
                    puedo = false;
                    break;
                }

            }
        }

        return puedo;
    }

    LinkedList<Tesoro> equiparse(LinkedList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        boolean puedo;
        LinkedList<Tesoro> tesorosNoEquipados = new LinkedList<Tesoro>();

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            if (puedoEquipar(tesoro)) {
                this.tesorosOcultos.remove(tesoro);
                this.tesorosVisibles.add(tesoro);
            } else {
                tesorosNoEquipados.add(tesoro);
            }
        }

        return tesorosNoEquipados;
    }

    public LinkedList<Tesoro> muerte() {
        Tesoro tesoro;
        LinkedList<Tesoro> tesorosPerdidos = new LinkedList<Tesoro>();

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
        return (this.tesorosOcultos.size() <= 4);
    }
}
