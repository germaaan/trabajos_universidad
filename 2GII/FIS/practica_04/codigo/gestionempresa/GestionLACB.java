package GestionEmpresa;

import ModeloLACB.LACB;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author Germán Martínez Maldonado
 */
public class GestionLACB {

    public static void main(String[] args) throws IOException {
        LACB miLiga = LACB.getLACB();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int opcion = 0;
        int nuevoDorsal;
        int contador;
        float altura;
        float peso;
        boolean tieneEquipo = false;
        boolean tieneJugadores = false;
        String nombreClub;
        String nombreEntrenador;
        String pabellon;
        String nombreJugador;
        String dniPass;
        SimpleDateFormat formatoFecha = new SimpleDateFormat("dd/MM/yyyy");
        Date fechaNaci;
        List infoClub;
        List infoJugador;
        Object valor;

        do {
            try {
                contador = 0;

                System.out.println("GESTIÓN DE LA EMPRESA. Menú principal:\n"
                        + "=====================================\n\n"
                        + "\t1. Dar de alta un club.\n"
                        + "\t2. Dar de alta un jugador.\n"
                        + "\t3. Vincular un jugador a un club.\n"
                        + "\t4. Desvincular a un jugador de un club\n"
                        + "\t5. Obtener la información de un club y sus jugador.\n"
                        + "\t6. Obtener información de un jugador y su club (si lo tiene).\n"
                        + "\t0. Terminar.\n");

                System.out.print("Seleccione una opción: ");

                try {
                    opcion = Integer.parseInt(in.readLine());

                    System.out.println("\n");

                    switch (opcion) {
                        case 1:
                            System.out.println("ALTA DE CLUB:\n");

                            System.out.print("Introduzca el nombre del club: ");
                            nombreClub = in.readLine().toUpperCase();
                            System.out.print("Introduzca el nombre del entrenador: ");
                            nombreEntrenador = in.readLine().toUpperCase();
                            System.out.print("Introduzca el nombre del pabellon: ");
                            pabellon = in.readLine().toUpperCase();

                            miLiga.incluirClub(nombreClub, nombreEntrenador, pabellon);
                            System.out.println("\nClub dado de alta en el sistema.\n\n");

                            break;

                        case 2:
                            System.out.println("ALTA DE JUGADOR:\n");

                            System.out.print("Introduzca el nombre del jugador: ");
                            nombreJugador = in.readLine().toUpperCase();
                            System.out.print("Introduzca el DNI o Pasaporte del jugador: ");
                            dniPass = in.readLine().toUpperCase();
                            System.out.print("Introduzca la fecha de nacimiento del jugador (DD/MM/YYYY): ");
                            fechaNaci = formatoFecha.parse(in.readLine());
                            System.out.print("Introduzca la altura del jugador (en metros): ");
                            altura = Float.parseFloat(in.readLine());
                            System.out.print("Introduzca la posición del jugador: ");
                            String posicion = in.readLine().toUpperCase();
                            System.out.print("Introduzca el peso del jugador (en kilos): ");
                            peso = Float.parseFloat(in.readLine());
                            System.out.print("Introduzca la nacionalidad del jugador: ");
                            String nacionalidad = in.readLine().toUpperCase();

                            miLiga.altaJugador(dniPass, nombreJugador, fechaNaci, altura, peso, posicion, nacionalidad);
                            System.out.println("\nJugador dado de alta en el sistema.\n\n");

                            break;

                        case 3:
                            System.out.println("VINCULACIÓN DE JUGADOR CON CLUB:\n");

                            System.out.print("Introduzca el nombre del club: ");
                            nombreClub = in.readLine().toUpperCase();
                            System.out.print("Introduzca el DNI o Pasaporte del jugador: ");
                            dniPass = in.readLine().toUpperCase();
                            System.out.print("Introduzca el dorsal del jugador: ");
                            nuevoDorsal = Integer.parseInt(in.readLine());

                            try {
                                miLiga.vincularJugador(nombreClub, dniPass, nuevoDorsal);
                                System.out.println("\nJugador vinculado a club en el sistema.\n\n");
                            } catch (NullPointerException npex) {
                                System.err.println("\nNo existe club o jugador en el sistema.\n\n");
                            }

                            break;

                        case 4:
                            System.out.println("DESVINCULACIÓN DE JUGADOR CON CLUB:\n");

                            System.out.print("Introduzca el nombre del club: ");
                            nombreClub = in.readLine().toUpperCase();
                            System.out.print("Introduzca el DNI o Pasaporte del jugador: ");
                            dniPass = in.readLine().toUpperCase();

                            try {
                                miLiga.desvincularJugador(nombreClub, dniPass);
                                System.out.println("\nJugador desvinculado a club en el sistema.\n\n");
                            } catch (NullPointerException npex) {
                                System.err.println("\nNo existe club o jugador en el sistema.\n\n");
                            }

                            break;

                        case 5:
                            System.out.println("INFORMACIÓN DE UN CLUB Y SUS JUGADORES:\n");

                            System.out.print("Introduzca el nombre del club: ");
                            nombreClub = in.readLine().toUpperCase();

                            try {
                                infoClub = miLiga.consultarClub(nombreClub);

                                for (Iterator<Object> it = infoClub.iterator(); it.hasNext(); contador++) {
                                    valor = it.next();

                                    if (contador == 0) {
                                        System.out.println("\nNombre del club: " + valor.toString());
                                    } else if (contador == 1) {
                                        System.out.println("Nombre del entrenador: " + valor.toString());
                                    } else if (contador == 2) {
                                        System.out.println("Nombre del pabellon: " + valor.toString());
                                        System.out.println("Datos de los jugadores:");
                                    } else if (contador == 3) {
                                        tieneJugadores = true;
                                        System.out.println("\tNúmero de licencia: " + valor.toString());
                                    } else if (contador == 4) {
                                        System.out.println("\tNombre: " + valor.toString());
                                    } else if (contador == 5) {
                                        System.out.println("\tDNI/Pasaporte: " + valor.toString());
                                    } else if (contador == 6) {
                                        System.out.println("\tFecha nacimiento: " + formatoFecha.format((Date) valor));
                                    } else if (contador == 7) {
                                        System.out.println("\tAltura: " + valor.toString());
                                    } else if (contador == 8) {
                                        System.out.println("\tPosicion: " + valor.toString());
                                    } else if (contador == 9) {
                                        System.out.println("\tPeso: " + valor.toString());
                                    } else if (contador == 10) {
                                        System.out.println("\tNacionalidad: " + valor.toString());
                                    } else {
                                        System.out.println("\tDorsal: " + valor.toString() + "\n\n");
                                        contador = 3;
                                    }
                                }

                                if (!tieneJugadores) {
                                    System.out.println("\nNo tiene jugadores vinculados.\n\n");
                                }
                            } catch (NullPointerException npex) {
                                System.err.println("\nNo existe club con ese nombre.\n\n");
                            }

                            break;

                        case 6:
                            System.out.println("INFORMACIÓN DE UN JUGADOR Y SU CLUB:\n");

                            System.out.print("Introduzca el DNI/Pasaporte del jugador: ");
                            dniPass = in.readLine().toUpperCase();

                            try {
                                infoJugador = miLiga.consultarJugador(dniPass);

                                for (Iterator<Object> it = infoJugador.iterator(); it.hasNext(); contador++) {
                                    valor = it.next();

                                    if (contador == 0) {
                                        System.out.println("\tNúmero de licencia: " + valor.toString());
                                    } else if (contador == 1) {
                                        System.out.println("\tNombre: " + valor.toString());
                                    } else if (contador == 2) {
                                        System.out.println("\tDNI/Pasaporte: " + valor.toString());
                                    } else if (contador == 3) {
                                        System.out.println("\tFecha nacimiento: " + formatoFecha.format((Date) valor));
                                    } else if (contador == 4) {
                                        System.out.println("\tAltura: " + valor.toString());
                                    } else if (contador == 5) {
                                        System.out.println("\tPosicion: " + valor.toString());
                                    } else if (contador == 6) {
                                        System.out.println("\tPeso: " + valor.toString());
                                    } else if (contador == 7) {
                                        System.out.println("\tNacionalidad: " + valor.toString());
                                    } else if (contador == 8) {
                                        if (valor.toString().equals("-1")) {
                                            System.out.println("\tDorsal: SIN DORSAL\n");
                                        } else {
                                            System.out.println("\tDorsal: " + valor.toString() + "\n");
                                        }
                                    } else {
                                        tieneEquipo = true;
                                        System.out.println("\tNombre del equipo vinculado: " + valor.toString() + "\n\n");
                                    }
                                }

                                if (!tieneEquipo) {
                                    System.out.println("\tNo está vinculado a ningún equipo.\n\n");
                                }
                            } catch (NullPointerException npex) {
                                System.err.println("\nNo existe jugador con ese DNI/Pasaporte.\n\n");
                            }

                            break;

                        case 0:
                            System.out.println("Saliendo del programa...");

                            break;

                        default:
                            System.out.println("Opción introducida no válida.");
                    }
                } catch (NumberFormatException nfe) {
                    System.err.println("Error en el formato de la opción seleccionada. Sólo valores numéricos.");
                    opcion = -1;
                }

            } catch (Exception ex) {
                System.err.println(ex);
            }

        } while (opcion != 0);
    }
}
