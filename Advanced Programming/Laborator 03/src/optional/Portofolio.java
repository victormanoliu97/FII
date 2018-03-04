package optional;

import compulsory.Item;

import java.util.List;

/**
 * @author Victor Manoliu on 04-Mar-18
 */
public class Portofolio {

    private GreedyAlgorithm greedyAlgorithm;
    private RandomAlgorithm randomAlgorithm;
    private int maxValue;
    private List<Item> items;

    public Portofolio(GreedyAlgorithm greedyAlgorithm, int maxValue)
    {
        this.greedyAlgorithm = greedyAlgorithm;
        this.maxValue = maxValue;
    }

    public Portofolio(RandomAlgorithm randomAlgorithm, int maxValue)
    {
        this.randomAlgorithm = randomAlgorithm;
        this.maxValue = maxValue;
    }

    public void printSolution()
    {
        greedyAlgorithm.printGreedySolution();
    }

}
