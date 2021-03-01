class Solution {
public:
    int scoreOfParentheses(string S) {        
        stack<int> nums;
        nums.push(0);
        
        int last, prelast;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') nums.push(0);
            else {
                last = nums.top();
                nums.pop();
                
                prelast = nums.top();
                nums.pop();
                
                nums.push(prelast + max(2 * last, 1));
            }
        }
        
        return nums.top();
    }
};