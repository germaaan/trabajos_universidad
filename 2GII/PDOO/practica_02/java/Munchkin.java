package munchkin_cthulhu;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Collections;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Munchkin {

    private static final Munchkin instance = new Munchkin();
    private Jugador jugadorActivo;
    private ArrayList<Jugador> jugadores;
    private LinkedList mazoTesoros;
    private LinkedList descarteDeTesoros;
    private Monstruo monstruoEnJuego;
    private LinkedList mazoMonstruos;
    private LinkedList descarteDeMonstruos;

    private Munchkin() {
    }

    public static Munchkin getInstance() {
        return instance;
    }

    public void comenzarJuego(String[] nombres) {
    }

    private void inicializarJuego() {
        //Como el constructor es privado, inicializamos en este método los mazos de cartas.
        mazoTesoros = new LinkedList();
        mazoMonstruos = new LinkedList();

        //incializacion del mazo de tesoros
        mazoTesoros.add(new Tesoro("¡Sí, Aaaaamo!", Tesoro.CASCO, 4, 0));
        mazoTesoros.add(new Tesoro("Ametralladora Thompson", Tesoro.DOS_MANOS, 4, 600));
        mazoTesoros.add(new Tesoro("Botas de lluvia ácida", Tesoro.CALZADO, 1, 300));
        mazoTesoros.add(new Tesoro("Botas de sutil investigación", Tesoro.CALZADO, 3, 600));
        mazoTesoros.add(new Tesoro("Camiseta de la Universidad de Miskatonic", Tesoro.ARMADURA, 1, 100));
        mazoTesoros.add(new Tesoro("Capucha de Cthulhu", Tesoro.CASCO, 3, 500));
        mazoTesoros.add(new Tesoro("Casco minero", Tesoro.CASCO, 2, 400));
        mazoTesoros.add(new Tesoro("Clavo de rail ferro viario", Tesoro.UNA_MANO, 3, 400));
        mazoTesoros.add(new Tesoro("El aparato de protección eléctrica del "
                + "Profesor Tesla", Tesoro.ARMADURA, 4, 900));
        mazoTesoros.add(new Tesoro("El cuchillo de sushi arcano", Tesoro.UNA_MANO, 2, 300));
        mazoTesoros.add(new Tesoro("Fez alópodo", Tesoro.CASCO, 3, 700));
        mazoTesoros.add(new Tesoro("Gaita", Tesoro.DOS_MANOS, 4, 500));
        mazoTesoros.add(new Tesoro("Garabato místico", Tesoro.UNA_MANO, 2, 300));
        mazoTesoros.add(new Tesoro("Hacha prehistória", Tesoro.UNA_MANO, 2, 500));
        mazoTesoros.add(new Tesoro("Insecticida", Tesoro.UNA_MANO, 2, 300));
        mazoTesoros.add(new Tesoro("La rebeca metálica", Tesoro.ARMADURA, 2, 400));
        mazoTesoros.add(new Tesoro("Lanzallamas", Tesoro.DOS_MANOS, 4, 800));
        mazoTesoros.add(new Tesoro("Mazo de los antiguos", Tesoro.UNA_MANO, 3, 200));
        mazoTesoros.add(new Tesoro("Necrocomicón", Tesoro.UNA_MANO, 1, 100));
        mazoTesoros.add(new Tesoro("Necrognomicón", Tesoro.UNA_MANO, 2, 200));
        mazoTesoros.add(new Tesoro("Necronomicón", Tesoro.DOS_MANOS, 5, 800));
        mazoTesoros.add(new Tesoro("Necroplayboycón", Tesoro.UNA_MANO, 3, 300));
        mazoTesoros.add(new Tesoro("Poncho a prueba de babas", Tesoro.ARMADURA, 2, 400));
        mazoTesoros.add(new Tesoro("Shogulador", Tesoro.DOS_MANOS, 5, 600));
        mazoTesoros.add(new Tesoro("Tentáculo de pega", Tesoro.CASCO, 0, 200));
        mazoTesoros.add(new Tesoro("Zapatos para dejar atrás a los amigos", Tesoro.CALZADO, 0, 500));

        //Inicializando mazo de monstruos
        mazoMonstruos.add(new Monstruo("Ángeles descarnados de la noche ibicenca", 14, 4, 1, 0,
                "Mal Rollo: Te atrapan para llevarte de fiesta y te dejan caer en mitad de vuelo."
                + " Después vuelven a hacerlo, porque es muy divertido. Descarta 3 objetos."));
        mazoMonstruos.add(new Monstruo("Bichoggoth", 1, 1, 1, 0, "Mal Rollo: Sientes bichos bajo la"
                + " ropa. Descarta tu Armadura."));
        mazoMonstruos.add(new Monstruo("Chibithulhu", 2, 1, 1, 0, "Mal Rollo: Embobados con el lindo"
                + " primigenio y le dan el objeto que le proporciona el Bonus más alto."));
        mazoMonstruos.add(new Monstruo("El Gorrón en el umbral", 10, 3, 1, 0, "Mal Rollo: Pierdes tus"
                + " tesoros visibles."));
        mazoMonstruos.add(new Monstruo("El Mal indecible e impronunciable", 10, 3, 1, 0, "Mal Rollo:"
                + " Pierdes una mano."));
        mazoMonstruos.add(new Monstruo("El Rey de rosa", 16, 4, 2, 0, "Mal Rollo: Pierdes un Nivel por"
                + " cada carta que tengas en la mano.")); //Por ahora haremos como que pierde 0 niveles.
        mazoMonstruos.add(new Monstruo("El sopor de Dunwich", 1, 1, 1, 0, "Mal Rollo: ¡El primordial"
                + " bostezo contagioso! Te tragas tu objeto menos caro (los objetos sin valor no"
                + " cuentan). Descártalo."));
        mazoMonstruos.add(new Monstruo("H.P. Munchcraft", 6, 2, 1, 0, "Mal Rollo: Pierdes la armadura."));
        mazoMonstruos.add(new Monstruo("La que redacta en las Tinieblas", 2, 1, 1, 1, "Mal Rollo: Toses"
                + " los pulmones y pierdes un Nivel."));
        mazoMonstruos.add(new Monstruo("Lolitaggoth", 1, 1, 1, 1, "Mal Rollo: ¡Ja! ¡Ja! ¡Pintalabios"
                + " negros! Pierdes un Nivel."));
        mazoMonstruos.add(new Monstruo("Los Hondos", 8, 2, 1, 10, "Mal Rollo: A diferencia de sus primos,"
                + " Los Profundos, que siempren están hablando con gravedad de temas serios, estos"
                + " monstruos resultan bastante superficiales, y te aburren mortalmente, en el sentido"
                + " más literal de la palabra. Estás muerto.")); // Perder 10 niveles es morir.
        mazoMonstruos.add(new Monstruo("Pollipólipo volante", 2, 1, 1, 1, "Mal Rollo: Da mucho asquito…"
                + " Pierdes un Nivel."));
        mazoMonstruos.add(new Monstruo("Roboggoth", 8, 2, 1, 2, "Mal Rollo: La quinta directiva primaria"
                + " de Roboggoth te obliga a perder 2 Niveles y descartarte de una carta de tu mano."));
        mazoMonstruos.add(new Monstruo("Semillas Frikonas de Cthulhu", 4, 2, 1, 1, "Mal Rollo: Pierdes"
                + " un Nivel."));
        mazoMonstruos.add(new Monstruo("Shoggoth", 16, 4, 2, 2, "Mal Rollo: Pierdes 2 niveles."));
        mazoMonstruos.add(new Monstruo("Tres Byakhees vienen de Bonanza", 8, 2, 1, 0, "Mal Rollo:"
                + " Pierdes un tesoro visible y otro oculto."));
        mazoMonstruos.add(new Monstruo("Y'skhthyssg-Goth", 12, 3, 1, 10, "Mal Rollo: No le hace gracia"
                + " que pronuncien mal su nombre. Estás muerto.")); //Perder 10 niveles es morir.

        //Barajamos los mazos antes de empezar a jugar.
        Collections.shuffle(mazoTesoros);
        Collections.shuffle(mazoMonstruos);
    }

    private void inicializarJugadores(String[] nombres) {
    }

    private void repartirCartas() {
    }

    public void determinarJugador() {
    }

    public void equiparJugador() {
    }

    public void desarrollarCombate() {
    }

    public void descartarTesorosDeJugador(LinkedList listaTes) {
    }
}
