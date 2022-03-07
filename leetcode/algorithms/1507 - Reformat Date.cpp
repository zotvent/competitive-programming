class Solution {
    
    vector<string> split(string& s) {
        vector<string> res;
        string cur = "";
        
        for (auto& i: s) {
            if (i == ' ') {
                res.push_back(cur);
                cur.clear();
            }
            else cur.push_back(i);
        }
        res.push_back(cur);
        
        return res;
    }
    
    int parseDay(string& s) {
        string day = "";
        int i = 0;
        
        while (i < s.size() && isdigit(s[i])) {
            day.push_back(s[i++]);
        }
        
        return stoi(day);
    }
    
    string leadingZero(int n) {
        return (n < 10 ? "0" : "") + to_string(n);
    }
    
    string format(int day, int month, int year) {
        return to_string(year) +
            "-" +
            leadingZero(month) +
            "-" +
            leadingZero(day);
    }
    
public:
    string reformatDate(string date) {
        vector<string> parts = split(date);
        unordered_map<string, int> months = {
            {"Jan", 1},
            {"Feb", 2},
            {"Mar", 3},
            {"Apr", 4},
            {"May", 5},
            {"Jun", 6},
            {"Jul", 7},
            {"Aug", 8},
            {"Sep", 9},
            {"Oct", 10},
            {"Nov", 11},
            {"Dec", 12},
        };
        int day = parseDay(parts[0]);
        int month = months[parts[1]];
        int year = stoi(parts[2]);
        return format(day, month, year);
    }
};