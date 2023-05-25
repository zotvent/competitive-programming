class Solution {

    long long parseLong(string s) {
        long long res = 0L;
        for (auto& i: s) {
            res *= 10;
            res += i - '0';
        }
        return res;
    }

    long long generatePalindrome(long long left, bool isEven) {
        long long res = left;
        if (!isEven) left /= 10;
        while (left > 0) {
            res *= 10;
            res += left % 10;
            left /= 10;
        }
        return res;
    }

public:
    string nearestPalindromic(string n) {
        int size = n.size();
        bool isEven = size % 2 == 0;
        int half = (size + 1) / 2;
        long long left = parseLong(n.substr(0, half));
        vector<long long> candidates;
        candidates.push_back(generatePalindrome(left, isEven));
        candidates.push_back(generatePalindrome(left + 1, isEven));
        candidates.push_back(generatePalindrome(left - 1, isEven));
        candidates.push_back((long long) pow(10, size - 1) - 1);
        candidates.push_back((long long) pow(10, size) + 1);

        long long res = 0, diff = LONG_LONG_MAX, N = parseLong(n);
        for (auto& i: candidates) {
            if (i == N) continue;
            if (abs(i - N) < diff) {
                diff = abs(i - N);
                res = i;
            }
            else if (abs(i - N) == diff) {
                res = min(res, i);
            }
        }
        return to_string(res);
    }
};
