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

            vector<int> prefix = prefix_function(pattern + "#" + text);
            

            for (int i = pattern.size() + 1; i < prefix.size(); i++) {
                if (prefix[i] == pattern.size())
                    res.pb(i - 2 * pattern.size() + 1);
            }

            print(j);
            res.clear();
        }
    }

    vector<int> prefix_function (string s) {
        int n = (int) s.length();
        vector<int> pi (n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j])  ++j;
            pi[i] = j;
        }
        return pi;
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