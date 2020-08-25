int Solution::repeatedNumber(const vector<int> &A) {
    int c1 = INT_MAX, c2 = INT_MAX, n1 = 0, n2 = 0, n = A.size();
    for (auto i : A) {
        if (i == c1)
            n1++;
        else if (i == c2)
            n2++;
        else if (n1 == 0) {
            n1 = 1;
            c1 = i;
        } else if (n2 == 0) {
            n2 = 1;
            c2 = i;
        } else {
            n1--;
            n2--;
        }
    }
    n1 = n2 = 0;
    for (auto i : A) {
        if (i == c1)
            n1++;
        else if (i == c2)
            n2++;
    }
    if (n1 > n / 3) return c1;
    if (n2 > n / 3) return c2;
    return -1;
}