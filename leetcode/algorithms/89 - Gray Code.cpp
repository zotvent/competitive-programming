class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int length = 1 << n;
        for (int i = 0; i < length; i++) {
            int num = i ^ (i >> 1);
            res.push_back(num);
        }
        return res;
    }
};