class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int mn = arr[0], mx = arr[0], sum = 0;
        
        for (auto& i: arr) {
            mn = min(mn, i);
            mx = max(mx, i);
            sum += i;
        }
        
        int expectedSum = (mn + mx) * (arr.size() + 1) / 2;
        
        return expectedSum - sum;
    }
};