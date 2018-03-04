package optional;

import compulsory.Item;

import java.util.List;

/**
 * @author Victor Manoliu on 04-Mar-18
 */
public interface Algorithm {

    public List<Item> GreedyAlgorithmResolver();

    public List<Item> RandomAlgorithmResolver();
}
