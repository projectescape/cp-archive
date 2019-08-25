#include <bits/stdc++.h>
using namespace std;

class graph {
   public:
    int num;
    vector<int> ctd;
};

int update(int c, graph obj[], int n) {
    for (int i = 0; i < obj[c].ctd.size(); i++) {
        for (int j = 0; j < obj[c].ctd.size(); j++) {
            if (i == j) continue;
            if (find(obj[obj[c].ctd[i]].ctd.begin(), obj[obj[c].ctd[i]].ctd.end(), obj[c].ctd[j]) == obj[obj[c].ctd[i]].ctd.end()) {
                obj[obj[c].ctd[i]].ctd.push_back(obj[c].ctd[j]);
            }
        }
    }
    return 0;
}
int connect(int c, int d, graph obj[], int n) {
    for (int i = 0; i < obj[c].ctd.size(); i++) {
        if (find(obj[d].ctd.begin(), obj[d].ctd.end(), obj[c].ctd[i]) == obj[d].ctd.end()) {
            obj[d].ctd.push_back(obj[c].ctd[i]);
        }
    }
    for (int i = 0; i < obj[d].ctd.size(); i++) {
        if (find(obj[c].ctd.begin(), obj[c].ctd.end(), obj[d].ctd[i]) == obj[c].ctd.end()) {
            obj[c].ctd.push_back(obj[d].ctd[i]);
        }
    }
    obj[d].ctd.push_back(c);
    obj[c].ctd.push_back(d);
    update(c, obj, n);
    update(d, obj, n);
    // for (int i = 0; i < obj[c].ctd.size(); i++)
    //     for (int j = 0; j < obj[d].ctd.size(); j++)
    //         check(i, j, obj, n);
    return 0;
}

int check(int c, int d, graph obj[], int n) {
    if ((find(obj[c].ctd.begin(), obj[c].ctd.end(), d) == obj[c].ctd.end())
        //  && (find(obj[d].ctd.begin(), obj[d].ctd.end(), c) == obj[d].ctd.end())
    ) {
        connect(c, d, obj, n);
        return 1;
    }
    // cout << c << " and " << d << " already connected" << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m, c, d, temp = 0, ans;
        cin >> n >> m;
        graph obj[n + 1];
        for (int i = 1; i <= n; i++) {
            obj[i].num = i;
        }
        for (int i = 0; i < m; i++) {
            cin >> c >> d;
            temp += check(c, d, obj, n);
        }

        ans = temp + (n - 1 - temp) * 2;
        cout << "Case #" << i << ": " << ans << endl;
        // cout << "temp " << temp << endl;
    }
}