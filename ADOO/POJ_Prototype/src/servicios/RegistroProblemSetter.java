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

import sun.awt.AppContext;

/**
 *
 * @author Carlo
 */
public class RegistroProblemSetter {
    private Connection conn;

    public RegistroProblemSetter() {
        try {
            conectar();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RegistroProblemSetter.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(RegistroProblemSetter.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void registrar(ProblemSetter problemsetter) throws SQLException, ClassNotFoundException{
        try{
            
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://localhost/mydb";
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "root");    

            PreparedStatement consulta;


            consulta = conn.prepareStatement("INSERT INTO " + "usuario" + "(nombre, password ) VALUES(?,?)");
            //consulta.setInt(1, problemsetter.getId_usuario());
            consulta.setString(1, problemsetter.getNombre());
            consulta.setString(2, problemsetter.getPassword());
            consulta.executeUpdate();
            int last_num = 0;
            consulta = conn.prepareStatement("SELECT idUsuario FROM " + "usuario"+ " order by idUsuario desc" );
            ResultSet resultado = consulta.executeQuery();
            if(resultado.next())
            last_num = resultado.getInt("idUsuario");


            consulta = conn.prepareStatement("INSERT INTO " + "problemsetter (idProblemSetter) " + " VALUES(?)");
            consulta.setInt(1, last_num);
            consulta.executeUpdate();
            JOptionPane.showMessageDialog(null,"Registro satisfactorio");
        }
        catch(SQLException ex){
         throw new SQLException(ex);
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
            consulta = conn.prepareStatement("SELECT idproblemsetter FROM " + "problemsetter where idproblemsetter = "+id );
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
