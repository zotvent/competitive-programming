#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int temp = n, cnt = 0;
        while (temp != 0) {
            int digit = temp%10;
            if (digit && n%digit == 0)
                cnt++;
            temp /= 10;
        }
        cout << cnt << endl;
    }
    return 0;
}
