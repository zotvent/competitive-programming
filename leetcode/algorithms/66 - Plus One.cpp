class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        
        int carry = 1;
        int i = (int) digits.size() - 1;
        
        while (carry > 0 || i >= 0) {
            if (i >= 0) carry += digits[i--];
            res.push_back(carry % 10);
            carry /= 10;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};