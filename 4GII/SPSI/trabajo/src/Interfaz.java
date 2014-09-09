package SiCoEn;

import java.awt.event.ItemEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.StringReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 * Ventana principal de la interfaz de la aplicación.
 *
 * @author German Martinez Maldonado
 * @author Jose Manuel Castillo Perez
 * @version 0.9
 */
public class Interfaz extends javax.swing.JFrame {

    private Encriptador encriptador;

    /**
     * Constructor de la ventana principal de la interfaz de la aplicación.
     *
     */
    public Interfaz() {
        initComponents();

        encriptador = new Encriptador();
    }

    /**
     * Método de inialización del componentes gráficos.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        grupoAlgoritmo = new javax.swing.ButtonGroup();
        grupoModo = new javax.swing.ButtonGroup();
        grupoPadding = new javax.swing.ButtonGroup();
        panelEscritorio = new javax.swing.JDesktopPane();
        barraMenus = new javax.swing.JMenuBar();
        menuArchivo = new javax.swing.JMenu();
        opcionNuevo = new javax.swing.JMenuItem();
        opcionAbrir = new javax.swing.JMenuItem();
        opcionGuardar = new javax.swing.JMenuItem();
        separador1 = new javax.swing.JPopupMenu.Separator();
        opcionSalir = new javax.swing.JMenuItem();
        menuFormato = new javax.swing.JMenu();
        opcion_formato_ascii = new javax.swing.JMenuItem();
        opcion_formato_bin = new javax.swing.JMenuItem();
        opcion_formato_hex = new javax.swing.JMenuItem();
        menuAlgoritmo = new javax.swing.JMenu();
        algoritmo_aes = new javax.swing.JRadioButtonMenuItem();
        algoritmo_blow = new javax.swing.JRadioButtonMenuItem();
        algoritmo_des = new javax.swing.JRadioButtonMenuItem();
        algoritmo_tdes = new javax.swing.JRadioButtonMenuItem();
        menuModo = new javax.swing.JMenu();
        modo_cbc = new javax.swing.JRadioButtonMenuItem();
        modo_cfb = new javax.swing.JRadioButtonMenuItem();
        modo_ecb = new javax.swing.JRadioButtonMenuItem();
        modo_ofb = new javax.swing.JRadioButtonMenuItem();
        menuPadding = new javax.swing.JMenu();
        padding_pkcs = new javax.swing.JRadioButtonMenuItem();
        padding_iso = new javax.swing.JRadioButtonMenuItem();
        menuEncriptacion = new javax.swing.JMenu();
        opcionCifrar = new javax.swing.JMenuItem();
        opcionDescifrar = new javax.swing.JMenuItem();
        menuErrores = new javax.swing.JMenu();
        opcion_error_cifrado = new javax.swing.JMenuItem();
        menu_error_comunicacion = new javax.swing.JMenu();
        opcion_error_com_1 = new javax.swing.JMenuItem();
        opcion_error_sincronizacion = new javax.swing.JMenuItem();
        menuAyuda = new javax.swing.JMenu();
        opcionAcerca = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("SiCoEn 1.0");
        setMinimumSize(new java.awt.Dimension(800, 600));

        panelEscritorio.setMaximumSize(null);
        panelEscritorio.setMinimumSize(new java.awt.Dimension(800, 600));

        javax.swing.GroupLayout panelEscritorioLayout = new javax.swing.GroupLayout(panelEscritorio);
        panelEscritorio.setLayout(panelEscritorioLayout);
        panelEscritorioLayout.setHorizontalGroup(
            panelEscritorioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 800, Short.MAX_VALUE)
        );
        panelEscritorioLayout.setVerticalGroup(
            panelEscritorioLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 600, Short.MAX_VALUE)
        );

        getContentPane().add(panelEscritorio, java.awt.BorderLayout.CENTER);

        menuArchivo.setText("Archivo");

        opcionNuevo.setText("Nuevo");
        opcionNuevo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accionNuevo(evt);
            }
        });
        menuArchivo.add(opcionNuevo);

        opcionAbrir.setText("Abrir");
        opcionAbrir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accionAbrir(evt);
            }
        });
        menuArchivo.add(opcionAbrir);

        opcionGuardar.setText("Guardar");
        opcionGuardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accionGuardar(evt);
            }
        });
        menuArchivo.add(opcionGuardar);
        menuArchivo.add(separador1);

        opcionSalir.setText("Salir");
        opcionSalir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accionSalir(evt);
            }
        });
        menuArchivo.add(opcionSalir);

        barraMenus.add(menuArchivo);

        menuFormato.setText("Formato");

        opcion_formato_ascii.setText("ASCII");
        opcion_formato_ascii.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accion_formato_ascii(evt);
            }
        });
        menuFormato.add(opcion_formato_ascii);

        opcion_formato_bin.setText("Binario");
        opcion_formato_bin.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accion_formato_bin(evt);
            }
        });
        menuFormato.add(opcion_formato_bin);

        opcion_formato_hex.setText("Hexadecimal");
        opcion_formato_hex.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accion_formato_hex(evt);
            }
        });
        menuFormato.add(opcion_formato_hex);

        barraMenus.add(menuFormato);

        menuAlgoritmo.setText("Algoritmo");

        grupoAlgoritmo.add(algoritmo_aes);
        algoritmo_aes.setSelected(true);
        algoritmo_aes.setText("AES");
        algoritmo_aes.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_algoritmo_aes(evt);
            }
        });
        menuAlgoritmo.add(algoritmo_aes);

        grupoAlgoritmo.add(algoritmo_blow);
        algoritmo_blow.setText("Blowfish");
        algoritmo_blow.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_algoritmo_blow(evt);
            }
        });
        menuAlgoritmo.add(algoritmo_blow);

        grupoAlgoritmo.add(algoritmo_des);
        algoritmo_des.setText("DES");
        algoritmo_des.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_algoritmo_des(evt);
            }
        });
        menuAlgoritmo.add(algoritmo_des);

        grupoAlgoritmo.add(algoritmo_tdes);
        algoritmo_tdes.setText("TripleDES");
        algoritmo_tdes.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_algoritmo_tdes(evt);
            }
        });
        menuAlgoritmo.add(algoritmo_tdes);

        barraMenus.add(menuAlgoritmo);

        menuModo.setText("Modo");

        grupoModo.add(modo_cbc);
        modo_cbc.setSelected(true);
        modo_cbc.setText("CBC");
        modo_cbc.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_modo_cbc(evt);
            }
        });
        menuModo.add(modo_cbc);

        grupoModo.add(modo_cfb);
        modo_cfb.setText("CFB");
        modo_cfb.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_modo_cfb(evt);
            }
        });
        menuModo.add(modo_cfb);

        grupoModo.add(modo_ecb);
        modo_ecb.setText("ECB");
        modo_ecb.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_modo_ecb(evt);
            }
        });
        menuModo.add(modo_ecb);

        grupoModo.add(modo_ofb);
        modo_ofb.setText("OFB");
        modo_ofb.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_modo_ofb(evt);
            }
        });
        menuModo.add(modo_ofb);

        barraMenus.add(menuModo);

        menuPadding.setText("Padding");

        grupoPadding.add(padding_pkcs);
        padding_pkcs.setSelected(true);
        padding_pkcs.setText("PKCS5");
        padding_pkcs.setToolTipText("El bloque será completado introduciendo bytes con valor del número de bytes de relleno al final hasta ser completado.");
        padding_pkcs.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_padding_pkcs(evt);
            }
        });
        menuPadding.add(padding_pkcs);

        grupoPadding.add(padding_iso);
        padding_iso.setText("ISO 10126");
        padding_iso.setToolTipText("El bloque será completado introduciendo bytes aleatorios al final hasta ser completado.");
        padding_iso.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                marca_padding_iso(evt);
            }
        });
        menuPadding.add(padding_iso);

        barraMenus.add(menuPadding);

        menuEncriptacion.setText("Encriptacion");

        opcionCifrar.setText("Cifrar");
        opcionCifrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcionCifrar(evt);
            }
        });
        menuEncriptacion.add(opcionCifrar);

        opcionDescifrar.setText("Descifrar");
        opcionDescifrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcionDescifrar(evt);
            }
        });
        menuEncriptacion.add(opcionDescifrar);

        barraMenus.add(menuEncriptacion);

        menuErrores.setText("Errores");

        opcion_error_cifrado.setText("Error en el texto plano");
        opcion_error_cifrado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcion_error_cifrado(evt);
            }
        });
        menuErrores.add(opcion_error_cifrado);

        menu_error_comunicacion.setText("Error en la comunicación");

        opcion_error_com_1.setText("Error de 1 bit");
        opcion_error_com_1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accion_error_com_1(evt);
            }
        });
        menu_error_comunicacion.add(opcion_error_com_1);

        menuErrores.add(menu_error_comunicacion);

        opcion_error_sincronizacion.setText("Error en la sincronización");
        opcion_error_sincronizacion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcion_error_sincronizacion(evt);
            }
        });
        menuErrores.add(opcion_error_sincronizacion);

        barraMenus.add(menuErrores);

        menuAyuda.setText("Ayuda");

        opcionAcerca.setText("Acerca de");
        opcionAcerca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                accionAcerca(evt);
            }
        });
        menuAyuda.add(opcionAcerca);

        barraMenus.add(menuAyuda);

        setJMenuBar(barraMenus);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Método que gestiona la opción de cifrar texto. Cifrará el texto de la
     * ventana actual según las opciones seleccionadas.
     *
     * @param evt Evento disparador de la acción (seleccionar opción
     * "Encriptación -> Cifrar")
     */
    private void opcionCifrar(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcionCifrar
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() == Formato.FORMATO_ASCII) {
                File origen = ventanaActual.getArchivo();

                if (origen != null) {
                    String texto = ventanaActual.getTexto();
                    String textoCifrado = encriptador.cifrar(origen);
                    String destino = origen.getAbsolutePath() + ".cfr";

                    if (textoCifrado != null) {
                        Texto vt = new Texto(textoCifrado);
                        vt.setTitle("\"" + ventanaActual.getTitle() + "\"" + " cifrado con " + encriptador.cadenaAlgoritmo());
                        vt.setArchivo(new File(destino));
                        panelEscritorio.add(vt);
                        vt.setVisible(true);
                    } else {
                        JOptionPane.showMessageDialog(this, "No se ha podido cifrar el texto. Consulte error en consola.");
                    }
                } else {
                    JOptionPane.showMessageDialog(this, "Debe guardar el archivo antes de codificarlo.");
                }
            } else {
                JOptionPane.showMessageDialog(this, "Cambie a formato ASCII para realizar el cifrado.");
            }
        }
    }//GEN-LAST:event_opcionCifrar

    /**
     * Método que gestiona la opción de descifrar texto. Descifrará el texto de
     * la ventana actual según las opciones seleccionadas.
     *
     * @param evt Evento disparador de la acción (seleccionar opción
     * "Encriptación -> Descifrar")
     */
    private void opcionDescifrar(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcionDescifrar
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() == Formato.FORMATO_ASCII) {
                String texto = ventanaActual.getTexto();
                File origen = ventanaActual.getArchivo();
                String textoDescifrado = this.encriptador.descifrar(origen);

                if (textoDescifrado != null) {
                    Texto vt = new Texto(textoDescifrado);
                    vt.setTitle("\"" + ventanaActual.getTitle() + "\"" + " descifrado con " + encriptador.cadenaAlgoritmo());
                    panelEscritorio.add(vt);
                    vt.setVisible(true);
                } else {
                    JOptionPane.showMessageDialog(this, "No se ha podido descifrar el texto. Consulte error en consola.");
                }
            } else {
                JOptionPane.showMessageDialog(this, "Cambie a formato ASCII para realizar el descifrado.");
            }
        }
    }//GEN-LAST:event_opcionDescifrar

    /**
     * Método que gestiona la opción de abrir de archivos de texto. Muestra una
     * ventana con un explorador de archivos para seleccionar un archivo de
     * texto a abrir en una nueva ventana.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Archivo ->
     * Abrir")
     */
    private void accionAbrir(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accionAbrir
        JFileChooser jfc = new JFileChooser();

        Filtro filtroTXT = new Filtro(Filtro.ABRIR_TEXTO_PLANO, null);

        jfc.setAcceptAllFileFilterUsed(false);
        jfc.addChoosableFileFilter(filtroTXT);
        jfc.setFileFilter(filtroTXT);

        int resp = jfc.showOpenDialog(this);
        if (resp == JFileChooser.APPROVE_OPTION) {
            if (((Filtro) jfc.getFileFilter()).getTipoFiltro() == Filtro.ABRIR_TEXTO_PLANO) {
                try {
                    File seleccionado = jfc.getSelectedFile();
                    String texto;

                    try (BufferedReader entrada = new BufferedReader(new InputStreamReader(new FileInputStream(seleccionado),
                            "UTF-8"))) {
                        StringBuilder sb = new StringBuilder();
                        String aux;

                        while ((aux = entrada.readLine()) != null) {
                            sb.append(aux);
                            sb.append("\n");
                        }

                        texto = (sb.substring(0, sb.length() - 1)).toString();
                    }

                    Texto vt = new Texto(texto);
                    vt.setTitle(seleccionado.getName());
                    vt.setArchivo(seleccionado);
                    panelEscritorio.add(vt);
                    vt.setVisible(true);
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Error al abrir archivo");
                    System.err.println("Error: Error al abrir archivo. " + ex.getMessage());
                }
            }
        }
    }//GEN-LAST:event_accionAbrir

    /**
     * Método que gestiona la opción de guardar texto en un archivo. Muestra una
     * ventana con un explorar de archivos para seleccionar donde guardar un
     * archivo con el texto de la ventana actual.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Archivo ->
     * Guardar")
     */
    private void accionGuardar(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accionGuardar
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            JFileChooser jfc = new JFileChooser();

            Filtro filtroTXT = new Filtro(Filtro.GUARDAR, "txt");

            jfc.setAcceptAllFileFilterUsed(false);
            jfc.addChoosableFileFilter(filtroTXT);
            jfc.setFileFilter(filtroTXT);

            int resp = jfc.showSaveDialog(this);

            if (resp == JFileChooser.APPROVE_OPTION) {
                try {
                    File seleccionado = jfc.getSelectedFile();

                    String formatoArchivo = ((Filtro) jfc.getFileFilter()).getExtension();
                    String extension = Filtro.getFileExtension(seleccionado);

                    if (extension == null) {
                        File fich = new File(seleccionado.getAbsolutePath() + "." + formatoArchivo);
                        seleccionado = fich;
                    } else if (!extension.equals(formatoArchivo)) {
                        int tamRuta = seleccionado.getAbsolutePath().length() - extension.length();
                        String ruta = seleccionado.getAbsolutePath().substring(0, tamRuta) + formatoArchivo;
                        File fich = new File(ruta);
                        seleccionado = fich;
                    }

                    if (seleccionado.exists()) {
                        int sobre = JOptionPane.showConfirmDialog(this,
                                "¿Desea sobreescribir el archivo \"" + jfc.getSelectedFile().getName() + "\"?",
                                "Sobreescribir archivo", JOptionPane.YES_NO_OPTION);

                        if (sobre == JOptionPane.YES_OPTION) {
                            String texto = ventanaActual.getTexto();

                            if (texto != null) {
                                try (BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(
                                        new FileOutputStream(seleccionado), "UTF-8"))) {
                                    salida.write(texto);
                                }

                                ventanaActual.setTitle(seleccionado.getName());
                            } else {
                                JOptionPane.showMessageDialog(this, "Campo de texto vacío.");
                            }
                        }
                    } else {
                        String texto = ventanaActual.getTexto();

                        if (texto != null) {
                            try (BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(
                                    new FileOutputStream(seleccionado), "UTF-8"))) {
                                salida.write(texto);
                            }

                            ventanaActual.setTitle(seleccionado.getName());
                        } else {
                            JOptionPane.showMessageDialog(this, "Campo de texto vacío.");
                        }
                    }

                    ventanaActual.setArchivo(seleccionado);
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Error al guardar archivo.");
                    System.err.println("Error: Error al guardar archivo. " + ex.getMessage());
                }
            }
        }
    }//GEN-LAST:event_accionGuardar

    /**
     * Método que gestiona la opción de crear una nueva ventana de texto. Crea
     * una nueva ventana de texto en blanco.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Archivo ->
     * Nuevo")
     */
    private void accionNuevo(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accionNuevo
        Texto vt = new Texto("");
        vt.setTitle("Nuevo texto");
        panelEscritorio.add(vt);
        vt.setVisible(true);
    }//GEN-LAST:event_accionNuevo

    /**
     * Método que gestiona la opción de salir del programa. Cierra el programa.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Archivo ->
     * Salir")
     */
    private void accionSalir(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accionSalir
        System.exit(0);
    }//GEN-LAST:event_accionSalir

    /**
     * Método que gestiona la selección del algoritmo AES.
     *
     * @param evt Evento disparador de la acción (marcar "Algoritmo -> AES")
     */
    private void marca_algoritmo_aes(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_algoritmo_aes
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setAlgoritmo(Encriptador.ALGORITMO_AES);
        }
    }//GEN-LAST:event_marca_algoritmo_aes

    /**
     * Método que gestiona la selección del algoritmo Blowfish.
     *
     * @param evt Evento disparador de la acción (marcar "Algoritmo ->
     * Blowfish")
     */
    private void marca_algoritmo_blow(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_algoritmo_blow
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setAlgoritmo(Encriptador.ALGORITMO_BLOW);
        }
    }//GEN-LAST:event_marca_algoritmo_blow

    /**
     * Método que gestiona la selección del algoritmo DES.
     *
     * @param evt Evento disparador de la acción (marcar "Algoritmo -> DES")
     */
    private void marca_algoritmo_des(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_algoritmo_des
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setAlgoritmo(Encriptador.ALGORITMO_DES);
        }
    }//GEN-LAST:event_marca_algoritmo_des

    /**
     * Método que gestiona la selección del algoritmo TripleDES.
     *
     * @param evt Evento disparador de la acción (marcar "Algoritmo ->
     * TripleDES")
     */
    private void marca_algoritmo_tdes(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_algoritmo_tdes
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setAlgoritmo(Encriptador.ALGORITMO_TDES);
        }
    }//GEN-LAST:event_marca_algoritmo_tdes

    /**
     * Método que gestiona la selección del modo de cifrado CBC.
     *
     * @param evt Evento disparador de la acción (marcar "Modo -> CBC")
     */
    private void marca_modo_cbc(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_modo_cbc
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setModo(Encriptador.MODO_CBC);
        }
    }//GEN-LAST:event_marca_modo_cbc

    /**
     * Método que gestiona la selección del modo de cifrado CFB.
     *
     * @param evt Evento disparador de la acción (marcar "Modo -> CFB")
     */
    private void marca_modo_cfb(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_modo_cfb
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setModo(Encriptador.MODO_CFB);
        }
    }//GEN-LAST:event_marca_modo_cfb

    /**
     * Método que gestiona la selección del modo de cifrado ECB.
     *
     * @param evt Evento disparador de la acción (marcar "Modo -> ECB")
     */
    private void marca_modo_ecb(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_modo_ecb
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setModo(Encriptador.MODO_ECB);
        }
    }//GEN-LAST:event_marca_modo_ecb

    /**
     * Método que gestiona la selección del modo de cifrado OFB.
     *
     * @param evt Evento disparador de la acción (marcar "Modo -> OFB")
     */
    private void marca_modo_ofb(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_modo_ofb
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setModo(Encriptador.MODO_OFB);
        }
    }//GEN-LAST:event_marca_modo_ofb

    /**
     * Método que gestiona la selección del padding PKCS5.
     *
     * @param evt Evento disparador de la acción (marcar "Padding -> PKCS5")
     */
    private void marca_padding_pkcs(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_padding_pkcs
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setPadding(Encriptador.PADDING_PKCS);
        }
    }//GEN-LAST:event_marca_padding_pkcs

    /**
     * Método que gestiona la selección del padding ISO 10126.
     *
     * @param evt Evento disparador de la acción (marcar "Padding -> ISO 10126")
     */
    private void marca_padding_iso(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_marca_padding_iso
        if (evt.getStateChange() == ItemEvent.SELECTED) {
            encriptador.setPadding(Encriptador.PADDING_ISO);
        }
    }//GEN-LAST:event_marca_padding_iso

    /**
     * Método que gestiona la selección de la opción de error en el texto plano.
     * Crea una ventana en la que se muestra el error introducido y otra que
     * muestra el resultado de dicho error en la descodificación.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Erores ->
     * Error en el texto plano")
     */
    private void opcion_error_cifrado(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcion_error_cifrado
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() == Formato.FORMATO_ASCII) {
                File origen = ventanaActual.getArchivo();

                if (origen != null) {

                    String texto = ventanaActual.getTexto();
                    String textoError = null;
                    String textoCifError;
                    String textoDesError;
                    File trampa = new File(origen.getAbsolutePath() + ".err");
                    File destino = new File(origen.getAbsolutePath() + ".err.cfr");
                    PrintStream salida;
                    StringBuilder sb = new StringBuilder();
                    String resultado;

                    int numBloques = (encriptador.numeroBloques(texto)) - 1;
                    int valorNumBloque = 0;
                    int opcion;
                    boolean error = false;
                    boolean parada = false;
                    String numBloque;
                    JTextField campoNumBloque = new JTextField();

                    Object[] contenido = {"Introduzca los parámetros para el error en el texto plano: ", " ",
                        "Número de bloque " + "[0-" + numBloques + "]:", campoNumBloque};
                    Object acciones[] = {"Aceptar", "Cancelar"};

                    do {
                        do {
                            if (error == true) {
                                JOptionPane.showMessageDialog(null, "Error: Tiene que rellenar todos los campos"
                                        + " con valores válidos.");
                            }

                            opcion = JOptionPane.showOptionDialog(null, contenido, "Error en el texto plano",
                                    JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, acciones, contenido);

                            if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                                parada = true;
                                break;
                            }

                            numBloque = campoNumBloque.getText().toString();

                            if (numBloque.isEmpty()) {
                                error = true;
                            } else {
                                valorNumBloque = Integer.parseInt(numBloque);
                                error = (valorNumBloque < 0 || valorNumBloque > numBloques);
                            }

                            if (!error) {

                                try {
                                    byte[] bytes = texto.getBytes("UTF-8");
                                    bytes[valorNumBloque] = (byte) (bytes[valorNumBloque] ^ 1);

                                    textoError = new String(bytes);
                                } catch (UnsupportedEncodingException uee) {
                                    System.err.println("Error: codificación UTF-8 no soportada. " + uee.getMessage());
                                }

                                try {
                                    salida = new PrintStream(new FileOutputStream(trampa));
                                    salida.print(textoError);
                                    salida.close();
                                } catch (FileNotFoundException fnfe) {
                                    System.err.println("Error: el archivo en el que guardar el encriptado no existe. "
                                            + fnfe.getMessage());
                                }

                                textoCifError = encriptador.cifrar(trampa);
                                textoDesError = encriptador.descifrar(destino);

                                String cabecera = "Modo de cifrado: " + encriptador.cadenaModo()
                                        + "\nError introducido en el bloque: " + valorNumBloque
                                        + "\n\nBloque\tTexto plano\t\tTexto descifrado";

                                sb.append(cabecera);

                                for (int i = 0; i < texto.length(); i++) {
                                    String x = Character.toString(texto.charAt(i));
                                    String y = Character.toString(textoDesError.charAt(i));
                                    String x_bin = Formato.ascii_to_bin(x);
                                    String y_bin = Formato.ascii_to_bin(y);
                                    String entrada = "\n" + i + "\t" + x + "\t" + x_bin + "\t" + y_bin + "\t" + y;

                                    sb.append(entrada);
                                }

                                resultado = sb.toString();

                                Texto vt = new Texto(textoDesError);
                                vt.setTitle("Resultado del error en el texto plano. Modo " + encriptador.cadenaModo());
                                panelEscritorio.add(vt);
                                vt.setVisible(true);

                                Texto vtr = new Texto(resultado);
                                vtr.setTitle("Resultado detallado del error en el texto plano. Modo "
                                        + encriptador.cadenaModo());
                                panelEscritorio.add(vtr);
                                vtr.setVisible(true);

                                parada = true;
                            }
                        } while (error == true);
                    } while (parada == false);
                } else {
                    JOptionPane.showMessageDialog(this, "Debe guardar el archivo antes de introducir errores.");
                }
            } else {
                JOptionPane.showMessageDialog(this, "Cambie a formato ASCII para realizar el cifrado.");
            }
        }
    }//GEN-LAST:event_opcion_error_cifrado

    /**
     * Método que gestiona la selección de la opción de error en la
     * comunicación. Crea una ventana en la que se muestra el error introducido
     * y otra que muestra el resultado de dicho error en la descodificación.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Erores ->
     * Error en la comunicación -> Error de 1 bit")
     */
    private void accion_error_com_1(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accion_error_com_1
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() == Formato.FORMATO_ASCII) {
                if (encriptador.getAlgoritmo() != Encriptador.ALGORITMO_AES) {
                    File origen = ventanaActual.getArchivo();

                    if (origen != null) {

                        String texto = ventanaActual.getTexto();
                        String textoCif = encriptador.cifrar(origen);
                        String textoCifError = null;
                        String textoDesError;
                        File trampa = new File(origen.getAbsolutePath() + ".err.cfr");
                        PrintStream salida;
                        StringBuilder sb = new StringBuilder();
                        String resultado;

                        int numBloques = (encriptador.numeroBloques(textoCif)) - 1;
                        int valorNumBloque = 0;
                        int opcion;
                        boolean error = false;
                        boolean parada = false;
                        String numBloque;
                        JTextField campoNumBloque = new JTextField();

                        Object[] contenido = {"Introduzca los parámetros para el error en la comunicación:\n[1 bit "
                            + "erróneo únicamente] ", " ", "Número de bloque " + "[0-" + numBloques + "]:", campoNumBloque};
                        Object acciones[] = {"Aceptar", "Cancelar"};

                        do {
                            do {
                                if (error == true) {
                                    JOptionPane.showMessageDialog(null, "Error: Tiene que rellenar todos los campos"
                                            + " con valores válidos.");
                                }

                                opcion = JOptionPane.showOptionDialog(null, contenido, "Error en la comunicación",
                                        JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, acciones, contenido);

                                if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                                    parada = true;
                                    break;
                                }

                                numBloque = campoNumBloque.getText().toString();

                                if (numBloque.isEmpty()) {
                                    error = true;
                                } else {
                                    valorNumBloque = Integer.parseInt(numBloque);
                                    error = (valorNumBloque < 0 || valorNumBloque > numBloques);
                                }

                                if (!error) {
                                    try {
                                        byte[] bytes = textoCif.getBytes("UTF-8");
                                        bytes[valorNumBloque] = (byte) (bytes[valorNumBloque] ^ 1);

                                        textoCifError = new String(bytes);
                                    } catch (UnsupportedEncodingException uee) {
                                        System.err.println("Error: codificación UTF-8 no soportada. " + uee.getMessage());
                                    }

                                    try {
                                        salida = new PrintStream(new FileOutputStream(trampa));
                                        salida.print(textoCifError);
                                        salida.close();
                                    } catch (FileNotFoundException fnfe) {
                                        System.err.println("Error: el archivo en el que guardar el encriptado no existe. "
                                                + fnfe.getMessage());
                                    }

                                    textoDesError = encriptador.descifrar(trampa);

                                    String cabecera = "Modo de cifrado: " + encriptador.cadenaModo()
                                            + "\nError introducido en el bloque: " + valorNumBloque
                                            + "\n\nBloque\tTexto\tSin error\tCon error\tDescifrado";

                                    sb.append(cabecera);

                                    Scanner lector;
                                    String entrada = null;
                                    ArrayList<String> bloquesTexto = new ArrayList<>();
                                    ArrayList<String> bloquesSinError = new ArrayList<>();
                                    ArrayList<String> bloquesConError = new ArrayList<>();
                                    ArrayList<String> bloquesDescifrados = new ArrayList<>();

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(texto)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesTexto.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoCif)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesSinError.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoCifError)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesConError.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoDesError)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesDescifrados.add(lector.next());
                                    }

                                    for (int i = 0; i < bloquesConError.size(); i++) {
                                        if (i < bloquesDescifrados.size() && i < bloquesTexto.size()) {
                                            entrada = "\n" + i + "\t" + bloquesTexto.get(i) + "\t" + bloquesSinError.get(i)
                                                    + "\t" + bloquesConError.get(i) + "\t" + bloquesDescifrados.get(i);
                                        } else if (i < bloquesDescifrados.size() && i >= bloquesTexto.size()) {
                                            entrada = "\n" + i + "\t" + "\t" + bloquesSinError.get(i)
                                                    + "\t" + bloquesConError.get(i) + "\t" + bloquesDescifrados.get(i);
                                        } else {
                                            entrada = "\n" + i + "\t\t" + bloquesSinError.get(i) + "\t"
                                                    + bloquesConError.get(i);
                                        }
                                        sb.append(entrada);
                                    }

                                    resultado = sb.toString();

                                    Texto vt = new Texto(textoDesError);
                                    vt.setTitle("Resultado del error la comunicacion. Modo " + encriptador.cadenaModo());
                                    panelEscritorio.add(vt);
                                    vt.setVisible(true);

                                    Texto vtr = new Texto(resultado);
                                    vtr.setTitle("Resultado detallado del error en la comunicacion. Modo "
                                            + encriptador.cadenaModo());
                                    panelEscritorio.add(vtr);
                                    vtr.setVisible(true);

                                    parada = true;
                                }
                            } while (error == true);
                        } while (parada == false);
                    } else {
                        JOptionPane.showMessageDialog(this, "Debe guardar el archivo antes de introducir errores.");
                    }
                } else {
                    JOptionPane.showMessageDialog(this, "Este método de error da problemas con AES. Cambie de algoritmo.");
                }
            } else {
                JOptionPane.showMessageDialog(this, "Cambie a formato ASCII para realizar el cifrado.");
            }
        }
    }//GEN-LAST:event_accion_error_com_1

    /**
     * Método que gestiona la selección de la opción de error en la
     * sincronización. Crea una ventana en la que se muestra el error
     * introducido y otra que muestra el resultado de dicho error en la
     * descodificación.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Erores ->
     * Error en la sincronización")
     */
    private void opcion_error_sincronizacion(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcion_error_sincronizacion
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() == Formato.FORMATO_ASCII) {
                if (encriptador.getAlgoritmo() != Encriptador.ALGORITMO_AES
                        && encriptador.getAlgoritmo() != Encriptador.ALGORITMO_BLOW
                        && encriptador.getModo() != Encriptador.MODO_CBC
                        && encriptador.getModo() != Encriptador.MODO_ECB) {
                    File origen = ventanaActual.getArchivo();

                    if (origen != null) {

                        String texto = ventanaActual.getTexto();
                        String textoCif = encriptador.cifrar(origen);
                        String textoCifError = null;
                        String textoDesError;
                        File trampa = new File(origen.getAbsolutePath() + ".err.cfr");
                        PrintStream salida;
                        StringBuilder sb = new StringBuilder();
                        String resultado;

                        int numBloques = (encriptador.numeroBloques(textoCif)) - 1;
                        int valorNumBloque = 0;
                        int opcion;
                        boolean error = false;
                        boolean parada = false;
                        String numBloque;
                        JTextField campoNumBloque = new JTextField();

                        Object[] contenido = {"Introduzca los parámetros para el error en la sincronización:\n[1 bit "
                            + "erróneo únicamente] ", " ", "Número de bloque " + "[1-" + numBloques + "]:", campoNumBloque};
                        Object acciones[] = {"Aceptar", "Cancelar"};

                        do {
                            do {
                                if (error == true) {
                                    JOptionPane.showMessageDialog(null, "Error: Tiene que rellenar todos los campos"
                                            + " con valores válidos.");
                                }

                                opcion = JOptionPane.showOptionDialog(null, contenido, "Error en la sincronización",
                                        JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, acciones, contenido);

                                if ((opcion == JOptionPane.NO_OPTION) || (opcion == JOptionPane.CLOSED_OPTION)) {
                                    parada = true;
                                    break;
                                }

                                numBloque = campoNumBloque.getText().toString();

                                if (numBloque.isEmpty()) {
                                    error = true;
                                } else {
                                    valorNumBloque = Integer.parseInt(numBloque);
                                    error = (valorNumBloque < 1 || valorNumBloque > numBloques);
                                }

                                if (!error) {
                                    try {
                                        byte[] bytes = textoCif.getBytes("UTF-8");
                                        bytes[valorNumBloque] = (byte) (bytes[valorNumBloque] >> 1);

                                        textoCifError = new String(bytes);
                                    } catch (UnsupportedEncodingException uee) {
                                        System.err.println("Error: codificación UTF-8 no soportada. " + uee.getMessage());
                                    }

                                    try {
                                        salida = new PrintStream(new FileOutputStream(trampa));
                                        salida.print(textoCifError);
                                        salida.close();
                                    } catch (FileNotFoundException fnfe) {
                                        System.err.println("Error: el archivo en el que guardar el encriptado no existe. "
                                                + fnfe.getMessage());
                                    }

                                    textoDesError = encriptador.descifrar(trampa);

                                    String cabecera = "Modo de cifrado: " + encriptador.cadenaModo()
                                            + "\nError introducido en el bloque: " + valorNumBloque
                                            + "\n\nBloque\tTexto\tSin error\tCon error\tDescifrado";

                                    sb.append(cabecera);

                                    Scanner lector;
                                    String entrada = null;
                                    ArrayList<String> bloquesTexto = new ArrayList<>();
                                    ArrayList<String> bloquesSinError = new ArrayList<>();
                                    ArrayList<String> bloquesConError = new ArrayList<>();
                                    ArrayList<String> bloquesDescifrados = new ArrayList<>();

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(texto)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesTexto.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoCif)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesSinError.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoCifError)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesConError.add(lector.next());
                                    }

                                    lector = new Scanner(new StringReader(Formato.ascii_to_bin(textoDesError)));
                                    lector.useDelimiter("\\s");
                                    while (lector.hasNext()) {
                                        bloquesDescifrados.add(lector.next());
                                    }

                                    for (int i = 0; i < bloquesConError.size(); i++) {
                                        if (i < bloquesDescifrados.size() && i < bloquesTexto.size()) {
                                            entrada = "\n" + i + "\t" + bloquesTexto.get(i) + "\t" + bloquesSinError.get(i)
                                                    + "\t" + bloquesConError.get(i) + "\t" + bloquesDescifrados.get(i);
                                        } else if (i < bloquesDescifrados.size() && i >= bloquesTexto.size()) {
                                            entrada = "\n" + i + "\t" + "\t" + bloquesSinError.get(i)
                                                    + "\t" + bloquesConError.get(i) + "\t" + bloquesDescifrados.get(i);
                                        } else {
                                            entrada = "\n" + i + "\t\t" + bloquesSinError.get(i) + "\t"
                                                    + bloquesConError.get(i);
                                        }
                                        sb.append(entrada);
                                    }

                                    resultado = sb.toString();

                                    Texto vt = new Texto(textoDesError);
                                    vt.setTitle("Resultado del error la sincronización. Modo " + encriptador.cadenaModo());
                                    panelEscritorio.add(vt);
                                    vt.setVisible(true);

                                    Texto vtr = new Texto(resultado);
                                    vtr.setTitle("Resultado detallado del error en la sincronización. Modo "
                                            + encriptador.cadenaModo());
                                    panelEscritorio.add(vtr);
                                    vtr.setVisible(true);

                                    parada = true;
                                }
                            } while (error == true);
                        } while (parada == false);
                    } else {
                        JOptionPane.showMessageDialog(this, "Debe guardar el archivo antes de introducir errores.");
                    }
                } else {
                    JOptionPane.showMessageDialog(this, "Este método de error da problemas con los algoritmos AES "
                            + "y Blowfish\ny los modos CBC y ECB. Cambie de algoritmo y/o modo.");
                }
            } else {
                JOptionPane.showMessageDialog(this, "Cambie a formato ASCII para realizar el cifrado.");
            }
        }
    }//GEN-LAST:event_opcion_error_sincronizacion

    /**
     * Método que gestiona la selección del formato ASCII. Cambia el texto de la
     * ventana actual formato ASCII.
     *
     * @param evt Evento disparador de la acción (marcar "Formato -> ASCII")
     */
    private void accion_formato_ascii(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accion_formato_ascii
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() != Formato.FORMATO_ASCII) {
                String texto = ventanaActual.getTexto();
                String textoAscii = null;

                switch (ventanaActual.getFormato()) {
                    case Formato.FORMATO_BIN:
                        textoAscii = Formato.bin_to_ascii(texto);
                        break;
                    case Formato.FORMATO_HEX:
                        textoAscii = Formato.hex_to_ascii(texto);
                        break;
                }

                if (textoAscii == null) {
                    JOptionPane.showMessageDialog(this, "Error al convertir a formato ASCII.");
                } else {
                    ventanaActual.setFormato(Formato.FORMATO_ASCII);
                    ventanaActual.setTexto(textoAscii);
                }
            } else {
                JOptionPane.showMessageDialog(this, "El texto de la ventana seleccionada ya está en formato ASCII.");
            }
        }
    }//GEN-LAST:event_accion_formato_ascii

    /**
     * Método que gestiona la selección del formato binario. Cambia el texto de
     * la ventana actual formato binario.
     *
     * @param evt Evento disparador de la acción (marcar "Formato -> Binario")
     */
    private void accion_formato_bin(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accion_formato_bin
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() != Formato.FORMATO_BIN) {
                String texto = ventanaActual.getTexto();
                String textoBin = null;

                switch (ventanaActual.getFormato()) {
                    case Formato.FORMATO_HEX:
                        texto = Formato.hex_to_ascii(texto);
                    case Formato.FORMATO_ASCII:
                        textoBin = Formato.ascii_to_bin(texto);
                        break;
                }

                if (textoBin == null) {
                    JOptionPane.showMessageDialog(this, "Error al convertir a formato binario.");
                } else {
                    ventanaActual.setFormato(Formato.FORMATO_BIN);
                    ventanaActual.setTexto(textoBin);
                }
            } else {
                JOptionPane.showMessageDialog(this, "El texto de la ventana seleccionada ya está en formato binario.");
            }
        }
    }//GEN-LAST:event_accion_formato_bin

    /**
     * Método que gestiona la selección del formato hexadecimal. Cambia el texto
     * de la ventana actual formato hexadecimal.
     *
     * @param evt Evento disparador de la acción (marcar "Formato ->
     * Hexadecimal")
     */
    private void accion_formato_hex(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accion_formato_hex
        Texto ventanaActual = ((Texto) panelEscritorio.getSelectedFrame());

        if (ventanaActual == null) {
            JOptionPane.showMessageDialog(this, "No hay ninguna ventana seleccionada.");
        } else {
            if (ventanaActual.getFormato() != Formato.FORMATO_HEX) {
                String texto = ventanaActual.getTexto();
                String textoHex = null;

                switch (ventanaActual.getFormato()) {
                    case Formato.FORMATO_BIN:
                        texto = Formato.bin_to_ascii(texto);
                    case Formato.FORMATO_ASCII:
                        textoHex = Formato.ascii_to_hex(texto);
                        break;
                }

                if (textoHex == null) {
                    JOptionPane.showMessageDialog(this, "Error al convertir a formato hexadecimal.");
                } else {
                    ventanaActual.setFormato(Formato.FORMATO_HEX);
                    ventanaActual.setTexto(textoHex);
                }
            } else {
                JOptionPane.showMessageDialog(this, "El texto de la ventana seleccionada ya está en formato hexadecimal.");
            }
        }
    }//GEN-LAST:event_accion_formato_hex

    /**
     * Método que muestra información sobre los desarrolladores del proyecto.
     *
     * @param evt Evento disparador de la acción (seleccionar opción "Ayuda ->
     * Acerca de")
     */
    private void accionAcerca(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_accionAcerca
        JOptionPane.showMessageDialog(this, "SiCoEn.\nVersión: 1.0\n\nDesarrolladores:\nGermán Martínez Maldonado\n"
                + "José Manuel Castillo Pérez\n\nTutor del proyecto:\nAlvaro Antonio Martínez Sevilla\n\nAsignatura:\n"
                + "Seguridad y Protección de\nSistemas Informáticos", "Acerca de", JOptionPane.PLAIN_MESSAGE);
    }//GEN-LAST:event_accionAcerca

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JRadioButtonMenuItem algoritmo_aes;
    private javax.swing.JRadioButtonMenuItem algoritmo_blow;
    private javax.swing.JRadioButtonMenuItem algoritmo_des;
    private javax.swing.JRadioButtonMenuItem algoritmo_tdes;
    private javax.swing.JMenuBar barraMenus;
    private javax.swing.ButtonGroup grupoAlgoritmo;
    private javax.swing.ButtonGroup grupoModo;
    private javax.swing.ButtonGroup grupoPadding;
    private javax.swing.JMenu menuAlgoritmo;
    private javax.swing.JMenu menuArchivo;
    private javax.swing.JMenu menuAyuda;
    private javax.swing.JMenu menuEncriptacion;
    private javax.swing.JMenu menuErrores;
    private javax.swing.JMenu menuFormato;
    private javax.swing.JMenu menuModo;
    private javax.swing.JMenu menuPadding;
    private javax.swing.JMenu menu_error_comunicacion;
    private javax.swing.JRadioButtonMenuItem modo_cbc;
    private javax.swing.JRadioButtonMenuItem modo_cfb;
    private javax.swing.JRadioButtonMenuItem modo_ecb;
    private javax.swing.JRadioButtonMenuItem modo_ofb;
    private javax.swing.JMenuItem opcionAbrir;
    private javax.swing.JMenuItem opcionAcerca;
    private javax.swing.JMenuItem opcionCifrar;
    private javax.swing.JMenuItem opcionDescifrar;
    private javax.swing.JMenuItem opcionGuardar;
    private javax.swing.JMenuItem opcionNuevo;
    private javax.swing.JMenuItem opcionSalir;
    private javax.swing.JMenuItem opcion_error_cifrado;
    private javax.swing.JMenuItem opcion_error_com_1;
    private javax.swing.JMenuItem opcion_error_sincronizacion;
    private javax.swing.JMenuItem opcion_formato_ascii;
    private javax.swing.JMenuItem opcion_formato_bin;
    private javax.swing.JMenuItem opcion_formato_hex;
    private javax.swing.JRadioButtonMenuItem padding_iso;
    private javax.swing.JRadioButtonMenuItem padding_pkcs;
    private javax.swing.JDesktopPane panelEscritorio;
    private javax.swing.JPopupMenu.Separator separador1;
    // End of variables declaration//GEN-END:variables

}
