class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<string, string>> res;

        for (int i = 0; i < A.size(); i++) {
            string odd = "";
            string even = "";
            
            for (int j = 0; j < A[i].size(); j++) {
                if (j % 2) even += A[i][j];
                else odd += A[i][j];
            }
            
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            res.insert(make_pair(odd, even));
        }
        
        return res.size();
    }
};