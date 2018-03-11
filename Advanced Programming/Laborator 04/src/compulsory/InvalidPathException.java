package compulsory;

/**
 * @author Victor Manoliu on 11-Mar-18
 */
public class InvalidPathException extends Exception {


    public InvalidPathException(String exceptionMessage) {
        super("Invalid path of the file");
    }

    public InvalidPathException(String exceptionMessage, Throwable cause) {
        super("Invalid path of the file", cause);
    }
}
