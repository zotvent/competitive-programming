class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        
        for (int i = 0; candies > 0; ++i) {
            res[i % num_people] += min(candies, i + 1);
            candies -= i + 1;
        }
        
        return res;
    }
};