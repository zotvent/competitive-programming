class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        double res = 0;
        
        int x = nums1.size();
        int y = nums2.size();
        
        int lo = 0;
        int hi = nums1.size();
        
        int partitionX, maxLeftX, minRightX;
        int partitionY, maxLeftY, minRightY;
        
        while (lo <= hi) {
            partitionX = lo + (hi - lo) / 2;
            partitionY = (x + y + 1) / 2 - partitionX;
            
            maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    res = (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
                else {
                    res = max(maxLeftX, maxLeftY);
                }
                break;
            }
            else if (maxLeftX > minRightY) {
                hi = partitionX - 1;
            }
            else {
                lo = partitionX + 1;
            }
        }
        
        return res;
    }
};