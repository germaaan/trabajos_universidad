import java.io.IOException;
import java.net.Socket;
import java.net.ServerSocket;

public class Servidor {

    public static void main(String args[]) throws IOException {
        int port = 8989;

        try {
            ServerSocket socketServidor = new ServerSocket(port);

            do {
                Socket socketServicio = socketServidor.accept();

                Procesador procesador = new Procesador(socketServicio);

                procesador.start();
            } while (true);

        } catch (IOException e) {
            System.err.println("Error al escuchar en el puerto " + port);
        }
    }
}
