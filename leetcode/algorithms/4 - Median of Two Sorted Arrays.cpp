class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;

        int n = nums1.size();
        int m = nums2.size();

        int head = 0;
        int l = 0;
        int r = 0;

        vector<int> last(2, 0);

        while (head <= (n + m) / 2) {
            swap(last[0], last[1]);

            if (l >= nums1.size()) {
                last[1] = nums2[r++];
            }
            else if (r >= nums2.size()) {
                last[1] = nums1[l++];
            }
            else if (nums1[l] <= nums2[r]) {
                last[1] = nums1[l++];
            }
            else {
                last[1] = nums2[r++];
            }

            head++;
        }

        if ((n + m) % 2 == 0) {
            res = (last[0] + last[1]) / 2.0;
        }
        else {
            res = last[1];
        }

        return res;
    }
};