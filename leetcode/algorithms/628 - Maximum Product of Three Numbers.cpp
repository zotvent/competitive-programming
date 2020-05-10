class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> mn(2, INT_MAX);
        vector<int> mx(3, INT_MIN);
        
        for (auto i: nums) {
            if (i < mn[0]) {
                mn[1] = mn[0];
                mn[0] = i;
            }
            else if (i < mn[1]) {
                mn[1] = i;
            }
            
            if (i > mx[2]) {
                mx[0] = mx[1];
                mx[1] = mx[2];
                mx[2] = i;
            }
            else if (i > mx[1]) {
                mx[0] = mx[1];
                mx[1] = i;
            }
            else if (i > mx[0]) {
                mx[0] = i;
            }
        }
        
        return max(mn[0] * mn[1] * mx[2], mx[0] * mx[1] * mx[2]);
    }
};