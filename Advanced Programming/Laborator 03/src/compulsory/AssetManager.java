package compulsory;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
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
     * @param buildings the list of buildings to be added
     */

    public void add(Building... buildings) {
        for (Building b : buildings) {
            items.add(b);
        }
    }

    /**
     * Adds a new object of type vehicles to the list of items
     * @param vehicles the list of vehicles to be added
     */

    public void add(Vehicle... vehicles) {
        for (Vehicle v : vehicles) {
            items.add(v);
        }
    }

    /**
     * Adds a new object of type jewels to the list of items
     * @param jewels the list of jewels to be added
     */

    public void add(Jewel... jewels) {
        for (Jewel j : jewels) {
            items.add(j);
        }
    }

    /**
     * Sorts the list of items in ascending order by the item name
     * @return the list of items in ascending order by their names
     */

    public List<Item> getItems() {
        ItemSorter comparator = new ItemSorter();
        Collections.sort(items, comparator);
        return items;
    }
}
