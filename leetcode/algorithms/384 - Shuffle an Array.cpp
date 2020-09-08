class Solution {
    
    vector<int> original;
    
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = original;
        int randomIndex;
        
        for (int i = 0; i < res.size(); i++) {
            randomIndex = i + rand() % (res.size() - i);
            swap(res[i], res[randomIndex]);
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */