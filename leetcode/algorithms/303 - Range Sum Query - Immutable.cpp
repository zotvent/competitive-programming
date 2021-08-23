class NumArray {
    vector<int> sum;
    
public:
    NumArray(vector<int>& nums) {
        sum = nums;
        for (int i = 1; i < nums.size(); i++) {
            sum[i] += sum[i - 1];
        } 
    }
    
    int sumRange(int left, int right) {
        return sum[right] - (left == 0 ? 0 : sum[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */