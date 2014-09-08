
import monitor.*;

class Estanco extends AbstractMonitor {

    private int estado;
    private Condition[] fumador = new Condition[3];
    private Condition estanquero;

    public Estanco() {
        this.estado = -1;

        for (int i = 0; i < this.fumador.length; i++) {
            this.fumador[i] = makeCondition();
        }

        this.estanquero = makeCondition();
    }

    public void obtenerIngredientes(int miIngrediente) {
        enter();

        if (estado != miIngrediente) {
            this.fumador[miIngrediente].await();
        }

        if (miIngrediente == 0) {
            System.out.println("El primer fumador coge el tabaco y las cerillas y se va a fumar.");
        } else if (miIngrediente == 1) {
            System.out.println("El segundo fumador coge el papel y las cerillas y se va a fumar.");
        } else {
            System.out.println("El tercer fumador coge el tabaco y el papel y se va a fumar.");
        }

        this.estado = -1;

        this.estanquero.signal();

        leave();
    }

    public void ponerIngredientes(int ingred1, int ingred2) {
        enter();

        if ((ingred1 == 0 && ingred2 == 1) || (ingred1 == 1 && ingred2 == 0)) {
            System.out.println("El estanquero pone tabaco y papel en la mesa.");
            this.estado = 2;
        } else if ((ingred1 == 0 && ingred2 == 2) || (ingred1 == 2 && ingred2 == 0)) {
            System.out.println("El estanquero pone papel y cerillas en la mesa.");
            this.estado = 1;
        } else if ((ingred1 == 1 && ingred2 == 2) || (ingred1 == 2 && ingred2 == 1)) {
            System.out.println("El estanquero pone tabaco y cerillas en la mesa.");
            this.estado = 0;
        }

        this.fumador[this.estado].signal();

        leave();
    }

    public void esperarRecogidaIngredientes() {
        enter();

        if (this.estado != -1) {
            this.estanquero.await();
        }

        System.out.println("La mesa del estanco está vacía.");

        leave();
    }
}

class Fumador implements Runnable {

    private Estanco estanco;
    private int miIngrediente;
    private int tiempo;

    public Fumador(int unIngrediente, Estanco unEstanco) {
        this.miIngrediente = unIngrediente;
        this.estanco = unEstanco;
        this.tiempo = 1000;
    }

    public void run() {
        while (true) {
            this.estanco.obtenerIngredientes(this.miIngrediente);

            System.out.println(Thread.currentThread().getName() + " está fumando...");

            try {
                Thread.sleep(tiempo);
            } catch (InterruptedException e) {
            }
        }

    }
}

class Estanquero implements Runnable {

    private Estanco estanco;

    public Estanquero(Estanco unEstanco) {
        this.estanco = unEstanco;
    }

    public void run() {
        int ingrediente1, ingrediente2;

        while (true) {
            do {
                ingrediente1 = (int) (Math.random() * 3.0);
                ingrediente2 = (int) (Math.random() * 3.0);
            } while (ingrediente1 == ingrediente2);

            estanco.ponerIngredientes(ingrediente1, ingrediente2);
            estanco.esperarRecogidaIngredientes();
        }

    }
}

public class Fumadores {

    public static void main(String[] args) {
        Estanco estanco = new Estanco();
        Thread hebraEstanquero = new Thread(new Estanquero(estanco));
        Thread[] hebraFumador = new Thread[3];

        hebraFumador[0] = new Thread(new Fumador(0, estanco), "El primer fumador");
        hebraFumador[1] = new Thread(new Fumador(1, estanco), "El segundo fumador");
        hebraFumador[2] = new Thread(new Fumador(2, estanco), "El tercer fumador");

        hebraEstanquero.start();

        for (int i = 0; i < hebraFumador.length; i++) {
            hebraFumador[i].start();
        }
    }
}
