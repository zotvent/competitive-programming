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

string winner(int catA, int catB, int mouse) {
    int a = abs(catA - mouse);
    int b = abs(catB - mouse);
    if (a == b)
        return "Mouse C";
    else if (a < b)
        return "Cat A";
    else
        return "Cat B";
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        cout << winner(x, y, z) << endl;
    }
    return 0;
}
