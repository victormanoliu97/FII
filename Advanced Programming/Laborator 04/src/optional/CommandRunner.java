package optional;

import compulsory.Catalog;
import compulsory.InvalidPathException;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public class CommandRunner {

    private Map<String, CommandFunctionalities> commands;
    private Catalog catalog;

    public CommandRunner(Catalog catalog) {
        this.catalog = catalog;
        commands = new HashMap<String, CommandFunctionalities>();

        commands.put("add", new AddCommand());
        commands.put("list", new ListCommand());
        commands.put("save", new SaveCommand());
        commands.put("load", new LoadCommand());
    }

    public void runCommand(List<String> commandArgs) throws InvalidPathException, InvalidArgsException {
        if (commandArgs.size() == 0) {
            throw new InvalidArgsException("You need to specify some arguments");
        } else {
            commands.get(commandArgs.get(0)).getArguments(commandArgs);

            try {
                commands.get(commandArgs.get(0)).executeCommand(catalog);
            } catch (InvalidPathException e) {
                e.printStackTrace();
            }
        }
    }

    public void setCatalog(Catalog catalog)
    {
        this.catalog = catalog;
    }

    public Catalog getCatalog() {
        return catalog;
    }
}
