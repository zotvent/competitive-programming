class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int res = 1;
        
        for (auto& i: arr) {
            if (i == res) res++;
            else if (res + k - 1 < i) break;
            else {
                k -= i - res;
                res = i + 1;
            }
        }
        
        return res + k - 1;
    }
};