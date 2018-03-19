package view;

import com.sun.deploy.panel.ControlPanel;

import javax.swing.*;
import java.awt.*;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class CatalogFrame extends JFrame {

    DocumentForm form;
    CatalogList list;
    ControlPanel control;


    public CatalogFrame() {
        super("Visual Document Manager");
        init();
    }

    private void init() {
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(700,600);
        setLayout(new BorderLayout());
        Container container = getContentPane();

        form = new DocumentForm();
        container.add(form);


    }
}
