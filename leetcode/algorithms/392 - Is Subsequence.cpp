class Solution {
public:
    bool isSubsequence(string s, string t) {
        int head = 0;
        
        for (int i = 0; i < t.size() && head < s.size(); i++) {
            if (t[i] == s[head]) {
                head++;
            }
        }
        
        return head == s.size();
    }
};