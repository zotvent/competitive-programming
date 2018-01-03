class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = nums.size();
        while (cnt) {
            cnt--;
            if (nums.size() > 0) {
                int front = nums[0];
                nums.erase(nums.begin());
                if (front != val)
                    nums.push_back(front);
            }
        }
        return nums.size();
    }
};