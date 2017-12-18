/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modelo;

/**
 *
 * @author Carlo
 */
public class ProblemSetter extends Persona{
    public ProblemSetter(String nom, String pass, int id)
    {
        nombre = nom;
        password = pass;
        id_usuario = id;
    }

    public String getNombre() {
       return nombre; //To change body of generated methods, choose Tools | Templates.
    }

    public String getPassword() {
       return password; //To change body of generated methods, choose Tools | Templates.
    }
    public int getId()
    {
        return id_usuario;
    }
}
