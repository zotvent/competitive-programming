/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
    
    int middle(int l, int r) {
        return l + (r - l) / 2;
    }
    
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (bottomLeft[0] > topRight[0] || bottomLeft[1] > topRight[1]) {
            return 0;
        }
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (topRight == bottomLeft) {
            return 1;
        }
        
        int x = middle(bottomLeft[0], topRight[0]);
        int y = middle(bottomLeft[1], topRight[1]);
        
        return countShips(sea, {x, y}, bottomLeft) +
            countShips(sea, {x, topRight[1]}, {bottomLeft[0], y + 1}) +
            countShips(sea, topRight, {x + 1, y + 1}) +
            countShips(sea, {topRight[0], y}, {x + 1, bottomLeft[1]});
    }
};