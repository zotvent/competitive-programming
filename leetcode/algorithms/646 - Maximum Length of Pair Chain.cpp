class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, to = INT_MIN;
        sort(pairs.begin(), pairs.end(), [](vector<int>& l, vector<int>& r) {
            return l[1] < r[1];
        });
        for (auto& i: pairs) {
            if (to < i[0]) {
                to = i[1];
                res++;
            }
        }
        return res;
    }
};
