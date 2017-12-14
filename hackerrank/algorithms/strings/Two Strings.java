import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        public void solve(BufferedReader in, PrintWriter out) throws IOException {
            int t = Integer.parseInt(in.readLine());
            for (int i = 0; i < t; i++) {
                String a = in.readLine();
                String b = in.readLine();
                int cnt [] = new int [26];

                for (int j = 0; j < a.length(); j++)
                    cnt[a.charAt(j)-'a']++;

                boolean res = false;
                for (int j = 0; j < b.length(); j++)
                    if (cnt[b.charAt(j)-'a'] > 0) {
                        res = true;
                        break;
                    }

                if (res)
                    out.println("YES");
                else
                    out.println("NO");
            }
        }

    }
}