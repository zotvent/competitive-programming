class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v, cnt(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1)
                v.push_back(nums[i]);
        }
        for (int i = 1; i <= nums.size(); i++)
            if (cnt[i] == 0)
                v.push_back(i);
        return v;
    }
};