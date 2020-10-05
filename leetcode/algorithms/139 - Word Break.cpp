class Solution {
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        
        queue<int> q;
        vector<int> used(n, 0);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        int start;
        string cur;
        
        q.push(0);
        
        while (!q.empty()) {
            start = q.front();
            q.pop();
            
            if (!used[start]) {
                cur.clear();
                
                for (int end = start; end < n; end++) {
                    cur.push_back(s[end]);
                    
                    if (words.count(cur) > 0) {
                        if (end == n - 1) {
                            return true;
                        }
                        
                        q.push(end + 1);
                    }
                }
                
                used[start] = 1;
            }
        }
        
        return false;
    }
};