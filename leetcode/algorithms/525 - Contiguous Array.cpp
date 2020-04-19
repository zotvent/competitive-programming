class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int res = 0;

        unordered_map<int, int> m;
        m[0] = -1;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1 ? 1 : -1);

            if (m.count(cnt) > 0) {
                res = max(res, i - m[cnt]);
            }
            else {
                m[cnt] = i;
            }
        }

        return res;
    }
};