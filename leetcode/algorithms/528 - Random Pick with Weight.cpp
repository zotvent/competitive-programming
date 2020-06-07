class Solution {
private:
    vector<int> prefixSums;
    
public:
    Solution(vector<int>& w) {
        for (auto& i: w) {
            prefixSums.push_back(i + (prefixSums.empty() ? 0 : prefixSums.back()));
        }
    }
    
    int pickIndex() {
        float randomNum = (float) rand() / RAND_MAX;
        float target = randomNum * prefixSums.back();
        return upper_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */