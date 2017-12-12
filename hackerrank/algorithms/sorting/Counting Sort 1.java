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
            int cnt[] = new int[105];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                cnt[x]++;
            }
            for (int i = 0; i < 100; i++)
                out.print(cnt[i] + " ");
        }

    }
}