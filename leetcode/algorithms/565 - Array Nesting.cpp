class Solution {
    
    int dfs(vector<int>& nums, vector<int>& used, int v) {
        int res = 0;
        while (!used[v]) {
            res++;
            used[v] = 1;
            v = nums[v];
        }
        return res;
    }
    
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        vector<int> used(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                res = max(res, dfs(nums, used, i));
            }
        }
        
        return res;
    }
};