class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        
        int carry = 0;
        int l = num1.size() - 1;
        int r = num2.size() - 1;
        
        while (carry > 0 || l >= 0 || r >= 0) {
            if (l >= 0) carry += num1[l--] - '0';
            if (r >= 0) carry += num2[r--] - '0';
            
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};