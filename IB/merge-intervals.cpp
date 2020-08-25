vector<Interval> Solution::insert(vector<Interval> &in, Interval newInterval) {
    int a = newInterval.start;
    int b = newInterval.end;
    vector<Interval> ans;
    int i = 0;
    bool flag = true;
    for (; i < in.size(); i++) {
        if (a > in[i].end) {
            ans.push_back(in[i]);
            continue;
        } else if (b < in[i].start) {
            flag = false;
            ans.push_back(newInterval);
            break;
        } else if ((a >= in[i].start && a <= in[i].end) || (b >= in[i].start && b <= in[i].end)) {
            flag = false;
            a = min(in[i].start, a);
            while (i < in.size() && in[i].start <= b) {
                b = max(b, in[i].end);
                i++;
            }
            ans.push_back(Interval(a, b));
            break;
        }
    }
    for (; i < in.size(); i++) {
        ans.push_back(in[i]);
    }
    if (flag) {
        ans.push_back(newInterval);
    }
    return ans;
}
