class Solution {
public:
    string toLowerCase(string str) {
        string res = "";
        int dif = 'a' - 'A';
        
        for (int i = 0; i < str.length(); i++)
            if (isAlpha(str[i]) && (str[i] < 'a' || str[i] > 'z'))
                res += str[i] + dif;
            else res += str[i];
        
        return res;
    }
    
    bool isAlpha(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    
};