class LRUCache {
    int capacity;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

   public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        auto i = m[key];
        int val = i->second;
        l.erase(i);
        l.push_front({key, val});
        m[key] = l.begin();
        return val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.erase(m[key]);
            m.erase(key);
        }
        if (l.size() == capacity) {
            auto i = l.end();
            i--;
            m.erase(i->first);
            l.erase(i);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};