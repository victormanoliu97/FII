package applogic;

import java.io.Serializable;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class Document implements Serializable {

    private String documentTitle;
    private String documentPath;
    private int documentYear;

    public Document(String documentTitle, String documentPath, int documentYear) {
        this.documentTitle = documentTitle;
        this.documentPath = documentPath;
        this.documentYear = documentYear;
    }

    public void setDocumentTitle(String documentTitle) {
        this.documentTitle = documentTitle;
    }

    public void setDocumentPath(String documentPath) {
        this.documentPath = documentPath;
    }

    public void setDocumentYear(int documentYear) {
        this.documentYear = documentYear;
    }

    public String getDocumentTitle() {
        return documentTitle;
    }

    public String getDocumentPath() {
        return documentPath;
    }

    public int getDocumentYear() {
        return documentYear;
    }

    @Override
    public String toString() {
        return "Document" + " " + documentTitle + " " + documentYear + " " + "[" + documentPath + "]";
    }
}
