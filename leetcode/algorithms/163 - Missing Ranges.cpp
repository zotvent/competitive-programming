class Solution {
    
    void update(vector<string>& res, int left, int right) {
        res.push_back(to_string(left));
        
        if (left != right) {
            res.back() += "->" + to_string(right);
        }
    }
    
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 && nums[i] > lower) {
                update(res, lower, nums[i] - 1);
            }
            else if (i > 0 && lower < INT_MAX && nums[i] > lower + 1) {
                update(res, lower + 1, nums[i] - 1);
            }
            lower = nums[i];
        }
        
        if (nums.empty()) {
            update(res, lower, upper);
        }
        else if (lower < upper) {
            update(res, lower + 1, upper);
        }
        
        return res;
    }
};