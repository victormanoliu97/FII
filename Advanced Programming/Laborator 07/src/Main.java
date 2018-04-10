import applogic.Bag;
import applogic.Board;
import applogic.Game;
import applogic.Player;

/**
 * @author Victor Manoliu on 06-Apr-18
 */
public class Main {

    public static void main(String[] args) {

        Game game = new Game();
        game.setBag(new Bag());
        game.setBoard(new Board());
        game.addPlayer(new Player("Player 1"));
        game.addPlayer(new Player("Player 2"));
        game.addPlayer(new Player("Player 3"));
        game.start();
    }
}
