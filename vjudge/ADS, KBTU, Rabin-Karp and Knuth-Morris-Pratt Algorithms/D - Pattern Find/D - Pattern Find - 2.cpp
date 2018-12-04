#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e5+5;
const int mod = 1e5+5;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int t;
    string text, pattern;
    vector<int> res;
    
    void print(int i) {
        if (i) cout << endl;

        if (res.empty()) cout << "Not Found\n";
        else {
            cout << res.size() << endl;
            for (int i = 0; i < res.size(); i++) {
                if (i) cout << ' ';
                cout << res[i];
            }
            cout << endl;
        }
    }
    
    void input() {
        speed
        cin >> t;
    }
    
    void output() {
    }
    
    void solution() {
        for (int j = 0; j < t; j++) {
            cin >> text >> pattern;
            prefix_find();
            print(j);
            res.clear();
        }
    }

    void prefix_find() {
        vector<size_t> pi(pattern.size());
        pi[0] = 0;

        size_t l;
        for (l = 1; pattern[l]; ++l) {
            size_t j = pi[l - 1];
            while (j > 0 && pattern[l] != pattern[j]) j = pi[j-1];
            if (pattern[l] == pattern[j]) ++j;
            pi[l] = j;
        }

        size_t j = 0;
        for (size_t i = 0; text[i]; ++i) {
            while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
            if (text[i] == pattern[j]) ++j;
            if (j == l) res.pb(i - l + 2);
        }
    } 
    
public:
    
    Solution() {
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}