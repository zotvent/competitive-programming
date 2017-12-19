class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for (int i = left; i <= right; i++) {
            vector<int> digits(10, 0);
            digitsOfNumber(digits, i);
            
            if (digits[0])
                continue;
            bool found = true;
            for (int j = 1; j < 10; j++)
                if (digits[j] && i%j != 0) 
                    found = false;
            
            if (found)
                v.push_back(i);
        }
        return v;
    }
    
    void digitsOfNumber(vector<int> &digits, int x) {
        while (x > 0) {
            digits[x%10] = 1;
            x /= 10;
        }
    }
};