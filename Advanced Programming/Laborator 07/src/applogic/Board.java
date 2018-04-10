package applogic;

import java.util.*;

/**
 * @author Victor Manoliu on 06-Apr-18
 */
public class Board {

    private Map<Player,String> wordPlayerMap = Collections.synchronizedMap(new HashMap<>());

    public synchronized void addWord(Player player, String word)
    {
        System.out.println(player.getName() + " submited the word " + word + " ");
        wordPlayerMap.put(player , word);
    }
}
