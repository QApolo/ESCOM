package servicios;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlo
 */
public class ConexionProblema {
    
   public ArrayList<String> getList() throws ClassNotFoundException, SQLException {
         ArrayList<String> nombres = new ArrayList<>();
         String nom;
         try{
            
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://localhost/mydb";
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "root");    

            PreparedStatement consulta;
            int last_num = 0;
            consulta = conn.prepareStatement("SELECT nombre FROM " + "problema" );
            ResultSet resultado = consulta.executeQuery();
                
            System.out.println("hola mundo");
            while(resultado.next())
            {
               nom = resultado.getString("nombre");
               nombres.add(nom);
               System.out.println(nom);
            }
            return nombres;
        

        }
        catch(SQLException ex){
         throw new SQLException(ex);
      }
        
       
    }
    
}
