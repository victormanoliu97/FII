import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author Victor Manoliu on 17-Apr-18
 */
public class ClientThread extends Thread {

    private Socket socket;
    private String generatedNumber;
    private int attemptsCounter;

    public ClientThread(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            while (true) {
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String request = in.readLine();
                String response = execute(request);
                PrintWriter out = new PrintWriter(socket.getOutputStream());
                out.println(response);
                out.flush();
                System.out.println("Message: " + "'" + request + "'" + " was received with success");
                System.out.println("Message: " + "'" + execute(request) + "'" + " was send with success to the client");
            }

        } catch (IOException e) {
            e.printStackTrace();
//        } finally {
//
//            try {
//                socket.close();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
        }
    }

    private String execute(String request) {
        //return "Server received the request" + " " + request;
        if (request.equals("create")) {
            generatedNumber = Integer.toString(new Random().nextInt(100));
            return "The maximum number is: " + Integer.toString(100);

        } else if (request.equals("quit")) {
            return "Loser, the number was: " + generatedNumber;

        } else if (countOccurences(request) == 1) {
            String[] strings = request.split(" ");

            if (Integer.parseInt(strings[1]) < Integer.parseInt(generatedNumber)) {
                attemptsCounter++;
                return "Too low";
            } else if (Integer.parseInt(strings[1]) < Integer.parseInt(generatedNumber)) {
                attemptsCounter++;
                return "Too big";
            } else {
                return "You got it in " + Integer.toString(attemptsCounter) + " attempts";
            }
        } else {
            return "Command not found";
        }
    }

    private int countOccurences(String findStr) {
        Pattern pattern = Pattern.compile("submit");
        Matcher matcher = pattern.matcher(findStr);
        int count = 0;

        while (matcher.find()) {
            count++;
        }
        return count;
    }
}

