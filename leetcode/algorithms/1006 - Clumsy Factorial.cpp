class Solution {
public:
    int clumsy(int N) {
        return my_clumsy(N, false);
    }

    int my_clumsy(int n, bool neg) {
        int res = (neg ? -n : n);

        n--;
        for (int i = 0; i < 4; i++) {
            if (n <= 0) {
                break;
            }

            if (i == 0) {
                res *= n;
            }
            else if (i == 1) {
                res /= n;
            }
            else if (i == 2) {
                res += n;
            }
            else {
                res += my_clumsy(n, true);
            }

            n--;
        }

        return res;
    }
};