package compulsory;

import java.lang.reflect.Type;
import java.util.Comparator;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Item {

    protected String itemName;
    protected int itemAttribute;
    protected int itemPrice;

    public Item(String itemName, int itemAttribute, int itemPrice) {
        this.itemName = itemName;
        this.itemAttribute = itemAttribute;
        this.itemPrice = itemPrice;
    }

    /**
     * Setter method for an item's name
     *
     * @param itemName the name of the item
     */
    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    /**
     * Setter method for an item's price
     *
     * @param itemPrice the price of an item
     */
    public void setItemPrice(int itemPrice) {
        this.itemPrice = itemPrice;
    }

    /**
     * Getter method for an item's name
     *
     * @return the name of the item
     */

    public String getItemName() {
        return itemName;
    }

    /**
     * Getter method for an item's price
     *
     * @return the price of the item
     */

    public int getItemPrice() {
        return itemPrice;
    }

    /**
     * Getter method for an item's specific attribute
     *
     * @return the specific attribute of an item
     */

    public int getItemAttribute() {
        return itemAttribute;
    }

    /**
     * Gets the string representation of an item
     * @return the string representation of an intem
     */

    public String toString() {
        return itemName + " " + itemAttribute + " " + itemPrice;
    }

    public static Comparator<Item> compareNames = new Comparator<Item>() {
        @Override
        public int compare(Item item1, Item item2) {
            String itemName1 = item1.getItemName();
            String itemName2 = item2.getItemName();

            if (itemName1 == null) {
                return (itemName2 == null) ? 0 : -1;
            }
            if (itemName2 == null) {
                return (itemName1 == null) ? 0 : -1;
            }
            return itemName1.compareTo(itemName2);
        }
    };

    public static Comparator<Item> compareProfits = new Comparator<Item>() {
        @Override
        public int compare(Item item1, Item item2) {
            int itemProfit1 = (item1.getItemAttribute()) / (item1.getItemPrice());
            int itemProfit2 = (item2.getItemAttribute()) / (item2.getItemPrice());

            return itemProfit1 - itemProfit2;
        }
    };
}
