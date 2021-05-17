class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, left = 0, right = 0;
        const int n = cardPoints.size();
        
        for (int i = 0; i < k; i++) {
            left += cardPoints[i];
        }
        
        res = left;
        
        for (int i = k - 1; i >= 0; i--) {
            left -= cardPoints[i];
            right += cardPoints[n - (k - i)];
            res = max(res, left + right);
        }
        
        return res;
    }
};