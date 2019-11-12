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
        int a = in.nextInt();
        int b = in.nextInt();
        int res = f(b) - f(a - 1);
        out.println(res);
    }

    int f(int x) {
        return (x + 1) / 2;
    }

}