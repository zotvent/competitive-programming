class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        double cnt = 0;
        int i = 0;
        
        double threshold = (double) arr.size() / 4.0;
        
        for (i = 0; i < arr.size(); i++) {
            if (i && arr[i] == arr[i - 1]) cnt++;
            else cnt = 1;
                        
            if (cnt > threshold) {
                break;
            }
        }
        
        return arr[i];
    }
};