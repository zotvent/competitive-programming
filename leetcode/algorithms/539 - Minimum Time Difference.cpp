class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        int day = 24 * 60;
        
        int t, minutes, hours;
        
        for (auto i: timePoints) {
            hours = stoi(i.substr(0, 2)) * 60;
            minutes = stoi(i.substr(3));
            t = hours + minutes;
            time.push_back(t);
        }
        
        sort(time.begin(), time.end());
        
        int res = INT_MAX;
        int n = (int) time.size();
        int left, right, dif;
        
        for (int i = 0; i < n; i++) {
            dif = abs(time[i] - time[(i + 1) % n]);
            left = min(dif, day - dif);
            
            dif = abs(time[i] - time[(i - 1 + n) % n]);
            right = min(dif, day - dif);
            
            res = min(res, min(left, right));
        }
        
        return res;
    }
};