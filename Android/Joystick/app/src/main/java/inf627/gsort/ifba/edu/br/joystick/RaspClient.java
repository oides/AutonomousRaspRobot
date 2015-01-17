package inf627.gsort.ifba.edu.br.joystick;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

/**
 * Created by eudes on 17/01/15.
 */
public class RaspClient {

    private static final int SERVERPORT = 8888;
    private static final String SERVER_IP = "192.168.1.5";

    private Socket socket;

    public void sendMessage(String message) {
        try {
            socket.getOutputStream().write(stringToBytesASCII(message));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void init() {
        try {
            InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
            RaspClient.this.socket = new Socket(serverAddr, SERVERPORT);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void destroy() {
        try {
            RaspClient.this.socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private byte[] stringToBytesASCII(String str) {
        char[] buffer = str.toCharArray();
        byte[] b = new byte[buffer.length];
        for (int i = 0; i < b.length; i++) {
            b[i] = (byte) buffer[i];
        }
        return b;
    }
}
