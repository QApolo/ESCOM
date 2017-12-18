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
public class Problema {
    private int idProblema;
    private String rutaArchivo;
    private String nombre;
    private int id_problem_setter;
    private String ruta_input;
    private String ruta_output;
    
    
    public Problema(int idProblema, String rutaArchivo, String nombre, int id_problem_setter, String ruta_input, String ruta_output) {
        this.idProblema = idProblema;
        this.rutaArchivo = rutaArchivo;
        this.nombre = nombre;
        this.id_problem_setter = id_problem_setter;
        this.ruta_input = ruta_input;
        this.ruta_output = ruta_output;
    }

    public int getIdProblema() {
        return idProblema;
    }

    public String getRutaArchivo() {
        return rutaArchivo;
    }

    public String getNombre() {
        return nombre;
    }

    public int getId_problem_setter() {
        return id_problem_setter;
    }

    public String getRuta_input() {
        return ruta_input;
    }

    public String getRuta_output() {
        return ruta_output;
    }
    public Problema()
    {
        
    }

    public void setIdProblema(int idProblema) {
        this.idProblema = idProblema;
    }

    public void setRutaArchivo(String rutaArchivo) {
        this.rutaArchivo = rutaArchivo;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setId_problem_setter(int id_problem_setter) {
        this.id_problem_setter = id_problem_setter;
    }

    public void setRuta_input(String ruta_input) {
        this.ruta_input = ruta_input;
    }

    public void setRuta_output(String ruta_output) {
        this.ruta_output = ruta_output;
    }
}
