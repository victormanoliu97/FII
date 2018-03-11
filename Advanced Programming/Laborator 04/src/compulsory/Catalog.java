package compulsory;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Catalog implements Serializable {

    private List<CatalogItem> catalogList;

    public Catalog() {
        catalogList = new ArrayList<CatalogItem>();
    }

    /**
     * Method for adding a book to the catalog
     *
     * @param book an object of the type book
     */

    public void add(Book book) {
        catalogList.add(book);
    }

    /**
     * Method for adding an article to the catalog
     *
     * @param article an object of type article
     */

    public void add(Article article) {
        catalogList.add(article);
    }

    /**
     * Method for adding a manual to the catalog
     *
     * @param manual an object of type manual
     */

    public void add(Manual manual) {
        catalogList.add(manual);
    }

    /**
     * Method for serializing an object to a certain path
     *
     * @param serializationPath the path to which to object should be serialized
     * @throws InvalidPathException custom exception for the path of serialization
     */

    public void save(String serializationPath) throws InvalidPathException {
        try {
            FileOutputStream fileOut = new FileOutputStream(serializationPath);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(this.catalogList);
            out.close();
            fileOut.close();

        } catch (IOException i) {
            i.printStackTrace();
        }
    }

    /**
     * Method for deserializing an object to a certain path
     *
     * @param deserializationPath the path to which to object should be deserialized
     * @throws InvalidPathException custom exception for the path of deserialization
     */

    public void load(String deserializationPath) throws InvalidPathException {
        try {
            FileInputStream fileIn = new FileInputStream(deserializationPath);
            ObjectInputStream in = new ObjectInputStream(fileIn);

            ArrayList<CatalogItem> catalogList = (ArrayList<CatalogItem>) in.readObject();
            this.catalogList = catalogList;

            in.close();
            fileIn.close();

        } catch (IOException i) {
            i.printStackTrace();
            return;
        } catch (ClassNotFoundException c) {
            c.printStackTrace();
            return;
        }
    }

    /**
     * Method for listing all catalog items
     */

    public void list() {
        for (CatalogItem i : catalogList) {
            System.out.println(i);
        }
    }

    /**
     * Open an object of type book using Desktop default program for that file
     *
     * @param book an object of type book
     * @throws InvalidPathException a custom exception for the path of the file
     */


    public void open(Book book) throws InvalidPathException {
        File file = new File(book.getItemPath());

        try {
            Desktop.getDesktop().open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Open an object of type manual using Desktop default program for that file
     *
     * @param manual an object of type manual
     * @throws InvalidPathException a custom exception for the path of the file
     */

    public void open(Manual manual) throws InvalidPathException {
        File file = new File(manual.getItemPath());

        try {
            Desktop.getDesktop().open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Open an object of type article using Desktop default program for that file
     *
     * @param article an object of type article
     * @throws InvalidPathException a custom exception for the path of the file
     */

    public void open(Article article) throws InvalidPathException {
        File file = new File(article.getItemPath());

        try {
            Desktop.getDesktop().open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
