class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
            long long b2 = c - a * a;
            long long b = sqrt(b2);
            if (b * b == b2) {
                return true;
            }
        }
        return false;
    }
};