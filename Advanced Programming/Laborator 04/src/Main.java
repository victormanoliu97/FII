import compulsory.Book;
import compulsory.Catalog;
import compulsory.InvalidPathException;
import compulsory.Manual;
import optional.CommandRunner;
import optional.InvalidArgsException;

import java.sql.Array;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author Victor Manoliu on 10-Mar-18
 */
public class Main {

    public static void main(String[] args) throws InvalidPathException {

        //COMPULSORY PART
        Catalog catalog = new Catalog();

        try {

            Book b = new Book("Exceptions", "C:\\Users\\Victor Manoliu\\Desktop\\curs4.pdf", 2017, "Cristian Frasinaru");
            Manual m = new Manual("LR0", "C:\\Users\\Victor Manoliu\\Desktop\\LFAC07.doc");
            catalog.add(b);
            catalog.add(m);
            catalog.open(b);
            catalog.open(m);

        } catch (InvalidPathException e) {
            e.printStackTrace();
        }

        catalog.save("C:\\Users\\Victor Manoliu\\Desktop\\catalog.dat");
        catalog.load("C:\\Users\\Victor Manoliu\\Desktop\\catalog.dat");
        catalog.list();


        //OPTIONAL PART
        CommandRunner commandRunner = new CommandRunner(catalog);
        Scanner s = new Scanner(System.in);

        while (s.hasNextLine()) {
            String line = s.nextLine();
            String[] auxArgs = line.split(" ");
            List<String> commandArgs = Arrays.asList(auxArgs);

            try {
                commandRunner.runCommand(commandArgs);
            } catch (InvalidArgsException e) {
                e.printStackTrace();
            }
        }

    }
}
