package utilidad;

import java.io.File;
import javax.swing.filechooser.FileFilter;

/**
 * Filtro de archivos.
 * @author German Martinez Maldonado
 */
public class Filtro extends FileFilter {

    /**
     * Filtro de selección de archivos de audio.
     */
    public final static int ABRIR_AUDIO = 1;
    /**
     * Filtro de selección de archivos de imagen.
     */
    public final static int ABRIR_IMAGEN = 2;
    /**
     * Filtro de selección de archivo de video.
     */
    public final static int ABRIR_VIDEO = 3;
    /**
     * Filtro de guardado de archivos.
     */
    public final static int GUARDAR = 4;
    private int tipoFiltro;
    private String extension;

    /**
     * Constructor del filtro.
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
     * @return Tipo de filtro seleccionado.
     */
    public int getTipoFiltro() {
        return tipoFiltro;
    }

    /**
     * Devuelve la extensión del tipo de filtro seleccionado.
     * @return Extensión del tipo de filtro seleccionado.
     */
    public String getExtension() {
        return extension;
    }

    /**
     * Aceptar un archivo como seleccionable.
     * @param f Archivo seleccionable.
     * @return Verdadero si el archivo seleccionable se acepta, falso en caso contrario.
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
                case Filtro.ABRIR_AUDIO:
                    if (fileExtension.equals("aif") || fileExtension.equals("mp3") || fileExtension.equals("wav")) {
                        aceptar = true;
                    } else {
                        aceptar = false;
                    }
                    break;
                case Filtro.ABRIR_IMAGEN:
                    if (fileExtension.equals("bmp") || fileExtension.equals("gif") || fileExtension.equals("png")
                            || fileExtension.equals("jpg") || fileExtension.equals("jpeg")) {
                        aceptar = true;
                    } else {
                        aceptar = false;
                    }
                    break;
                case Filtro.ABRIR_VIDEO:
                    if (fileExtension.equals("avi") || fileExtension.equals("mpg") || fileExtension.equals("mov")) {
                        aceptar = true;
                    } else {
                        aceptar = false;
                    }
                    break;
                case Filtro.GUARDAR:
                    if (fileExtension.equals(extension)) {
                        aceptar = true;
                    } else {
                        aceptar = false;
                    }
            }
        }

        return aceptar;
    }

    /**
     * Devuelve la descripción del filtro.
     * @return Descripción del filtro.
     */
    @Override
    public String getDescription() {
        String descripcion = null;

        switch (tipoFiltro) {
            case Filtro.ABRIR_AUDIO:
                descripcion = "Archivos de audio (aif, mp3, wav)";
                break;
            case Filtro.ABRIR_IMAGEN:
                descripcion = "Archivos de imagen (bmp, gif, png, jpeg)";
                break;
            case Filtro.ABRIR_VIDEO:
                descripcion = "Archivos de video (avi, mpg, mov)";
                break;
            case Filtro.GUARDAR:
                descripcion = "Archivo " + extension.toUpperCase();
        }

        return descripcion;
    }
}
