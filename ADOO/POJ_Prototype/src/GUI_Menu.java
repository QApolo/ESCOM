
import java.io.IOException;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import metodos_estaticos.Servicio;
import servicios.ConexionConcurso;
import servicios.EvaluacionConcurso;
import servicios.RegistroProblemSetter;


public class GUI_Menu extends javax.swing.JFrame {

    public GUI_Menu() {
        initComponents();
        btn_registrar.setEnabled(false);
        
        System.out.println(EvaluacionConcurso.compararOutput("C:\\Users\\Carlo\\Downloads\\ProblemasPDF_Programacion\\Ainput.txt", "C:\\Users\\Carlo\\Downloads\\ProblemasPDF_Programacion\\Ainput.txt"));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btn_registrar = new javax.swing.JButton();
        btn_admin_problemas = new javax.swing.JButton();
        btn_part_concurso = new javax.swing.JButton();
        btn_tipo = new javax.swing.JButton();
        btn_crear_concurso = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        btn_registrar.setText("Registrar");
        btn_registrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_registrarActionPerformed(evt);
            }
        });

        btn_admin_problemas.setText("Administrar Problemas subidos");
        btn_admin_problemas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_admin_problemasActionPerformed(evt);
            }
        });

        btn_part_concurso.setText("Participar Concurso");
        btn_part_concurso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_part_concursoActionPerformed(evt);
            }
        });

        btn_tipo.setText("Tipo");
        btn_tipo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_tipoActionPerformed(evt);
            }
        });

        btn_crear_concurso.setText("Crear Concurso");
        btn_crear_concurso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_crear_concursoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(btn_crear_concurso, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(btn_registrar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btn_admin_problemas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btn_part_concurso, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addGap(28, 28, 28)
                .addComponent(btn_tipo)
                .addContainerGap(132, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btn_registrar)
                    .addComponent(btn_tipo))
                .addGap(29, 29, 29)
                .addComponent(btn_admin_problemas)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btn_part_concurso)
                .addGap(18, 18, 18)
                .addComponent(btn_crear_concurso)
                .addContainerGap(144, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btn_registrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_registrarActionPerformed

        switch(index-1)
       {
           case 0:
               this.setVisible(false);
               new GUI_RegistroUsuario().setVisible(true);
              // btn_registrar.setText("Registrar Concursante");
               break;
           case 1:
               this.setVisible(false);
               new GUI_RegistroProblemSetter().setVisible(true);
              // btn_registrar.setText("Registrar ProblemSetter");
               break;
           case 2:
               //btn_registrar.setText("Registrar Organizador");
               break;
       }
    }//GEN-LAST:event_btn_registrarActionPerformed

    int index = 0;
    private void btn_tipoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_tipoActionPerformed
       btn_registrar.setEnabled(true);
       switch(index)
       {
           case 0:
               btn_registrar.setText("Registrar Concursante");
               break;
           case 1:
               btn_registrar.setText("Registrar ProblemSetter");
               break;
           case 2:
               btn_registrar.setText("Registrar Organizador");
               break;
       }
       index = (index + 1) % 3;
    }//GEN-LAST:event_btn_tipoActionPerformed

    private void btn_admin_problemasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_admin_problemasActionPerformed
        
        int id = Integer.parseInt(JOptionPane.showInputDialog("Ingresa id de problem setter"));
        RegistroProblemSetter r1 = new RegistroProblemSetter();
        
        try {
            if(r1.existe(id) == true){
                this.setVisible(false);
                new GUI_NuevoProblema(id).setVisible(true);
            }
            else JOptionPane.showMessageDialog(null, "No existe id de problem setter");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_admin_problemasActionPerformed

    private void btn_part_concursoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_part_concursoActionPerformed
        
        ConexionConcurso con1 = new ConexionConcurso();
        int id_concurso = Integer.parseInt(JOptionPane.showInputDialog("Ingresa el id del concurso a participar"));
        try {
            if(con1.existe(id_concurso)){
               this.setVisible(false);
                new GUI_Concurso().setVisible(true);
            }
            else JOptionPane.showMessageDialog(null,"No existe un concurso con ese id asignado");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_part_concursoActionPerformed

    private void btn_crear_concursoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_crear_concursoActionPerformed
        this.setVisible(false);
        try {
            new GUI_CrearConcurso().setVisible(true);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(GUI_Menu.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_crear_concursoActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GUI_Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GUI_Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GUI_Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GUI_Menu.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new GUI_Menu().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btn_admin_problemas;
    private javax.swing.JButton btn_crear_concurso;
    private javax.swing.JButton btn_part_concurso;
    private javax.swing.JButton btn_registrar;
    private javax.swing.JButton btn_tipo;
    // End of variables declaration//GEN-END:variables
}
