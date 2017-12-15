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
            int cnt[] = new int[20005];
            int shift = 10000;

            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                cnt[x+shift]++;
            }

            int i = 0, j = 0;
            while (i < n/2+1)
                i += cnt[j++];

            j -= shift;
            out.print(j-1);
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