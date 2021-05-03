class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> res;
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0;
        int start, end;
        
        while (i < slots1.size() && j < slots2.size()) {
            if (slots1[i][1] < slots2[j][0]) i++;
            else if (slots2[j][1] < slots1[i][0]) j++;
            else {
                start = max(slots1[i][0], slots2[j][0]);
                end = min(slots1[i][1], slots2[j][1]);
                if (end - start >= duration) {
                    res.push_back(start);
                    res.push_back(start + duration);
                    break;
                }
                else if (slots1[i][1] < slots2[j][1]) i++;
                else j++;
            }
        }
        
        return res;
    }
};