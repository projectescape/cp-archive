string Solution::convert(string A, int B) {
    if (B == 1) return A;
    vector<string> v(B, "");
    int temp = 0;
    bool inc = true;
    for (int i = 0; i < A.size(); i++) {
        v[temp] += A[i];
        if (temp == 0) {
            inc = true;
            temp++;
        } else if (temp == B - 1) {
            inc = false;
            temp--;
        } else if (inc)
            temp++;
        else
            temp--;
    }
    string ans = "";
    for (auto i : v) {
        ans += i;
    }
    return ans;
}
