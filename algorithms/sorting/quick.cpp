// usage example
// n - size of the array
int n;
vector<int> a;
quick_sort(a, 0, n);

void quick_sort(vector<int> &array, int l, int r) {
    if (l < r) {
        int q = random_partition(array, l, r);
        if (q == -1) {
            return;
        }
        quick_sort(array, l, q);
        quick_sort(array, q + 1, r);
    }
}

int random_partition(vector<int> &array, int l, int r) {
    int i = rand() % (r - l);
    swap(array[l + i], array[r - 1]);
    return partition(array, l, r);
}

int partition(vector<int> &array, int l, int r) {
    int x = array[r - 1];
    int i = l - 1;
    int cnt = 0;

    for (int j = l; j < r - 1; j++) {
        if (array[j] <= x) {
            cnt += (array[j] == x ? 1 : 0);
            swap(array[++i], array[j]);
        }
    }

    swap(array[++i], array[r - 1]);

    // case if all numbers are equal
    if (cnt == r - l - 1) {
        i = -1;
    }

    return i;
}
