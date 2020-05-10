class FirstUnique {
private:
    unordered_map<int, int> numToCnt, numToIndex;
    set<pair<int, int>> indexToNum;
    int cnt;
    
public:
    FirstUnique(vector<int>& nums) {
        cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        return indexToNum.empty() ? -1 : (*(indexToNum.begin())).second;
    }
    
    void add(int value) {
        numToCnt[value]++;
        if (numToCnt[value] == 1) {
            numToIndex[value] = cnt;
            indexToNum.insert({cnt, value});
        }
        else {
            indexToNum.erase({numToIndex[value], value});
        }
        cnt++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */