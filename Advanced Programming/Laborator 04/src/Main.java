import compulsory.Book;
import compulsory.Catalog;
import compulsory.InvalidPathException;
import compulsory.Manual;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Main {

    public static void main(String[] args) throws InvalidPathException {

        //COMPULSORY PART
        Catalog catalog = new Catalog();

        try {

            Book b = new Book("Exceptions", "C:\\Users\\Victor Manoliu\\Desktop\\curs4.pdf", 2017, "Cristian Frasinaru");
            Manual m = new Manual("LR0", "C:\\Users\\Victor Manoliu\\Desktop\\LFAC07.doc");
            catalog.add(b);
            catalog.add(m);
            catalog.open(b);
            catalog.open(m);

        } catch (InvalidPathException e) {
            e.printStackTrace();
        }

        catalog.save("C:\\Users\\Victor Manoliu\\Desktop\\catalog.dat");
        catalog.load("C:\\Users\\Victor Manoliu\\Desktop\\catalog.dat");
        catalog.list();

    }
}
