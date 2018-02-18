import hellorandom.HelloAndRandom;
import magicsquare.MagicSquare;

public class Main {

    public static void main(String[] args) {

        //COMPULSORY PART
        long startTime = System.currentTimeMillis();

        HelloAndRandom test = new HelloAndRandom();

        test.printWelcome();
        System.out.println("First generated number");
        System.out.println(test.generateRandom());
        System.out.println("Computed number");
        System.out.println(test.computeRandom());
        System.out.println("Computed digits of the number");
        System.out.println(test.computeDigits());
        test.displayMessage();
        System.out.println();


        //OPTIONAL PART
        MagicSquare matrix = new MagicSquare();

        if(args.length != 1)
        {
            System.out.println("Invalid number of arguments");
            System.exit(-1);
        }
        int n = Integer.parseInt(args[0]);

        if(n % 2 == 0)
        {
            System.out.println("Number must be odd");
            System.exit(-1);
        }

        if( n <= 10)
        {
            System.out.println("The magic constant for the magic square");
            matrix.printMagicConstant(n);
            System.out.println("The generated magic square");
            matrix.generateMagicSquare(n);
        }
        else if(n > 5000)
        {
            System.out.println("The magic constant for the magic square");
            matrix.printMagicConstant(n);
            long endTime = System.currentTimeMillis();
            System.out.printf("The application running time is:" + (endTime - startTime));
        }

    }
}
