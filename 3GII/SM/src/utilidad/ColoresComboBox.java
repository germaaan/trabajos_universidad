package utilidad;

import java.awt.Component;
import java.util.HashMap;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

/**
 * Lista de colores con iconos.
 * @author German Martinez Maldonado
 */
public class ColoresComboBox extends JLabel implements ListCellRenderer {

    HashMap<Object, ImageIcon> icono = null;
    String[] textoCombo = {"Negro", "Blanco", "Rojo", "Amarillo", "Azul", "Verde"};

    /**
     * Constructor de lista de colores con iconos.
     */
    public ColoresComboBox() {
        icono = new HashMap<>();
        icono.put("Negro", new ImageIcon(getClass().getResource("/iconos/Negro.png")));
        icono.put("Blanco", new ImageIcon(getClass().getResource("/iconos/Blanco.png")));
        icono.put("Rojo", new ImageIcon(getClass().getResource("/iconos/Rojo.png")));
        icono.put("Amarillo", new ImageIcon(getClass().getResource("/iconos/Amarillo.png")));
        icono.put("Azul", new ImageIcon(getClass().getResource("/iconos/Azul.png")));
        icono.put("Verde", new ImageIcon(getClass().getResource("/iconos/Verde.png")));
    }

    /**
     * Obtiene la lista de colores.
     *
     * @param list Lista de colores.
     * @param value Valor del color.
     * @param index Indice del color.
     * @param isSelected Indica si el color es seleccionado.
     * @param cellHasFocus Indica si la celda del color obtiene el foco.
     * @return Pareja icono-texto (siempre que haya un icono correspondiente a
     * dicho texto).
     */
    @Override
    public Component getListCellRendererComponent(JList list, Object value, int index,
            boolean isSelected, boolean cellHasFocus) {
        if (icono.get(value) != null) {
            setIcon(icono.get(value));
            setText(" " + value);
        } else {
            setIcon(null);
            setText(" " + value);
        }
        return this;
    }
}