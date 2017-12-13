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
            String a = in.readLine();
            String b = in.readLine();

            int cntA[] = new int [26];
            int cntB[] = new int [26];

            for (int i = 0; i < a.length(); i++) cntA[a.charAt(i)-'a']++;
            for (int i = 0; i < b.length(); i++) cntB[b.charAt(i)-'a']++;

            int common = 0;
            for (int i = 0; i < 26; i++) common += Math.min(cntA[i], cntB[i]);

            out.println(a.length()+b.length()-common*2);
        }

    }
}