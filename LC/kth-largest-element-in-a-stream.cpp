bool comp(int &a, int &b) {
    return a > b;
}

class KthLargest {
   public:
    vector<int> v;
    int size;
    KthLargest(int k, vector<int> &nums) {
        size = k;
        v = nums;
        make_heap(v.begin(), v.end(), comp);
        while (v.size() > size) {
            pop_heap(v.begin(), v.end(), comp);
            v.pop_back();
        }
    }

    int add(int val) {
        v.push_back(val);
        push_heap(v.begin(), v.end(), comp);
        while (v.size() > size) {
            pop_heap(v.begin(), v.end(), comp);
            v.pop_back();
        }
        return v[0];
    }
};