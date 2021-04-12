class Solution {
    
    struct UnionFind {
        
        UnionFind(int size) {
            nums.resize(size);
            sizes.resize(size);
            for (int i = 0; i < size; i++) {
                nums[i] = i;
                sizes[i] = 1;
            }
        }
        
        // returns size of the bigger root
        int add(int l, int r) {
            int left = root(l);
            int right = root(r);
            
            if (left == right) {
                return sizes[left];
            }
            else if (sizes[left] > sizes[right]) {
                nums[right] = left;
                sizes[left] += sizes[right];
                return sizes[left];
            }
            else {
                nums[left] = right;
                sizes[right] += sizes[left];
                return sizes[right];
            }
        }
        
    private:
        vector<int> nums, sizes;
        
        int root(int id) {
            while (nums[id] != id) {
                if (nums[id] != nums[nums[id]]) {
                    nums[id] = nums[nums[id]];
                }
                id = nums[id];
            }
            return id;
        }
    };
    
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        UnionFind uf(N);
        int size;
        
        sort(logs.begin(), logs.end());
        
        for (auto& log: logs) {
            size = uf.add(log[1], log[2]);
            
            if (size == N) {
                return log[0];
            }
        }
        
        return -1;
    }
};