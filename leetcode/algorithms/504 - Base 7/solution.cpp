class Solution {
public:
    string convertToBase7(int num) {
        string res;
        int base = 7;
        bool negative = num < 0;
        if (negative)
            num = -num;
        
        while (num >= base) {
            res += to_string(num%base);
            num /= base;
        }
        res += to_string(num);
        if (negative)
            res += "-";
        reverse(res.begin(), res.end());
        return res;
    }
};