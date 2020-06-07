class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        
        unordered_map<int, int> m;
        vector<pair<int, int>> v;
        
        for (auto& i: nums) {
            m[i]++;
        }
        
        for (auto i: m) {
            v.push_back({i.second, i.first});
        }
        
        sort(v.rbegin(), v.rend());
        
        for (int i = 0; i < k && i < v.size(); i++) {
            res.push_back(v[i].second);
        }
        
        return res;
    }
};