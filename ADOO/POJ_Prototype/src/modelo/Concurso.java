/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modelo;

import java.sql.Date;

/**
 *
 * @author Carlo
 */
public class Concurso {
    private int idConcurso;
    Date fecha_inicio;
    Date fecha_fin;
    private int idOrganizador;

    public Concurso(int idConcurso, Date fecha_inicio, Date fecha_fin, int idOrganizador) {
        this.idConcurso = idConcurso;
        this.fecha_inicio = fecha_inicio;
        this.fecha_fin = fecha_fin;
        this.idOrganizador = idOrganizador;
    }

    public void setIdConcurso(int idConcurso) {
        this.idConcurso = idConcurso;
    }

    public void setFecha_inicio(Date fecha_inicio) {
        this.fecha_inicio = fecha_inicio;
    }

    public void setFecha_fin(Date fecha_fin) {
        this.fecha_fin = fecha_fin;
    }

    public void setIdOrganizador(int idOrganizador) {
        this.idOrganizador = idOrganizador;
    }

    public int getIdConcurso() {
        return idConcurso;
    }

    public Date getFecha_inicio() {
        return fecha_inicio;
    }

    public Date getFecha_fin() {
        return fecha_fin;
    }

    public int getIdOrganizador() {
        return idOrganizador;
    }
}
