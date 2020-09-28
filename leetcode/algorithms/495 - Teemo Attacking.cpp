class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int last = -1;
        
        for (auto& i: timeSeries) {
            if (last < i) {
                res += duration;
            }
            else {
                res += i + duration - last - 1;
            }
            last = i + duration - 1;
        }
        
        return res;
    }
};