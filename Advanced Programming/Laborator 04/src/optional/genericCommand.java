package optional;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 12-Mar-18
 */
public abstract class genericCommand {

    public List<String> commandArgs;

    public genericCommand()
    {
        commandArgs = new ArrayList<String>();
    }

    void getArguments(List<String> commandArgs)
    {
        this.commandArgs = commandArgs;
    }
}
