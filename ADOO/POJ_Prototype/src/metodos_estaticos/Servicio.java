/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package metodos_estaticos;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Carlo
 */
public class Servicio {
     public static String charToString(char arreglo[])
    {
        String string = "";
        for(int i = 0; i < arreglo.length; i++)
            string += (arreglo[i]);
        return string;
    }
        public static void copyFileUsingStream(File source, File dest) throws IOException {
            InputStream is = null;
            OutputStream os = null;
            try {
                is = new FileInputStream(source);
                os = new FileOutputStream(dest);
                byte[] buffer = new byte[1024];
                int length;
                while ((length = is.read(buffer)) > 0) {
                    os.write(buffer, 0, length);
                }
            } finally {
                is.close();
                os.close();
            }
        }
        public static void mostrarPDF(String ruta)
        {
             ProcessBuilder builder = new ProcessBuilder(
                    "cmd.exe", "/c", " "+ruta);
            builder.redirectErrorStream(true);
         try {
             Process p = builder.start();
         } catch (IOException ex) {
             Logger.getLogger(Servicio.class.getName()).log(Level.SEVERE, null, ex);
         }
        }
}
