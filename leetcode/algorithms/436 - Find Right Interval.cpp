class Solution {
    
    int binarySearch(vector<pair<int, int>>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;
        int mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (arr[mid].first < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        
        return arr[lo].second;
    }
    
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        
        const int n = intervals.size();
        vector<pair<int, int>> start;
        
        for (int i = 0; i < n; i++) {
            start.push_back({intervals[i][0], i});
        }
        
        sort(start.begin(), start.end());
        
        int target, index, cur;
        
        for (auto& i: intervals) {
            target = i[1];
            index = binarySearch(start, target);
            cur = (intervals[index][0] >= i[1]) ? index : -1;
            res.push_back(cur);
        }
        
        return res;
    }
};