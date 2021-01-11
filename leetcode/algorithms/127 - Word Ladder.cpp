class Solution {
    
    bool difByOne(string& left, string& right) {
        if (left.size() != right.size()) {
            return false;
        }
        
        int cnt = 0;
        
        for (int i = 0; i < left.size(); i++) {
            cnt += left[i] != right[i];
        }
        
        return cnt == 1;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<int> indexes, remove;
        int steps = 0, size;
        string cur;
        
        q.push(beginWord);
        
        for (int i = 0; i < wordList.size(); i++) {
            indexes.insert(i);
        }
        
        while (!q.empty()) {
            size = q.size();
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                if (cur == endWord) {
                    return steps + 1;
                }
                
                for (auto i = indexes.begin(); i != indexes.end(); i++) {
                    if (difByOne(cur, wordList[*i]) && remove.count(*i) == 0) {
                        q.push(wordList[*i]);
                        remove.insert(*i);
                    }
                }
            }
            
            for (auto i = remove.begin(); i != remove.end(); i++) {
                indexes.erase(*i);
            }
            remove.clear();
            
            steps++;
        }
        
        return 0;
    }
};