package compulsory;

import java.util.Comparator;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class ItemSorter implements Comparator<Item> {

    public int compare(Item item1, Item item2) {

        String itemName1 = item1.getItemName();
        String itemName2 = item2.getItemName();

        if(itemName1 == null)
        {
            return (itemName2 == null) ? 0 : -1;
        }
        if(itemName2 == null)
        {
            return (itemName1 == null) ? 0 : -1;
        }
        return itemName1.compareTo(itemName2);
    }
}
