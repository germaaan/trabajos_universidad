package munchkin_cthulhu;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Munchkin juego = Munchkin.getInstance();

            Vista v = new VentanaPrincipal(juego);

            v.mostrar(args);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}
