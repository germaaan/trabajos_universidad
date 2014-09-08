package primerapractica;

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Map;

/**
 *
 *
 */
class Alumno {

    String nombre;
    GregorianCalendar fechaNacimiento = null;
    int curso = 0;
    String titulacion = null;
    Map<String, Asignatura> asignaturas = new HashMap();

    Alumno(String unNombre, GregorianCalendar unaFechNaci, int unCurso, String unaTitulacion) {
        nombre = unNombre;
        fechaNacimiento = unaFechNaci;
        curso = unCurso;
        titulacion = unaTitulacion;
    }

    Alumno(String unNombre, GregorianCalendar unaFecha) {// para construirse alumnos sin matricular
        nombre = unNombre;
        fechaNacimiento = unaFecha;
    }

    String getNombre() {
        return nombre;
    }

    int getAnioNacimiento() {
        return fechaNacimiento.get(Calendar.YEAR);
    }

    int getMesNacimiento() {
        return fechaNacimiento.get(Calendar.MONTH) + 1;
    }

    int getDiaNacimiento() {
        return fechaNacimiento.get(Calendar.DATE);
    }

    GregorianCalendar getFechaNacimiento() {
        return fechaNacimiento;
    }

    String getFechaNacimientoToString() {
        return this.getDiaNacimiento() + " del "
                + this.getMesNacimiento() + " de "
                + this.getAnioNacimiento();
    }

    String getCurso() {
        return Integer.toString(curso);
    }

    String getTitulacion() {
        return titulacion;
    }

    void setTitulacion(String unaTitulacion) {
        titulacion = unaTitulacion;
    }

    void setCurso(int unCurso) {
        curso = unCurso;
    }

    void setNombre(String unNombre) {
        nombre = unNombre;
    }

    void matricular(String unaTitulacion, int unCurso) {
        if (titulacion == null) {
            titulacion = unaTitulacion;
            curso = unCurso;
        }
    }

    @Override
    public String toString() {
        if (titulacion != null) {
            return getNombre() + " con fecha de nacimiento " + getFechaNacimientoToString() + " esta estudiando " + getCurso() + "º de " + getTitulacion() + ".";
        } else {
            return getNombre() + " con fecha de nacimiento " + getFechaNacimientoToString() + " aun no se ha matriculado.";
        }
    }

    void comer(String alimento) {
        if (alimento.equals("Solido.")) {
            System.out.println("Ñan Ñan");
        } else if (alimento.equals("Liquido")) {
            System.out.println("Glup Glup");
        }
    }

    void respirar() {
        System.out.println("Inspira...Expira...");
    }

    void dormir() {
        System.out.println("ZzZzZz");
    }

    void estudiar() {
        if (titulacion != null) {
            System.out.println("Estudiar, estudiar, tomar un cafe, estudiar...");
        } else {
            System.out.println("Todavia no tengo que estudiar");
        }
    }

    int edad() {
        int edad;
        if (new GregorianCalendar().get(Calendar.MONTH) < fechaNacimiento.get(Calendar.MONTH)) {
            edad = new GregorianCalendar().get(Calendar.YEAR) - fechaNacimiento.get(Calendar.YEAR) - 1;
        } else if (new GregorianCalendar().get(Calendar.MONTH) == fechaNacimiento.get(Calendar.MONTH)) {
            if (new GregorianCalendar().get(Calendar.DATE) < fechaNacimiento.get(Calendar.DATE)) {
                edad = new GregorianCalendar().get(Calendar.YEAR) - fechaNacimiento.get(Calendar.YEAR) - 1;
            } else {
                edad = new GregorianCalendar().get(Calendar.YEAR) - fechaNacimiento.get(Calendar.YEAR);
            }
        } else {
            edad = new GregorianCalendar().get(Calendar.YEAR) - fechaNacimiento.get(Calendar.YEAR);
        }

        return edad;
    }

    String cumple() {
        return " el " + fechaNacimiento.get(Calendar.DATE) + " del " + (fechaNacimiento.get(Calendar.MONTH) + 1);
    }

    boolean esMenor(Alumno a1) {
        return fechaNacimiento.after(a1.getFechaNacimiento());

    }

    void matricularAsignatura(Asignatura asig) throws Exception {
        if (titulacion != null) {
            if (!estaMatriculado(asig.getCodigo())) {
                asignaturas.put(asig.getCodigo(), asig);
            } else {
                throw new Exception("\nEste alumno ya esta matriculado de esa asignatura.");
            }
        } else {
            throw new Exception("\nEl alumno no se encuentra estudiando en este momento.");
        }
    }

    void desmatricularAsignatura(String codAsig) throws Exception {
        if (titulacion != null) {
            if (estaMatriculado(codAsig)) {
                asignaturas.remove(codAsig);
            } else {
                throw new Exception("\nEste alumno no tiene esa asignatura matriculada.");
            }
        } else {
            throw new Exception("\nEl alumno no se encuentra estudiando en este momento.");
        }
    }

    void mostrarMatricula() throws Exception {
        if (titulacion != null) {
            System.out.println("\nEl alumno " + getNombre() + " se encuentra matriculado de: ");
            for (Asignatura asignatura : asignaturas.values()) {
                System.out.println(asignatura.toString());
            }
        } else {
            throw new Exception("\nEl alumno no se encuentra estudiando en este momento.");
        }
    }

    Asignatura buscarAsignatura(String codAsig) throws Exception {
        if (asignaturas.containsKey(codAsig)) {
            return asignaturas.get(codAsig);
        } else {
            throw new Exception("\nAsignatura no encontrada.");
        }
    }

    boolean estaMatriculado(String codAsig) {
        if (asignaturas.containsKey(codAsig)) {
            return true;
        } else {
            return false;
        }
    }
}
