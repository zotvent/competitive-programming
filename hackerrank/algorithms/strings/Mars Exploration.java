import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner in = new Scanner(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        public void solve(Scanner in, PrintWriter out) {
            String s = in.nextLine();
            int cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                int j = i+1;
                if ((j%3 == 0 || j%3 == 1) && s.charAt(i) != 'S')
                    cnt++;
                else if (j%3 == 2 && s.charAt(i) != 'O')
                    cnt++;
            }
            out.print(cnt);
        }

    }
}