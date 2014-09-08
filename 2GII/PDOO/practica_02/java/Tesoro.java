package munchkin_cthulhu;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Tesoro {

    private String nombre;
    private int tipo;
    private int bonus;
    private int piezasOro;
    public static int CASCO = 0;
    public static int ARMADURA = 1;
    public static int CALZADO = 2;
    public static int UNA_MANO = 3;
    public static int DOS_MANOS = 4;

    public Tesoro(String unNombre, int unTipo, int unosBonus, int unasPiezas) {
        this.nombre = unNombre;
        this.tipo = unTipo;
        this.bonus = unosBonus;
        this.piezasOro = unasPiezas;
    }

    public String obtenerNombre() {
        return this.nombre;
    }

    public int obtenerTipo() {
        return this.tipo;
    }

    public int obtenerBonus() {
        return this.bonus;
    }

    public int obtenerPiezasOro() {
        return this.piezasOro;
    }
}
