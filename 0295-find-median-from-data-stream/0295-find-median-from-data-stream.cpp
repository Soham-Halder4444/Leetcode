class MedianFinder {
public:
    priority_queue<int> left;  // max heap
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
    }
    void addNum(int num) {
        left.push(num);

        // Make sure every element in left <= every element in right
        if (!right.empty() && left.top() > right.top()) {
            int x = left.top();
            left.pop();

            right.push(x);
        }

        // Balance the sizes
        if (left.size() > right.size() + 1) {
            int x = left.top();
            left.pop();

            right.push(x);
        }
        else if (right.size() > left.size()) {
            int x = right.top();
            right.pop();

            left.push(x);
        }
    }
    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */