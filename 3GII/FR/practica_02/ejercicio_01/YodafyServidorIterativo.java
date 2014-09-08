import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class YodafyServidorIterativo {
    public static void main(String[] args) {
        int port = 8989;

        try {
            ServerSocket socketServidor = new ServerSocket(port);

            do {
                Socket socketServicio = socketServidor.accept();

                ProcesadorYodafy procesador = new ProcesadorYodafy(socketServicio);
                procesador.procesa();
            } while (true);
        } catch (IOException e) {
            System.err.println("Error al escuchar en el puerto " + port);
        }
    }
}
