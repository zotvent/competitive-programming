class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tankSum = 0;
        int sum = 0, start = 0;
        const int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            tankSum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        
        return (tankSum >= 0) ? start : -1;
    }
};