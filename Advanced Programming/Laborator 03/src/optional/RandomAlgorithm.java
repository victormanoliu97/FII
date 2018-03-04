package optional;

import compulsory.Item;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * @author Victor Manoliu on 04-Mar-18
 */
public class RandomAlgorithm implements Algorithm {

    private List<Item> items;
    private List<Item> solution;
    private int priceMaxVaue;
    private Random randomGenerator;

    public RandomAlgorithm() {
        items = new ArrayList<Item>();
        solution = new ArrayList<Item>();
        printRandomSolution();
    }

    public String printRandomSolution() {
        StringBuilder build = new StringBuilder();
        for (Item i : solution) {
            build.append(i.toString());
        }
        return build.toString();
    }

    private Item pickRandomItem() {
        int index = randomGenerator.nextInt(items.size());
        return items.get(index);
    }

    @Override
    public RandomAlgorithm RandomAlgorithmResolver(List<Item> items, int priceMaxValue) {
        int totalPrice = priceMaxValue;

        Item i = pickRandomItem();

        while (i.getItemPrice() <= totalPrice) {
            totalPrice = totalPrice - i.getItemPrice();
            solution.add(i);

            i = pickRandomItem();
        }

        this.items = solution;
        return this;
    }


    @Override
    public GreedyAlgorithm GreedyAlgorithmResolver(List<Item> items, int priceMaxValue) {
        return null;
    }

}
