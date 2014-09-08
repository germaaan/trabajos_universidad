
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Cliente_Calculadora {

    public static void main(String args[]) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String nombre_objeto_remoto = "calculadora_remota";
            System.out.println("Buscando el objeto remoto");
            Registry registry = LocateRegistry.getRegistry(args[0]);
            Calculadora_I instancia_local = (Calculadora_I) registry.lookup(nombre_objeto_remoto);
            System.out.println("Invocando el objeto remoto");

            if (0 == args[2].compareTo("+")) {
                System.out.println(instancia_local.sumar(Integer.parseInt(args[1]), Integer.parseInt(args[3])));
            }

            if (args[2].compareTo("-") == 0) {
                System.out.println(instancia_local.restar(Integer.parseInt(args[1]), Integer.parseInt(args[3])));
            }

            if (args[2].compareTo("x") == 0) {
                System.out.println(instancia_local.multiplicar(Integer.parseInt(args[1]), Integer.parseInt(args[3])));
            }

            if (args[2].compareTo("/") == 0) {
                System.out.println(instancia_local.dividir(Double.parseDouble(args[1]), Double.parseDouble(args[3])));
            }

        } catch (Exception e) {
            System.err.println("Ejemplo_I exception:");
            e.printStackTrace();
        }
    }
}
