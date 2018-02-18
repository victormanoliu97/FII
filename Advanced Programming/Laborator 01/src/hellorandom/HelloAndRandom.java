package hellorandom;

public class HelloAndRandom {


    private int n;

    public static void printWelcome()
    {
        System.out.println("Welcome");
    }

    public int generateRandom()
    {
        n = (int)(Math.random() * 1_000_000);

        return n;
    }

    public int computeRandom()
    {
        int result;
        int bin2Decimal = Integer.parseInt("10101", 2);
        int hex2Decimal = Integer.parseInt("FF", 16);
        n = generateRandom();

        result = n*3;
        result += bin2Decimal;
        result += hex2Decimal;
        result *= 6;

        return result;
    }

    public int sumDigitsNumber(int x)
    {
        int result = 0;

        while(x > 0)
        {
            result += x%10;
            x = x/10;
        }
        return result;
    }

    public int computeDigits()
    {
        int sum = 0;
        int auxSum = 0;
        n = computeRandom();
        
        sum = sumDigitsNumber(n);

        if(sum > 9)
        {
            auxSum = sumDigitsNumber(sum);
        }

        if(auxSum <= 9)
        {
            return auxSum;
        }
        else
        {
            return sum;
        }
    }


    public void displayMessage()
    {
        String s = "C C++ C# Go Javascript Perl PHP Python Swift Java";
        String languages[];

        int result = computeDigits();

        languages = s.split("\\s+");

        for(int i=0; i<languages.length; i++)
        {
            languages[i] = languages[i].replace("[^\\w]", "");
        }

        System.out.println("Willy-nilly, this semester I will learn " + languages[result-1]);
    }
}
