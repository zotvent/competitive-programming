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
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;
const int p = 31;

class Solution {
    string text, pattern;
    vector<ll> p_pow, hash_text;
    ll hash;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> pattern >> text;
    }
    
    void output() {
    }
    
    void solution() {
        prepare();

        for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
            ll cur = hash_text[i + pattern.size() - 1];
            if (i) cur -= hash_text[i - 1];
            if (cur == hash * p_pow[i])
                cout << i << ' ';
        }
    }

    void prepare() {
        // all pows of p
        p_pow.resize(max(pattern.size(), text.size()));
        p_pow[0] = 1;
        for (int i = 1; i < p_pow.size(); i++)
            p_pow[i] = p_pow[i - 1] * p;

        // all hashes of text
        hash_text.resize(text.size());
        for (int i = 0; i < text.size(); i++) {
            hash_text[i] = (text[i] - 'a' + 1) * p_pow[i];
            if (i) hash_text[i] += hash_text[i - 1];
        }

        // hash of the pattern
        for (int i = 0; i < pattern.size(); i++)
            hash += pattern[i] * p_pow[i];
    }
    
public:

    Solution() {
        hash = 0;
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
