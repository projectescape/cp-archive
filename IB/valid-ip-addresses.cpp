void helper(string &A, vector<string> &ans, string curr, int i, int j) {
    if (j == 4) {
        if (i == A.size()) {
            curr.pop_back();
            ans.push_back(curr);
        }
        return;
    }
    string temp;

    for (int k = i, a = 0; k < A.size() && a < 3 && temp != "0"; k++, a++) {
        temp += A[k];
        if (stoi(temp) > 255) break;
        helper(A, ans, curr + temp + '.', k + 1, j + 1);
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    string curr;
    helper(A, ans, "", 0, 0);
    return ans;
}
