class Solution {
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings, int l, int r) {
        vector<vector<int>> res;
        
        if (l > r) {
            return res;
        }
        
        if (l == r) {
            res.push_back({buildings[l][0], buildings[l][2]});
            res.push_back({buildings[l][1], 0});
            return res;
        }
        
        int m = l + (r - l) / 2;
        vector<vector<int>> left = getSkyline(buildings, l, m);
        vector<vector<int>> right = getSkyline(buildings, m + 1, r);
        
        return mergeSkylines(left, right);
    }
    
    vector<vector<int>> mergeSkylines(vector<vector<int>> left, vector<vector<int>> right) {
        vector<vector<int>> res;
        
        vector<int> sizes = { (int) left.size(), (int) right.size() };
        vector<int> head(2, 0);
        int x = 0, y = 0;;
        int maxY, leftY = 0, rightY = 0;
        
        vector<int> leftPoint, rightPoint;
        
        while (head[0] < sizes[0] && head[1] < sizes[1]) {
            leftPoint = left[head[0]];
            rightPoint = right[head[1]];
            
            // find point with smaller X coordinate
            if (leftPoint[0] < rightPoint[0]) {
                x = leftPoint[0];
                leftY = leftPoint[1];
                head[0]++;
            }
            else {
                x = rightPoint[0];
                rightY = rightPoint[1];
                head[1]++;
            }
            
            maxY = max(leftY, rightY);
            
            if (y != maxY) {
                updateRes(res, x, maxY);
                y = maxY;
            }
        }
        
        appendSkyline(res, left, head[0], y);
        appendSkyline(res, right, head[1], y);
        
        return res;
    }
    
    void updateRes(vector<vector<int>>& res, int x, int y) {
        if (res.empty() || res.back()[0] != x) {
            res.push_back({x, y});
        }
        else {
            res.back()[1] = y;
        }
    }
    
    void appendSkyline(vector<vector<int>>& res, vector<vector<int>> &skyline, int start, int& curY) {
        vector<int> point;
        
        for (int i = start; i < skyline.size(); i++) {
            point = skyline[i];
            
            if (curY != point[1]) {
                updateRes(res, point[0], point[1]);
                curY = point[1];
            }
        }
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) {
            vector<vector<int>> res;
            return res;
        }
        
        return getSkyline(buildings, 0, (int) buildings.size() - 1);
    }
};