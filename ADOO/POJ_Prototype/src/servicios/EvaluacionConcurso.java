/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servicios;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.util.Pair;
import modelo.*;
/**
 *
 * @author Carlo
 */
public class EvaluacionConcurso {
        
    public EvaluacionConcurso()
    {
        
    }
    public static boolean compararOutput(String ruta1, String ruta2)
    {
        FileReader fr1 = null;
        try {
            fr1 = new FileReader(ruta1);
            FileReader fr2 = new FileReader(ruta2);
            BufferedReader bf1 = new BufferedReader(fr1);
            BufferedReader bf2 = new BufferedReader(fr2);
            
            String lineaA = "", lineaB = "";
            do
            {
                if(!lineaA.equals(lineaB)) return false;
                lineaA = bf1.readLine();
                lineaB = bf2.readLine();
       
            }while(lineaA != null && lineaB != null);
          
        } catch (FileNotFoundException ex) {
            Logger.getLogger(EvaluacionConcurso.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(EvaluacionConcurso.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr1.close();
            } catch (IOException ex) {
                Logger.getLogger(EvaluacionConcurso.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return true;
    }
    
}
