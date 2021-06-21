class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxi = INT_MIN;
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxi) {
                res.push_back(i);
                maxi = heights[i];
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};