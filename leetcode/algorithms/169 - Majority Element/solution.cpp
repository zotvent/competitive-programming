class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) m[nums[i]]++;
            else m[nums[i]] = 1;
        }
        
        int element = nums[0];
        int times = nums.size()/2;
        for (int i = 1; i < nums.size(); i++)
            if (m[nums[i]] > times) element = nums[i];
        return element;
    }
};