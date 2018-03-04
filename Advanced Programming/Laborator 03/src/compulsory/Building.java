package compulsory;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Building extends Item implements Asset {

    /**
     * Builds a new instance of an object of type Bulding
     *
     * @param buildingName  the building name
     * @param buildingArea  the building available size to build
     * @param buildingPrice the building price
     */

    public Building(String buildingName, int buildingArea, int buildingPrice) {

        super(buildingName, buildingArea, buildingPrice);
    }


    /**
     * Setter method for a building's name
     *
     * @param buildingName the name of the building
     */

    public void setBuildingName(String buildingName) {
        this.itemName = buildingName;
    }

    /**
     * Setter method for a building's available area to build
     *
     * @param buildingArea the area of the building
     */

    public void setBuildingArea(int buildingArea) {
        this.itemAttribute = buildingArea;
    }

    /**
     * Setter method for a building's price
     *
     * @param buildingPrice the price of the bulding
     */

    public void setBuildingPrice(int buildingPrice) {
        this.itemPrice = buildingPrice;
    }

    /**
     * Getter method for building's name
     *
     * @return the name of the building
     */

    public String getBuildingName() {
        return itemName;
    }

    /**
     * Getter method for building's area
     *
     * @return the area of the building
     */

    public int getBuildingArea() {
        return itemAttribute;
    }

    /**
     * Getter method for building's price
     *
     * @return the price of the bulding
     */

    public int getBuildingPrice() {
        return itemPrice;
    }

    /**
     * Method for computing the profit of a building
     *
     * @return the computed profit
     */

    @Override
    public int computeProfit() {
        return getBuildingArea() / getBuildingPrice();
    }

    /**
     * Method for computing the profit of a building using the risk factor
     *
     * @return the computed profit using the risk factor
     */

    @Override
    public double computeProfitUsingRisk() {
        return (getBuildingArea() / getBuildingPrice()) * evaluateRisk();
    }


    /**
     * Gets the string representation of this object
     *
     * @return the string representation of this object
     */

    public String toString() {
        return "[Name: " + itemName + " Area:" + " " + itemAttribute + " Price: " + " " + itemPrice + "]";
    }
}
