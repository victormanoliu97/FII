package compulsory;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Vehicle extends Item implements Asset {

    /**
     * Creates an instance of an object of Vehicle type
     *
     * @param vehicleName        the vehicle name
     * @param vehiclePerformance the vehicle performance
     * @param vehiclePrice       the vehicle price
     */

    public Vehicle(String vehicleName, int vehiclePerformance, int vehiclePrice) {

        super(vehicleName, vehiclePerformance, vehiclePrice);
    }

    /**
     * Setter method a vehicle name
     *
     * @param vehicleName the name of the vehicle
     */

    public void setVehicleName(String vehicleName) {
        this.itemName = vehicleName;
    }

    /**
     * Setter method for a vehicle performance
     *
     * @param vehiclePerformance the vehicle performance
     */

    public void setVehiclePerformance(int vehiclePerformance) {
        this.itemAttribute = vehiclePerformance;
    }

    /**
     * Setter method for a vehicle price
     *
     * @param vehiclePrice the price of the vehicle
     */

    public void setVehiclePrice(int vehiclePrice) {
        this.itemPrice = vehiclePrice;
    }

    /**
     * Getter method for the vehicle name
     *
     * @return the name of the vehicle
     */

    public String getVehicleName() {
        return itemName;
    }

    /**
     * Getter method for the vehicle performance
     *
     * @return the performance of the vehicle
     */

    public int getVehiclePerformance() {
        return itemAttribute;
    }

    /**
     * Getter method for the price of the vehicle
     *
     * @return the price of a vehicle
     */

    public int getVehiclePrice() {
        return itemPrice;
    }


    /**
     * Method for computing the profit of a building
     *
     * @return the computed profit
     */

    @Override
    public int computeProfit() {
        return getVehiclePerformance() / getVehiclePrice();
    }

    /**
     * Method for computing the profit of a vehicle using the risk factor
     *
     * @return the computed profit using the risk factor
     */

    @Override
    public double computeProfitUsingRisk() {
        return (getVehiclePerformance() / getVehiclePrice()) * evaluateRisk();
    }

    /**
     * Returns the string representation of this object
     *
     * @return the string representation of this object
     */

    public String toString() {
        return "[Name: " + itemName + " Performance:" + " " + itemAttribute + " Price: " + " " + itemPrice + "]";
    }
}
