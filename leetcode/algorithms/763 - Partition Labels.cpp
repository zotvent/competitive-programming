class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        const int n = S.size();
        vector<int> lastIndex(26, -1);
        int end;
        
        for (int i = 0; i < n; i++) {
            lastIndex[S[i] - 'a'] = i;
        }
        
        for (int start = 0; start < n;) {
            end = lastIndex[S[start] - 'a'];
            
            for (int i = start + 1; i <= end; i++) {
                end = max(end, lastIndex[S[i] - 'a']);
            }
            
            res.push_back(end - start + 1);
            start = end + 1;
        }
        
        return res;
    }
};