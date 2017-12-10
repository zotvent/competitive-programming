import java.io.*;
import java.util.Scanner;

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
            String s = in.nextLine();
            int cnt[] = new int[26];
            for (char c : s.toCharArray()) {
                if (Character.isAlphabetic(c)) {
                    cnt[Character.toLowerCase(c)-'a']++;
                }
            }
            for (int letterCounter : cnt) {
                if (letterCounter == 0) {
                    out.print("not pangram");
                    return;
                }
            }
            out.print("pangram");
        }

    }
}