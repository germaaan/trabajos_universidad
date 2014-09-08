package ModeloLACB;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author Germán Martínez Maldonado
 */
class Club {

    private String nombre;
    private String entrenador;
    private String pabellon;
    private List<Jugador> jugadores;

    public Club(String nombre, String nombreEntrenador, String pabellon) {
        this.nombre = nombre;
        this.entrenador = nombreEntrenador;
        this.pabellon = pabellon;
        this.jugadores = new ArrayList<Jugador>();
    }

    List obtenerDatosClub() {
        Jugador jugador;
        List infoClub = new ArrayList();
        List datosJugador;

        infoClub.add(this.nombre);
        infoClub.add(this.entrenador);
        infoClub.add(this.pabellon);

        for (Iterator<Jugador> it = this.jugadores.iterator(); it.hasNext();) {
            jugador = it.next();
            datosJugador = jugador.obtenerDatos();

            for (Iterator<Jugador> it2 = datosJugador.iterator(); it2.hasNext();) {
                infoClub.add(it2.next());
            }
        }

        return infoClub;
    }

    boolean dorsalOcupado(int dorsal) {
        boolean ocupado = false;
        Jugador jugador;

        for (Iterator<Jugador> it = this.jugadores.iterator(); (it.hasNext() & !ocupado);) {
            jugador = it.next();
            ocupado = jugador.esEsteTuDorsal(dorsal);
        }

        return ocupado;
    }

    void vincularJugador(Jugador jugador) {
        this.jugadores.add(jugador);
    }

    void desvincularJugador(Jugador jugador) throws Exception {
        boolean existe = this.existeJugador(jugador.obtenerNumeroLicencia());

        if (existe) {
            this.jugadores.remove(jugador);
        } else {
            throw new Exception("Jugador no vinculado a ese club.\n\n");
        }
    }

    String obtenerNombre() {
        return this.nombre;
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
}
