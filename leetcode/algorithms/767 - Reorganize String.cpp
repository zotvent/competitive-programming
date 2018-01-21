class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        vector<int> cnt(26, 0);
        int mx = 0;
        int n =  S.length();

        for (int i = 0; i < n; i++) {
            cnt[S[i]-'a']++;
            mx = max(mx, cnt[S[i]-'a']);
        }

        if (mx <= (n+1) / 2) {
            for (int i = 0; i < n; i++) {
                mx = 0;
                char c = 'a';
                for (int j = 0; j < 26; j++) {
                    if (res.length() == 0) {
                        if (cnt[j] > mx) {
                            mx = cnt[j];
                            c = j+'a';
                        }
                    }
                    else {
                        if (cnt[j] > mx && j+'a' != res[res.length()-1]) {
                            mx = cnt[j];
                            c = j+'a';
                        }
                    }
                }
                res += c;
                cnt[c-'a']--;
            }
        }

        return res;
    }
};