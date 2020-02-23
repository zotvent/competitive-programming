class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        
        vector<int> m(60, 0);
        int comp;
        
        for (auto i: time) {
            comp = (60 - i % 60) % 60;
            res += m[comp];
            m[i % 60]++;
        }
        
        return res;
    }
};