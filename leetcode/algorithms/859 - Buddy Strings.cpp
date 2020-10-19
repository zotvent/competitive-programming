class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        
        vector<int> dif;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                dif.push_back(i);
            }
            
            if (dif.size() > 2) {
                return false;
            }
        }
        
        if (dif.size() == 1) {
            return false;
        }
        
        if (dif.size() == 0) {
            unordered_set<char> seen;
            
            for (int i = 0; i < A.size(); i++) {
                if (seen.count(A[i]) > 0) {
                    return true;
                }
                seen.insert(A[i]);
            }
            
            return false;
        }
        else {
            return A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
        }
    }
};