class Solution {
public:
    int missingNumber(vector<int>& arr) {        
        int n = (int) arr.size();
        int shouldBeSum = (arr[0] + arr.back()) * (n + 1) / 2 ;
        int realSum = 0;
        
        for (auto i: arr) realSum += i;   
        
        return shouldBeSum - realSum;
    }
};