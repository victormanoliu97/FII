
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @author Victor Manoliu on 17-Apr-18
 */
public class GameServer {

    private static final int PORT = 8100;
    private ServerSocket serverSocket;
    private boolean running = false;

    public static void main(String[] args) {

        System.out.println("Server is running");

        GameServer server = new GameServer();
        server.init();
        server.waitForClients();

    }

    private void init() {
        try {
            running = true;
            serverSocket = new ServerSocket(PORT);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void waitForClients() {
        try {
            while (running) {
                Socket socket = serverSocket.accept();
                new ClientThread(socket).start();
            }
        } catch (IOException e) {
            e.printStackTrace();

        } finally {
            try {
                stop();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void stop() throws IOException {
        this.running = false;
        serverSocket.close();
        System.out.println("Server has stopped");
    }
}
