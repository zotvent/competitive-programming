/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int rows = binaryMatrix.dimensions()[0];
        const int cols = binaryMatrix.dimensions()[1];
        int r = rows - 1, c = cols - 1;
        int res = cols;
        
        while (r >= 0 && c >= 0) {
            if (binaryMatrix.get(r, c) == 0) r--;
            else {
                res = min(res, c);
                c--;
            }
        }
        
        return res < cols ? res : -1;
    }
};