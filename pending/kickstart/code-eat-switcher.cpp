#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    // cout << "inside comp" << endl;
    if (a.first == 0) {
        if (b.first == 0) {
            return a.second < b.second;
        }
        return true;
    }
    if (b.first == 0) {
        return false;
    }
    return ((double)a.first / (double)a.second) < ((double)b.first / (double)b.second);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int D, S, C, E, A, B;
        cin >> D >> S;
        vector<pair<int, int>> CE;
        vector<pair<int, int>> AB;
        // CE.push_back({0, 0});
        // AB.push_back({0, 0});
        for (int i = 0; i < S; i++) {
            cin >> C >> E;
            CE.push_back({C, E});
        }
        // cout << "stored s" << endl;
        sort(CE.begin(), CE.end(), comp);
        // for (int i = 0; i < S; i++) {
        //     cout << CE[i].first << " " << CE[i].second << endl;
        // }

        for (int i = 0; i < D; i++) {
            cin >> A >> B;
            AB.push_back({A, B});
        }
        }
}