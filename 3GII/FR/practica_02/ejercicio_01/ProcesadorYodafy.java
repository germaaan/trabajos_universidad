import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Random;

public class ProcesadorYodafy {
    private Socket socketServicio;
    private InputStream inputStream;
    private OutputStream outputStream;
    private Random random;

    public ProcesadorYodafy(Socket socketServicio) {
        this.socketServicio = socketServicio;
        random = new Random();
    }

    void procesa() {
        byte[] datosRecibidos = new byte[1024];
        int bytesRecibidos = 0;

        byte[] datosEnviar;

        try {
            inputStream = socketServicio.getInputStream();
            outputStream = socketServicio.getOutputStream();

            bytesRecibidos = inputStream.read(datosRecibidos);

            String peticion = new String(datosRecibidos, 0, bytesRecibidos);
            String respuesta = yodaDo(peticion);
            datosEnviar = respuesta.getBytes();

            outputStream.write(datosEnviar, 0, datosEnviar.length);
        } catch (IOException e) {
            System.err.println("Error al obtener los flujo de entrada/salida.");
        }
    }

    private String yodaDo(String peticion) {
        String[] s = peticion.split(" ");
        String resultado = "";

        for (int i = 0; i < s.length; i++) {
            int j = random.nextInt(s.length);
            int k = random.nextInt(s.length);
            String tmp = s[j];

            s[j] = s[k];
            s[k] = tmp;
        }

        resultado = s[0];

        for (int i = 1; i < s.length; i++) {
            resultado += " " + s[i];
        }

        return resultado;
    }
}
