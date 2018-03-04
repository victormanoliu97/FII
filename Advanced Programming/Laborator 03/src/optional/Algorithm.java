package optional;

import compulsory.Item;

import java.util.List;

/**
 * @author Victor Manoliu on 04-Mar-18
 */
public interface Algorithm {

    public GreedyAlgorithm GreedyAlgorithmResolver(List<Item> items, int priceMaxValue);

    public RandomAlgorithm RandomAlgorithmResolver(List<Item> items, int priceMaxValue);
}
