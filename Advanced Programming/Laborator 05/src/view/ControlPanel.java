package view;

import javax.swing.*;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class ControlPanel extends JPanel {

    private final CatalogFrame frame;
    JButton loadBtn = new JButton("Load");
    JButton addBtn = new JButton("Add");
    JButton saveBtn = new JButton("Save");

    public ControlPanel(CatalogFrame frame) {
        this.frame = frame;
        init();
    }
    private void init() {
        add(loadBtn);
        add(addBtn);
        add(saveBtn);
    }

}
