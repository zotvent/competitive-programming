class Solution {
public:
    string toGoatLatin(string S) {
        string res = "";
        int index = 0;
        bool wordStarted = false;
        bool startsWithVowel = false;
        char firstLetter = 'a';

        for (int i = 0; i <= S.size(); i++) {
            if (i == S.size() || S[i] == ' ') {
                if (wordStarted) {
                    wordStarted = false;

                    if (startsWithVowel) res += "ma";
                    else {
                        res += firstLetter;
                        res += "ma";
                    }

                    res += endFor(index);
                    if (i < S.size()) res += S[i];
                }
                else {
                    if (i < S.size()) res += S[i];
                }
            }
            else {
                if (wordStarted) res += S[i];
                else {
                    wordStarted = true;
                    startsWithVowel = isVowel(S[i]);

                    if (startsWithVowel) res += S[i];
                    else firstLetter = S[i];

                    index++;
                }
            }
        }

        return res;
    }

    bool isVowel(char c) {
        string vowels = "aeiou";
        for (int i = 0; i < vowels.size(); i++)
            if (vowels[i] == tolower(c))
                return true;
        return false;
    }

    string endFor(int index) {
        string res = "";
        for (int i = 0; i < index; i++)
            res += "a";
        return res;
    }
};