import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Random;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;

public class Procesador extends Thread {

    private static final int TOPE = 20;
    private Socket socketServicio;
    private Random random;
    private int numeroPropio;

    public Procesador(Socket socketServicio) {
        this.socketServicio = socketServicio;

        this.random = new Random();
        do {
            this.numeroPropio = random.nextInt(TOPE);
        } while (numeroPropio == 0);
    }

    public void run() {
        procesa();
    }

    void procesa() {
        String buferRecepcion = null;
        String buferEnvio = null;
        int numeroRecibido;
        int numeroCliente;
        int inferior = 0;
        int superior = TOPE;
        boolean fin = false;

        InputStream inputStream = null;
        OutputStream outputStream = null;
        PrintWriter outPrinter = null;
        BufferedReader inReader = null;

        try {
            inputStream = socketServicio.getInputStream();
            outputStream = socketServicio.getOutputStream();
            inReader = new BufferedReader(new InputStreamReader(inputStream));
            outPrinter = new PrintWriter(outputStream, true);

            do {
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

                    do {
                        numeroCliente = random.nextInt(superior);
                    } while (numeroCliente <= inferior);

                    buferEnvio = Integer.toString(numeroCliente);

                    System.out.println("\tServidor envía: " + buferEnvio);

                    outPrinter.println(buferEnvio);
                    outPrinter.flush();

                    buferRecepcion = inReader.readLine();

                    if (buferRecepcion.equals("=")) {
                        fin = true;
                        socketServicio.close();
                        System.out.println("Respuesta de cliente: Correcto, " + numeroCliente + ". El servidor ha ganado.");
                    } else {

                        if (buferRecepcion.equals("<")) {
                            superior = numeroCliente;
                        } else {
                            inferior = numeroCliente;
                        }

                        System.out.println("Respuesta de cliente: " + buferRecepcion);
                    }
                }

            } while (!fin);

        } catch (IOException e) {
            System.err.println("Error al obtener los flujo de entrada/salida.");
        }
    }
}
