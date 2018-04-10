package applogic;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * @author Victor Manoliu on 06-Apr-18
 */
public class Bag {
    private final Queue<Character> letters = new LinkedList<>();

    public Bag() {
        for (int i = 0; i < 26; i++) {
            letters.add((char) ('a' + i));
        }
    }

    public synchronized List<Character> extractLetters(int howMany) {
        List<Character> extracted = new ArrayList<>();
        for (int i = 0; i < howMany; i++) {
            if (letters.isEmpty()) break;
            extracted.add(letters.poll());
        }
        return extracted;
    }

    public Queue<Character> getLetters() {
        return letters;
    }

}
