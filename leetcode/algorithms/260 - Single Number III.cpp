class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (auto& i: nums) {
            if (seen.count(i) > 0) {
                seen.erase(i);
            }
            else seen.insert(i);
        }
        
        return vector<int>(seen.begin(), seen.end());
    }
};