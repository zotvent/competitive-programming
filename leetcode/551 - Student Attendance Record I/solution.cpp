class Solution {
public:
    bool checkRecord(string s) {
        map<char, int> m;
        int maxLate = 0, cur = 0;
        for (int i = 0; i < s.length(); i++) {
            cur = (s[i] == 'L' ? cur+1 : 0); 
            maxLate = max(maxLate, cur);
            m[s[i]]++;
        }
        return (m['A'] > 1 || maxLate > 2 ? false : true);
    }
};