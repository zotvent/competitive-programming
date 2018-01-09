class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        vector<bool> used(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i] == B[j] && !used[j]) {
                    res[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        return res;
    }
};