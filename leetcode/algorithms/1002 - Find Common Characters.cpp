class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<int> cnt(26, 0);
        
        if (A.size() == 0) {
            return res;
        }

        for (int j = 0; j < A[0].size(); j++) {
            cnt[A[0][j] - 'a']++;
        }

        for (int i = 1; i < A.size(); i++) {
            vector<int> tmp(26, 0);

            for (int j = 0; j < A[i].size(); j++) {
                tmp[A[i][j] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                cnt[j] = min(cnt[j], tmp[j]);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                string tmp;
                tmp.push_back(i + 'a');

                for (int j = 0; j < cnt[i]; j++) {
                    res.push_back(tmp);
                }
            }
        }

        return res;
    }
};