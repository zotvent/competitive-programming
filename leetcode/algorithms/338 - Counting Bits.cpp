class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++)
            res[i] = res[i & (i-1)] + 1;
        return res;
    }
};