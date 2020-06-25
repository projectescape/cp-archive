string Solution::solve(string A) {
    stack<string> words;
    string curr;
    for (int i = 0; i < A.size(); i++) {
        // cout << "Check 1" << i << endl;
        curr = "";
        for (; i < A.size() && A[i] != ' '; i++) {
            curr += A[i];
        }
        if (curr != "")
            words.push(curr);
    }
    string ans = "";
    while (!words.empty()) {
        ans += words.top();
        words.pop();
        if (!words.empty()) ans += " ";
    }
    return ans;
}
