class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        
        int n = citations.size();
        vector<int> cnt(citations.size() + 1, 0);
        
        for (auto& i: citations) {
            cnt[min(i, n)]++;
        }
        
        int sum = 0;
        for (int i = n; i >= 0; i--) {
            sum += cnt[i];
            
            if (sum >= i) {
                res = i;
                break;
            }
        }
        
        return res;
    }
};