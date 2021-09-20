class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int maxi = releaseTimes[0];
        
        for (int i = 1; i < releaseTimes.size(); i++) {
            int time = releaseTimes[i] - releaseTimes[i - 1];
            if (time > maxi) {
                maxi = time;
                res = keysPressed[i];
            }
            else if (time == maxi && keysPressed[i] > res) {
                res = keysPressed[i];
            }
        }
        
        return res;
    }
};