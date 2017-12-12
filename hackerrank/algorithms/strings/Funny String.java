import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String args[]) {
        Scanner in = new Scanner(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        public void solve(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            for (int j = 0; j < n; j++) {
                String s = in.next();
                boolean ok = true;
                for (int i = 1; i < s.length(); i++) {
                    if (Math.abs(s.charAt(i) - s.charAt(i - 1)) != Math.abs(s.charAt(s.length() - i - 1) - s.charAt(s.length() - i))) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    out.println("Funny");
                else
                    out.println("Not Funny");
            }
        }

    }
}