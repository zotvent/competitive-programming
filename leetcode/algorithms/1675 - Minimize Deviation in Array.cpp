class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, mn = INT_MAX, mx;
        priority_queue<int> q;
        
        for (auto& i: nums) {
            if (i % 2 == 1) {
                mn = min(mn, i * 2);
                q.push(i * 2);
            }
            else {
                mn = min(mn, i);
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            mx = q.top();
            q.pop();
            res = min(res, mx - mn);
            
            if (mx % 2 == 0) {
                q.push(mx / 2);
                mn = min(mn, mx / 2);
            }
            else {
                break;
            }
        }
        
        return res;
    }
};