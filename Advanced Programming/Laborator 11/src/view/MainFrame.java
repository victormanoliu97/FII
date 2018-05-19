package view;

import javax.swing.*;
import java.awt.*;

/**
 * @author Victor Manoliu on 16-May-18
 */
public class MainFrame extends JFrame {
    ControlPanel controlPanel;
    DesignPanel designPanel;

    public MainFrame() {
        super("Swing Designer");
        init();

        controlPanel = new ControlPanel(this);
        designPanel = new DesignPanel(this);
        setLayout(new java.awt.GridLayout(0, 2));

        this.add(designPanel);
        this.add(controlPanel);

    }

    private void init() {
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(800, 800));
        pack();
    }

    public static void main(String[] args) {
        MainFrame mainFrame = new MainFrame();
        mainFrame.setVisible(true);
    }
}