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
            String s = in.readLine();
            int cnt[] = new int [26];

            for (int i = 0; i < s.length(); i++)
                cnt[s.charAt(i)-'a']++;

            String res = "NO";
            int odd = 0;
            for (int i = 0; i < 26; i++)
                if (cnt[i]%2 != 0)
                    odd++;
            if (s.length()%2 == odd)
                res = "YES";
            out.println(res);
        }

    }
}