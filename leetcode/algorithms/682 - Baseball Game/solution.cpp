class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        vector<int> scores;
        
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "D")
                scores.push_back(scores.back() * 2);
            else if (ops[i] == "C")
                scores.pop_back();
            else if (ops[i] == "+") {
                int last = scores.back();
                int pre = scores[scores.size() - 2];
                scores.push_back(pre + last);
            }
            else
                scores.push_back(stoi(ops[i]));
        }
        
        for (int i = 0; i < scores.size(); i++)
            res += scores[i];
        
        return res;
    }
};