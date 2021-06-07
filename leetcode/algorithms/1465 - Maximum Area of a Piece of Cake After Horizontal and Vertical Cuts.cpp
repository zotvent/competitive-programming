class Solution {
    
    int calcMax(vector<int>& cuts, int size) {
        int maxi = 0, prev = 0;
        
        for (auto& i: cuts) {
            maxi = max(maxi, i - prev);
            prev = i;
        }
        maxi = max(maxi, size - prev);
        
        return maxi;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        const int mod = (int) 1e9 + 7;
        long long maxHorCut = calcMax(horizontalCuts, h);
        long long maxVerCut = calcMax(verticalCuts, w);
        
        return (maxHorCut * maxVerCut) % mod;
    }
};