class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;
        
        for (auto& i: nums) {
            if (cnt == 0) {
                candidate = i;
            }
            
            cnt += (candidate == i ? 1 : -1);
        }
        
        return candidate;
    }
};