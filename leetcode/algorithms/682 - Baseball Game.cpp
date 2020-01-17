class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> points;
        
        int last, pre_last;
        
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                last = points.top(); points.pop();
                pre_last = points.top();
                points.push(last);
                points.push(last + pre_last);
            }
            else if (ops[i] == "D") points.push(2 * points.top());
            else if (ops[i] == "C") points.pop();
            else points.push(stoi(ops[i]));
        }
        
        int res = 0;
        
        while (!points.empty()) {
            res += points.top();
            points.pop();
        }
        
        return res;
    }
};