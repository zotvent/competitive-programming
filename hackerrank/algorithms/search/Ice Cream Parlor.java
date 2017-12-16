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
            final int N = 10005;
            for (int k = 0; k < t; k++) {
                int m = in.nextInt();
                int n = in.nextInt();
                Vector<Vector<Integer>> cnt = new Vector<>();
                for (int i = 0; i < N; i++) cnt.add(new Vector<>());
                for (int i = 1; i <= n; i++) {
                    int c = in.nextInt();
                    cnt.elementAt(c).add(i);
                }
                for (int i = 0; i < m; i++) {
                    StringBuilder sb = new StringBuilder();
                    if (cnt.elementAt(i).size() > 0 && cnt.elementAt(m-i).size() > 0) {
                        int index = (i == m-i ? 1 : 0);
                        int first = cnt.elementAt(i).firstElement();
                        int second = cnt.elementAt(m-i).elementAt(index);
                        sb.append(Math.min(first, second));
                        sb.append(" ");
                        sb.append(Math.max(first, second));
                        out.println(sb);
                        break;
                    }
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