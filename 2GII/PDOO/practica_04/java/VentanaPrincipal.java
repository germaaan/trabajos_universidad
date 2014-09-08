package munchkin_cthulhu;

/**
 *
 * @author Germán Martínez Maldonado
 * @author José Rubén Sánchez Iruela
 * @author Pablo Sánchez Robles
 */
import java.awt.Color;
import java.util.LinkedList;
import javax.swing.*;
import javax.swing.border.BevelBorder;
import javax.swing.border.Border;

public class VentanaPrincipal extends JFrame implements Vista {

    private static final int posXtesorOcult[] = {20, 190, 360, 530, 700, 870};
    private static final int posYtesorOcult = 260;
    private static final int posXtesorVisib[] = {20, 190, 360, 530, 700};
    private static final int posYtesorVisib = 80;
    private static final Border bordeEtiqueta = BorderFactory.createLineBorder(Color.GRAY);
    private static final Border bordeCarta = BorderFactory.createBevelBorder(
            BevelBorder.RAISED, Color.WHITE, Color.DARK_GRAY);
    private Munchkin juego;
    private String[] nombresJugadores;
    private Monstruo monstruoEnJuego;
    private Jugador jugadorActivo;
    private LinkedList<TesoroGrafico> tesorosAlimpiar = new LinkedList<TesoroGrafico>();
    private LinkedList<Tesoro> tesorosVisiblesSeleccionados = new LinkedList<Tesoro>();
    private LinkedList<Tesoro> tesorosOcultosSeleccionados = new LinkedList<Tesoro>();

    private class TesoroGrafico extends JPanel {

        protected Tesoro tesoro;
        private JLabel jL_nombreTesoro;
        private JLabel jL_bonus;
        private JLabel jL_piezas;
        private JLabel jL_tipo;
        protected boolean seleccionado;

        TesoroGrafico(Tesoro unTesoro) {
            this.tesoro = unTesoro;

            this.jL_nombreTesoro = new JLabel();
            this.jL_bonus = new JLabel();
            this.jL_piezas = new JLabel();
            this.jL_tipo = new JLabel();

            this.setPreferredSize(new java.awt.Dimension(150, 153));
            this.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());
            this.setBorder(bordeCarta);
            this.setBackground(new java.awt.Color(200, 200, 0));
            this.setOpaque(false);

            this.jL_nombreTesoro.setPreferredSize(new java.awt.Dimension(140, 30));
            this.jL_nombreTesoro.setText(" " + this.tesoro.obtenerNombre());
            this.jL_nombreTesoro.setBorder(bordeEtiqueta);

            this.jL_bonus.setPreferredSize(new java.awt.Dimension(140, 25));
            this.jL_bonus.setText(" Bonus: " + String.valueOf(this.tesoro.obtenerBonus()));
            this.jL_bonus.setBorder(bordeEtiqueta);

            this.jL_piezas.setPreferredSize(new java.awt.Dimension(140, 25));
            this.jL_piezas.setText(" Oro: " + String.valueOf(this.tesoro.obtenerPiezasOro()));
            this.jL_piezas.setBorder(bordeEtiqueta);

            this.jL_tipo.setPreferredSize(new java.awt.Dimension(140, 25));
            switch (this.tesoro.obtenerTipo()) {
                case 0:
                    this.jL_tipo.setText(" Tipo: CASCO");
                    break;
                case 1:
                    this.jL_tipo.setText(" Tipo: ARMADURA");
                    break;
                case 2:
                    this.jL_tipo.setText(" Tipo: CALZADO");
                    break;
                case 3:
                    this.jL_tipo.setText(" Tipo: UNA MANO");
                    break;
                case 4:
                    this.jL_tipo.setText(" Tipo: DOS MANOS");
                    break;
            }
            this.jL_tipo.setBorder(bordeEtiqueta);

            this.add(this.jL_nombreTesoro, new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    5, 5, -1, -1));
            this.add(this.jL_bonus, new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    5, 67, -1, -1));
            this.add(this.jL_piezas, new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    5, 95, -1, -1));
            this.add(this.jL_tipo, new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    5, 123, -1, -1));
        }
    }

    private class TesoroGraficoVisible extends TesoroGrafico {

        TesoroGraficoVisible(Tesoro unTesoro) {
            super(unTesoro);

            addMouseListener(new java.awt.event.MouseAdapter() {

                @Override
                public void mouseClicked(java.awt.event.MouseEvent evt) {
                    if (!TesoroGraficoVisible.this.seleccionado) {
                        TesoroGraficoVisible.this.setOpaque(true);
                        tesorosVisiblesSeleccionados.add(TesoroGraficoVisible.this.tesoro);
                        TesoroGraficoVisible.this.seleccionado = true;
                    } else {
                        TesoroGraficoVisible.this.setOpaque(false);
                        tesorosVisiblesSeleccionados.remove(TesoroGraficoVisible.this.tesoro);
                        TesoroGraficoVisible.this.seleccionado = false;
                    }

                    repaint();
                    pack();
                }
            });
        }
    }

    private class TesoroGraficoOculto extends TesoroGrafico {

        TesoroGraficoOculto(Tesoro unTesoro) {
            super(unTesoro);

            addMouseListener(new java.awt.event.MouseAdapter() {

                @Override
                public void mouseClicked(java.awt.event.MouseEvent evt) {
                    if (!TesoroGraficoOculto.this.seleccionado) {
                        TesoroGraficoOculto.this.setOpaque(true);
                        tesorosOcultosSeleccionados.add(TesoroGraficoOculto.this.tesoro);
                        TesoroGraficoOculto.this.seleccionado = true;
                    } else {
                        TesoroGraficoOculto.this.setOpaque(false);
                        tesorosOcultosSeleccionados.remove(TesoroGraficoOculto.this.tesoro);
                        TesoroGraficoOculto.this.seleccionado = false;
                    }

                    repaint();
                    pack();
                }
            });
        }
    }

    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal(Munchkin unJuego) {
        initComponents();

        this.juego = unJuego;
        this.jB_siguiente.setEnabled(false);
        this.jB_robarTesoro.setEnabled(false);

        this.setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jP_monstruo = new javax.swing.JPanel();
        jL_datosMonstruo = new javax.swing.JLabel();
        jL_nombreMonstruo = new javax.swing.JLabel();
        jL_nivelesGanados = new javax.swing.JLabel();
        jL_tesorosGanados = new javax.swing.JLabel();
        jL_nivelMonstruo = new javax.swing.JLabel();
        jL_nivelesPerdidos = new javax.swing.JLabel();
        jL_malRollo = new javax.swing.JLabel();
        jL_mensajeResultado = new javax.swing.JLabel();
        jP_jugador = new javax.swing.JPanel();
        jL_datosJugador = new javax.swing.JLabel();
        jL_datosTesoros = new javax.swing.JLabel();
        jL_tesorosVisibles = new javax.swing.JLabel();
        jL_nombreJugador = new javax.swing.JLabel();
        jL_nivelJugador = new javax.swing.JLabel();
        jL_tesorosOcultos = new javax.swing.JLabel();
        jL_etiquetaNombre = new javax.swing.JLabel();
        jL_etiquetaNivel = new javax.swing.JLabel();
        jL_etiquetaNivelC = new javax.swing.JLabel();
        jL_nivelCombate = new javax.swing.JLabel();
        jB_equipaTesoros = new javax.swing.JButton();
        jB_compraNiveles = new javax.swing.JButton();
        jB_descartaTesoros = new javax.swing.JButton();
        jB_siguiente = new javax.swing.JButton();
        jB_combatir = new javax.swing.JButton();
        jB_robarTesoro = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Munchkin");
        setMaximizedBounds(new java.awt.Rectangle(1050, 675, 675, 675));
        setMinimumSize(new java.awt.Dimension(1055, 670));
        setName("jF_ventanaPrincipal"); // NOI18N
        setResizable(false);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jP_monstruo.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        jP_monstruo.setToolTipText("Datos del monstruo en juego.");
        jP_monstruo.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jP_monstruo.setFocusable(false);
        jP_monstruo.setName("jP_monstruo"); // NOI18N
        jP_monstruo.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jL_datosMonstruo.setFont(new java.awt.Font("Comic Sans MS", 1, 11));
        jL_datosMonstruo.setLabelFor(jP_monstruo);
        jL_datosMonstruo.setText("Datos del monstruo en juego:");
        jL_datosMonstruo.setName("jL_monstruoEnJuego"); // NOI18N
        jP_monstruo.add(jL_datosMonstruo, new org.netbeans.lib.awtextra.AbsoluteConstraints(80, 0, -1, 20));

        jL_nombreMonstruo.setBackground(new java.awt.Color(204, 204, 204));
        jL_nombreMonstruo.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_nombreMonstruo, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 30, 370, 20));

        jL_nivelesGanados.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_nivelesGanados, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 60, 170, 20));

        jL_tesorosGanados.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_tesorosGanados, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 90, 170, 20));

        jL_nivelMonstruo.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_nivelMonstruo, new org.netbeans.lib.awtextra.AbsoluteConstraints(240, 60, 150, 20));

        jL_nivelesPerdidos.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_nivelesPerdidos, new org.netbeans.lib.awtextra.AbsoluteConstraints(240, 90, 150, 20));

        jL_malRollo.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_malRollo, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 130, 1000, 20));

        jL_mensajeResultado.setFont(new java.awt.Font("Tahoma", 0, 30));
        jL_mensajeResultado.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_monstruo.add(jL_mensajeResultado, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 30, 570, 80));

        getContentPane().add(jP_monstruo, new org.netbeans.lib.awtextra.AbsoluteConstraints(5, 5, 1040, 170));
        jP_monstruo.getAccessibleContext().setAccessibleName("jP_monstruoEnJuego");

        jP_jugador.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        jP_jugador.setToolTipText("Datos del jugador actual");
        jP_jugador.setPreferredSize(new java.awt.Dimension(350, 1040));
        jP_jugador.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jL_datosJugador.setFont(new java.awt.Font("Comic Sans MS", 1, 11));
        jL_datosJugador.setLabelFor(jP_jugador);
        jL_datosJugador.setText("Datos del jugador activo:");
        jP_jugador.add(jL_datosJugador, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 10, -1, -1));

        jL_datosTesoros.setFont(new java.awt.Font("Comic Sans MS", 1, 11));
        jL_datosTesoros.setText("Tesoros:");
        jP_jugador.add(jL_datosTesoros, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 30, -1, -1));

        jL_tesorosVisibles.setFont(new java.awt.Font("Comic Sans MS", 1, 11));
        jL_tesorosVisibles.setText("Visibles:");
        jP_jugador.add(jL_tesorosVisibles, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 60, -1, -1));

        jL_nombreJugador.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_jugador.add(jL_nombreJugador, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 23, 150, 30));

        jL_nivelJugador.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_jugador.add(jL_nivelJugador, new org.netbeans.lib.awtextra.AbsoluteConstraints(660, 23, 40, 30));

        jL_tesorosOcultos.setFont(new java.awt.Font("Comic Sans MS", 1, 11));
        jL_tesorosOcultos.setText("Ocultos:");
        jP_jugador.add(jL_tesorosOcultos, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 240, -1, -1));

        jL_etiquetaNombre.setText("Nombre:");
        jP_jugador.add(jL_etiquetaNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(330, 28, -1, -1));

        jL_etiquetaNivel.setText("Nivel:");
        jP_jugador.add(jL_etiquetaNivel, new org.netbeans.lib.awtextra.AbsoluteConstraints(620, 28, -1, -1));

        jL_etiquetaNivelC.setText("Nivel de combate:");
        jP_jugador.add(jL_etiquetaNivelC, new org.netbeans.lib.awtextra.AbsoluteConstraints(775, 28, -1, -1));

        jL_nivelCombate.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jP_jugador.add(jL_nivelCombate, new org.netbeans.lib.awtextra.AbsoluteConstraints(887, 23, 40, 30));

        getContentPane().add(jP_jugador, new org.netbeans.lib.awtextra.AbsoluteConstraints(5, 180, 1040, 430));

        jB_equipaTesoros.setText("Equiparse");
        jB_equipaTesoros.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_equipaTesorosActionPerformed(evt);
            }
        });
        getContentPane().add(jB_equipaTesoros, new org.netbeans.lib.awtextra.AbsoluteConstraints(150, 615, 140, -1));

        jB_compraNiveles.setText("Comprar niveles");
        jB_compraNiveles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_compraNivelesActionPerformed(evt);
            }
        });
        getContentPane().add(jB_compraNiveles, new org.netbeans.lib.awtextra.AbsoluteConstraints(295, 615, 140, -1));

        jB_descartaTesoros.setText("Descartarse");
        jB_descartaTesoros.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_descartaTesorosActionPerformed(evt);
            }
        });
        getContentPane().add(jB_descartaTesoros, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 615, 140, -1));

        jB_siguiente.setText("Siguiente");
        jB_siguiente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_siguienteActionPerformed(evt);
            }
        });
        getContentPane().add(jB_siguiente, new org.netbeans.lib.awtextra.AbsoluteConstraints(905, 615, 140, -1));

        jB_combatir.setText("Combatir");
        jB_combatir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_combatirActionPerformed(evt);
            }
        });
        getContentPane().add(jB_combatir, new org.netbeans.lib.awtextra.AbsoluteConstraints(5, 615, 140, -1));

        jB_robarTesoro.setText("Robar");
        jB_robarTesoro.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jB_robarTesoroActionPerformed(evt);
            }
        });
        getContentPane().add(jB_robarTesoro, new org.netbeans.lib.awtextra.AbsoluteConstraints(585, 615, 140, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jB_equipaTesorosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_equipaTesorosActionPerformed
        this.juego.equiparseJugador(tesorosOcultosSeleccionados);
        this.tesorosOcultosSeleccionados.clear();
        this.actualizarJugador();
    }//GEN-LAST:event_jB_equipaTesorosActionPerformed

    private void jB_siguienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_siguienteActionPerformed
        try {
            this.juego.siguienteTurno();
            this.actualizarJugador();
            this.actualizarMonstruo();
            this.jB_combatir.setEnabled(true);
            this.jB_compraNiveles.setEnabled(true);
            this.jB_descartaTesoros.setEnabled(true);
            this.jB_equipaTesoros.setEnabled(true);
            this.jB_siguiente.setEnabled(false);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage());
        }
    }//GEN-LAST:event_jB_siguienteActionPerformed

    private void jB_combatirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_combatirActionPerformed
        this.jB_combatir.setEnabled(false);
        this.jB_compraNiveles.setEnabled(false);
        this.jB_equipaTesoros.setEnabled(false);
        this.jB_siguiente.setEnabled(false);

        int resultado = this.juego.desarrollarCombate();

        if (resultado == 1) {
            this.jB_robarTesoro.setEnabled(true);
        } else {
            this.jB_siguiente.setEnabled(true);
        }

        this.actualizarJugador();
        this.actualizarMensaje(resultado);
    }//GEN-LAST:event_jB_combatirActionPerformed

    private void jB_compraNivelesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_compraNivelesActionPerformed
        LinkedList<Tesoro> tesorosParaVender = new LinkedList<Tesoro>();

        tesorosParaVender.addAll(this.tesorosOcultosSeleccionados);
        tesorosParaVender.addAll(this.tesorosVisiblesSeleccionados);

        this.juego.comprarNivelesJugador(tesorosParaVender);
        this.tesorosOcultosSeleccionados.clear();
        this.tesorosVisiblesSeleccionados.clear();

        if (this.jugadorActivo.obtenerNivel() >= 10) {
            this.actualizarMensaje(10);
        }

        this.actualizarJugador();
    }//GEN-LAST:event_jB_compraNivelesActionPerformed

    private void jB_descartaTesorosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_descartaTesorosActionPerformed
        this.juego.descartarTesorosOcultos(this.tesorosOcultosSeleccionados);
        this.juego.descartarTesorosVisibles(this.tesorosVisiblesSeleccionados);
        this.tesorosOcultosSeleccionados.clear();
        this.tesorosVisiblesSeleccionados.clear();
        this.actualizarJugador();
    }//GEN-LAST:event_jB_descartaTesorosActionPerformed

    private void jB_robarTesoroActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jB_robarTesoroActionPerformed
        Tesoro tesoro;

        for (int i = 0; i < this.monstruoEnJuego.obtenerGananciaTesoros(); i++) {
            tesoro = this.juego.primerTesoro();
            this.jugadorActivo.robarTesoro(tesoro);
        }

        this.jB_robarTesoro.setEnabled(false);
        this.jB_siguiente.setEnabled(true);

        this.actualizarJugador();
    }//GEN-LAST:event_jB_robarTesoroActionPerformed
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jB_combatir;
    private javax.swing.JButton jB_compraNiveles;
    private javax.swing.JButton jB_descartaTesoros;
    private javax.swing.JButton jB_equipaTesoros;
    private javax.swing.JButton jB_robarTesoro;
    private javax.swing.JButton jB_siguiente;
    private javax.swing.JLabel jL_datosJugador;
    private javax.swing.JLabel jL_datosMonstruo;
    private javax.swing.JLabel jL_datosTesoros;
    private javax.swing.JLabel jL_etiquetaNivel;
    private javax.swing.JLabel jL_etiquetaNivelC;
    private javax.swing.JLabel jL_etiquetaNombre;
    private javax.swing.JLabel jL_malRollo;
    private javax.swing.JLabel jL_mensajeResultado;
    private javax.swing.JLabel jL_nivelCombate;
    private javax.swing.JLabel jL_nivelJugador;
    private javax.swing.JLabel jL_nivelMonstruo;
    private javax.swing.JLabel jL_nivelesGanados;
    private javax.swing.JLabel jL_nivelesPerdidos;
    private javax.swing.JLabel jL_nombreJugador;
    private javax.swing.JLabel jL_nombreMonstruo;
    private javax.swing.JLabel jL_tesorosGanados;
    private javax.swing.JLabel jL_tesorosOcultos;
    private javax.swing.JLabel jL_tesorosVisibles;
    private javax.swing.JPanel jP_jugador;
    private javax.swing.JPanel jP_monstruo;
    // End of variables declaration//GEN-END:variables

    public void mostrar(String[] args) {
        JD_nombresJugadores dialogoNombres;
        dialogoNombres = new JD_nombresJugadores(this, true);
        this.nombresJugadores = dialogoNombres.getNombres();
        try {
            this.juego.comenzarJuego(this.nombresJugadores);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, ex.getMessage());
        }

        this.setVisible(true);
        this.actualizarMonstruo();
        this.actualizarJugador();
    }

    private void actualizarMonstruo() {
        this.monstruoEnJuego = this.juego.getMonstruoEnJuego();
        this.jL_nombreMonstruo.setText(" Nombre: " + this.monstruoEnJuego.obternerNombre());
        this.jL_nivelMonstruo.setText(String.valueOf(" Nivel: "
                + this.monstruoEnJuego.obtenerNivel()));
        this.jL_tesorosGanados.setText(String.valueOf(" Tesoros: "
                + this.monstruoEnJuego.obtenerGananciaTesoros()));
        this.jL_nivelesGanados.setText(String.valueOf(" Niveles ganados: "
                + this.monstruoEnJuego.obtenerGananciaNiveles()));
        this.jL_nivelesPerdidos.setText(String.valueOf(" Niveles perdidos: "
                + this.monstruoEnJuego.obtenerNivelesPerdidos()));
        this.jL_malRollo.setText(" " + this.monstruoEnJuego.obtenerMalRollo());
        this.jL_mensajeResultado.setText(null);
        repaint();
        pack();
    }

    private void actualizarJugador() {
        TesoroGrafico unTesoroGrafico;
        int i;
        this.jugadorActivo = this.juego.getJugadorActivo();

        this.jL_nombreJugador.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        this.jL_nombreJugador.setText(this.jugadorActivo.obtenerNombre());

        this.jL_nivelJugador.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        this.jL_nivelJugador.setText(String.valueOf(this.jugadorActivo.obtenerNivel()));

        this.jL_nivelCombate.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        this.jL_nivelCombate.setText(String.valueOf(this.jugadorActivo.nivelDeCombate()));

        for (TesoroGrafico tg : tesorosAlimpiar) {
            jP_jugador.remove(tg);
        }
        tesorosAlimpiar.clear();

        i = 0;
        for (Tesoro t : this.jugadorActivo.getTesorosVisibles()) {

            unTesoroGrafico = new TesoroGraficoVisible(t);

            this.jP_jugador.add(unTesoroGrafico,
                    new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    posXtesorVisib[i], posYtesorVisib, -1, -1));

            this.tesorosAlimpiar.add(unTesoroGrafico);
            i++;
        }

        i = 0;
        for (Tesoro t : this.jugadorActivo.getTesorosOcultos()) {
            unTesoroGrafico = new TesoroGraficoOculto(t);

            this.jP_jugador.add(unTesoroGrafico,
                    new org.netbeans.lib.awtextra.AbsoluteConstraints(
                    posXtesorOcult[i], posYtesorOcult, -1, -1));

            this.tesorosAlimpiar.add(unTesoroGrafico);
            i++;
        }

        this.tesorosVisiblesSeleccionados.clear();
        this.tesorosOcultosSeleccionados.clear();

        repaint();
        pack();
    }

    private void actualizarMensaje(int resultado) {
        this.jL_mensajeResultado.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);

        switch (resultado) {
            case -1:
                this.jL_mensajeResultado.setText(" ¡Has perdido el combate!");
                break;
            case 0:
                this.jB_descartaTesoros.setEnabled(false);
                this.jL_mensajeResultado.setText(" ¡Has conseguido huir del monstruo!");
                break;
            case 1:
                this.jL_mensajeResultado.setText(" ¡Has ganado el combate!");
                break;
            case 10:
                this.jB_siguiente.setEnabled(false);
                this.jB_descartaTesoros.setEnabled(false);
                this.jL_mensajeResultado.setText(" ¡Has ganado la partida!");
                JOptionPane.showMessageDialog(null, "¡FELICIDADES, eres el ganador de la partida!");
                break;
        }
    }
}
