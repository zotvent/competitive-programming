class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int last = -1, cnt = 0, head = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > last || cnt < 2) {
                nums[head++] = nums[i];
                
                if (nums[i] == last) cnt++;
                else cnt = 1;
                
                last = nums[i];
                res++;
            }
        }
        
        return res;
    }
};