package magicsquare;

public class MagicSquare {

    public void generateMagicSquare(int n)
    {
       int i = 0;
       int j = n/2;
       int[][] magicSquare = new int[n][n];

       for(int it = 1; it<=n*n;)
       {
           magicSquare[i][j] = it++;
           i--;
           j++;

           if(i < 0 && j > n-1)
           {
               i += 2;
               j--;
           }
           if(i < 0)
           {
               i = n-1;
           }
           if(j > n-1)
           {
               j = 0;
           }
           if(magicSquare[i][j] > 0)
           {
               i = i+2;
               j--;
           }
       }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                System.out.print(magicSquare[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void printMagicConstant(int n)
    {
        int magicConstant = n * ((n * n + 1) / 2);
        System.out.println(magicConstant);
    }

}
