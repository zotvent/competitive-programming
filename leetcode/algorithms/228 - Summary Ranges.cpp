class Solution {
    
    string range(int start, int end) {
        string res = to_string(start);
        
        if (end > start) {
            res += "->" + to_string(end);
        }
        
        return res;
    }
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if (nums.empty()) {
            return res;
        }
        
        const int n = nums.size();
        int start, end;
        start = end = nums[0];
        
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                res.push_back(range(start, end));
            }
            else if (nums[i] > nums[i - 1] + 1) {
                res.push_back(range(start, end));
                start = end = nums[i];
            }
            else {
                end = nums[i];
            }
        }
        
        return res;
    }
};