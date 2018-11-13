class Solution {
public:
    int getSum(int a, int b) {
        if (a && b) return getSum(a^b, (a&b) << 1);
        else return a|b;
    }
};