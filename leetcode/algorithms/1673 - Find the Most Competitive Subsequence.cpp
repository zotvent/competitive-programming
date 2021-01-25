class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> q;
        int canDrop = (int) nums.size() - k;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.back() > nums[i] && canDrop > 0) {
                q.pop_back();
                canDrop--;
            }
            q.push_back(nums[i]);
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q[i]);
        }
        return res;
    }
};