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
        long w = in.nextLong();
        long h = in.nextLong();

        long res = (w + 1) * w / 2 * (h + 1) * h / 2;

        out.println(res);
    }

}