class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);

        while (area % w != 0) 
            w--;
        
        vector<int> v;
        v.push_back(area/w);
        v.push_back(w);
        return v;
    }
};