package optional;

import compulsory.AssetManager;
import compulsory.Item;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 04-Mar-18
 */
public class GreedyAlgorithm implements Algorithm {

    private List<Item> items;
    private List<Item> solution;
    private int priceMaxVaue;

    public GreedyAlgorithm() {
        items = new ArrayList<Item>();
        solution = new ArrayList<Item>();
        printGreedySolution();
    }

    public String printGreedySolution() {
        StringBuilder build = new StringBuilder();
        for (Item i : solution) {
            build.append(i.toString());
        }
        return build.toString();
    }

    @Override
    public GreedyAlgorithm GreedyAlgorithmResolver(List<Item> items, int priceMaxVaue) {

        int totalPrice = priceMaxVaue;

        for (Item i : items) {
            if (i.getItemPrice() <= totalPrice) {
                totalPrice = totalPrice - i.getItemPrice();
                solution.add(i);
            }
        }
        this.items = solution;
        return this;
    }

    @Override
    public RandomAlgorithm RandomAlgorithmResolver(List<Item> items, int priceMaxValue) {
        return null;
    }


}
