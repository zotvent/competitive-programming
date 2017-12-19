class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char const k = 'z'+1;
        char bigger = k;
        char less = k;
        for (auto c: letters) {
            if (c > target && c < bigger)
                bigger = c;
            if (c < target && c < less)
                less = c;
        }
        return (bigger != k ? bigger : less);
    }
};