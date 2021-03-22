class Solution {
    
    vector<int> convert(int x) {
        vector<int> digits(10, 0);
        
        while (x > 0) {
            digits[x % 10]++;
            x /= 10;
        }
        
        return digits;
    }
    
public:
    bool reorderedPowerOf2(int N) {
        const vector<int> n = convert(N);
        vector<int> tmp;
        
        for (int i = 0; i < 31; i++) {
            tmp = convert((1 << i));
            if (n == tmp) {
                return true;
            }
        }
        
        return false;
    }
};