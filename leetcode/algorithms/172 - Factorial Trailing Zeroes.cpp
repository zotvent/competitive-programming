class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        int temp = 0;
        while (n) {
            temp = n/5;
            zeros += temp;
            n = temp;
        }
        return zeros;
    }
};