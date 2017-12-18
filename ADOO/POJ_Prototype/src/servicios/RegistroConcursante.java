package servicios;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import modelo.Concursante;

import sun.awt.AppContext;

/**
 *
 * @author Carlo
 */
public class RegistroConcursante {
    private Connection conn;
    public RegistroConcursante()
    {
        try {
            conectar();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RegistroConcursante.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(RegistroConcursante.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    public void registrar( Concursante concursante) throws SQLException, ClassNotFoundException{
        try{
               

            PreparedStatement consulta;


            consulta = conn.prepareStatement("INSERT INTO " + "usuario" + "(nombre, password ) VALUES(?,?)");
            //consulta.setInt(1, concursante.getId_usuario());
            consulta.setString(1, concursante.getNombre());
            consulta.setString(2, concursante.getPassword());
            consulta.executeUpdate();
            int last_num = 0;
            consulta = conn.prepareStatement("SELECT idUsuario FROM " + "usuario"+ " order by idUsuario desc    " );
            ResultSet resultado = consulta.executeQuery();
            if(resultado.next())
            last_num = resultado.getInt("idUsuario");


            consulta = conn.prepareStatement("INSERT INTO " + "concursante (idConcursante) " + " VALUES(?)");
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
            consulta = conn.prepareStatement("SELECT idconcursante FROM " + "concursante where idconcursante = "+id );
            ResultSet resultado = consulta.executeQuery();
            if(resultado.next())
                 return true;
        }
        catch(SQLException ex){
         throw new SQLException(ex);
      }
        return false;
    }

    public boolean existeNombre(String text) {
        try{
            PreparedStatement consulta;
            int last_num = 0;
            consulta = conn.prepareStatement("SELECT * FROM " + "usuario where nombre = '"+text+"'" );
            ResultSet resultado = consulta.executeQuery();
            try {
                if(resultado.next() && existe(resultado.getInt("idusuario")))
                    return true;
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(RegistroConcursante.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        catch(SQLException ex){
            try {
                throw new SQLException(ex);
            } catch (SQLException ex1) {
                Logger.getLogger(RegistroConcursante.class.getName()).log(Level.SEVERE, null, ex1);
            }
      }
        return false; //To change body of generated methods, choose Tools | Templates.
    }
}
