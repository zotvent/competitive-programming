// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int mid = (r-l)/2 + l;
        
        int res = guess(mid);
        while (res != 0) {
            if (res == 1) l = mid + 1;
            else r = mid - 1;
            mid = (r-l)/2 + l;
            res = guess(mid);
        }
        return mid;
    }
};