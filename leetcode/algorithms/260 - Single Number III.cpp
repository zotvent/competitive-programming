class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        
        for (auto& i: nums) {
            if (s.count(i) > 0) {
                s.erase(i);
            }
            else {
                s.insert(i);
            }
        }
        
        vector<int> res(s.begin(), s.end());
        
        return res;
    }
};