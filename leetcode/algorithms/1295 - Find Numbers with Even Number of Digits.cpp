class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        
        for (auto i: nums) {
            if (isEvenNumberOfDigits(i)) {
                res++;
            }
        }
        
        return res;
    }
    
    bool isEvenNumberOfDigits(int x) {
        int cnt = 0;
        
        while (x > 0) {
            cnt++;
            x /= 10;
        }
        
        return cnt % 2 == 0;
    }
};