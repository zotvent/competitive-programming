class Solution {
    
    unordered_map<int, int> mem;
    
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        
        if (mem.count(n) == 0) {
            if (n & 1) {
                mem[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            }
            else {
                mem[n] = 1 + integerReplacement(n / 2);
            }
        }
        
        return mem[n];
    }
};