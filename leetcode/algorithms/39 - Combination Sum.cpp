class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;

        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, path, res, target, 0);

        return res;
    }

    void backtrack(vector<int> &candidates, vector<int>& path, vector<vector<int>>& res, int remain, int head) {
        if (remain < 0) return;
        else if (remain == 0) {
            res.push_back(path);
            return;
        }

        for (int i = head; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtrack(candidates, path, res, remain - candidates[i], i);
            path.pop_back();
        }
    }
};