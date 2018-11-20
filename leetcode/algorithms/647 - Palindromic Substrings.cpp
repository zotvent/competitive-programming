class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int odd = count(s, i, i);
            int even = count(s, i, i + 1);
            res += odd + even;
        }
        
        return res;
    }

    int count(string &s, int left, int right) {
        int res = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
        
        return res;
    }

};