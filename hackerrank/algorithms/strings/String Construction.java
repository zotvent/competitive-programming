import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        public void solve(InputReader in, PrintWriter out) throws IOException {
            int q = in.nextInt();
            for (int k = 0; k < q; k++) {
                String s = in.next();
                int cost = 0;
                int cnt[] = new int[26];
                int j = 0;
                while (j != s.length()) {
                    if (cnt[s.charAt(j)-'a'] == 0) {
                        cost++;
                        cnt[s.charAt(j)-'a']++;
                    }
                    else
                        cnt[s.charAt(j)-'a']++;
                    j++;
                }
                out.println(cost);
            }
        }

    }

    static class InputReader {

        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}