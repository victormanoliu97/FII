package optional;

import compulsory.*;

import java.util.List;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public class AddCommand extends genericCommand implements CommandFunctionalities {

    public AddCommand() {
        super();
    }

    @Override
    public void executeCommand(Catalog catalog) throws InvalidArgsException, InvalidPathException {

        if (commandArgs.get(1).equals("book")) {
            if (commandArgs.size() < 4) {
                throw new InvalidArgsException("The number of arguments is too low. You need to specify 4 arguments");
            } else {
                catalog.add(new Book(commandArgs.get(1), commandArgs.get(2), Integer.parseInt(commandArgs.get(3)), commandArgs.get(4)));
            }
        } else if (commandArgs.get(1).equals("article")) {
            if (commandArgs.size() < 4) {
                throw new InvalidArgsException("The number of arguments is too low. You need to specify 4 arguments");
            } else {
                catalog.add(new Article(commandArgs.get(1), commandArgs.get(2), Integer.parseInt(commandArgs.get(3)), commandArgs.get(4)));
            }
        } else if (commandArgs.get(1).equals("manual")) {
            if (commandArgs.size() < 2) {
                throw new InvalidArgsException("The number of arguments is too low, You need to specify 2 arguments");
            } else {
                catalog.add(new Manual(commandArgs.get(1), commandArgs.get(2)));
            }
        }
    }

    @Override
    public void getArguments(List<String> commandArgs) {

        this.commandArgs = commandArgs;
    }
}
