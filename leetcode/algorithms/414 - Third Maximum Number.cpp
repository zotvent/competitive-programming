class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mn = (long long) INT_MIN - 1L;
        long long first = mn;
        long long second = mn;
        long long third = mn;
        
        for (auto i: nums) {
            if (i > first) {
                third = second;
                second = first;
                first = i;
            }
            else if (i > second && i != first) {
                third = second;
                second = i;
            }
            else if (i > third && i != second && i != first) {
                third = i;
            }
        }
        
        return (third == mn ? first : third);
    }
};