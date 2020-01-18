class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int first = n, second = 0;
        
        for (first = 1; first <= n / 2; first++) {
            second = n - first;
            if (!containsZero(first) && !containsZero(second)) {
                break;
            }
        }
        
        return {first, second};
    }
    
    bool containsZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        
        return false;
    }
};