class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        const int n = arr.size();
        int l = 0, r = n - 1;
        
        while (r - l + 1 > k) {
            if (abs(arr[l] - x) > abs(arr[r] - x)) l++;
            else r--;
        }
        
        for (int i = l; i <= r; i++) {
            res.push_back(arr[i]);
        }
        
        return res;
    }
};