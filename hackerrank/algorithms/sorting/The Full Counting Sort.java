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
            int max = 100;
            int n = Integer.parseInt(in.readLine());
            HashMap<Integer, ArrayList<String>> map = new HashMap<>();
            for (int i = 0; i < max; i++)
                map.put(i, new ArrayList<>());

            for (int i = 0; i < n; i++) {
                String [] tmp = in.readLine().split(" ");
                int key = Integer.parseInt(tmp[0]);
                String s = tmp[1];
                if (i < n/2)
                    map.get(key).add("-");
                else
                    map.get(key).add(s);
            }

            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < max; i++) {
                ArrayList<String> arr = map.get(i);
                for (String s : arr) {
                    sb.append(s);
                    sb.append(" ");
                }
            }

            out.println(sb);
        }

    }
}