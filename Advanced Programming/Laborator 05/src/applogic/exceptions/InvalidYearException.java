package applogic.exceptions;

/**
 * @author Victor Manoliu on 17-Mar-18
 */
public class InvalidYearException extends Exception {

    public InvalidYearException(String exceptionMessage) {
        super(exceptionMessage);
    }

    public InvalidYearException(String exceptionMessage, Throwable cause) {
        super(exceptionMessage, cause);
    }
}
