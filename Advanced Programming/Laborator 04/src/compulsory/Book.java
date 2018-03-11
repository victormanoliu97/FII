package compulsory;

import java.io.Serializable;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Book extends CatalogItem implements Serializable {

    /**
     * Creates a new instance of a book object
     *
     * @param bookTitle  the book title
     * @param bookPath   the path to the book
     * @param bookYear   the year of book appeared
     * @param bookAuthor the book author
     * @throws InvalidPathException custom exception for the path of the book
     */

    public Book(String bookTitle, String bookPath, int bookYear, String bookAuthor) throws InvalidPathException {

        super(bookTitle, bookPath, bookYear, bookAuthor);
    }

    /**
     * String representation of the object
     *
     * @return the string representation of the object
     */

    @Override
    public String toString() {
        return "Book:" + " " + itemTitle + " " + itemPath + " " + itemYear + " " + itemAuthor;
    }
}
