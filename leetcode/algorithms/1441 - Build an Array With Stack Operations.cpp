class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        
        int prev = 0;
        int dif = 0;
        
        for (auto& i: target) {
            dif = i - prev;
            
            while (dif > 1) {
                res.push_back("Push");
                res.push_back("Pop");
                dif--;
            }
            
            res.push_back("Push");
            prev = i;
        }
        
        return res;
    }
};