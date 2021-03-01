class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;
    
    MaxStack() { 
    }
    
    void push(int x) {
        v.insert(v.begin(),x);
        mp[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};