class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        const int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                res++;
                flowerbed[i] = 1;
            }
        }
        
        return res >= n;
    }
};