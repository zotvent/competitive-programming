class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        map<int, int> m;
        stack<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = -1;
            if (s.empty()) s.push(nums[i]);
            else {
                while (!s.empty() && s.top() < nums[i]) {
                    m[s.top()] = nums[i];
                    s.pop();
                }
                s.push(nums[i]);
            }
        }
        
        for (int i = 0; i < findNums.size(); i++)
            res.push_back(m[findNums[i]]);
        
        return res;
    }
};