class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        
        int jumbo, small;
        
        for (int i = 0; i <= cheeseSlices; i++) {
            jumbo = i;
            small = cheeseSlices - i;
            
            if (jumbo * 4 + small * 2 == tomatoSlices) {
                res.push_back(jumbo);
                res.push_back(small);
                break;
            }
        }
        
        return res;
    }
};