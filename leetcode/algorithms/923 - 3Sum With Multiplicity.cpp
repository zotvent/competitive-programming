class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res = 0;
        const int mod = 1e9 + 7;
        
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        int l, r, left, right, comp;
        
        for (int i = 0; i < n; i++) {
            comp = target - arr[i];
            l = i + 1;
            r = n - 1;
            
            while (l < r) {
                if (arr[l] + arr[r] < comp) {
                    l++;
                }
                else if (arr[l] + arr[r] > comp) {
                    r--;
                }
                else if (arr[l] != arr[r]) {
                    left = right = 1;
                    
                    while (l + 1 < r && arr[l] == arr[l + 1]) {
                        left++;
                        l++;
                    }
                    
                    while (l < r - 1 && arr[r] == arr[r - 1]) {
                        right++;
                        r--;
                    }
                    
                    res = (res + left * right) % mod;
                    l++;
                    r--;
                }
                else {
                    res += (r - l + 1) * (r - l) / 2;
                    res %= mod;
                    break;
                }
            }
        }
        
        return res;
    }
};