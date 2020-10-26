/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0;
        int r = INT_MAX;
        int m, value;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            value = reader.get(m);
            
            if (value == INT_MAX || value > target) {
                r = m - 1;
            }
            else if (value == target) {
                return m;
            }
            else {
                l = m + 1;
            }
        }
        
        return -1;
    }
};