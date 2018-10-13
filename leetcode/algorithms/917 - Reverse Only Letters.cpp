class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;

        while (l < r) {
            if (isalpha(S[l]) && isalpha(S[r]))
                swap(S[l++], S[r--]);
            else if (isalpha(S[l]) && !isalpha(S[r]))
                r--;
            else
                l++;
        }

        return S;
    }
};