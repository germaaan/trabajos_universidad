package primerapractica;

import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.List;
import java.util.ListIterator;

public class PruebaPrimeraPractica {

    public static void main(String[] args) {
        List<Alumno> alumnos = new ArrayList();

        GregorianCalendar fn = new GregorianCalendar(1970, 12, 2);
        Alumno alu = new Alumno("Juan Pedro", fn, 1, "Informatica");
        alumnos.add(alu);
        System.out.println(alu.toString());

        GregorianCalendar fn2 = new GregorianCalendar(1980, 5, 31);
        Alumno alu2 = new Alumno("Ana Maria", fn2);
        alumnos.add(alu2);
        System.out.println(alu2.toString());

        System.out.println("\nEl alumno " + alu.getNombre() + " tiene " + alu.edad() + " años.");

        System.out.println("\nAcciones del alumno " + alu.getNombre() + ":");
        for (int i = 0; i < 5; i++) {
            alu.dormir();
            alu.respirar();
            alu.comer("Solido");
            alu.estudiar();
        }

        int i = 0;
        System.out.println("\nAcciones del alumno " + alu2.getNombre() + ":");
        while (i < 5) {
            alu2.dormir();
            alu2.respirar();
            alu2.comer("Solido");
            alu2.estudiar();
            i++;
        }

        System.out.println("\n¿Es " + alu.getNombre() + " menor que " + alu2.getNombre() + "? "
                + alu.esMenor(alu2));

        Asignatura asig1 = new Asignatura("1", "PDOO", 6);
        Asignatura asig2 = new Asignatura("2", "FIS", 6);
        Asignatura asig3 = new Asignatura("3", "SO", 6);

        try {
            alu.matricularAsignatura(asig1);
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar matricular a " + alu.getNombre()
                    + " en la asignatura de " + asig1.getTitulo() + ".");
        }

        try {
            alu.matricularAsignatura(asig2);
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar matricular a " + alu.getNombre()
                    + " en la asignatura de " + asig2.getTitulo() + ".");
        }

        try {
            alu2.matricularAsignatura(asig3);
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar matricular a " + alu2.getNombre()
                    + " en la asignatura de " + asig3.getTitulo() + ".");
        }

        try {
            alu.mostrarMatricula();
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar mostrar la matricula de "
                    + alu.getNombre() + ".");
        }

        try {
            alu2.mostrarMatricula();
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar mostrar la matricula de "
                    + alu2.getNombre() + ".");
        }

        try {
            alu.desmatricularAsignatura("1");
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar desmatricular a " + alu.getNombre()
                    + " en la asignatura con codigo 1.");
        }

        try {
            alu.mostrarMatricula();
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar mostrar la matricula de "
                    + alu.getNombre() + ".");
        }

        alu2.matricular("Informatica", 4);

        try {
            alu2.matricularAsignatura(asig3);
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar matricular a " + alu2.getNombre()
                    + " en la asignatura de " + asig3.getTitulo() + ".");
        }

        try {
            alu2.matricularAsignatura(asig2);
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar matricular a " + alu2.getNombre()
                    + " en la asignatura de " + asig2.getTitulo() + ".");
        }

        try {
            alu2.mostrarMatricula();
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar mostrar la matricula de "
                    + alu2.getNombre() + ".");
        }

        try {
            alu2.desmatricularAsignatura("1");
        } catch (Exception ex) {
            //Logger.getLogger(PruebaPrimeraPractica.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\nExcepcion capturada al intentar desmatricular a " + alu2.getNombre()
                    + " en la asignatura con codigo 1.");
        }

        System.out.println("\nMostrando informacion de todos los alumnos del sistema: " + alumnos.size());
        ListIterator<Alumno> itAlum = alumnos.listIterator();
        while (itAlum.hasNext()) {
            System.out.println(itAlum.next().toString());
        }
    }
}
