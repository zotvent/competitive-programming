class NumArray {
    vector<int> nums;
    int size;
    
    void build(vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            nums[v] = arr[tl - 1];
            return;
        }

        int tm = tl + (tr - tl) / 2;
        build(arr, 2*v, tl, tm);
        build(arr, 2*v + 1, tm + 1, tr);
        nums[v] = nums[2*v] + nums[2*v+1];
    }
    
    void update(int v, int tl, int tr, int index, int val) {
        if (tl == tr) {
            if (tl == index) nums[v] = val;
            return;
        }
        
        int tm = tl + (tr - tl) / 2;
        if (index <= tm) update(2*v, tl, tm, index, val);
        else update(2*v + 1, tm + 1, tr, index, val);
        nums[v] = nums[2*v] + nums[2*v + 1];
    }
    
    int sum(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) return 0;
        if (l <= tl && tr <= r) {
            return nums[v];
        }

        int tm = (tl + tr) / 2;
        return sum(2*v, tl, tm, l, r) + sum(2*v + 1, tm + 1, tr, l, r);
    }
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        this->nums.resize(4 * size);
        build(nums, 1, 1, size);
    }
    
    void update(int index, int val) {
        update(1, 1, size, index + 1, val);
    }
    
    int sumRange(int left, int right) {
        return sum(1, 1, size, left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */