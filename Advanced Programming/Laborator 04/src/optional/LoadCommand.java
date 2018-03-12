package optional;

import compulsory.Catalog;
import compulsory.InvalidPathException;

import java.util.List;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public class LoadCommand extends genericCommand implements CommandFunctionalities {

    public LoadCommand() {
        super();
    }

    @Override
    public void executeCommand(Catalog catalog) throws InvalidArgsException, InvalidPathException {

        if (commandArgs.size() < 1) {
            throw new InvalidArgsException("You need to specify a path to save");
        } else if (commandArgs.size() > 1) {
            throw new InvalidArgsException("Too many arguments");
        } else {
            catalog.load(commandArgs.get(1));
        }
    }

    @Override
    public void getArguments(List<String> commandArgs) {

        this.commandArgs = commandArgs;
    }
}
