// usage example
// n - size of the array
int n, int a[n];
quick_sort(0, n - 1);

void quick_sort(int start, int end) {
  if (start < end) {
    int m = random_partition(start, end);
    quick_sort(start, m - 1);
    quick_sort(m + 1, end);
  }
}

int random_partition(int start, int end) {
  int pivot = start + rand() % (end - start + 1);
  swap(a[end], a[pivot]);
  return partition(start, end);
}

int partition(int start, int end) {
  int pivot = end;
  int index = start;

  for (int i = start; i < end; i++) {
    if (a[i] < a[pivot]) {
      swap(a[i], a[index]);
      index++;
    }
  }
  swap(a[pivot], a[index]);

  return index;
}
