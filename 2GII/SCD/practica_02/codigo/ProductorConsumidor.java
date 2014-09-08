
import monitor.*;

class Buffer extends AbstractMonitor {

    private int numSlots = 0;
    private volatile int cont = 0;
    private double[] buffer = null;
    private final Condition puede_despositar = makeCondition();
    private final Condition puede_extraer = makeCondition();

    public Buffer(int numSlots) {
        this.numSlots = numSlots;
        this.buffer = new double[this.numSlots];
    }

    public void depositar(double valor) {
        enter();

        if (this.cont == this.numSlots) {
            this.puede_despositar.await();
        }

        this.buffer[this.cont] = valor;
        this.cont++;

        this.puede_extraer.signal();

        leave();
    }

    public double extraer() {
        double valor;

        enter();

        if (this.cont == 0) {
            this.puede_extraer.await();
        }

        this.cont--;
        valor = this.buffer[this.cont];

        this.puede_despositar.signal();

        leave();

        return valor;
    }
}

class Productor implements Runnable {

    private Buffer bb = null;
    private int veces;

    public Productor(Buffer bb, int veces) {
        this.bb = bb;
        this.veces = veces;
    }

    public void run() {
        String str = Thread.currentThread().getName();
        double item = 100 * Integer.parseInt(str);
        int i = 0;

        while (i++ < this.veces) {
            this.bb.depositar(++item);
            System.out.println("Produciendo " + item);
        }

    }

}

class Consumidor implements Runnable {

    private Buffer bb = null;
    private int veces;

    public Consumidor(Buffer bb, int veces) {
        this.bb = bb;
        this.veces = veces;
    }

    public void run() {
        String str = Thread.currentThread().getName();
        double item;
        int i = 0;

        while (i++ < this.veces) {
            item = this.bb.extraer();
            System.out.println(Thread.currentThread().getName() + " consumiendo " + item);
        }
    }

}

public class ProductorConsumidor {

    public static void main(String[] args) {
        if (args.length != 5) {
            System.err.println("Uso: num_cons num_prods tam_buf n_iter_prod n_iter_cons");
        } else {
            try {
                int iter_cons = Integer.parseInt(args[3]);
                int iter_prod = Integer.parseInt(args[4]);

                Buffer buffer = new Buffer(Integer.parseInt(args[2]));

                Thread[] cons = new Thread[Integer.parseInt(args[0])];

                for (int i = 0; i < cons.length; i++) {
                    cons[i] = new Thread(new Consumidor(buffer, iter_cons), "Consumidor " + (i + 1));
                }

                Thread[] prod = new Thread[Integer.parseInt(args[1])];

                for (int i = 0; i < prod.length; i++) {
                    prod[i] = new Thread(new Productor(buffer, iter_prod), "" + (i + 1));
                }

                for (int i = 0; i < prod.length; i++) {
                    prod[i].start();
                }

                for (int i = 0; i < cons.length; i++) {
                    cons[i].start();
                }

            } catch (Exception e) {
                System.err.println("Excepcion en main: " + e);
            }
        }
    }
}
