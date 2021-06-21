class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> res;
        const int n = colors.size();
        vector<vector<int>> left(n, vector<int>(3, -1)), right(n, vector<int>(3, -1));
        int index, color, cur;
        
        for (int i = 0; i < n; i++) {
            left[i][colors[i] - 1] = 0;
            
            color = colors[i] % 3;
            left[i][color] = (i == 0 || left[i - 1][color] == -1) ? -1 : left[i - 1][color] + 1;
            
            color = (colors[i] + 1) % 3;
            left[i][color] = (i == 0 || left[i - 1][color] == -1) ? -1 : left[i - 1][color] + 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            right[i][colors[i] - 1] = 0;
            
            color = colors[i] % 3;
            right[i][color] = (i == n - 1 || right[i + 1][color] == -1) ? -1 : right[i + 1][color] + 1;
            
            color = (colors[i] + 1) % 3;
            right[i][color] = (i == n - 1 || right[i + 1][color] == -1) ? -1 : right[i + 1][color] + 1;
        }
        
        for (auto& i: queries) {
            index = i[0];
            color = i[1] - 1;
            
            if (left[index][color] != -1 && right[index][color] != -1) {
                cur = min(left[index][color], right[index][color]);
            }
            else if (left[index][color] == -1 && right[index][color] == -1) {
                cur = -1;
            }
            else if (left[index][color] != -1) {
                cur = left[index][color];
            }
            else cur = right[index][color];
            
            res.push_back(cur);
        }
        
        return res;
    }
};