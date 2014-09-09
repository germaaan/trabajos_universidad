package divide_cadena;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 *
 * @author Jose Manuel Castillo Perez
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static int NUMERO_DE_FUNCIONES = 12;
    static ArrayList<Funcion> funciones = new ArrayList<Funcion>();
    static char abecedario[] = new char[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
        'x', 'y', 'z'};

    static String textoCompleto = "GE JEASGDXV, ZIJ GL MW, LAAM, XZY ZMLWHFZEK EJLVDXW KWKE TX LBR ATGH LBMX AANU BAI VSMUKKSS PWNVLWK AGH GNUMK WDLNZWEG JNBXVV OAEG ENWB ZWMGY MO MLW WNBX MW AL PNFDCFPKH WZKEX HSSF XKIYAHUL. MK NUM YEXDM WBXY SBC HV WYX PHWKGNAMCUK ?.";
    static String texto = "GEJEASGDXVZIJGLMWLAAMXZYZMLWHFZEKEJLVDXWKWKETXLBRATGHLBMXAANUBAIVSMUKKSSPWNVLWKAGHGNUMKWDLNZWEGJNBXVVOAEGENWBZWMGYMOMLWWNBXMWALPNFDCFPKHWZKEXHSSFXKIYAHULMKNUMYEXDMWBXYSBCHVWYXPHWKGNAMCUK";
    static String textoDesencriptado = "";
    static int distanciasIguales[] = new int[10];

    static public void separaLetras() {
        int contador = 0;
        
        for (int i = 0; i < texto.length(); i++) {
            if (contador == NUMERO_DE_FUNCIONES) {
                contador = 0;
            }
            
            funciones.get(contador).funcion = funciones.get(contador).funcion + texto.substring(i, i + 1);
            contador++;
        }
    }

    static public void calculaFrecuencias(Funcion f) {

        f.frec = new int[f.funcion.length()];
        f.frec[0] = 1;
        f.alfabeto = f.funcion.substring(0, 1);
        
        for (int i = 1; i < f.funcion.length(); i++) {
            for (int j = 0; j < f.alfabeto.length(); j++) {
                if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(j, j + 1)) == 0) {
                    f.frec[j]++;
                    j = f.alfabeto.length();
                    f.contada = true;
                }
            }
            
            if (!f.contada) {
                f.alfabeto = f.alfabeto + f.funcion.substring(i, i + 1);
                f.frec[f.pos] = 1;
                f.pos++;
            } else {
                f.contada = false;
            }
        }
    }

    public static void ordenaAlfabetoPorFrecuencias(Funcion f) {
        String cadenaAux = f.alfabeto;
        int frecuenciaAux;
        
        for (int i = 0; i < f.alfabeto.length(); i++) {
            for (int j = 0; j < f.alfabeto.length() - 1; j++) {
                if (f.frec[j] < f.frec[j + 1]) {
                    frecuenciaAux = f.frec[j];
                    f.frec[j] = f.frec[j + 1];
                    f.frec[j + 1] = frecuenciaAux;
                    cadenaAux = cadenaAux.substring(0, j) + cadenaAux.substring(j + 1, j + 2) + cadenaAux.substring(j, j + 1) + cadenaAux.substring(j + 2, cadenaAux.length());
                }
            }
        }
        
        f.alfabeto = cadenaAux;
    }

    public static void mostrarFrecuencias(Funcion f) {
        for (int i = 0; i < f.alfabeto.length(); i++) {
            System.out.print(f.alfabeto.substring(i, i + 1) + " = ");
            System.out.println(f.frec[i]);
        }
        System.out.println("----");
    }

    public static void desencripta(Funcion f, String primera, String segunda, String tercera, String cuarta, String quinta, String sexta) {
        for (int i = 0; i < f.funcion.length(); i++) {
            if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(1, 2)) == 0) {
                f.desencriptada = f.desencriptada + primera;
            } else if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(2, 3)) == 0) {
                f.desencriptada = f.desencriptada + segunda;
            } else if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(3, 4)) == 0) {
                f.desencriptada = f.desencriptada + tercera;
            } else if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(4, 5)) == 0) {
                f.desencriptada = f.desencriptada + cuarta;
            } else if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(5, 6)) == 0) {
                f.desencriptada = f.desencriptada + quinta;
            } else if (f.funcion.substring(i, i + 1).compareTo(f.alfabeto.substring(6, 7)) == 0) {
                f.desencriptada = f.desencriptada + sexta;
            } else {
                f.desencriptada = f.desencriptada + f.funcion.substring(i, i + 1);
            }
        }

    }

    public static void uneDesencriptados() {
        for (int i = 0; i < funciones.get(0).funcion.length(); i++) {
            for (int j = 0; j < NUMERO_DE_FUNCIONES; j++) {

                if (funciones.get(j).funcion.length() > i) {

                    textoDesencriptado = textoDesencriptado + funciones.get(j).desencriptada.substring(i, i + 1);
                }
            }
        }
        textoDesencriptado = textoDesencriptado + ".";
    }

    public static void inicializaArrayList() {
        for (int i = 0; i < NUMERO_DE_FUNCIONES; i++) {
            funciones.add(new Funcion());
        }
    }

    public static void introduceEspacios() {
        String aux = "";
        int cont = 0;
        
        for (int i = 0; i < textoCompleto.length(); i++) {
            if ((textoCompleto.substring(i, i + 1).compareTo(" ") == 0)
                    || (textoCompleto.substring(i, i + 1).compareTo(",") == 0)
                    || (textoCompleto.substring(i, i + 1).compareTo(".") == 0)
                    || (textoCompleto.substring(i, i + 1).compareTo("?") == 0)) {
                aux = aux + textoCompleto.substring(i, i + 1);
            } else {
                if (cont < textoDesencriptado.length() - 1) {
                    aux = aux + textoDesencriptado.substring(cont, cont + 1);
                    cont++;
                }
            }
        }
        
        textoDesencriptado = aux;
    }

    public static void buscaFrecuencias() {
        String aux;
        int pos = 0;
        for (int i = 0; i < texto.length(); i++) {
            aux = texto.substring(i, i + 3);
            for (int j = 1; j < texto.length(); j++) {
                if (aux.compareTo(texto.substring(j, j + 3)) == 0) {
                    if (i != j) {
                        distanciasIguales[pos] = j - i;
                        System.out.println(aux + " " + texto.substring(j, j + 3) + " = " + distanciasIguales[pos]);
                        pos++;
                    }
                }
            }
        }
    }

    public static void guardarEnfichero() {
        FileWriter fichero = null;
        PrintWriter pw = null;

        try {
            fichero = new FileWriter("/Users/pablosanchezrobles/Desktop/universidad/ESPECIALIDAD/seguridad y protección de sistemas informáticos/teoria/trabajos/carta a poe/salida.txt");
            pw = new PrintWriter(fichero);
            pw.println(textoDesencriptado);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (null != fichero) {
                    fichero.close();
                }
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }

    public static void prueba(Funcion f, int distancia) {
        int trans = 0;
        String car;
        f.desencriptada = "";
        for (int i = 0; i < f.funcion.length(); i++) {
            for (int j = 0; j < abecedario.length; j++) {
                car = "" + abecedario[j];
                car = car.toUpperCase();

                if (f.funcion.substring(i, i + 1).compareTo(car) == 0) {
                    trans = (j + distancia) % 26;
                    if (trans < 0) {
                        trans = trans + 26;
                    }
                    System.out.println(trans);
                    f.desencriptada = f.desencriptada + abecedario[trans];
                }
            }

        }

    }

    public static void main(String[] args) {
        inicializaArrayList();
        separaLetras();

        for (int i = 0; i < NUMERO_DE_FUNCIONES; i++) {
            calculaFrecuencias(funciones.get(i));
            ordenaAlfabetoPorFrecuencias(funciones.get(i));
            // mostrarFrecuencias(funciones.get(i));
            // desencripta(funciones.get(i),"t","a","e","o","i","n");
            funciones.get(i).desencriptada = funciones.get(i).funcion;
        }
        
        prueba(funciones.get(0), 13);
        prueba(funciones.get(1), 18);
        prueba(funciones.get(2), 7);
        prueba(funciones.get(3), 22);
        prueba(funciones.get(4), 23);
        prueba(funciones.get(5), 8);
        prueba(funciones.get(6), 7);
        prueba(funciones.get(7), 0);
        prueba(funciones.get(8), 7);
        prueba(funciones.get(9), 22);
        prueba(funciones.get(10), 8);
        prueba(funciones.get(11), 6);
        
        /*desencripta(funciones.get(0),"e","t","a","o","i","n");
         desencripta(funciones.get(4),"e","t","a","o","i","n");
         desencripta(funciones.get(5),"e","t","a","o","i","n");
         desencripta(funciones.get(6),"e","t","a","o","i","n");
         desencripta(funciones.get(7),"e","t","a","o","i","n");
         desencripta(funciones.get(8),"e","t","a","o","i","n");
         desencripta(funciones.get(9),"e","t","a","o","i","n");
         desencripta(funciones.get(10),"e","t","a","o","i","n");
         desencripta(funciones.get(11),"e","t","a","o","i","n");*/

        uneDesencriptados();
        introduceEspacios();
        guardarEnfichero();

        System.out.println(textoDesencriptado);
    }
}
