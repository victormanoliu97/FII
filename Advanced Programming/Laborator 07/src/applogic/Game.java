package applogic;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Victor Manoliu on 06-Apr-18
 */
public class Game {
    private Bag bag;
    private Board board;
    private final List<Player> players = new ArrayList<>();

    public void addPlayer(Player player) {
        players.add(player);
        player.setGame(this);
    }

    public Bag getBag() {
        return bag;
    }

    public Board getBoard() {
        return board;
    }

    public List<Player> getPlayers() {
        return players;
    }

    public void setBag(Bag bag) {
        this.bag = bag;
    }

    public void setBoard(Board board) {
        this.board = board;
    }

    public void start() {
        for (Player player : players) {
            Thread t = new Thread(player);
            t.start();
        }
    }
}