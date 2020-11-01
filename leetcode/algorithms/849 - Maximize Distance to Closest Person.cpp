class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int cur = 0;
        bool foundPerson = false;
        
        for (auto& i: seats) {
            if (i == 1) {
                if (!foundPerson) {
                    res = max(res, cur);
                }
                else {
                    res = max(res, (cur - 1) / 2 + 1);
                }
                
                foundPerson = true;
                cur = 0;
            }
            else {
                cur++;
            }
        }
        
        return max(res, cur);
    }
};