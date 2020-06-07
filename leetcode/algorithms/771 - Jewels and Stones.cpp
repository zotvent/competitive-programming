class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        
        unordered_set<char> jewels;
        
        for (auto& i: J) {
            jewels.insert(i);
        }
        
        for (auto& i: S) {
            if (jewels.count(i) > 0) {
                res++;
            }
        }
        
        return res;
    }
};