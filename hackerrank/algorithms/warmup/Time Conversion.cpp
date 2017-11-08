#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int h, m, s;
    char q, w;
    scanf("%d:%d:%d%c%c", &h, &m, &s, &q, &w);
    if (q == 'A') {
        if (h == 12) h = 0;
    }
    else {
        if (h != 12) h += 12;
    }
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
