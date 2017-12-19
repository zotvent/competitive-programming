class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < ops.size(); i++) 
            if (ops[i] == "C") {
                if (v.size() > 0) {
                    sum -= v[v.size()-1];
                    v.pop_back();  
                }
            }
            else if (ops[i] == "D") {
                if (v.size() > 0) {
                    int temp = v[v.size()-1]*2;
                    v.push_back(temp);
                    sum += temp;   
                }
            }
            else if (ops[i] == "+") {
                int temp = 0;
                if (v.size() > 0)
                    temp += v[v.size()-1];
                if (v.size() > 1)
                    temp += v[v.size()-2];
                v.push_back(temp);
                sum += temp;
            }
            else {
                int temp = stoi(ops[i]);
                v.push_back(temp);
                sum += temp;
            }
        return sum;
    }
};