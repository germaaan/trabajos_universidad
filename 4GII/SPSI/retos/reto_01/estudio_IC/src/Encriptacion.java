package encriptacion;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 *
 * @author Jose Manuel Castillo Perez
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */
public class Encriptacion {

    public static void main(String[] args) {
        String buffer, texto = "";
        char caracter;
        ArrayList<Character> caracteres = new ArrayList();
        BufferedReader entrada;

        try {
            entrada = new BufferedReader(
                    new InputStreamReader(
                            new FileInputStream(args[0]), "UTF-8"));

            while ((buffer = entrada.readLine()) != null) {
                if (buffer != null) {

                    buffer = buffer.replace('Á', 'A');
                    buffer = buffer.replace('É', 'E');
                    buffer = buffer.replace('Í', 'I');
                    buffer = buffer.replace('Ó', 'O');
                    buffer = buffer.replace('Ú', 'U');

                    texto += buffer.toLowerCase();
                }
            }

            for (int i = 0; i < texto.length(); i++) {
                caracter = texto.charAt(i);

                if (((caracter >= 'a') && (caracter <= 'z')) || (caracter == 'ñ')) {
                    caracteres.add(caracter);
                }
            }

            System.out.println(caracteres.toString());

            //Codificacion de la secuencia
            Vigenere vg = new Vigenere(caracteres, "quijotesñadfwryzmxcv");
            vg.codVigenere();
            System.out.println(vg.getCodificada());

            //Decodificacion de la secuencia
            Vigenere vg2 = new Vigenere(vg.getCodificada(), "quijotesñadfwryzmxcv");
            vg2.decodVigenere();
            System.out.println(vg2.getDecodificada());

            //Numero de veces que aparece cada caracter en la secuencia codificada
            Frecuencia f = new Frecuencia(vg.getCodificada());
            f.calcularFrecuencia();
            System.out.println(f.getLetras());
            double[] frec = f.getAparece();
            for (int i = 0; i < frec.length; i++) {
                System.out.println(frec[i]);
            }

            double suma = 0.0;

            for (int i = 0; i < frec.length; i++) {
                suma += (frec[i] * frec[i]);
            }

            //suma -= 0.037;
            System.out.println("IC: " + suma);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
