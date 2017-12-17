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
            int t = in.nextInt();
            for (int k = 0; k < t; k++) {
                int n = in.nextInt();
                int array[] = new int [n+1];
                for (int i = 1; i <= n; i++) {
                    array[i] = in.nextInt();
                }

                int left[] = new int [n+3];
                int right[] = new int [n+3];
                for (int i = 1; i <= n; i++) left[i] = left[i-1] + array[i];
                for (int i = n; i > 0; i--) right[i] = right[i+1] + array[i];

                boolean found = false;
                for (int i = 1; i <= n; i++) {
                    if (left[i-1] == right[i+1]) {
                        found = true;
                        break;
                    }
                }

                if (found)
                    out.println("YES");
                else
                    out.println("NO");
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