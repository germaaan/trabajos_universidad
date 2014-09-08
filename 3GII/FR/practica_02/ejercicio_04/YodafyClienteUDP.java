import java.io.IOException;
import java.net.UnknownHostException;
import java.net.DatagramSocket;		// Añadido
import java.net.DatagramPacket;		// Añadido
import java.net.InetAddress;		// Añadido

public class YodafyClienteUDP {
    public static void main(String[] args) {
        byte[] buferEnvio = new byte[256];
        byte[] buferRecepcion = new byte[256];

        int port = 8989;

        // Añadidos elementos necesarios para establecer la comunicación mediante datagramas.
        DatagramSocket socket = null;
        DatagramPacket paquete = null;
        DatagramPacket paqueteModificado = null;
        InetAddress direccion = null;

        String fraseYodificada;

        // Se crea el socket para la comunicación mediante datagramas
        try {
            socket = new DatagramSocket();
        } catch (IOException e) {
            System.err.println("Error de entrada/salida al abrir el socket.");
        }

        // Se obtiene la dirección con la que se quiere realizar la comunicación
        try {
            direccion = InetAddress.getByName("localhost");
        } catch (UnknownHostException e) {
            System.out.println("Error al recuperar la direccion.");
        }

        buferEnvio = "Al monte del volcan debes ir sin demora".getBytes();

        // Se envian un DatagramPacket con el mensaje original y se recibe uno con el mensaje yodificado
        try {
            paquete = new DatagramPacket(buferEnvio, buferEnvio.length, direccion, port);
            socket.send(paquete);

            paqueteModificado = new DatagramPacket(buferRecepcion, buferRecepcion.length);
            socket.receive(paqueteModificado);
        } catch (IOException e) {
            System.err.println("Error de entrada/salida al abrir el socket.");
        }

        fraseYodificada = new String(paqueteModificado.getData());

        System.out.println("\nRecibido: " + fraseYodificada + "\n");
        socket.close();
    }
}
