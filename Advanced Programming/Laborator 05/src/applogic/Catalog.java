package applogic;

import applogic.exceptions.InvalidPathException;
import applogic.exceptions.InvalidYearException;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class Catalog {

    private List<Document> documentList;

    public Catalog() {
        documentList = new ArrayList<Document>();
    }

    public void addDocument(Document document) {
        documentList.add(document);
    }

    public void listDocuments() {
        for (Document d : documentList) {
            System.out.println(d);
        }
    }

    public void openDocument(Document document) throws InvalidPathException {
        File file = new File(document.getDocumentPath());

        try {
            Desktop.getDesktop().open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void saveDocument(String serializationPath) throws InvalidPathException {
        try {
            FileOutputStream fileOut = new FileOutputStream(serializationPath);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(this.documentList);
            out.close();
            fileOut.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String loadDocument(String deserializationPath) throws InvalidPathException {
        try {
            FileInputStream fileIn = new FileInputStream(deserializationPath);
            ObjectInputStream in = new ObjectInputStream(fileIn);

            ArrayList<Document> documentList = (ArrayList<Document>)in.readObject();
            this.documentList = documentList;

            in.close();
            fileIn.close();

        } catch (IOException i) {
            i.printStackTrace();
        } catch (ClassNotFoundException c) {
            c.printStackTrace();
        }

        return String.valueOf(documentList.toString());
    }
}
