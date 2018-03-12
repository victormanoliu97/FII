package optional;

import compulsory.InvalidPathException;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public class InvalidArgsException extends Exception {

    public InvalidArgsException(String exceptionMessage) {
        super("The arguments are invalid");
    }

    public InvalidArgsException(String exceptionMessage, Throwable cause) {
        super("The arguments are invalid", cause);
    }


}
