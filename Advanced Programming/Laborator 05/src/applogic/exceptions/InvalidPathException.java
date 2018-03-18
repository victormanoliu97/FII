package applogic.exceptions;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class InvalidPathException extends Exception {

    public InvalidPathException(String exceptionMessage)
    {
        super(exceptionMessage);
    }

    public InvalidPathException(String exceptionMessage, Throwable cause)
    {
        super(exceptionMessage, cause);
    }
}
