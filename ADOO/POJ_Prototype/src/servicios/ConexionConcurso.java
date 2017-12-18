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
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import modelo.*;

/**
 *
 * @author Carlo
 */
public class ConexionConcurso {
    private Concurso concurso;
    Connection conn;
    public ConexionConcurso()
    {
        try {
            conectar();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ConexionConcurso.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(ConexionConcurso.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public void conectar() throws ClassNotFoundException, SQLException
    {
        String myDriver = "org.gjt.mm.mysql.Driver";
        String myUrl = "jdbc:mysql://localhost/mydb";
        Class.forName(myDriver);
        conn = DriverManager.getConnection(myUrl, "root", "root"); 
    }
    public boolean existe(int id) throws ClassNotFoundException, SQLException
    {
          try{
            PreparedStatement consulta;
            int last_num = 0;
            consulta = conn.prepareStatement("SELECT id_concurso FROM " + "concurso where id_concurso = "+id );
            ResultSet resultado = consulta.executeQuery();
            if(resultado.next())
                 return true;
        }
        catch(SQLException ex){
         throw new SQLException(ex);
      }
        return false;
    }
    
}
