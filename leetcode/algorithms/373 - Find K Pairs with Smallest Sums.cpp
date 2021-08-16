class Solution {
    
    class MyComparator {
    public:
        bool operator()(vector<int>& l, vector<int>& r) const {
            return l[0] + l[1] > r[0] + r[1];
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        const int n2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, MyComparator> mins;
        vector<int> cur;
        
        for (int i = 0; i < min((int) nums1.size(), k); i++) {
            mins.push({nums1[i], nums2[0], 0});
        }
        
        while (res.size() < k && !mins.empty()) {
            cur = mins.top();
            mins.pop();
            res.push_back({cur[0], cur[1]});
            if (cur[2] < n2 - 1) {
                mins.push({cur[0], nums2[cur[2] + 1], cur[2] + 1});
            }
        }
        
        return res;
    }
};