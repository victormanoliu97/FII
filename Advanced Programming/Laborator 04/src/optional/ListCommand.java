package optional;

import compulsory.Catalog;
import compulsory.InvalidPathException;

import java.util.List;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public class ListCommand extends genericCommand implements CommandFunctionalities {

    public ListCommand() {
        super();
    }


    @Override
    public void executeCommand(Catalog catalog) throws InvalidArgsException, InvalidPathException {

        catalog.list();
    }

    @Override
    public void getArguments(List<String> commandArgs) {

        this.commandArgs = commandArgs;
    }
}
