class Solution {
public:
    int nthUglyNumber(int n) {
        const int size = 1690;
        
        vector<int> ugly(size);
        ugly[0] = 1;

        vector<int> p(3, 0);
        int next;

        for (int i = 1; i < size; i++) {
            next = min(ugly[p[0]] * 2, min(ugly[p[1]] * 3, ugly[p[2]] * 5));
            ugly[i] = next;

            if (next == ugly[p[0]] * 2) p[0]++;
            if (next == ugly[p[1]] * 3) p[1]++;
            if (next == ugly[p[2]] * 5) p[2]++;
        }

        return ugly[n - 1];
    }
};