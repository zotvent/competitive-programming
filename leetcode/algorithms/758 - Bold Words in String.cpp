class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res = "";
        int n = S.length();
        vector<bool> bold(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words.size(); j++) {
                int ii = i;
                int k = 0;
                while (S[ii] == words[j][k] && ii < n && k < words[j].length()) {
                    ii++;
                    k++;
                }
                if (k == words[j].length()) {
                    for (int l = i; l < ii; l++)
                        bold[l] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if ((bold[i] && i && !bold[i-1]) || (i == 0 && bold[i]))
                res += "<b>";
            res += S[i];
            if ((i < n-1 && bold[i] && !bold[i+1]) || (i == n-1 && bold[i]))
                res += "</b>";
        }

        return res;
    }
};