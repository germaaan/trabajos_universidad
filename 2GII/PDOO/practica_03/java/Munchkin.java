package munchkin_cthulhu;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Collections;
import java.util.Iterator;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Munchkin {

    private static final Munchkin INSTANCIA = new Munchkin();
    private Jugador jugadorActivo;
    private ArrayList<Jugador> jugadores;
    private LinkedList<Tesoro> mazoTesoros;
    private LinkedList<Tesoro> descarteTesoros;
    private Monstruo monstruoEnJuego;
    private LinkedList<Monstruo> mazoMonstruos;
    private LinkedList<Monstruo> descarteMonstruos;
    private int indexJugador;

    private Munchkin() {
    }

    public static Munchkin getInstance() {
        return INSTANCIA;
    }

    private void primero() {
        this.indexJugador = (int) Math.floor(Math.random() * this.jugadores.size() + 1);
    }

    private void siguiente() {
        this.indexJugador = (this.indexJugador + 1) % this.jugadores.size();
    }

    private Tesoro primerTesoro() {
        Tesoro tesoro;

        if (this.mazoTesoros.isEmpty()) {
            Iterator<Tesoro> iteraTesoros = this.descarteTesoros.iterator();

            while (iteraTesoros.hasNext()) {
                tesoro = iteraTesoros.next();
                this.mazoTesoros.add(tesoro);
            }

            Collections.shuffle(this.mazoTesoros);
            this.descarteTesoros.clear();
        }

        tesoro = new Tesoro(this.mazoTesoros.getFirst());
        this.mazoTesoros.removeFirst();

        return tesoro;
    }

    private Monstruo primerMonstruo() {
        Monstruo monstruo;

        if (this.mazoMonstruos.isEmpty()) {
            Iterator<Monstruo> iteraMonstruos = this.descarteMonstruos.iterator();

            while (iteraMonstruos.hasNext()) {
                monstruo = iteraMonstruos.next();
                this.mazoMonstruos.add(monstruo);
            }

            Collections.shuffle(this.mazoMonstruos);
            this.descarteMonstruos.clear();
        }

        monstruo = new Monstruo(this.mazoMonstruos.getFirst());
        this.mazoMonstruos.removeFirst();

        return monstruo;
    }

    public void comenzarJuego(String[] nombres) throws Exception {
        if ((nombres.length <= 1) || (nombres.length > 3)) {
            Exception e = new Exception("Número de jugadores no permitido.");
            throw e;
        }

        this.inicializarJuego();
        this.inicializarJugadores(nombres);
        this.repartirCartas();
    }

    private void inicializarJuego() {
        //Como el constructor es privado, inicializamos en este método los mazos de cartas.
        this.mazoTesoros = new LinkedList<Tesoro>();
        this.descarteTesoros = new LinkedList<Tesoro>();
        this.mazoMonstruos = new LinkedList<Monstruo>();
        this.descarteMonstruos = new LinkedList<Monstruo>();

        //incializacion del mazo de tesoros
        this.mazoTesoros.add(new Tesoro("¡Sí, Aaaaamo!", Tesoro.CASCO, 4, 0));
        this.mazoTesoros.add(new Tesoro("Ametralladora Thompson", Tesoro.DOS_MANOS, 4, 600));
        this.mazoTesoros.add(new Tesoro("Botas de lluvia ácida", Tesoro.CALZADO, 1, 300));
        this.mazoTesoros.add(new Tesoro("Botas de sutil investigación", Tesoro.CALZADO, 3, 600));
        this.mazoTesoros.add(new Tesoro("Camiseta de la Universidad de Miskatonic", Tesoro.ARMADURA, 1,
                100));
        this.mazoTesoros.add(new Tesoro("Capucha de Cthulhu", Tesoro.CASCO, 3, 500));
        this.mazoTesoros.add(new Tesoro("Casco minero", Tesoro.CASCO, 2, 400));
        this.mazoTesoros.add(new Tesoro("Clavo de rail ferro viario", Tesoro.UNA_MANO, 3, 400));
        this.mazoTesoros.add(new Tesoro("El aparato de protección eléctrica del"
                + " Profesor Tesla", Tesoro.ARMADURA, 4, 900));
        this.mazoTesoros.add(new Tesoro("El cuchillo de sushi arcano", Tesoro.UNA_MANO, 2, 300));
        this.mazoTesoros.add(new Tesoro("Fez alópodo", Tesoro.CASCO, 3, 700));
        this.mazoTesoros.add(new Tesoro("Gaita", Tesoro.DOS_MANOS, 4, 500));
        this.mazoTesoros.add(new Tesoro("Garabato místico", Tesoro.UNA_MANO, 2, 300));
        this.mazoTesoros.add(new Tesoro("Hacha prehistória", Tesoro.UNA_MANO, 2, 500));
        this.mazoTesoros.add(new Tesoro("Insecticida", Tesoro.UNA_MANO, 2, 300));
        this.mazoTesoros.add(new Tesoro("La rebeca metálica", Tesoro.ARMADURA, 2, 400));
        this.mazoTesoros.add(new Tesoro("Lanzallamas", Tesoro.DOS_MANOS, 4, 800));
        this.mazoTesoros.add(new Tesoro("Mazo de los antiguos", Tesoro.UNA_MANO, 3, 200));
        this.mazoTesoros.add(new Tesoro("Necrocomicón", Tesoro.UNA_MANO, 1, 100));
        this.mazoTesoros.add(new Tesoro("Necrognomicón", Tesoro.UNA_MANO, 2, 200));
        this.mazoTesoros.add(new Tesoro("Necronomicón", Tesoro.DOS_MANOS, 5, 800));
        this.mazoTesoros.add(new Tesoro("Necroplayboycón", Tesoro.UNA_MANO, 3, 300));
        this.mazoTesoros.add(new Tesoro("Poncho a prueba de babas", Tesoro.ARMADURA, 2, 400));
        this.mazoTesoros.add(new Tesoro("Shogulador", Tesoro.DOS_MANOS, 5, 600));
        this.mazoTesoros.add(new Tesoro("Tentáculo de pega", Tesoro.CASCO, 0, 200));
        this.mazoTesoros.add(new Tesoro("Zapatos para dejar atrás a los amigos", Tesoro.CALZADO, 0, 500));

        //Inicializando mazo de monstruos
        this.mazoMonstruos.add(new Monstruo("Ángeles descarnados de la noche ibicenca", 14, 4, 1, 0,
                "Mal Rollo: Te atrapan para llevarte de fiesta y te dejan caer en mitad de vuelo."
                + " Después vuelven a hacerlo, porque es muy divertido. Descarta 3 objetos."));
        this.mazoMonstruos.add(new Monstruo("Bichoggoth", 1, 1, 1, 0, "Mal Rollo: Sientes bichos bajo"
                + " la ropa. Descarta tu Armadura."));
        this.mazoMonstruos.add(new Monstruo("Chibithulhu", 2, 1, 1, 0, "Mal Rollo: Embobados con el"
                + " lindo primigenio y le dan el objeto que le proporciona el Bonus más alto."));
        this.mazoMonstruos.add(new Monstruo("El Gorrón en el umbral", 10, 3, 1, 0, "Mal Rollo: Pierdes"
                + " tus tesoros visibles."));
        this.mazoMonstruos.add(new Monstruo("El Mal indecible e impronunciable", 10, 3, 1, 0, "Mal"
                + " Rollo: Pierdes una mano."));
        this.mazoMonstruos.add(new Monstruo("El Rey de rosa", 16, 4, 2, 0, "Mal Rollo: Pierdes un"
                + " Nivel por cada carta que tengas en la mano."));
        this.mazoMonstruos.add(new Monstruo("El sopor de Dunwich", 1, 1, 1, 0, "Mal Rollo:"
                + " ¡El primordial bostezo contagioso! Te tragas tu objeto menos caro (los objetos"
                + " sin valor no cuentan). Descártalo."));
        this.mazoMonstruos.add(new Monstruo("H.P. Munchcraft", 6, 2, 1, 0, "Mal Rollo: Pierdes la"
                + " armadura."));
        this.mazoMonstruos.add(new Monstruo("La que redacta en las Tinieblas", 2, 1, 1, -1, "Mal Rollo:"
                + " Toses los pulmones y pierdes un Nivel."));
        this.mazoMonstruos.add(new Monstruo("Lolitaggoth", 1, 1, 1, -1, "Mal Rollo: ¡Ja! ¡Ja!"
                + " ¡Pintalabios negros! Pierdes un Nivel."));
        this.mazoMonstruos.add(new Monstruo("Los Hondos", 8, 2, 1, -10, "Mal Rollo: A diferencia de"
                + " sus primos, Los Profundos, que siempren están hablando con gravedad de temas"
                + " serios, estos monstruos resultan bastante superficiales, y te aburren mortalmente,"
                + " en el sentido más literal de la palabra. Estás muerto."));
        this.mazoMonstruos.add(new Monstruo("Pollipólipo volante", 2, 1, 1, -1, "Mal Rollo: Da"
                + " mucho asquito… Pierdes un Nivel."));
        this.mazoMonstruos.add(new Monstruo("Roboggoth", 8, 2, 1, -2, "Mal Rollo: La quinta directiva"
                + " primaria de Roboggoth te obliga a perder 2 Niveles y descartarte de una carta"
                + " de tu mano."));
        this.mazoMonstruos.add(new Monstruo("Semillas Frikonas de Cthulhu", 4, 2, 1, -1, "Mal Rollo:"
                + " Pierdes un Nivel."));
        this.mazoMonstruos.add(new Monstruo("Shoggoth", 16, 4, 2, -2, "Mal Rollo: Pierdes 2 niveles."));
        mazoMonstruos.add(new Monstruo("Tres Byakhees vienen de Bonanza", 8, 2, 1, 0, "Mal Rollo:"
                + " Pierdes un tesoro visible y otro oculto."));
        this.mazoMonstruos.add(new Monstruo("Y'skhthyssg-Goth", 12, 3, 1, -10, "Mal Rollo: No le hace"
                + " gracia que pronuncien mal su nombre. Estás muerto."));

        //Barajamos los mazos antes de empezar a jugar.
        Collections.shuffle(this.mazoTesoros);
        Collections.shuffle(this.mazoMonstruos);
    }

    private void inicializarJugadores(String[] nombres) {
        String nombre;
        Jugador jugador;

        this.jugadores = new ArrayList<Jugador>();
        this.indexJugador = -1;

        for (int i = 0; i < nombres.length; i++) {
            nombre = nombres[i];
            jugador = new Jugador(nombre);
            this.jugadores.add(jugador);
        }
    }

    private void repartirCartas() {
        Jugador jugador;
        Tesoro tesoro;

        Iterator<Jugador> iteraJugadores = this.jugadores.iterator();
        while (iteraJugadores.hasNext()) {
            jugador = iteraJugadores.next();

            for (int j = 0; j < 2; j++) {
                tesoro = this.primerTesoro();
                jugador.robarTesoro(tesoro);
            }
        }
    }

    public void siguienteTurno() throws Exception {
        boolean fin = false;

        if (this.jugadorActivo != null) {
            /* Por como se especifica terminarTurno() en el diagrama, es posible que
             * produzca un bucle infinito.
             */
            fin = this.jugadorActivo.terminarTurno();
        }

        if ((this.jugadorActivo != null) && (!fin)) {
            Exception e = new Exception("El jugador tiene más de 4 tesoros ocultos, no se puede pasar"
                    + " al siguiente turno.");
            throw e;
        }

        if (this.jugadorActivo == null) {
            this.primero();
        } else {
            this.siguiente();
        }

        this.jugadorActivo = this.jugadores.get(indexJugador);
        this.monstruoEnJuego = this.primerMonstruo();
    }

    public ArrayList<Tesoro> equiparseJugador(ArrayList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        boolean puedo;

        ArrayList<Tesoro> tesorosNoEquipados = new ArrayList<Tesoro>();
        /* ArrayList<Tesoro> tesorosNoEquipados = new ArrayList<Tesoro>();
         * tesorosNoEquipados = this.jugadorActivo.equiparse(listaTesoros);
         * Según diagrama tesorosNoEquipados debería ser un ArrayList de Tesoros
         * devueltos por el método equiparse(listaTesoros) del jugador, pero tiene más
         * sentido que el ArrayList se ocupe según las siguientes operaciones.
         */

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            puedo = this.jugadorActivo.puedoEquipar(tesoro);

            if (puedo) {
                this.jugadorActivo.eliminarTesorosOcultos(tesoro);
                this.jugadorActivo.incluirTesorosVisibles(tesoro);
            } else {
                tesorosNoEquipados.add(tesoro);
            }
        }

        if (tesorosNoEquipados.isEmpty()) {
            return null;
        } else {
            return tesorosNoEquipados;
        }
    }

    public void descartarTesorosOcultos(ArrayList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        boolean eliminado;

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            eliminado = this.jugadorActivo.eliminarTesorosOcultos(tesoro);

            if (eliminado) {
                this.descarteTesoros.add(tesoro);
            }
        }
    }

    public void descartarTesorosVisibles(ArrayList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        boolean eliminado;

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            eliminado = this.jugadorActivo.eliminarTesorosVisibles(tesoro);

            if (eliminado) {
                this.descarteTesoros.add(tesoro);
            }
        }
    }

    public int desarrollarCombate() {
        int tesorosGanados;
        int resultado = 0;
        int dado;

        if (this.monstruoEnJuego.obtenerNivel() < this.jugadorActivo.nivelDeCombate()) {
            tesorosGanados = this.monstruoEnJuego.obtenerGananciaTesoros();

            for (int i = 1; i <= tesorosGanados; i++) {
                this.jugadorActivo.robarTesoro(this.primerTesoro());
            }

            this.jugadorActivo.modificarNivel(this.monstruoEnJuego.obtenerGananciaNiveles());

            if (this.jugadorActivo.obtenerNivel() == 10) {
                resultado = 10;
            } else {
                resultado = 1;
            }
        } else if (this.monstruoEnJuego.obtenerNivel() >= this.jugadorActivo.nivelDeCombate()) {
            dado = (int) Math.floor(Math.random() * (6 + 1));

            if (dado < 5) {
                this.jugadorActivo.modificarNivel(this.monstruoEnJuego.obtenerNivelesPerdidos());
                resultado = -1;
            } else {
                resultado = 0;
            }
        }

        return resultado;
    }

    public void muerteJugador() {
        Tesoro nuevoTesoro;

        ArrayList<Tesoro> tesorosPerdidos = new ArrayList<Tesoro>();
        tesorosPerdidos = this.jugadorActivo.muerte();

        this.descarteTesoros.addAll(tesorosPerdidos);

        for (int i = 0; i < 2; i++) {
            nuevoTesoro = this.primerTesoro();
            this.jugadorActivo.robarTesoro(nuevoTesoro);
        }
    }

    public void comprarNivelesJugador(ArrayList<Tesoro> listaTesoros) {
        Tesoro tesoro;
        int contNiveles = 0;
        int contOro = 0;

        Iterator<Tesoro> iteraTesoros = listaTesoros.iterator();
        while (iteraTesoros.hasNext()) {
            tesoro = iteraTesoros.next();

            contOro += tesoro.obtenerPiezasOro();

            if (contOro >= 1000) {
                contOro -= 1000;
                contNiveles++;
            }
        }

        this.jugadorActivo.modificarNivel(contNiveles);

        this.descartarTesorosOcultos(listaTesoros);
        this.descartarTesorosVisibles(listaTesoros);
    }
}
