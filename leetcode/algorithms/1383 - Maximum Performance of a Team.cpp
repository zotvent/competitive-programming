class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long res = 0, mod = (int) 1e9 + 7, sum = 0;
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({efficiency[i], speed[i]});
        }
        
        sort(arr.rbegin(), arr.rend());
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int i = 0; i < n; i++) {
            if (heap.size() == k) {
                sum -= heap.top();
                heap.pop();
            }
            heap.push(arr[i].second);
            sum += arr[i].second;
            res = max(res, sum * arr[i].first);
        }
        
        return res % mod;
    }
};