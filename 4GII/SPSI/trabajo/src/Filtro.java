package SiCoEn;

import java.io.File;
import javax.swing.filechooser.FileFilter;

/**
 * Filtro de archivos.
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class Filtro extends FileFilter {

    /**
     * Código interno que representa filtro de archivo de texto plano.
     */
    public final static int ABRIR_TEXTO_PLANO = 1;
    /**
     * Código interno que representa filtro de guardado.
     */
    public final static int GUARDAR = 4;
    private int tipoFiltro;
    private String extension;

    /**
     * Constructor del filtro.
     *
     * @param tipoFiltro Tipo de filtro a crear de los predefinidos.
     * @param extension Extensión concreta del filtro.
     */
    public Filtro(int tipoFiltro, String extension) {
        super();

        this.tipoFiltro = tipoFiltro;
        this.extension = extension;
    }

    /**
     * Obtiene la extensión del archivo seleccionado.
     *
     * @param f Archivo seleccionado.
     * @return Extensión del archivo seleccionado.
     */
    public static String getFileExtension(File f) {
        String fileExt = null;
        String s = f.getName();
        int i = s.lastIndexOf('.');

        if (i > 0 && i < s.length() - 1) {
            fileExt = s.substring(i + 1).toLowerCase();
        }

        return fileExt;
    }

    /**
     * Devuelve el tipo de filtro seleccionado.
     *
     * @return Tipo de filtro seleccionado.
     */
    public int getTipoFiltro() {
        return tipoFiltro;
    }

    /**
     * Devuelve la extensión del tipo de filtro seleccionado.
     *
     * @return Extensión del tipo de filtro seleccionado.
     */
    public String getExtension() {
        return extension;
    }

    /**
     * Aceptar un archivo como seleccionable.
     *
     * @param f Archivo seleccionable.
     * @return Verdadero si el archivo seleccionable se acepta, falso en caso
     * contrario.
     */
    @Override
    public boolean accept(File f) {
        if (f.isDirectory()) {
            return true;
        }

        String fileExtension = Filtro.getFileExtension(f);
        boolean aceptar = false;

        if (fileExtension != null) {
            switch (tipoFiltro) {
                case Filtro.ABRIR_TEXTO_PLANO:
                    aceptar = fileExtension.equals("txt");
                    break;
                case Filtro.GUARDAR:
                    aceptar = fileExtension.equals(extension);
            }
        }

        return aceptar;
    }

    /**
     * Devuelve la descripción del filtro.
     *
     * @return Descripción del filtro.
     */
    @Override
    public String getDescription() {
        String descripcion = null;

        switch (tipoFiltro) {
            case Filtro.ABRIR_TEXTO_PLANO:
                descripcion = "Archivo de texto plano (txt)";
                break;
            case Filtro.GUARDAR:
                descripcion = "Archivo " + extension.toUpperCase();
        }

        return descripcion;
    }
}
