class Solution {
public:
    int binaryGap(int N) {
        int res = 0, cnt = 0;

        while (N) {
            if (N & 1) {
                res = max(res, cnt);
                cnt = 1;
            }
            else if (cnt) cnt++;
            
            N >>= 1;
        }

        return res;
    }
};