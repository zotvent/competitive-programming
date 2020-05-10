class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res = A;
        
        int head = 0;
        
        for (int i = 0; i < res.size(); i++) {
            if (res[i] % 2 == 0) {
                swap(res[head++], res[i]);
            }
        }
        
        return res;
    }
};