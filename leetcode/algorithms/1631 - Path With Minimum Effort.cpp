class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = 0, hi = (int) 1e6, mid;
        int res = hi;

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (canReach(heights, mid, dir)) {
                res = min(res, mid);
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return res;
    }

    bool canReach(vector<vector<int>>& heights, int& threshold, vector<vector<int>>& dir) {
        const int rows = heights.size();
        const int cols = (heights.empty() ? 0 : heights[0].size());

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<vector<int>> q;
        vector<int> next(2, 0), cur;
        int dif;

        visited[0][0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (cur[0] == rows - 1 && cur[1] == cols - 1) {
                return true;
            }

            for (int i = 0; i < dir.size(); i++) {
                next[0] = cur[0] + dir[i][0];
                next[1] = cur[1] + dir[i][1];

                if (valid(next, rows, cols) && !visited[next[0]][next[1]]) {
                    dif = abs(heights[cur[0]][cur[1]] - heights[next[0]][next[1]]);

                    if (dif <= threshold) {
                        visited[next[0]][next[1]] = 1;
                        q.push(next);
                    }
                }
            }
        }

        return false;
    }

    bool valid(vector<int>& loc, int rows, int cols) {
        return loc[0] >= 0 && loc[0] < rows && loc[1] >= 0 && loc[1] < cols;
    }
};