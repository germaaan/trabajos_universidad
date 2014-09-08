package utilidad;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineListener;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.TargetDataLine;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

/**
 * Grabador de audio basado en la clase 'SMSoundRecorder'.
 *
 * @author German Martinez Maldonado
 */
public class Grabador {

    /**
     * Formatos de codificación aceptados.
     */
    public static final Object valoresCodificacion[] = {"PCM SIGNED", "PCM UNSIGNED"};
    /**
     * Frencuencias de muestreo aceptadas.
     */
    public static final Object valoresMuestreo[] = {"8000", "16000", "24000", "32000", "44100", "96000", "192000"};
    /**
     * Bits de resolución aceptados.
     */
    public static final Object valoresResolucion[] = {"8", "16", "24"};
    /**
     * Número de canales de audio aceptados.
     */
    public static final Object valoresNumCanales[] = {"1", "2"};
    /**
     * Formatos de archivos de audio aceptados.
     */
    public static final Object valoresFormato[] = {"AIFF", "WAVE"};
    private static final boolean _DEFAULT_BIGENDIAN = false;
    private AudioFormat.Encoding _CODING;
    private float _SAMPLE_RATE;
    private int _SAMPLE_SIZE;
    private int _NUMCHANELS;
    private int _FRAME_SIZE;
    private float _FRAME_RATE;
    private AudioFileFormat.Type _FILE_FORMAT;
    private DataLine line;
    private LineListener lineListener = null;
    private File tempFile;

    /**
     * Constructor del grabador de audio.
     */
    public Grabador() {
        _CODING = null;
        _SAMPLE_RATE = 0.0f;
        _SAMPLE_SIZE = 0;
        _NUMCHANELS = 0;
        _FRAME_SIZE = 0;
        _FRAME_RATE = 0.0f;
        _FILE_FORMAT = null;

        tempFile = null;
    }

    /**
     * Asigna los valores para la digitalización del sonido a capturar.
     *
     * @param _CODING Tipo de codificación.
     * @param _SAMPLE_RATE Frecuencia de muestreo.
     * @param _SAMPLE_SIZE Bits de resolución.
     * @param _NUMCHANELS Número de canales.
     * @param _FILE_FORMAT Formato del archivo.
     */
    public void setValores(AudioFormat.Encoding _CODING, float _SAMPLE_RATE, int _SAMPLE_SIZE,
            int _NUMCHANELS, AudioFileFormat.Type _FILE_FORMAT) {
        this._CODING = _CODING;
        this._SAMPLE_RATE = _SAMPLE_RATE;
        this._SAMPLE_SIZE = _SAMPLE_SIZE;
        this._NUMCHANELS = _NUMCHANELS;
        this._FRAME_SIZE = ((_SAMPLE_SIZE / 8) * _NUMCHANELS);
        this._FRAME_RATE = _SAMPLE_RATE;
        this._FILE_FORMAT = _FILE_FORMAT;

        try {
            tempFile = File.createTempFile("grabacionTemporal", null);
        } catch (IOException e) {
            System.err.println("Error al crear el archivo temporal para la grabación. " + e.getMessage());
        }
    }

    /**
     * Inicia el hilo que se encargar de la captura del sonido.
     */
    public void record() {
        Thread thread = new Thread() {
            @Override
            public void run() {
                startRecord();
            }
        };
        thread.start();
    }

    /**
     * Detiene la grabación y guarda la misma en un archivo.
     */
    public void stop() {
        if (line != null) {
            line.stop();
            line.close();

            JFileChooser dlg = new JFileChooser();
            Filtro filtro = null;
            boolean guardar = false;

            if (_FILE_FORMAT == AudioFileFormat.Type.AIFF) {
                filtro = new Filtro(Filtro.GUARDAR, "aif");
            } else if (_FILE_FORMAT == AudioFileFormat.Type.WAVE) {
                filtro = new Filtro(Filtro.GUARDAR, "wav");
            }

            if (filtro != null) {
                dlg.setAcceptAllFileFilterUsed(false);
                dlg.addChoosableFileFilter(filtro);
                dlg.setFileFilter(filtro);
            }

            int resp = dlg.showSaveDialog(null);
            if (resp == JFileChooser.APPROVE_OPTION) {
                try {
                    File f = dlg.getSelectedFile();

                    String formato = ((Filtro) dlg.getFileFilter()).getExtension();

                    String fileExtension = Filtro.getFileExtension(f);

                    if (fileExtension == null) {
                        File fich = new File(f.getAbsolutePath() + "." + formato);
                        f = fich;
                    } else if (!fileExtension.equals(formato)) {
                        int tamRuta = f.getAbsolutePath().length() - fileExtension.length();
                        String ruta = f.getAbsolutePath().substring(0, tamRuta) + formato;
                        File fich = new File(ruta);
                        f = fich;
                    }

                    if (f.exists()) {
                        int sobre = JOptionPane.showConfirmDialog(null,
                                "¿Desea sobreescribir el archivo \"" + dlg.getSelectedFile().getName() + "\"?",
                                "Sobreescribir archivo",
                                JOptionPane.YES_NO_OPTION);

                        if (sobre == JOptionPane.YES_OPTION) {
                            guardar = true;
                        }
                    } else {
                        guardar = true;
                    }

                    if (guardar) {
                        InputStream in = new FileInputStream(tempFile);
                        OutputStream out = new FileOutputStream(f);

                        byte[] buf = new byte[1024];
                        int len;

                        while ((len = in.read(buf)) > 0) {
                            out.write(buf, 0, len);
                        }

                        in.close();
                        out.close();

                        tempFile.delete();
                    }

                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(null, "No se pudo guardar el archivo de audio de la grabación.");
                    System.err.println("No se pudo guardar el archivo de audio de la grabación. " + ex.getMessage());
                }
            }
        }
    }

    /**
     * Inicia la grabación del sonido en el archivo temporal.
     */
    private void startRecord() {
        if ((_CODING != null) && (_SAMPLE_RATE != 0.0f) && (_SAMPLE_SIZE != 0) && (_NUMCHANELS != 0)
                && (_FILE_FORMAT != null) && (tempFile != null)) {
            AudioFormat audioFormat = new AudioFormat(_CODING, _SAMPLE_RATE,
                    _SAMPLE_SIZE, _NUMCHANELS, _FRAME_SIZE, _FRAME_RATE,
                    _DEFAULT_BIGENDIAN);

            DataLine.Info info = new DataLine.Info(TargetDataLine.class, audioFormat);

            TargetDataLine targetDataLine = null;

            try {
                line = targetDataLine = (TargetDataLine) AudioSystem.getLine(info);
                line.addLineListener(lineListener);
                targetDataLine.open(audioFormat);
            } catch (LineUnavailableException e) {
                System.err.println("SoundPlayerRecorder: " + e.getMessage());
            }

            AudioFileFormat.Type targetType = _FILE_FORMAT;

            AudioInputStream audioInputStream = new AudioInputStream(targetDataLine);

            targetDataLine.start();

            try {
                AudioSystem.write(audioInputStream, targetType, tempFile);
            } catch (IOException e) {
                System.err.println("SoundPlayerRecorder: " + e.getMessage());
            }
        } else {
            System.err.println("El grabador no tiene unos parámetros de grabación válidos.");
        }
    }

    /**
     * Estable la línea de entrada del audio a captura.
     *
     * @param l Línea de entrada del audio a captura.
     */
    public void setLineListener(LineListener l) {
        lineListener = l;
    }
}
