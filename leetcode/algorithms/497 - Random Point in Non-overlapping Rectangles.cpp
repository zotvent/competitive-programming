class Solution {
    
    vector<vector<int>> rects;
    vector<int> area;
    
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        
        int sum = 0;
        
        for (auto& r: rects) {
            sum += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            area.push_back(sum);
        }
    }
    
    vector<int> pick() {
        int randomArea = rand() % area.back();
        
        int lo = 0;
        int hi = area.size() - 1;
        int mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (randomArea >= area[mid]) lo = mid + 1;
            else hi = mid;
        }
        
        vector<int> rect = rects[lo];
        int width = rect[2] - rect[0] + 1;
        int height = rect[3] - rect[1] + 1;
        int base = area[lo] - width * height;
        
        int x = rect[0] + (randomArea - base) % width;
        int y = rect[1] + (randomArea - base) / width;
        
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */