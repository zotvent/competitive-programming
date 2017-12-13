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
                int dp[] = new int[s.length()];
                dp[0] = 1;
                for (int i = 1; i < s.length(); i++) {
                    if (s.charAt(i) == s.charAt(i - 1))
                        dp[i] = dp[i - 1] + 1;
                    else
                        dp[i] = 1;
                }
                int res = 0;
                for (int i = s.length()-1; i >= 0; i--) {
                    if (dp[i] > 1) {
                        int cnt = dp[i]-1;
                        res += cnt;
                        i -= cnt;
                    }
                }
                out.println(res);
            }
        }

    }
}