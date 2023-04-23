class Solution {

    string range(int s, int e) {
        if (s == e) return to_string(s);
        return to_string(s) + "->" + to_string(e);
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start = nums.empty() ? -1 : 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1] + 1) {
                res.push_back(range(nums[start], nums[i - 1]));
                start = i;
            }
        }
        if (start != -1) res.push_back(range(nums[start], nums.back()));
        return res;
    }
};
