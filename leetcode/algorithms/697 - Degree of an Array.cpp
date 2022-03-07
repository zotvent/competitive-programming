class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m; // value -> (count, left, right)
        int degree = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            
            if (m.count(key) == 0) {
                m[key] = {1, i, i};
            }
            else {
                m[key][0]++;
                m[key][2] = i;
            }
            
            degree = max(degree, m[key][0]);
        }
        
        int res = nums.size();
        
        for (auto& i: m) {
            if (i.second[0] == degree) {
                res = min(res, i.second[2] - i.second[1] + 1);
            }
        }
        
        return res;
    }
};