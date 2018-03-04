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

    public Portofolio(GreedyAlgorithm greedyAlgorithm, List<Item> items, int maxValue) {
        this.items = items;
        this.greedyAlgorithm = greedyAlgorithm;
        this.maxValue = maxValue;
    }

    public Portofolio(RandomAlgorithm randomAlgorithm, List<Item> items, int maxValue) {
        this.items = items;
        this.randomAlgorithm = randomAlgorithm;
        this.maxValue = maxValue;
    }


    @Override
    public String toString() {
        return greedyAlgorithm.GreedyAlgorithmResolver(this.items, this.maxValue).printGreedySolution();
    }

    public String toStringRandom() {
        return randomAlgorithm.RandomAlgorithmResolver(this.items, this.maxValue).printRandomSolution();
    }

    public void printSolution() {
        greedyAlgorithm.printGreedySolution();
    }


}
