class MedianFinder {
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!right.empty() && right.top() < num) {
            right.push(num);
            int size = left.size() + right.size();
            while (left.size() < right.size() + (size % 2)) {
                left.push(right.top());
                right.pop();
            }
        }
        else {
            left.push(num);
            if (left.size() - right.size() > 1) {
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        if ((left.size() + right.size()) % 2 == 0) {
            return (left.top() + right.top()) / 2.0;
        }
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */