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
            int cnt[] = new int[26];
            for (int i = 1; i <= n; i++) {
                String stone = in.next();
                for (int j = 0; j < stone.length(); j++)
                    if (cnt[stone.charAt(j)-'a'] == i-1)
                        cnt[stone.charAt(j)-'a']++;
            }
            int res = 0;
            for (int i = 0; i < 26; i++)
                if (cnt[i] == n)
                    res++;
            out.print(res);
        }

    }
}