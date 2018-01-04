class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        int carry = 1;
        while (i >= 0) {
            int sum = digits[i] + carry;
            digits[i--] = sum % 10;
            carry = sum / 10;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};