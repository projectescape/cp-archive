class MinStack {
    stack<pair<int, int>> s;

   public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (s.empty())
            s.push({x, x});
        else {
            s.push({x, (x < s.top().second ? x : s.top().second)});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

// class MinStack {
//     stack<int> s;
//     vector<pair<int, int>> v;

//    public:
//     /** initialize your data structure here. */
//     MinStack() {
//     }

//     void push(int x) {
//         s.push(x);
//         if (v.empty()) {
//             v.push_back({x, 1});
//         } else {
//             if (v[v.size() - 1].first > x) {
//                 v.push_back({x, s.size()});
//             }
//         }
//     }

//     void pop() {
//         s.pop();
//         if (v[v.size() - 1].second > s.size()) v.pop_back();
//     }

//     int top() {
//         return s.top();
//     }

//     int getMin() {
//         return v[v.size() - 1].first;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */