class Solution {
public:
    string customSortString(string S, string T) {
        string res = "";
        vector<int> v(26, 0);
        int i, j;

        for (i = 0; i < T.size(); i++)
            v[T[i] - 'a']++;
        for (i = 0; i < S.size(); i++) {
            for (j = 0; j < v[S[i] - 'a']; j++)
                res += S[i];
            v[S[i] - 'a'] = 0;
        }
        for (i = 0; i < 26; i++)
            for (j = 0; j < v[i]; j++)
                res += i + 'a';

        return res;
    }
};