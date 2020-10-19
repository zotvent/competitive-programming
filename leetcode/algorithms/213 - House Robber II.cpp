class Solution {
    
    int calc(int start, vector<int>& nums) {
        const int n = nums.size();
        int preLast = 0, last = 0, tmp;
        
        for (int i = start; i < n - 1 + start; i++) {
            tmp = last;
            last = max(last, preLast + nums[i]);
            preLast = tmp;
        }
        
        return last;
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int startFromFirst = calc(0, nums);
        int startFromSecond = calc(1, nums);
        
        return max(startFromFirst, startFromSecond);
    }
};