package compulsory;

import java.io.Serializable;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Manual extends CatalogItem implements Serializable {

    /**
     * Creates a new instance of a manual
     *
     * @param manualTitle the manual title
     * @param manualPath  the path to the manual
     * @throws InvalidPathException an custom exception for the path of the manual
     */

    public Manual(String manualTitle, String manualPath) throws InvalidPathException {
        super(manualTitle, manualPath, 0, null);
    }

    /**
     * String representation of this object
     *
     * @return the string representation of the object
     */

    @Override
    public String toString() {
        return "Manual:" + " " + itemTitle + " " + itemPath;
    }
}
