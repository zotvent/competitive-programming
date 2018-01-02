class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, vector<pair<int,int>>> dict;
        
        for (int i = 0; i < nums.size(); i++)
            dict[nums[i]].push_back(make_pair(nums[i], i));
        
        for (int i = 0; i < nums.size(); i++) {
            int dif = target-nums[i];
            bool found = false;
            
            if (dict.find(dif) != dict.end()) {
                auto v = dict[dif];
                for (int j = 0; j < v.size(); j++)
                    if (v[j].second != i) {
                        res.push_back(i);
                        res.push_back(v[j].second);
                        found = true;
                        break;
                    }
            }
            
            if (found)
                break;
        }
        
        return res;
    }
};