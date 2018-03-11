package compulsory;

import java.io.Serializable;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class CatalogItem implements Serializable {

    protected String itemTitle;
    protected String itemPath;
    protected int itemYear;
    protected String itemAuthor;

    /**
     * Creates a new instance of a catalog item
     *
     * @param itemTitle  the title of a catalog item
     * @param itemPath   the path of a catalog item
     * @param itemYear   the year in which a catalog item appeared
     * @param itemAuthor the author of that catalog
     * @throws InvalidPathException a custom exception for the path of the catalog item
     */

    public CatalogItem(String itemTitle, String itemPath, int itemYear, String itemAuthor) throws InvalidPathException {
        this.itemTitle = itemTitle;
        this.itemPath = itemPath;
        this.itemYear = itemYear;
        this.itemAuthor = itemAuthor;
    }

    public void setItemTitle(String itemTitle) {
        this.itemTitle = itemTitle;
    }

    public void setItemPath(String itemPath) {
        this.itemPath = itemPath;
    }

    public void setItemYear(int itemYear) {
        this.itemYear = itemYear;
    }

    public void setItemAuthor(String itemAuthor) {
        this.itemAuthor = itemAuthor;
    }

    public String getItemTitle() {
        return itemTitle;
    }

    public String getItemPath() {
        return itemPath;
    }

    public int getItemYear() {
        return itemYear;
    }

    public String getItemAuthor() {
        return itemAuthor;
    }

    /**
     * String representation of a catalog item
     *
     * @return the string representation
     */

    @Override
    public String toString() {
        return "Book:" + " " + itemTitle + " " + itemPath + " " + itemYear + " " + itemAuthor;
    }
}
