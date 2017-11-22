#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    // Complete this function
    int min = s[0], max = s[0];
    int min_cnt = 0, max_cnt = 0;
    for (int i = 1; i < s.size(); i++) 
        if (s[i] < min) {
            min = s[i];
            min_cnt++;
        }
        else if (s[i] > max) {
            max = s[i];
            max_cnt++;
        }
    vector<int> v;
    v.push_back(max_cnt);
    v.push_back(min_cnt);
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
