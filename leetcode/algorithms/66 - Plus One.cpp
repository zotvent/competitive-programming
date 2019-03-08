class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        
        int i = res.size() - 1;
        int carry = 1;

        while (i >= 0 && carry > 0) {
            int sum = res[i] + carry;
            res[i--] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0) {
            res.insert(res.begin(), carry);
        }

        return res;
    }
};