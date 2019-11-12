import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            solve(in, out);
        }
    }

    void solve(Scanner in, PrintWriter out) {
        int volume = in.nextInt();
        int cover = in.nextInt();
        int start = in.nextInt();
        int end = in.nextInt();
        out.println(Math.abs(volume + (start - end) * (2 * cover + volume)));
    }

}