import applogic.Catalog;
import applogic.Document;
import view.CatalogFrame;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class Main {

    public static void main(String[] args) {

        /*
        Catalog catalog = new Catalog();

        catalog.addDocument(new Document("TitluTest", "TestPath", 2017));

        catalog.listDocuments();
        */

        new CatalogFrame().setVisible(true);

    }
}
