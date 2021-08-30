class Solution {
    
    vector<string> split(string& s) {
        vector<string> res;
        string cur = "";
        
        for (auto& c: s) {
            if (c == ',') {
                res.push_back(cur);
                cur.clear();
            }
            else cur.push_back(c);
        }
        res.push_back(cur);
        
        return res;
    }
    
    bool reversePreorder(vector<string>& values, int& head) {
        if (head == values.size()) {
            return false;
        }
        
        if (values[head++] == "#") {
            return true;
        }
        
        return reversePreorder(values, head) && reversePreorder(values, head);
    }
    
public:
    bool isValidSerialization(string preorder) {
        vector<string> values = split(preorder);
        int head = 0;
        return reversePreorder(values, head) && head == values.size();
    }
};