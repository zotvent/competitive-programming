class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
        }
        else {
            right.push(num);
            if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        double sum = left.top() + right.top();
        return sum / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
