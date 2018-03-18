package applogic;

import applogic.exceptions.InvalidPathException;
import applogic.exceptions.InvalidYearException;

import java.awt.*;
import java.io.File;
import java.io.IOException;
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
}
