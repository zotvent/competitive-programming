class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.length()) return i;
                if (i+j == haystack.length()) return -1;
                if (haystack[i+j] != needle[j]) break;
            }
        }
    }
};