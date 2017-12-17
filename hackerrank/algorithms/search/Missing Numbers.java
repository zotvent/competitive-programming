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
            int n = in.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                a[i] = x;
            }
            int m = in.nextInt();
            int min = 10005;
            int b[] = new int[m];
            for (int i = 0; i < m; i++) {
                int x = in.nextInt();
                b[i] = x;
                min = Math.min(b[i], min);
            }

            int cnt[] = new int[m];
            for (int i = 0; i < m; i++) {
                cnt[b[i]-min]++;
            }
            for (int i = 0; i < n; i++) {
                cnt[a[i]-min]--;
            }

            for (int i = 0; i < m; i++) {
                if (cnt[i] != 0) {
                    int x = i+min;
                    out.print(x + " ");
                }
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