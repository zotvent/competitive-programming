class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int mx = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (mx == -1 && arr[i] == i) res++;
            else if (mx == i && arr[i] < mx) {
                res++;
                mx = -1;
            }
            else mx = max(mx, arr[i]);
        }
        return res;
    }
};