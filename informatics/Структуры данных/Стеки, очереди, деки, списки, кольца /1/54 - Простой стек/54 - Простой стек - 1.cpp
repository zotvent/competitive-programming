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
const int N = 1e2+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

template<typename T>
struct Stack {
    
    Stack() {
        head = -1;
        m_size = 0;
        for (int i = 0; i < N; i++)
            elements[i] = 0;
    }
    
    void push(T x) {
        elements[++head] = x;
        m_size++;
        cout << "ok" << endl;
    }
    
    T pop() {
        T res = back();
        elements[head--] = 0;
        m_size--;
        return res;
    }
    
    T back() {
        return elements[head];
    }
    
    int size() {
        return m_size;
    }
    
    void clear() {
        for (int i = 0; i <= head; i++)
            elements[i] = 0;
        head = 0;
        m_size = 0;
        cout << "ok" << endl;
    }

private:
    int m_size;
    T elements[N];
    int head;
};

class Solution {
    
    Stack<int> stack = Stack<int>();
    string command;
    int number;
    
    void print() {
    }
    
    void input() {
        speed
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        while (true) {
            cin >> command;
            if (command == "push") {
                cin >> number;
                stack.push(number);
            }
            else if (command == "pop") {
                int res = stack.pop();
                cout << res << endl;
            }
            else if (command == "back") {
                int res = stack.back();
                cout << res << endl;
            }
            else if (command == "size") {
                int size = stack.size();
                cout << size << endl;
            }
            else if (command == "clear")
                stack.clear();
            else if (command == "exit") {
                cout << "bye" << endl;
                break;
            }
        }
    }
    
    void output() {
    }
    
    void solution() {
    }
    
public:
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
