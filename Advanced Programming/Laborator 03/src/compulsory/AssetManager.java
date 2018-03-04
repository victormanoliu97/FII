package compulsory;

import optional.Algorithm;
import optional.GreedyAlgorithm;
import optional.Portofolio;
import optional.RandomAlgorithm;

import javax.sound.sampled.Port;
import java.util.*;
import java.util.concurrent.CompletionException;


/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class AssetManager {

    private List<Item> items;

    public AssetManager() {
        items = new ArrayList<Item>();
    }

    /**
     * Adds a new object of type building to the list of items
     *
     * @param buildings the list of buildings to be added
     */

    public void add(Building... buildings) {
        for (Building b : buildings) {
            items.add(b);
        }
    }

    /**
     * Adds a new object of type vehicles to the list of items
     *
     * @param vehicles the list of vehicles to be added
     */

    public void add(Vehicle... vehicles) {
        for (Vehicle v : vehicles) {
            items.add(v);
        }
    }

    /**
     * Adds a new object of type jewels to the list of items
     *
     * @param jewels the list of jewels to be added
     */

    public void add(Jewel... jewels) {
        for (Jewel j : jewels) {
            items.add(j);
        }
    }

    /**
     * Helper method for removing an object that is not an Asset from the list of item
     *
     * @return the item list without all the object that are not Asset
     */

    public List<Item> removeNonAsset() {
        Iterator<Item> it = items.iterator();

        while (it.hasNext()) {
            Item nextItem = it.next();

            if (nextItem.getItemAttribute() == 0) {
                it.remove();
            }
        }
        return items;
    }

    /**
     * Sorts the list of items in ascending order by the item name
     *
     * @return the list of items in ascending order by their names
     */

    public List<Item> getItems() {
        Collections.sort(items, Item.compareNames);
        return items;
    }

    /**
     * Sorts the list of items in ascending order by the item's profit
     *
     * @return the list of items in ascending order by their profits
     */

    public List<Item> getAssets() {
        removeNonAsset();
        Collections.sort(items, Item.compareProfits);
        return items;
    }

    public Portofolio createPortofolio(GreedyAlgorithm algorithm, int maxValue) {
        Portofolio p = new Portofolio(algorithm, items, maxValue);

        return p;
    }

    public Portofolio createPortofolio(RandomAlgorithm algorithm, int maxValue) {
        Portofolio p = new Portofolio(algorithm, items, maxValue);

        return p;
    }

    public void printPortofolioSolution(Portofolio p) {
        p.printSolution();
    }
}
