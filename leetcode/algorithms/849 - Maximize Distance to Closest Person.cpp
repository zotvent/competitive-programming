class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, empty;
        const int n = seats.size();
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                empty = 0;
            }
            else {
                res = max(res, (++empty + 1) / 2);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                res = max(res, i);
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                res = max(res, n - 1 - i);
                break;
            }
        }
        
        return res;
    }
};