class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int cnt[2] = {0, 0};
        for (auto i: chips) cnt[i % 2]++;
        return min(cnt[0], cnt[1]);
    }
};