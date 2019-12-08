class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            int key = groupSizes[i];
            m[key].push_back(i);
            
            if (m[key].size() == key) {
                res.push_back(m[key]);
                m.erase(key);
            }
        }
        
        return res;
    }
};