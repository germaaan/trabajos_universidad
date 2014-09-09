package SiCoEn;

/**
 * Clase principal de la aplicación.
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class SiCoEn {

    /**
     * Metodo principal de la aplicacion.
     *
     * @param args El argumento de línea de comandos.
     */
    public static void main(String args[]) {
        /* Establece el Nimbus Look and Feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Crear y mostrar el formulario */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Interfaz().setVisible(true);
            }
        });
    }
}
