/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servicios;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;
import modelo.Problema;

/**
 *
 * @author Carlo
 */
public class RegistroProblema {
     public void registrar(Problema problema) throws SQLException, ClassNotFoundException{
        try{
            
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://localhost/mydb";
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "root");    

            PreparedStatement consulta;


            consulta = conn.prepareStatement("INSERT INTO " + "problema" + "(ruta_archivo, nombre, id_problemsetter, ruta_input, ruta_output) VALUES(?,?,?,?,?)");
            //consulta.setInt(1, problemsetter.getId_usuario());
            consulta.setString(1, problema.getRutaArchivo());
            consulta.setString(2, problema.getNombre());
            consulta.setInt(3, problema.getId_problem_setter());
            consulta.setString(4, problema.getRuta_input());
            consulta.setString(5, problema.getRuta_input());
            consulta.executeUpdate();
            
            JOptionPane.showMessageDialog(null,"Registro satisfactorio");
        }
        catch(SQLException ex){
         throw new SQLException(ex);
      }
    }  
    
}
