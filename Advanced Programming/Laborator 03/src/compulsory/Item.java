package compulsory;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Item {

    protected String itemName;
    protected int itemAttribute;
    protected int itemPrice;

    public Item(String itemName, int itemAttribute, int itemPrice)
    {
        this.itemName = itemName;
        this.itemAttribute = itemAttribute;
        this.itemPrice = itemPrice;
    }

    /**
     * Setter method for an item's name
     * @param itemName the name of the item
     */
    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    /**
     * Setter method for an item's price
     * @param itemPrice the price of an item
     */
    public void setItemPrice(int itemPrice) {
        this.itemPrice = itemPrice;
    }

    /**
     * Getter method for an item's name
     * @return the name of the item
     */

    public String getItemName() {
        return itemName;
    }

    /**
     * Getter method for an item's price
     * @return the price of the item
     */

    public int getItemPrice() {
        return itemPrice;
    }

    public String toString()
    {
        return itemName + " " + itemAttribute + " " + itemPrice;
    }
}
