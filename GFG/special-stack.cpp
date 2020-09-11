stack<pair<int, int>> p;

void push(int a) {
    if (p.empty())
        p.push({a, a});
    else {
        int m = min(p.top().second, a);
        p.push({a, m});
    }
}

bool isFull(int n) {
    return p.size() == n;
}

bool isEmpty() {
    return p.empty();
}

int pop() {
    int ans = p.top().first;
    p.pop();
    return ans;
}

int getMin() {
    return p.top().second;
}