package SiCoEn;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;

/**
 * Encriptador usado para las operaciones de cifrado y descifrado
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class Encriptador {

    /**
     * Código interno que representa el algoritmo AES.
     */
    public final static int ALGORITMO_AES = 20;
    /**
     * Código interno que representa el algoritmo Blowfish.
     */
    public final static int ALGORITMO_BLOW = 21;
    /**
     * Código interno que representa el algoritmo DES.
     */
    public final static int ALGORITMO_DES = 22;
    /**
     * Código interno que representa el algoritmo TripleDES.
     */
    public final static int ALGORITMO_TDES = 23;
    /**
     * Código interno que representa el modo CBC.
     */
    public final static int MODO_CBC = 30;
    /**
     * Código interno que representa el modo CFB.
     */
    public final static int MODO_CFB = 31;
    /**
     * Código interno que representa el modo ECB.
     */
    public final static int MODO_ECB = 32;
    /**
     * Código interno que representa el modo OFB.
     */
    public final static int MODO_OFB = 33;
    /**
     * Código interno que representa el padding PKC5
     */
    public final static int PADDING_PKCS = 40;
    /**
     * Código interno que representa el padding ISO 10126
     */
    public final static int PADDING_ISO = 41;
    /**
     * Código interno que representa el modo cifrador
     */
    public final static int CIFRADOR = 100;
    /**
     * Código interno que representa el modo descifrador
     */
    public final static int DESCIFRADOR = 101;

    private int algoritmo;
    private int modo;
    private int padding;

    private KeyGenerator generadorClave_aes;
    private KeyGenerator generadorClave_blow;
    private KeyGenerator generadoClave_des;
    private KeyGenerator generadorClave_tdes;

    private SecretKey clave_aes;
    private SecretKey clave_blow;
    private SecretKey clave_des;
    private SecretKey clave_tdes;

    private IvParameterSpec iv8;
    private IvParameterSpec iv16;

    /**
     * Constructor del encriptador.
     */
    public Encriptador() {
        try {
            this.algoritmo = Encriptador.ALGORITMO_AES;
            this.modo = Encriptador.MODO_CBC;
            this.padding = Encriptador.PADDING_PKCS;

            // Generar claves
            generadorClave_aes = KeyGenerator.getInstance("AES");
            generadorClave_aes.init(128);
            generadorClave_blow = KeyGenerator.getInstance("Blowfish");
            generadorClave_blow.init(128);
            generadoClave_des = KeyGenerator.getInstance("DES");
            generadoClave_des.init(56);
            generadorClave_tdes = KeyGenerator.getInstance("TripleDES");
            generadorClave_tdes.init(168);

            clave_aes = generadorClave_aes.generateKey();
            clave_blow = generadorClave_blow.generateKey();
            clave_des = generadoClave_des.generateKey();
            clave_tdes = generadorClave_tdes.generateKey();

            iv8 = new IvParameterSpec(new byte[8]);
            iv16 = new IvParameterSpec(new byte[16]);
        } catch (NoSuchAlgorithmException nsae) {
            System.err.println("Error: Alguno de los algoritmos de encriptación (AES, Blowfish, DES o Triple DES) no"
                    + " están disponible en el sistema. " + nsae.getMessage());
        }
    }

    /**
     * Método que devuelve el código interno del algoritmo actual del
     * encriptador.
     *
     * @return Algoritmo actual del encriptador (AES/Blowfis/DES/TripleDES).
     */
    public int getAlgoritmo() {
        return this.algoritmo;
    }

    /**
     * Método que devuelve el código interno del modo actual del encriptador.
     *
     * @return Algoritmo actual del encriptador (CBC/CFB/ECB/OFB).
     */
    public int getModo() {
        return this.modo;
    }

    /**
     * Método que devuelve el código interno del padding actual del encriptador.
     *
     * @return Algoritmo actual del encriptador (PKCS5/ISO 10126).
     */
    public int getPadding() {
        return this.padding;
    }

    /**
     * Método para cambiar el algoritmo actual del encriptador mediante su
     * código interno.
     *
     * @param algoritmo Algoritmo al que cambiar (AES/Blowfis/DES/TripleDES).
     */
    public void setAlgoritmo(int algoritmo) {
        this.algoritmo = algoritmo;
    }

    /**
     * Método para cambiar el modo actual del encriptador mediante su código
     * interno.
     *
     * @param modo Modo al que cambiar (CBC/CFB/ECB/OFB).
     */
    public void setModo(int modo) {
        this.modo = modo;
    }

    /**
     * Método para cambiar el padding actual del encriptador mediante su código
     * interno.
     *
     * @param padding Padding al que cambiar (PKCS5/ISO 10126).
     */
    public void setPadding(int padding) {
        this.padding = padding;
    }

    /**
     * Método que devuelve una cadena de texto con el algoritmo seleccionado
     * para el encriptador.
     *
     * @return Cadena de texto con el algoritmo actual.
     */
    public String cadenaAlgoritmo() {
        String valor = null;

        switch (this.getAlgoritmo()) {
            case Encriptador.ALGORITMO_AES:
                valor = "AES";
                break;
            case Encriptador.ALGORITMO_BLOW:
                valor = "Blowfish";
                break;
            case Encriptador.ALGORITMO_DES:
                valor = "DES";
                break;
            case Encriptador.ALGORITMO_TDES:
                valor = "TripleDES";
                break;
        }

        return valor;
    }

    /**
     * Método que devuelve una cadena de texto con el modo seleccionado para el
     * encriptador.
     *
     * @return Cadena de texto con el modo actual.
     */
    public String cadenaModo() {
        String valor = null;

        switch (this.modo) {
            case Encriptador.MODO_CBC:
                valor = "CBC";
                break;
            case Encriptador.MODO_CFB:
                valor = "CFB";
                break;
            case Encriptador.MODO_ECB:
                valor = "ECB";
                break;
            case Encriptador.MODO_OFB:
                valor = "OFB";
                break;
        }

        return valor;
    }

    /**
     * Método que devuelve una cadena de texto con el padding seleccionado para
     * el encriptador.
     *
     * @return Cadena de texto con el padding actual.
     */
    public String cadenaPadding() {
        String valor = null;

        switch (this.padding) {
            case Encriptador.PADDING_PKCS:
                valor = "PKCS5Padding";
                break;
            case Encriptador.PADDING_ISO:
                valor = "ISO10126Padding";
                break;
        }

        return valor;
    }

    /**
     * Método que genera el cifrador con el que se realizarán las operaciones de
     * cifrado y descifrado de texto.
     *
     * @param func Código que indica si se va a generar un encriptador para
     * cifrar texto o para descifrarlo.
     * @return Encriptador que cifrará o descifrará texto.
     */
    public Cipher generarCifrador(int func) {
        Cipher cifrador = null;
        SecretKey clave = null;
        IvParameterSpec iv = null;
        String valorAlgoritmo = this.cadenaAlgoritmo();
        String valorModo = this.cadenaModo();
        String valorPadding = this.cadenaPadding();

        try {
            switch (this.algoritmo) {
                case Encriptador.ALGORITMO_AES:
                    clave = this.clave_aes;
                    iv = this.iv16;
                    break;
                case Encriptador.ALGORITMO_BLOW:
                    clave = this.clave_blow;
                    iv = this.iv8;
                    break;
                case Encriptador.ALGORITMO_DES:
                    clave = this.clave_des;
                    iv = this.iv8;
                    break;
                case Encriptador.ALGORITMO_TDES:
                    clave = this.clave_tdes;
                    iv = this.iv8;
                    break;
            }

            if (valorAlgoritmo != null && valorModo != null && valorPadding != null && clave != null && iv != null) {
                cifrador = Cipher.getInstance(valorAlgoritmo + "/" + valorModo + "/" + valorPadding);

                if (this.modo != Encriptador.MODO_ECB) {
                    if (func == Encriptador.CIFRADOR) {
                        cifrador.init(Cipher.ENCRYPT_MODE, clave, iv);
                    } else if (func == Encriptador.DESCIFRADOR) {
                        cifrador.init(Cipher.DECRYPT_MODE, clave, iv);
                    }
                } else {
                    if (func == Encriptador.CIFRADOR) {
                        cifrador.init(Cipher.ENCRYPT_MODE, clave);
                    } else if (func == Encriptador.DESCIFRADOR) {
                        cifrador.init(Cipher.DECRYPT_MODE, clave);
                    }
                }
            }
        } catch (NoSuchAlgorithmException nsae) {
            System.err.println("Error: Alguno de los algoritmos de encriptación (AES, Blowfish, DES o Triple DES) no"
                    + " están disponible en el sistema. " + nsae.getMessage());
        } catch (NoSuchPaddingException nspe) {
            System.err.println("Error: Alguno de los mecanismos de padding (PKCS5 o ISO 10126) no están disponibles en"
                    + " el sistema. " + nspe.getMessage());
        } catch (InvalidKeyException ike) {
            System.err.println("Error: Llave inválida (codificación no válida, longitud incorrecta, no inicializada, etc). "
                    + ike.getMessage());
        } catch (InvalidAlgorithmParameterException iape) {
            System.err.println("Error: Parámetro del algoritmo inválido (Revisar IV). "
                    + iape.getMessage());
        }

        return cifrador;
    }

    /**
     * Método que cifrará el texto según los valores actuales del encriptador
     * generado.
     *
     * @param origen Archivo con el texto de la ventana actual que se usará
     * durante el cifrado.
     * @return Texto cifrado según los valores del encriptador.
     */
    public String cifrar(File origen) {
        String textoCifrado = null;

        String destino = origen.getAbsolutePath() + ".cfr";
        int i;
        byte[] block = new byte[8];

        // Generar cifrador
        Cipher cifrador = generarCifrador(Encriptador.CIFRADOR);

        if (cifrador != null) {
            // Cifrar
            try {
                FileInputStream fis = new FileInputStream(origen);
                FileOutputStream fos = new FileOutputStream(destino);

                try (CipherOutputStream cos = new CipherOutputStream(fos, cifrador)) {
                    while ((i = fis.read(block)) != -1) {
                        cos.write(block, 0, i);
                    }
                }

                textoCifrado = new String(Files.readAllBytes(FileSystems.getDefault().getPath(destino)));
            } catch (FileNotFoundException fnfe) {
                System.err.println("Error: Alguno de los archivos de entrada o salida de las operaciones"
                        + " no ha sido encontrador. " + fnfe.getMessage());
            } catch (IOException ioe) {
                System.err.println("Error: Se ha producido un problema de entrada/salida con alguno de"
                        + "los archivos. " + ioe.getMessage());
            }
        }

        return textoCifrado;
    }

    /**
     * Método que descifrará el texto según los valores actuales del encriptador
     * generado.
     *
     * @param origen Archivo con el texto de la ventana actual cifrado que se
     * usará durante el descifrado.
     * @return Texto descifrado según los valores del encriptador.
     */
    public String descifrar(File origen) {
        String textoDescifrado = null;

        int i;
        byte[] block = new byte[8];

        // Generar descifrador
        Cipher descifrador = generarCifrador(Encriptador.DESCIFRADOR);

        if (descifrador != null) {
            // Descifrar
            try {
                FileInputStream fis = new FileInputStream(origen);
                CipherInputStream cis = new CipherInputStream(fis, descifrador);
                ByteArrayOutputStream baos = new ByteArrayOutputStream();

                while ((i = cis.read(block)) != -1) {
                    baos.write(block, 0, i);
                }

                baos.close();

                textoDescifrado = new String(baos.toByteArray());
            } catch (FileNotFoundException fnfe) {
                System.err.println("Error: Alguno de los archivos de entrada o salida de las operaciones"
                        + " no ha sido encontrador. " + fnfe.getMessage());
            } catch (IOException ioe) {
                System.err.println("Error: Se ha producido un problema de entrada/salida con alguno de"
                        + "los archivos. " + ioe.getMessage());
            }
        }

        return textoDescifrado;
    }

    /**
     * Método que devuelve el número de bloques que tiene un texto.
     * 
     * @param texto Texto del que se quieren conocer el número de bloques.
     * @return Número de bloques del texto.
     */
    public int numeroBloques(String texto) {
        StringBuilder sb = new StringBuilder();
        int aux = 0;

        byte[] bytes = texto.getBytes();

        for (byte b : bytes) {

            for (int i = 0; i < 8; i++) {
                sb.append((b & 128) == 0 ? 0 : 1);
                b <<= 1;
            }

            aux++;
        }

        return aux;
    }
}
