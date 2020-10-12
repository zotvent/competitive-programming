class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> lastOccurence;
        
        for (int i = 0; i < s.size(); i++) {
            lastOccurence[s[i]] = i;
        }
        
        stack<char> st;
        unordered_set<char> seen;
        char c;
        
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            
            if (seen.count(c) == 0) {
                while (!st.empty() && c < st.top() && lastOccurence[st.top()] > i) {
                    seen.erase(st.top());
                    st.pop();
                }
                
                st.push(c);
                seen.insert(c);
            }
        }
        
        string res = "";
        
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};