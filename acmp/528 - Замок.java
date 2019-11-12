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
        long n = in.nextLong();
        long k = in.nextLong();
 
        long b = 3;
        long res = n * k * (1 + k) / 2 - (b + k - 2) * (k - 1);
 
        out.println(res);
    }
 
}