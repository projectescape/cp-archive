int Solution::findCount(const vector<int> &A, int B) {
    int s = 0, e = A.size() - 1, mid;
    for (; s <= e;) {
        mid = s + (e - s) / 2;
        if (A[mid] == B) {
            break;
        }
        if (A[mid] > B) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    if (s > e) {
        return 0;
    }
    for (s = mid; s >= 0; s--) {
        if (A[s] != B) {
            s++;
            break;
        }
    }
    if (s == -1) s = 0;
    for (e = mid; e < A.size(); e++) {
        if (A[e] != B) {
            e--;
            break;
        }
    }
    if (e == A.size()) e = A.size() - 1;

    return e - s + 1;
}
