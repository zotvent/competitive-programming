class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        
        vector<string> letterLogs, digitLogs;
        
        string id;
        size_t i;
        
        for (auto log: logs) {
            i = log.find_first_of(" ");
            id = log.substr(0, i - 1);
            
            if (isalpha(log[i + 1])) {
                letterLogs.push_back(log);
            }
            else {
                digitLogs.push_back(log);
            }
        }
        
        sort(letterLogs.begin(), letterLogs.end(), comp);
        
        for (auto log: letterLogs) res.push_back(log);
        for (auto log: digitLogs) res.push_back(log);
        
        return res;
    }
    
    static bool comp(string left, string right) {
        size_t leftDelimeter = left.find_first_of(" ");
        size_t rightDelimeter = right.find_first_of(" ");
        
        string leftLog = left.substr(leftDelimeter + 1);
        string rightLog = right.substr(rightDelimeter + 1);
        
        if (leftLog != rightLog) {
            return leftLog < rightLog;
        }
        else {
            return left.substr(0, leftDelimeter) < right.substr(0, rightDelimeter);
        }
    }
};