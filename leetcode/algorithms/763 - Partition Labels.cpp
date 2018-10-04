class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res, dict(26, 0);

        for (int i = 0; i < S.size(); i++) 
            dict[S[i] - 'a'] = i;

        int start = 0, end = dict[S[0] - 'a'];
        for (int i = 0; i < S.size(); i++) {
            end = max(end, dict[S[i] - 'a']);
            if (end == i) {
                res.push_back(end - start + 1);
                start = end + 1;
            }                
        }

        return res;
    }
};