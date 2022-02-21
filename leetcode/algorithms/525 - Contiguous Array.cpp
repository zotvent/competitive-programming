class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] > 0 ? 1 : -1);
            if (m.count(sum) > 0) {
                res = max(res, i - m[sum]);
            }
            else m[sum] = i;
        }
        
        return res;
    }
};