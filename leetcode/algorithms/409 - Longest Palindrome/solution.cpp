class Solution {
public:
    int longestPalindrome(string s) {
        int const N = 128;
        int cnt[N];
        for (int i = 0; i < N; i++) cnt[i] = 0;

        for (int i = 0; i < s.length(); i++) cnt[s[i]]++;

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (cnt[i] > 1) {
                res += (cnt[i]/2) * 2;
                cnt[i] -= (cnt[i]/2) * 2;
            }
        }
        for (int i = 0; i < N; i++) {
            if (cnt[i] > 0) {
                res++;
                break;
            }
        }
        return res;
    }
};
