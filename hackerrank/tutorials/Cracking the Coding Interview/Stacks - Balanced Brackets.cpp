#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isOpenBracket(char c) {
    return c == '{' || c == '[' || c == '(';
}

bool matchPair(char open, char close) {
    return  (open == '{' && close == '}') ||
            (open == '[' && close == ']') ||
            (open == '(' && close == ')');
}

bool is_balanced(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
        if (isOpenBracket(expression[i]))
            s.push(expression[i]);
        else {
            if (s.size() > 0 && matchPair(s.top(), expression[i]))
                s.pop();
            else
                s.push(expression[i]);
        }
    return s.size() == 0;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
