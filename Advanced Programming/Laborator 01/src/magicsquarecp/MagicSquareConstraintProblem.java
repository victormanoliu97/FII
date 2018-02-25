package magicsquarecp;
import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solver;
import org.chocosolver.solver.constraints.IIntConstraintFactory;
import org.chocosolver.solver.variables.IntVar;
import org.chocosolver.util.tools.ArrayUtils;
import java.util.Arrays;

public class MagicSquareConstraintProblem {

    /* Created by Manoliu Victor-Codrin */

    public int magicConstant;

    public int n = 5;

    public IntVar[][] magicSquare = new IntVar[n][n];

    Model model = new Model(n+ "magic square constraint");

    public int getMagicConstant(int n)
    {
        return n * (n * n + 1) / 2;
    }

    public void buildMagicSquareCPModel()
    {
        IntVar[] matrixValues = new IntVar[n];
        IntVar[][] transposeMatrix = new IntVar[n][n];
        IntVar[] matrixLineValues = new IntVar[n];
        IntVar[] matrixColumnValues = new IntVar[n];
        magicConstant = getMagicConstant(n);

        int[] coefficients = new int[n];
        Arrays.fill(coefficients,1);

        int k = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++, k++)
            {
                transposeMatrix[j][i] = magicSquare[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrixLineValues[i] = magicSquare[i][j];
            }
        }

        for(int j=0; j<n; j++)
        {
            for(int i=0; i<n; i++)
            {
                matrixColumnValues[i] = magicSquare[i][j];
            }
        }

        IntVar principalDiagonal[] = new IntVar[n];
        IntVar secondaryDiagonal[] = new IntVar[n];

        for(int i=0; i<n; i++)
        {
            principalDiagonal[i] = magicSquare[i][i];
            secondaryDiagonal[i] = magicSquare[(n-1)-i][i];
        }

        model.allDifferent(matrixValues);

        model.sum(matrixLineValues, "=", magicConstant);
        model.sum(matrixColumnValues, "=", magicConstant);


        model.scalar(principalDiagonal, coefficients, "=", magicConstant);
        model.scalar(secondaryDiagonal, coefficients, "=", magicConstant);

        model.arithm(magicSquare[0][n-1], "<" ,magicSquare[n-1][0]);
        model.arithm(magicSquare[0][0], "<", magicSquare[n-1][n-1]);
        model.arithm(magicSquare[0][0], "<", magicSquare[n-1][0]);

    }

    public void printMagicSquareCP()
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                System.out.println(magicSquare[i][j] + " ");
            }
            System.out.println();
        }
    }

}
