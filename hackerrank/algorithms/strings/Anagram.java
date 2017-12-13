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
            for (int k = 0; k < t; k++) {
                String s = in.readLine();
                if (s.length()%2 == 1) {
                    out.println(-1);
                    continue;
                }
                int cnt[] = new int [26];
                for (int i = 0; i < s.length()/2; i++)
                    cnt[s.charAt(i)-'a']++;
                for (int i = s.length()/2; i < s.length(); i++)
                    cnt[s.charAt(i)-'a']--;
                int res = 0;
                for (int i = 0; i < 26; i++)
                    res += Math.abs(cnt[i]);
                out.println(res/2);
            }
        }

    }
}