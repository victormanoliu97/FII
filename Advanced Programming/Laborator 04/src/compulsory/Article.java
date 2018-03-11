package compulsory;

import java.io.Serializable;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Article extends CatalogItem implements Serializable {

    /**
     * Creates a new instance of a Article
     *
     * @param articleTitle  the article title
     * @param articlePath   the path to the article file
     * @param articleYear   the year in which the article appeared
     * @param articleAuthor the author of the article
     * @throws InvalidPathException custom exception for the path of the article file
     */

    public Article(String articleTitle, String articlePath, int articleYear, String articleAuthor) throws InvalidPathException {
        super(articleTitle, articlePath, articleYear, articleAuthor);
    }

    /**
     * String representation of the object
     *
     * @return the string representation of the object
     */

    @Override
    public String toString() {
        return "Article" + " " + itemTitle + " " + itemPath + " " + itemYear + " " + itemAuthor;
    }

}
