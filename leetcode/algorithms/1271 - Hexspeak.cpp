class Solution {
public:
    string reverseString(string s) {
        string result;
        for (int i = s.length() - 1; i >= 0; i--) result += s[i];
        return result;
    }

    string convert(long number, long base) {
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        string result;
        while (number >= base) {
            result += digits[number % base];
            number /= base;
        }
        result += digits[number];
        reverse(result.begin(), result.end());
        return result;
    }
    
    string toHexspeak(string num) {
        string res = convert(stol(num), 16);
        
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0') res[i] = 'O';
            if (res[i] == '1') res[i] = 'I';
            if (isdigit(res[i])) {
                res = "ERROR";
                break;
            }
        }
        
        return res;
    }
};