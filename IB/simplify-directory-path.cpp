string Solution::simplifyPath(string A) {
    vector<string> s;
    string temp;
    for (auto i : A) {
        if (i == '/') {
            if (temp != "") {
                if (temp == ".") {
                    temp = "";
                } else if (temp == "..") {
                    temp = "";
                    if (!s.empty())
                        s.pop_back();
                } else {
                    s.push_back(temp);
                    temp = "";
                }
            }
        } else {
            temp += i;
        }
    }
    if (temp != "")
        if (temp == ".") {
            temp = "";
        } else if (temp == "..") {
            temp = "";
            if (!s.empty())
                s.pop_back();
        } else {
            s.push_back(temp);
            temp = "";
        }
    if (s.empty()) return "/";
    temp = "";
    for (auto i : s) {
        temp += "/";
        temp += i;
    }
    return temp;
}
