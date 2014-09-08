package munchkin_cthulhu;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Monstruo {

    private String nombre;
    private int nivel;
    private int gananciaTesoros;
    private int gananciaNiveles;
    private int nivelesPerdidos;
    private String malRollo;

    public Monstruo(String nom, int niv, int tg, int ng, int np, String mr) {
        this.nombre = nom;
        this.nivel = niv;
        this.gananciaTesoros = tg;
        this.gananciaNiveles = ng;
        this.nivelesPerdidos = np;
        this.malRollo = mr;
    }

    public Monstruo(Monstruo unMonstruo) {
        this.nombre = unMonstruo.nombre;
        this.nivel = unMonstruo.nivel;
        this.gananciaTesoros = unMonstruo.gananciaTesoros;
        this.gananciaNiveles = unMonstruo.gananciaNiveles;
        this.nivelesPerdidos = unMonstruo.nivelesPerdidos;
        this.malRollo = unMonstruo.malRollo;
    }

    public String obternerNombre() {
        return this.nombre;
    }

    public int obtenerNivel() {
        return this.nivel;
    }

    public int obtenerGananciaTesoros() {
        return this.gananciaTesoros;
    }

    public int obtenerGananciaNiveles() {
        return this.gananciaNiveles;
    }

    public int obtenerNivelesPerdidos() {
        return this.nivelesPerdidos;
    }

    public String obtenerMalRollo() {
        return this.malRollo;
    }
}
