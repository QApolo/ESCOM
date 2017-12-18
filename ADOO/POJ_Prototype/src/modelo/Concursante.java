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
public class Concursante extends Persona{
 
    
    public Concursante(int id_us,String pass, String nom) {
        id_usuario = id_us;
        password = pass;
        nombre = nom;        
    }
    public Concursante(){
        
    }

    /**
     * @return the id_usuario
     */
    public int getId_usuario() {
        return id_usuario;
    }

    /**
     * @param id_usuario the id_usuario to set
     */
    public void setId_usuario(int id_usuario) {
        this.id_usuario = id_usuario;
    }

    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }   
}
