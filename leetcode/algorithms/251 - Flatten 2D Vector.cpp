class Vector2D {
    
    vector<vector<int>> arr;
    int row, col;
    
public:
    Vector2D(vector<vector<int>>& v) {
        row = col = 0;
        for (int i = 0; i < v.size(); i++) {
            row = i;
            if (!v[i].empty()) {
                break;
            }
        }
        arr = v;
    }
    
    int next() {
        int res = arr[row][col];
        
        col++;
        if (col == arr[row].size()) {
            row++;
            col = 0;
            while (row < arr.size() && arr[row].empty()) {
                row++;
            }
        }
        
        return res;
    }
    
    bool hasNext() {
        return row < arr.size() && col < arr[row].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */