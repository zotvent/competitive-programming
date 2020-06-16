class Solution {
public:
    bool isSubsequence(string s, string t) {
        int head = 0;
        
        for (int i = 0; i < t.size(); i++) {
            if (head < s.size() && s[head] == t[i]) {
                head++;
            }
        }
        
        return head == s.size();
    }
};