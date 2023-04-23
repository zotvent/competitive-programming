class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x;
        while (l < r) {
            long long m = l + (r - l) / 2;
            if (m * m > x) r = m;
            else l = m + 1;
        }
        return l * l <= x ? l : l - 1;
    }
};
