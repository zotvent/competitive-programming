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

const int inf = 1e9 + 5;
const int N = 1e6;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    string s;
    stack<int> numbers;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    void prepare() {
    }
    
    void output() {
        cout << numbers.top();
    }
    
    void solution() {
        while (cin >> s) {
            if (isOperation(s)) {
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();

                if (s == "+") {
                    second += first;
                }
                else if (s == "-") {
                    second -= first;
                }
                else {
                    second *= first;
                }

                numbers.push(second);
            }
            else {
                numbers.push(stoi(s));
            }
        }
    }

    bool isOperation(string str) {
        return s == "+" || s == "-" || s == "*";
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
