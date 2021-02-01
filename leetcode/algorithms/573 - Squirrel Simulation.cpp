class Solution {
    
    int distance(vector<int>& from, vector<int>& to) {
        return abs(from[0] - to[0]) + abs(from[1] - to[1]);
    }
    
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = 0, dif = INT_MAX;
        
        for (int i = 0; i < nuts.size(); i++) {
            res += 2 * distance(tree, nuts[i]);
            dif = min(dif, distance(squirrel, nuts[i]) - distance(nuts[i], tree));            
        }
        
        return res + dif;
    }
};