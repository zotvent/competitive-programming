class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0;
        
        vector<int> m(101, 0);
        
        for (auto i: heights) {
            m[i]++;
        }
        
        int cur = 0;
        
        for (auto i: heights) {
            while (m[cur] == 0) {
                cur++;
            }
            
            if (i != cur) {
                res++;
            }
            
            m[cur]--;
        }
        
        return res;
    }
};