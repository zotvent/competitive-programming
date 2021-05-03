class Solution {
    
    bool hasSquare(vector<int>& rec) {
        return (rec[3] - rec[1]) > 0 && (rec[2] - rec[0]) > 0;
    }
    
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool notIntersectByX = (rec1[0] >= rec2[2] || rec1[2] <= rec2[0]);
        bool notIntersectByY = (rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
        return !(notIntersectByX || notIntersectByY) && hasSquare(rec1) && hasSquare(rec2);
    }
};