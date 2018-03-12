package optional;

import compulsory.*;

import java.util.List;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public interface CommandFunctionalities {

    void executeCommand(Catalog catalog) throws InvalidArgsException, InvalidPathException;

    void getArguments(List<String> commandArgs);

}
