/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval &a, Interval &b) {
    if (a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<Interval> ans;
    if (A.size() == 0) return ans;
    sort(A.begin(), A.end(), comp);

    int s = -1, e = -1;

    for (auto i : A) {
        if (e < i.start) {
            if (e != -1)
                ans.push_back(Interval(s, e));
            s = i.start;
            e = i.end;
        } else if (e <= i.end) {
            e = i.end;
        }
    }
    if (s != -1) ans.push_back(Interval(s, e));
    return ans;
}
