class Solution {
    
    vector<vector<int>> dp;
    int rows, cols;
    int const inf = INT_MAX;
    
    int getHealth(int curCell, int nextRow, int nextCol) {
        if (nextRow >= rows || nextCol >= cols) {
            return inf;
        }
        return max(1, dp[nextRow][nextCol] - curCell);
    }
    
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        rows = dungeon.size();
        cols = (dungeon.empty() ? 0 : dungeon[0].size());

        dp.assign(rows, vector<int>(cols, inf));
        
        int curHealth, rightHealth, downHealth, nextHealth, minHealth;
        
        for (int i = rows - 1; i >=0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                curHealth = dungeon[i][j];
                
                rightHealth = getHealth(curHealth, i, j + 1);
                downHealth = getHealth(curHealth, i + 1, j);
                nextHealth = min(rightHealth, downHealth);
                
                if (nextHealth != inf) {
                    minHealth = nextHealth;
                }
                else {
                    minHealth = (curHealth < 0 ? 1 - curHealth : 1);
                }
                
                dp[i][j] = minHealth;
            }
        }

        return dp[0][0];
    }
};