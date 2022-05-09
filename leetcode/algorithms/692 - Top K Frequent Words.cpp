class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        priority_queue <pair<int, string>> q;
        
        for (auto &i: words) {
            m[i]++;
        }
        
        for (auto it: m) {
            q.push({-it.second, it.first});
            if (q.size() > k) q.pop();
        }
        
        while (k--) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};