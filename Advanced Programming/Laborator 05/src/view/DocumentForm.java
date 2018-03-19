package view;

import applogic.Catalog;
import applogic.Document;
import applogic.exceptions.InvalidPathException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class DocumentForm extends JPanel {

    //private final CatalogFrame frame = new CatalogFrame();

    JLabel titleLabel;
    JLabel titleLabel2;
    JLabel titleLabel3;

    JButton addBtn;
    JButton saveBtn;
    JButton loadBtn;
    JButton openBtn;

    JSpinner yearField = new JSpinner(
            new SpinnerNumberModel(1950, 1900, 2017, 1));

    JTextField documentNameTxtField;
    JTextField documentPathTxtField;

    private String documentTitle;
    private String documentPath;
    private int documentYear;


    public DocumentForm() {
        init();
    }

    private void init() {

        Catalog catalog = new Catalog();
        CatalogList catalogList = new CatalogList();

        titleLabel = new JLabel("Title of the document");
        titleLabel2 = new JLabel("Path in the local file system");
        titleLabel3 = new JLabel("Publication Year");
        documentPathTxtField = new JTextField();
        documentNameTxtField = new JTextField();
        addBtn = new JButton("Add");
        saveBtn = new JButton("Save");
        loadBtn = new JButton("Load");
        openBtn = new JButton("Open");

        setLayout(new GridLayout(6, 2));
        add(titleLabel);
        add(documentNameTxtField);
        add(titleLabel2);
        add(documentPathTxtField);
        add(titleLabel3);
        add(yearField);
        add(addBtn);
        add(saveBtn);
        add(loadBtn);
        add(openBtn);
        add(catalogList);

        addBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                documentTitle = documentNameTxtField.getText();
                documentPath = documentPathTxtField.getText();
                documentYear = (Integer) yearField.getValue();

                catalog.addDocument(new Document(documentTitle, documentPath, documentYear));
                catalog.listDocuments();
            }
        });

        openBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                documentTitle = documentNameTxtField.getText();
                documentPath = documentPathTxtField.getText();
                documentYear = (Integer) yearField.getValue();

                try {
                    catalog.openDocument(new Document(documentTitle, documentPath, documentYear));
                } catch (InvalidPathException e1) {
                    e1.printStackTrace();
                }
            }
        });

        saveBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inputSerializationPath = JOptionPane.showInputDialog(new JFrame(), "Path to save", null);

                try {
                    catalog.saveDocument(inputSerializationPath);
                } catch (InvalidPathException e1) {
                    e1.printStackTrace();
                }
            }
        });

        loadBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String inputDeserializationPath = JOptionPane.showInputDialog(new JFrame(), "Path to load", null);

                try {
                    catalogList.addDocument(catalog.loadDocument(inputDeserializationPath));
                } catch (InvalidPathException e1) {
                    e1.printStackTrace();
                }

            }
        });

    }

    private void addDocument() {
        //frame.list.addDocument();
    }

}
