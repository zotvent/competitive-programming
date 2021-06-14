class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        int last = nums[0];
        q.push({nums[0], 0});
        
        for (int i = 1; i < nums.size(); i++) {
            while (q.top().second < i - k) {
                q.pop();
            }
            last = q.top().first + nums[i];
            q.push({last, i});
        }
        
        return last;
    }
};