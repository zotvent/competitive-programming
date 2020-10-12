class Solution {
    
    void addIfNotExistsOrRemove(unordered_set<string>& seen, int x, int y) {
        string key = generateKey(x, y);
        
        if (seen.count(key) > 0) seen.erase(key);
        else seen.insert(key);
    }
    
    bool contains(unordered_set<string>& seen, int x, int y) {
        return seen.count(generateKey(x, y)) > 0;
    }
    
    string generateKey(int x, int y) {
        return to_string(x) + " " + to_string(y);
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) {
            return true;
        }
        
        unordered_set<string> corners;
        int area = 0;
        
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        
        for (auto& r: rectangles) {
            x1 = min(x1, r[0]);
            y1 = min(y1, r[1]);
            x2 = max(x2, r[2]);
            y2 = max(y2, r[3]);
            
            area += (r[2] - r[0]) * (r[3] - r[1]);
            
            addIfNotExistsOrRemove(corners, r[0], r[1]);
            addIfNotExistsOrRemove(corners, r[0], r[3]);
            addIfNotExistsOrRemove(corners, r[2], r[1]);
            addIfNotExistsOrRemove(corners, r[2], r[3]);
        }
                
        if (corners.size() != 4 ||
            !contains(corners, x1, y1) ||
            !contains(corners, x1, y2) ||
            !contains(corners, x2, y1) ||
            !contains(corners, x2, y2)) {
            return false;
        }
        
        return area == (x2 - x1) * (y2 - y1);
    }
};