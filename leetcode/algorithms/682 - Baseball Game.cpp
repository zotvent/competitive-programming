class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> scores;
        
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int last = scores.top();
                scores.pop();
                int pre_last = scores.top();
                
                scores.push(last);
                scores.push(last + pre_last);
            }
            else if (ops[i] == "D") {
                scores.push(scores.top() * 2);
            }
            else if (ops[i] == "C") {
                scores.pop();
            }
            else {
                scores.push(stoi(ops[i]));
            }
        }
        
        while (!scores.empty()) {
            int top = scores.top();
            scores.pop();
            res += top;
        }
        
        return res;
    }
};