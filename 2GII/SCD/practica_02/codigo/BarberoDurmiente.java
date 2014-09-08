
import monitor.*;

class Barberia extends AbstractMonitor {

    private boolean barberoOcupado;
    private boolean sillaOcupada;
    private boolean puertaAbierta;
    private final Condition barbero;
    private final Condition silla;
    private final Condition puerta;
    private final Condition siguienteCliente;

    public Barberia() {
        this.barberoOcupado = false;
        this.sillaOcupada = false;
        this.puertaAbierta = false;

        this.barbero = makeCondition();
        this.silla = makeCondition();
        this.puerta = makeCondition();
        this.siguienteCliente = makeCondition();
    }

    public void cortarPelo() {
        enter();

        if (this.barberoOcupado) {
            System.out.println("Un cliente quiere pelarse pero el barbero está ocupado.");
            this.barbero.await();
        } else {
            System.out.println("El cliente despierta al barbero para que le corte el pelo.\n...");
        }

        this.barberoOcupado = true;
        this.sillaOcupada = true;

        this.silla.signal();

        if (!this.puertaAbierta) {
            this.puerta.await();
        }

        this.puertaAbierta = false;
        System.out.println("El cliente que acaba de pelarse ha salido por la puerta.");

        if (this.siguienteCliente.isEmpty()) {
            System.out.println("El barbero no tiene trabajo y se pone a dormir.");
        } else {
            System.out.println("El barbero espera al próximo cliente.");
        }

        this.siguienteCliente.signal();

        leave();
    }

    public void siguienteCliente() {
        enter();

        this.barberoOcupado = false;

        this.barbero.signal();

        if (!this.sillaOcupada) {
            this.silla.await();
        }

        this.sillaOcupada = false;

        leave();
    }

    public void finCliente() {
        enter();

        this.puertaAbierta = true;
        this.puerta.signal();

        if (this.puertaAbierta) {
            this.siguienteCliente.await();
        }

        leave();
    }

}

class Cliente implements Runnable {

    private Barberia barberia;
    private int tiempo;

    public Cliente(Barberia unaBarberia) {
        this.barberia = unaBarberia;
        this.tiempo = 100;
    }

    public void run() {

        while (true) {
            System.out.println("\nUn nuevo cliente entra en la barberia.");

            this.barberia.cortarPelo();

            try {
                Thread.sleep(this.tiempo);
            } catch (InterruptedException e) {
            }
        }

    }
}

class Barbero implements Runnable {

    private Barberia barberia;
    private int tiempo;

    public Barbero(Barberia unaBarberia) {
        this.barberia = unaBarberia;
    }

    public void run() {

        while (true) {
            this.barberia.siguienteCliente();

            this.tiempo = (int) (Math.random() * 2000.0);

            try {
                Thread.sleep(this.tiempo);
            } catch (InterruptedException e) {
            }

            this.barberia.finCliente();
        }

    }
}

public class BarberoDurmiente {

    public static void main(String[] args) {
        Barberia barberia = new Barberia();
        Thread hebraBarbero = new Thread(new Barbero(barberia));
        Thread hebraCliente = new Thread(new Cliente(barberia));

        hebraBarbero.start();
        hebraCliente.start();
    }
}
