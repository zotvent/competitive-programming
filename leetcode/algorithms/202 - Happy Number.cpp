class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while (n != 1 && s.count(n) == 0) {
            s.insert(n);
            n = square_digits_sum(n);
        }
        
        return n == 1;
    }
    
    int square_digits_sum(int n) {
        int res = 0;
        
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return res;
    }
};