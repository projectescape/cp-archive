string caseSort(string str, int n) {
    string ans = str;
    sort(str.begin(), str.end());
    int i = 0, j = 0;
    while (i < str.size() && !(str[i] >= 'a' && str[i] <= 'z')) i++;
    while (j < str.size() && !(str[j] >= 'A' && str[j] <= 'Z')) j++;
    for (int k = 0; k < str.size(); k++) {
        if (ans[k] >= 'a' && ans[k] <= 'z') {
            ans[k] = str[i++];

            while (i < str.size() && !(str[i] >= 'a' && str[i] <= 'z')) i++;
        } else {
            ans[k] = str[j++];
            while (i < str.size() && !(str[i] >= 'a' && str[i] <= 'z')) i++;
        }
    }
    return ans;
}