class Solution {
    
    bool isPrefix(string& word, string& prefix) {
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> g;
        unordered_map<char, int> incomingEdges;
        string left, right;
        
        for (auto& word: words) {
            for (auto& c: word) {
                incomingEdges[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            left = words[i];
            right = words[i + 1];
            
            if (left.size() > right.size() && isPrefix(left, right)) {
                return "";
            }
            
            for (int j = 0; j < min(left.size(), right.size()); j++) {
                if (left[j] != right[j]) {
                    g[left[j]].push_back(right[j]);
                    incomingEdges[right[j]]++;
                    break;
                }
            }
        }
        
        string res;
        queue<char> q;
        char cur;
        
        for (auto& it: incomingEdges) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            res.push_back(cur);

            for (auto& next: g[cur]) {
                incomingEdges[next]--;
                if (incomingEdges[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if (res.size() != incomingEdges.size()) {
            return "";
        }
        
        return res;
    }
};