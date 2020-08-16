vector<string> Solution::prettyJSON(string A) {
    int tab = 0;
    string ans = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == ']' || A[i] == '}') {
            ans += '\n';
            tab--;
            for (int j = 0; j < tab; j++) ans += '\t';
            ans += A[i];
            continue;
        }
        if (A[i] == '{' || A[i] == '[') {
            ans += A[i];
            tab++;
            ans += '\n';
            for (int j = 0; j < tab; j++) ans += '\t';
            continue;
        } else if (A[i] == ',') {
            ans += A[i];
            ans += '\n';
            for (int j = 0; j < tab; j++) ans += '\t';
            continue;
        } else if (A[i] == ':') {
            ans += A[i];
            if (A[i + 1] == '{' || A[i + 1] == '[') {
                ans += '\n';
                for (int j = 0; j < tab; j++) ans += '\t';
            }
            continue;
        }
        ans += A[i];
    }
    vector<string> ret;
    string temp;
    for (auto i : ans) {
        if (i == '\n') {
            ret.push_back(temp);
            temp = "";
        } else {
            temp += i;
        }
    }
    ret.push_back(temp);
    return ret;
}
