#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;
       }
};

bool compare(IceCream left, IceCream right) {
    return left.flavor < right.flavor;
}
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
   if (first == last)
       return ((search == arr[first].flavor) ? arr[first].index : -1);
    
    int middle = (first+last)/2;
    if (arr[middle].flavor > search)
        return binarySearch(first, middle, arr, search);
    else if (arr[middle].flavor < search)
        return binarySearch(middle+1, last, arr, search);
    else
        return arr[middle].index;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}

