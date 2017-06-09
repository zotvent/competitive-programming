class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        const int N = 200005;
        int kinds[N], shift = 100000;
        size_t cnt = 0;
        for (int i = 0; i < N; i++) {
            kinds[i] = 0;
        }
        for (int i = 0; i < candies.size(); i++) {
            if (!kinds[candies[i]+shift]) {
                kinds[candies[i]+shift] = 1;
                cnt++;
            }
        }
        return min(cnt, candies.size()/2);
    }
};