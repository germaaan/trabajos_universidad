package ModeloLACB;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Germán Martínez Maldonado
 */
public class Jugador {

    private String licencia;
    private String nombre;
    private String dniPass;
    private Date edad;
    private float altura;
    private String posicion;
    private float peso;
    private String nacionalidad;
    private int dorsal;
    private Club club;

    public Jugador(String dniPass, String nombre, Date fechaNaci, float altura, float peso, String posicion, String nacionalidad) {
        this.licencia = dniPass;
        this.dniPass = dniPass;
        this.nombre = nombre;
        this.edad = fechaNaci;
        this.altura = altura;
        this.posicion = posicion;
        this.peso = peso;
        this.nacionalidad = nacionalidad;
        this.dorsal = -1;
        this.club = null;
    }

    String obtenerNumeroLicencia() {
        return this.licencia;
    }

    List obtenerDatosJugadorClub() {
        String nombreC;
        List infoJugadorClub = this.obtenerDatos();

        if (this.estasVinculado()) {
            nombreC = this.club.obtenerNombre();
            infoJugadorClub.add(nombreC);
        }

        return infoJugadorClub;
    }

    boolean estasVinculado() {
        return this.club != null;
    }

    void vincularClub(Club club, int nuevoDorsal) {
        this.club = club;
        this.dorsal = nuevoDorsal;
    }

    boolean esEsteTuDorsal(int dorsal) {
        return this.dorsal == dorsal;
    }

    void desvincularClub() {
        this.club = null;
        this.dorsal = -1;
    }

    List obtenerDatos() {
        List datosJugador = new ArrayList();

        datosJugador.add(this.licencia);
        datosJugador.add(this.nombre);
        datosJugador.add(this.dniPass);
        datosJugador.add(this.edad);
        datosJugador.add(this.altura);
        datosJugador.add(this.posicion);
        datosJugador.add(this.peso);
        datosJugador.add(this.nacionalidad);
        datosJugador.add(this.dorsal);

        return datosJugador;
    }
}
