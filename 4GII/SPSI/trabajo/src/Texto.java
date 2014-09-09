package SiCoEn;

import java.io.File;

/**
 * Ventana de texto.
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class Texto extends javax.swing.JInternalFrame {

    private File archivo;
    private int formato;

    /**
     * Constructor de la ventana de texto.
     *
     * @param texto Texto que será mostrado en la ventana una vez sea creada.
     */
    public Texto(String texto) {
        initComponents();

        this.archivo = null;
        this.formato = Formato.FORMATO_ASCII;
        this.campoTexto.setText(texto);
    }

    /**
     * Método que asigna un archivo de texto a una ventana de texto. Necesario
     * para las operaciones de cifrado y descifrado.
     *
     * @param archivo Archivo de texto que será asignado a la ventana de texto.
     */
    public void setArchivo(File archivo) {
        this.archivo = archivo;
    }

    /**
     * Método que devuelve el archivo al que está asignado la ventana de texto.
     *
     * @return Archivo al que está asignado la ventana de texto.
     */
    public File getArchivo() {
        return this.archivo;
    }

    /**
     * Método que asigna el formato en el que está el texto de la ventana
     * (ASCII, binario o hexadecimal).
     *
     * @param formato Formato al que se va a cambiar el texto de la ventana.
     */
    public void setFormato(int formato) {
        this.formato = formato;
    }

    /**
     * Método que devuelve el formato en el que está el texto de la ventana.
     *
     * @return Formato del texto de la ventana.
     */
    public int getFormato() {
        return this.formato;
    }

    /**
     * Método que devuelve el texto actual que se muestra en la ventana.
     *
     * @return Texto de la ventana.
     */
    public String getTexto() {
        String texto = null;

        try {
            texto = this.campoTexto.getText();
        } catch (NullPointerException npe) {
            System.err.println("Error: Campo de texto vacío. " + npe.getMessage());
        }

        return texto;
    }

    /**
     * Método que permite asignar texto a la ventana para que sea mostrado en
     * ella.
     *
     * @param texto Texto a introducir en la ventana.
     */
    public void setTexto(String texto) {
        this.campoTexto.setText(texto);
    }

    /**
     * Método de inialización de los elementos gráficos.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panelScroll = new javax.swing.JScrollPane();
        campoTexto = new javax.swing.JTextArea();
        campoTexto.setLineWrap(true);
        campoTexto.setWrapStyleWord(true);

        setClosable(true);
        setIconifiable(true);
        setMaximizable(true);
        setResizable(true);
        setMaximumSize(null);
        setMinimumSize(new java.awt.Dimension(550, 400));
        setPreferredSize(new java.awt.Dimension(550, 400));

        panelScroll.setMaximumSize(null);
        panelScroll.setMinimumSize(new java.awt.Dimension(400, 400));
        panelScroll.setPreferredSize(new java.awt.Dimension(400, 400));

        campoTexto.setColumns(20);
        campoTexto.setRows(5);
        panelScroll.setViewportView(campoTexto);

        getContentPane().add(panelScroll, java.awt.BorderLayout.CENTER);

        pack();
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea campoTexto;
    private javax.swing.JScrollPane panelScroll;
    // End of variables declaration//GEN-END:variables
}
