class MedianFinder {
    priority_queue<int> f;
    priority_queue<int, vector<int>, greater<int>> s;

   public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (s.empty()) {
            s.push(num);
        } else {
            if (num < s.top()) {
                f.push(num);
                if (f.size() > s.size()) {
                    s.push(f.top());
                    f.pop();
                }
            } else {
                s.push(num);
                if (s.size() > f.size() + 1) {
                    f.push(s.top());
                    s.pop();
                }
            }
        }
    }

    double findMedian() {
        if (s.size() == f.size()) {
            return double(s.top() + f.top()) / 2.0;
        }
        return s.top();
    }
};