package SiCoEn;

import java.io.UnsupportedEncodingException;

/**
 * Clase que gestiona los diferentes formatos en los que se puede mostrar el
 * texto.
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class Formato {

    /**
     * Código interno que representa la selección de formato ASCII.
     */
    public final static int FORMATO_ASCII = 10;
    /**
     * Código interno que representa la selección de formato binario.
     */
    public final static int FORMATO_BIN = 11;
    /**
     * Código interno que representa la selección de formato hexadecimal.
     */
    public final static int FORMATO_HEX = 12;

    /**
     * Método que convierte un texto recibido en formato ASCII a formato
     * hexadecimal.
     *
     * @param texto Texto en formato ASCII que se va a convertir.
     * @return Texto convertido en formato hexadecimal.
     */
    public static String ascii_to_hex(String texto) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < texto.length(); i++) {
            sb.append(Integer.toHexString(texto.charAt(i)));

            if (i != texto.length() - 1) {
                sb.append(" ");
            }
        }

        return sb.toString();
    }

    /**
     * Método que convierte un texto recibido en formato ASCII a formato
     * binario.
     *
     * @param texto Texto en formato ASCII que se va a convertir.
     * @return Texto convertido en formato binario.
     */
    public static String ascii_to_bin(String texto) {
        StringBuilder sb = new StringBuilder();
        String textoBinario = null;

        try {
            byte[] bytes = texto.getBytes("UTF-8");

            for (byte b : bytes) {

                for (int i = 0; i < 8; i++) {
                    sb.append((b & 128) == 0 ? 0 : 1);
                    b <<= 1;
                }

                sb.append(' ');
            }

            textoBinario = (sb.substring(0, sb.length() - 1)).toString();
        } catch (UnsupportedEncodingException uee) {
            System.err.println("Error: codificación UTF-8 no soportada. " + uee.getMessage());
        }

        return textoBinario;
    }

    /**
     * Método que convierte un texto recibido en formato hexadecimal a formato
     * ASCII.
     *
     * @param texto Texto en formato hexadecimal que se va a convertir.
     * @return Texto convertido en formato ASCII.
     */
    public static String hex_to_ascii(String texto) {
        texto = texto.replaceAll("\\s+", "");

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < texto.length() - 1; i += 2) {

            String aux = texto.substring(i, (i + 2));
            int decimal = Integer.parseInt(aux, 16);

            sb.append((char) decimal);
        }

        return sb.toString();
    }

    /**
     * Método que convierte un texto recibido en formato binario a formato
     * ASCII.
     *
     * @param texto Texto en formato binario que se va a convertir.
     * @return Texto convertido en formato ASCII.
     */
    public static String bin_to_ascii(String texto) {
        texto = texto.replaceAll("\\s+", "");

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < texto.length() - 1; i += 8) {

            String aux = texto.substring(i, (i + 8));
            int decimal = Integer.parseInt(aux, 2);

            sb.append((char) decimal);
        }

        return sb.toString();
    }
}
