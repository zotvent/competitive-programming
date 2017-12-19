class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string dict = "0123456789abcdef";
        string res = "";
        int i = 0;
        while (num && i++ < 8) {
            res = dict[num & 15] + res;
            num >>= 4;
        }
        return res;
    }
};