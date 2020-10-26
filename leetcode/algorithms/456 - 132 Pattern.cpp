class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        const int n = nums.size();
        vector<int> mn(n, nums[0]);
        stack<int> s;
        
        for (int i = 1; i < n; i++) {
            mn[i] = min(nums[i], mn[i - 1]);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > mn[i]) {
                while (!s.empty() && s.top() <= mn[i]) {
                    s.pop();
                }
                
                if (!s.empty() && s.top() < nums[i]) {
                    return true;
                }
                
                s.push(nums[i]);
            }
        }
        
        return false;
    }
};