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

vector<int> cnt;

int atIndex(char c) {
    return (c == '_' ? 26 : c-'A');
}

bool hasUniqueCharacters() {
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 1)
            return true;
    return false;
}

bool alreadyHappy(string s) {
    for (int i = 0; i < s.length()-1; i++) {
        if (i == 0 && s[i] != s[i+1])
            return false;
        else if (s[i-1] != s[i] && s[i] != s[i+1])
            return false;
    }
    return true;
}

bool hasSpace() {
    return cnt[26] > 0;
}

void findFrequency(string s) {
    for (int i = 0; i < s.length(); i++)
        cnt[atIndex(s[i])]++;
}

bool isHappy(string s) {
    cnt.assign(27, 0);
    findFrequency(s);
    if (hasUniqueCharacters())
        return false;
    if (alreadyHappy(s) || hasSpace())
        return true;
    return false;
}

int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;
        cout << (isHappy(b) ? "YES" : "NO") << endl;
    }
    return 0;
}
