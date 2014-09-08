package ModeloLACB;

import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author Germán Martínez Maldonado
 */
public class LACB {

    private static final LACB INSTANCIA = new LACB();
    private List<Club> clubes = new ArrayList<Club>();
    private List<Jugador> jugadores = new ArrayList<Jugador>();

    private LACB() {
    }

    public static LACB getLACB() {
        return INSTANCIA;
    }

    public void incluirClub(String nombre, String nombreEntrenador, String pabellon) throws Exception {
        boolean existe;
        Club unClub;

        existe = this.existeClub(nombre);

        if (existe) {
            throw new Exception("Club ya dado de alta.\n\n");
        } else {
            unClub = new Club(nombre, nombreEntrenador, pabellon);
            clubes.add(unClub);
        }
    }

    public String altaJugador(String dniPass, String nombre, Date fechaNaci, float altura, float peso, String posicion, String nacionalidad) throws Exception {
        boolean existe;
        String nLicencia;
        Jugador jugador;

        existe = this.existeJugador(dniPass);

        if (existe) {
            throw new Exception("Ya existe un jugador con ese DNI o pasaporte.\n\n");
        } else {
            jugador = new Jugador(dniPass, nombre, fechaNaci, altura, peso, posicion, nacionalidad);
            nLicencia = jugador.obtenerNumeroLicencia();
            this.jugadores.add(jugador);
        }

        return nLicencia;
    }

    public List consultarClub(String nombre) {
        Club club = this.buscarClub(nombre);
        List infoClub = club.obtenerDatosClub();

        return infoClub;
    }

    public void vincularJugador(String nombreClub, String dniPass, int nuevoDorsal) throws Exception {
        boolean vinculado;
        boolean ocupado;
        Jugador jugador;
        Club club;

        jugador = this.buscarJugador(dniPass);
        vinculado = jugador.estasVinculado();

        if (vinculado) {
            throw new Exception("El jugador está vinculado a otro club.\n\n");
        } else {
            club = this.buscarClub(nombreClub);
            ocupado = club.dorsalOcupado(nuevoDorsal);

            if (ocupado) {
                throw new Exception("Dorsal ya asignado a otro jugador.\n\n");
            } else {
                jugador.vincularClub(club, nuevoDorsal);
                club.vincularJugador(jugador);
            }
        }
    }

    public void desvincularJugador(String nombreClub, String dniPass) throws Exception {
        Club club = this.buscarClub(nombreClub);
        Jugador jugador = this.buscarJugador(dniPass);

        club.desvincularJugador(jugador);
        jugador.desvincularClub();
    }

    public List consultarJugador(String dniPas) {
        Jugador jugador = this.buscarJugador(dniPas);
        List infoJugadorClub = jugador.obtenerDatosJugadorClub();

        return infoJugadorClub;
    }

    private Jugador buscarJugador(String dniPas) {
        Jugador jugador = null;
        boolean encontrado = false;

        for (Iterator<Jugador> it = this.jugadores.iterator(); (it.hasNext() & !encontrado);) {
            jugador = it.next();

            if (jugador.obtenerNumeroLicencia().equals(dniPas)) {
                encontrado = true;
            }
        }

        if (!encontrado) {
            jugador = null;
        }

        return jugador;
    }

    private Club buscarClub(String nombreClub) {
        Club club = null;
        boolean encontrado = false;

        for (Iterator<Club> it = this.clubes.iterator(); (it.hasNext() & !encontrado);) {
            club = it.next();

            if (club.obtenerNombre().equals(nombreClub)) {
                encontrado = true;
            }
        }

        if (!encontrado) {
            club = null;
        }

        return club;
    }

    private boolean existeJugador(String dniPass) {
        boolean encontrado = false;
        Jugador jugador;

        for (Iterator<Jugador> it = this.jugadores.iterator(); (it.hasNext() & !encontrado);) {
            jugador = it.next();

            if (jugador.obtenerNumeroLicencia().equals(dniPass)) {
                encontrado = true;
            }
        }

        return encontrado;
    }

    private boolean existeClub(String nombreClub) {
        boolean encontrado = false;
        Club club;

        for (Iterator<Club> it = this.clubes.iterator(); (it.hasNext() & !encontrado);) {
            club = it.next();

            if (club.obtenerNombre().equals(nombreClub)) {
                encontrado = true;
            }
        }

        return encontrado;
    }
}
