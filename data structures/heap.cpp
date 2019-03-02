template <typename T>
struct Heap {

private:

    int _size;
    int val[N];

    int sift_up(int pos) {
        int p = (pos - 1) / 2;

        if (val[p] < val[pos]) {
            swap(val[p], val[pos]);
            return sift_up(p);
        }

        return pos;
    }

    int sift_down(int pos) {
        int ch1 = 2 * pos + 1;
        int ch2 = 2 * pos + 2;

        if (ch1 < _size) {
            if (ch2 < _size) {
                if (val[ch1] >= val[ch2] && val[ch1] > val[pos]) {
                    swap(val[ch1], val[pos]);
                    return sift_down(ch1);
                }
                else if (val[ch2] >= val[ch1] && val[ch2] > val[pos]) {
                    swap(val[ch2], val[pos]);
                    return sift_down(ch2);
                }
            }
            else {
                if (val[ch1] > val[pos]) {
                    swap(val[pos], val[ch1]);
                    return sift_down(ch1);
                }
            }
        }

        return pos;
    }

public:

    Heap() {
        _size = 0;
    }

    int insert(int x) {
        val[_size] = x;
        int index = sift_up(_size);
        _size++;
        return index;
    }

    void add(int x) {
        val[_size++] = x;
    }

    void print() {
        for (int i = 0; i < _size; i++) {
            cout << val[i] << ' ';
        }
        cout << endl;
    }

    int increase_priority(int index, int x) {
        val[index] += x;
        return sift_up(index);
    }

    int decrease_priority(int index, int x) {
        val[index] -= x;
        return sift_down(index);
    }

    int get_max() {
        return val[0];
    }

    int extract_max() {
        _size--;
        val[0] = val[_size];
        return sift_down(0);
    }

    int remove(int pos) {
        _size--;
        int old = val[pos];
        swap(val[pos], val[_size]);

        if (val[pos] > old) {
            sift_up(pos);
        }
        else if (val[pos] < old) {
            sift_down(pos);
        }

        return old;
    }

    void build_down() {
        for (int i = _size / 2 - 1; i >= 0; i--) {
            sift_down(i);
        }
    }

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

    void sort() {
      int initial_size = _size;
      for (int i = initial_size - 1; i > 0; i--) {
        swap(val[0], val[i]);
        _size--;
        sift_down(0);
      }
      _size = initial_size;
    }

};
