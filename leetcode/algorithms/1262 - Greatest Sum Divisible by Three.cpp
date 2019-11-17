class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res = 0;
        
        int inf = (int) 1e9;
        pair<int, int> min_one = make_pair(inf, inf);
        pair<int, int> min_two = make_pair(inf, inf);
        int mod;
        
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i];
            mod = nums[i] % 3;
            
            if (mod == 1) {
                min_one.second = min(min_one.second, nums[i]);
                if (min_one.second < min_one.first) {
                    swap(min_one.second, min_one.first);
                }
            }
            else if (mod == 2) {
                min_two.second = min(min_two.second, nums[i]);
                if (min_two.second < min_two.first) {
                    swap(min_two.second, min_two.first);
                }
            }
        }
        
        if (res % 3 == 1) {
            res -= min(min_one.first, min_two.first + min_two.second);
        }
        else if (res % 3 == 2) {
            res -= min(min_two.first, min_one.first + min_one.second);
        }
        
        return res;
    }
};