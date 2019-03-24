class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    
    static bool comp(vector<int> left, vector<int> right) {
        int l = left[0] * left[0] + left[1] * left[1];
        int r = right[0] * right[0] + right[1] * right[1];
        
        return l < r;
    }
};