class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0, boxes = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[1] > r[1];
        });
        
        for (int i = 0; i < boxTypes.size() && boxes < truckSize; i++) {
            res += boxTypes[i][1] * min(boxTypes[i][0], truckSize - boxes);
            boxes += min(boxTypes[i][0], truckSize - boxes);
        }
        
        return res;
    }
};