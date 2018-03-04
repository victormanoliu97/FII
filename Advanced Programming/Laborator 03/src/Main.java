import compulsory.*;
import optional.GreedyAlgorithm;
import optional.Portofolio;

import java.lang.reflect.GenericArrayType;


/**
 * @author Victor Manoliu on 03-Mar-18
 */
public class Main {

    public static void main(String[] args) {

        //COMPULSORY PART
        Building h1 = new Building("House 1", 27, 9);
        Building h2 = new Building("House 2", 27, 9);
        Building h3 = new Building("House 3", 64, 16);
        Building h4 = new Building("House 4", 8, 8);

        Vehicle c1 = new Vehicle("Car 1", 8, 4);
        Vehicle c2 = new Vehicle("Car 2", 8, 4);

        Jewel j1 = new Jewel("Gold Diamond", 2);

        AssetManager manager = new AssetManager();
        manager.add(h1, h2, h3, h4);
        manager.add(c1, c2);
        manager.add(j1);

        System.out.println("Items sorted by the name: " + manager.getItems());
        System.out.println();


        //OPTIONAL PART
        System.out.println("Assets sorted by the profit: " + manager.getAssets());

        int maxValue = 20;
        Portofolio solution = manager.createPortofolio(new GreedyAlgorithm(), maxValue);
        System.out.println("The best portofolio: " + solution);

    }
}
