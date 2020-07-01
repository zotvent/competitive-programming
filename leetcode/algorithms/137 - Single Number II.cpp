class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0;
        int seenTwice = 0;
        
        for (auto& i: nums) {
            seenOnce = ~seenTwice & (seenOnce ^ i);
            seenTwice = ~seenOnce & (seenTwice ^ i);
        }
        
        return seenOnce;
    }
};