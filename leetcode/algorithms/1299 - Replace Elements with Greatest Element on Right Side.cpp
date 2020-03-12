class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int sz = (int) arr.size();
        vector<int> res(sz, -1);
        
        int mx = (arr.empty() ? 0 : arr.back());
        
        for (int i = sz - 2; i >= 0; i--) {
            res[i] = mx;
            mx = max(mx, arr[i]);
        }
        
        return res;
    }
};