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

    public GreedyAlgorithm()
    {
        items = new ArrayList<Item>();
        solution = new ArrayList<Item>();
        GreedyAlgorithmResolver();
        printGreedySolution();
    }

    public void printGreedySolution()
    {
        for(Item i : solution)
        {
            System.out.println(i.toString());
        }
    }

    @Override
    public List<Item> GreedyAlgorithmResolver() {
        AssetManager manager = new AssetManager();

        int totalPrice = priceMaxVaue;

        items = manager.getAssets();

        for(Item i : items)
        {
            if(i.getItemPrice() <= totalPrice)
            {
                totalPrice = totalPrice - i.getItemPrice();
                solution.add(i);
            }
        }
        return solution;
    }

    @Override
    public List<Item> RandomAlgorithmResolver() {
        return null;
    }
}
