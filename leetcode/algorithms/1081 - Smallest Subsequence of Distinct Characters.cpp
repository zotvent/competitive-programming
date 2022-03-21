class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        const int n = 26;
        vector<int> cnt(n, 0), used(n, 0);
        
        for (auto& i: s) {
            cnt[i - 'a']++;
        }
        
        for (auto& i: s) {
            cnt[i - 'a']--;
            if (used[i - 'a']) continue;
            
            while (!res.empty() && res.back() > i && cnt[res.back() - 'a'] > 0) {
                used[res.back() - 'a'] = 0;
                res.pop_back();
            }
            
            res.push_back(i);
            used[i - 'a'] = 1;
        }
        
        return res;
    }
};