class Solution {
    
    void backtrack(vector<int>& nums, int head, int& res) {
        if (head == nums.size()) {
            res++;
        }
        
        for (int i = head; i < nums.size(); i++) {
            swap(nums[head], nums[i]);
            if (nums[head] % (head + 1) == 0 || (head + 1) % nums[head] == 0) {
                backtrack(nums, head + 1, res);
            }
            swap(nums[head], nums[i]);
        }
    }
    
public:
    int countArrangement(int n) {
        int res = 0;
        vector<int> nums(n, 0);
        
        for (int i = 1; i <= n; i++) {
            nums[i - 1] = i;
        }
        
        backtrack(nums, 0, res);
        
        return res;      
    }
};