class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        sort(arr.begin(), arr.end());
        for (auto& i: arr) m[i]++;
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (m[arr[i]] > 0) {
                if (arr[i] % 2 == 0 && m[arr[i] / 2] > 0) {
                    m[arr[i]]--;
                    m[arr[i] / 2]--;
                }
                else if (m[arr[i] * 2] > 0) {
                    m[arr[i]]--;
                    m[arr[i] * 2]--;
                }
            }
        }
        
        for (auto& i: arr) {
            if (m[i] > 0) {
                return false;
            }
        }
        
        return true;
    }
};