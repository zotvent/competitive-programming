class Solution {
    
    string range(int left, int right) {
        return to_string(left) + (left == right ? "" : "->" + to_string(right));
    }
    
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int last = lower;
        
        for (auto& i: nums) {
            if (i > last) {
                res.push_back(range(last, i - 1));
            }
            last = i + 1;
        }
        
        if (last <= upper) {
            res.push_back(range(last, upper));
        }
        
        return res;
    }
};