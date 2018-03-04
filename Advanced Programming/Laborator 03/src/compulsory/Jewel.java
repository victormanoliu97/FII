package compulsory;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Jewel extends Item {

    /**
     * Creates a new instance of the Jewel class
     *
     * @param jewelName  the name of a jewel
     * @param jewelPrice the price of a jewel
     */
    public Jewel(String jewelName, int jewelPrice) {

        super(jewelName, 0, jewelPrice);
    }

    /**
     * Setter method for the name of a jewel
     *
     * @param jewelName the name of a jewel
     */

    public void setJewelName(String jewelName) {
        this.itemName = jewelName;
    }


    /**
     * Setter method for the price of a jewel
     *
     * @param jewelPrice the price of a jewel
     */

    public void setJewelPrice(int jewelPrice) {
        this.itemPrice = jewelPrice;
    }


    /**
     * Getter method for the name of a jewel
     *
     * @return the name of a jewel
     */

    public String getJewelName() {
        return itemName;
    }


    /**
     * Getter method for the price of a jewel
     *
     * @return the price of a jewel
     */

    public int getJewelPrice() {
        return itemPrice;
    }

    /**
     * Returns the string representation of this object
     *
     * @return the string representation of this object
     */

    public String toString() {
        return "[Name: " + itemName + " " + "Price: " + itemPrice + "]";
    }
}
