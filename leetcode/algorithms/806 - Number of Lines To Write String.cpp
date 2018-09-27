class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1, last = 0, cur = 0;

        for (int i = 0; i < S.length(); i++) {
            int w = widths[S[i] - 'a'];

            if (cur + w <= 100) 
                cur += w;
            else {
                lines++;
                cur = w;
            }

            last = cur;
        }

        vector<int> res = {lines, last};
        return res;
    }
};