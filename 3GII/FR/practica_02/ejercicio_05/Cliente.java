import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;

public class Cliente {
    private static final int TOPE = 20;

    public static void main(String[] args) {

        String buferEnvio;
        String buferRecepcion = null;

        String host = "localhost";
        int port = 8989;
        int numeroPropio;
        int numeroServidor;
        int numeroRecibido;
        int inferior = 0;
        int superior = TOPE;
        boolean fin = false;

        Socket socketServicio = null;
        InputStream inputStream = null;
        OutputStream outputStream = null;
        PrintWriter outPrinter = null;
        BufferedReader inReader = null;

        Random random = new Random();

        try {
            socketServicio = new Socket(host, port);
            inputStream = socketServicio.getInputStream();
            outputStream = socketServicio.getOutputStream();
            outPrinter = new PrintWriter(outputStream, true);
            inReader = new BufferedReader(new InputStreamReader(inputStream));
        } catch (IOException e) {
            System.err.println("Error de entrada/salida al abrir el socket.");
        }

        do {
            numeroPropio = random.nextInt(TOPE);
        } while (numeroPropio == 0);

        do {
            try {

                do {
                    numeroServidor = random.nextInt(superior);
                } while (numeroServidor <= inferior);

                buferEnvio = Integer.toString(numeroServidor);

                System.out.println("Cliente envía: " + buferEnvio);

                outPrinter.println(buferEnvio);
                outPrinter.flush();

                buferRecepcion = inReader.readLine();

                if (buferRecepcion.equals("=")) {
                    fin = true;
                    socketServicio.close();
                    System.out.println("\tRespuesta de servidor: Correcto, " + numeroServidor + ". El cliente ha ganado.");
                } else {

                    if (buferRecepcion.equals("<")) {
                        superior = numeroServidor;
                    } else {
                        inferior = numeroServidor;
                    }

                    System.out.println("\tRespuesta de servidor: " + buferRecepcion);

                    buferRecepcion = inReader.readLine();

                    numeroRecibido = Integer.parseInt(buferRecepcion);

                    if (numeroRecibido == numeroPropio) {
                        outPrinter.println("=");
                        fin = true;
                    } else {

                        if (numeroRecibido > numeroPropio) {
                            outPrinter.println("<");
                        } else {
                            outPrinter.println(">");
                        }
                    }
                }

            } catch (IOException e) {
                System.err.println("Error de entrada/salida al abrir el socket.");
            }
        } while (!fin);
    }
}
