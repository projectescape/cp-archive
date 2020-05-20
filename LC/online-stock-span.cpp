class StockSpanner {
    stack<pair<int, int>> s;
    int count = 0;

   public:
    StockSpanner() {
    }

    int next(int price) {
        count++;
        while (!s.empty() && s.top().first <= price) {
            s.pop();
        }
        if (s.empty()) {
            s.push({price, count});
            return count;
        } else {
            int ans = count - s.top().second;
            s.push({price, count});
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */