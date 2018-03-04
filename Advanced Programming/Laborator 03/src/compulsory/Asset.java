package compulsory;

/**
 * @author Victor Manoliu on 03-Mar-18
 */
public interface Asset {

    public int computeProfit();

    default double evaluateRisk()
    {
        double riskFactor = 0.5;
        return riskFactor;
    }

    public double computeProfitUsingRisk();

}
