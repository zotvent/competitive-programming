class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int ans = -1;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    ans = nums[j];
                    break;
                }
            }
            m[nums[i]] = ans;
        }
        for (int i = 0; i < findNums.size(); i++) {
            v.push_back(m[findNums[i]]);
        }
        return v;
    }
};