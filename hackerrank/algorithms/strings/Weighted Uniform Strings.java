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
            String s = in.next();
            int weight[] = new int[s.length()];
            Set<Integer> set = new HashSet<Integer>();
            weight[0] = s.charAt(0)-'a'+1;
            set.add(weight[0]);
            for (int i = 1; i < s.length(); i++) {
                int w = s.charAt(i)-'a'+1;
                if (s.charAt(i) == s.charAt(i-1))
                    weight[i] = weight[i-1] + w;
                else
                    weight[i] = w;
                set.add(weight[i]);
            }
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                if (set.contains(x))
                    out.println("Yes");
                else
                    out.println("No");
            }
        }

    }
}