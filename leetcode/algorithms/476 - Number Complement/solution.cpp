class Solution {
public:
    int findComplement(int num) {
        unsigned int i = 0, n = num;
        while ((1 << i) <= n) {
            n ^= (1 << i);
            i++;
        }
        return n;
    }
};