class Solution {
public:
    int myAtoi(string str) {
        int res = 0, sign = 1, i = 0;
        
        while (i < str.size() && str[i] == ' ') i++;
        
        if (i < str.size() && (str[i] == '-' || str[i] == '+')) {
            sign = (str[i++] == '-' ? -1 : 1);
        }
        
        for (; i < str.size() && isdigit(str[i]); i++) {
            if (INT_MAX / 10 < res || (res == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            res = res * 10 + (str[i] - '0');
        }
        
        return res * sign;
    }
};