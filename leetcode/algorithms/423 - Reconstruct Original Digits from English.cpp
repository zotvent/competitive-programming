class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> cnt;
        
        for (auto& i: s) {
            cnt[i]++;
        }
        
        vector<int> nums(10, 0);
        nums[0] = cnt['z'];
        nums[2] = cnt['w'];
        nums[4] = cnt['u'];
        nums[6] = cnt['x'];
        nums[8] = cnt['g'];
        nums[3] = cnt['h'] - nums[8];
        nums[5] = cnt['f'] - nums[4];
        nums[7] = cnt['s'] - nums[6];
        nums[9] = cnt['i'] - nums[5] - nums[6] - nums[8];
        nums[1] = cnt['n'] - nums[7] - 2 * nums[9];
        
        string res = "";
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i]; j++) {
                res.push_back(i + '0');
            }
        }
        
        return res;
    }
};