package primerapractica;

class Asignatura {

    String codigo;
    String titulo;
    float creditosECTS;

    Asignatura(String unCodigo, String unTitulo, float creditos) {
        codigo = unCodigo;
        titulo = unTitulo;
        creditosECTS = creditos;
    }

    String getCodigo() {
        return codigo;
    }

    String getTitulo() {
        return titulo;
    }

    float getCreditosECTS() {
        return creditosECTS;
    }

    void setTitulo(String unTitulo) {
        titulo = unTitulo;
    }

    void setCreditosECTS(float creditos) {
        creditosECTS = creditos;
    }

    @Override
    public String toString() {
        String creditos = Float.toString(creditosECTS);
        return "Asignatura de " + titulo + " con " + creditos
                + " creditos ECTS.";
    }
}
