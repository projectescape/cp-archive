vector<int> Solution::maxone(vector<int> &A, int B) {
    int wl = 0;  //left window pointer
    int wr = 0;  //right window pointer
    int best_left = 0;
    int best_right = 0;
    int max_window_size = INT_MIN;
    int n = A.size();
    int num_zero = 0;

    while (wr < n) {
        if (A[wr] == 0)
            num_zero++;

        while (num_zero > B) {
            if (A[wl] == 0)
                num_zero--;
            wl++;
        }

        if (wr - wl + 1 > max_window_size) {
            max_window_size = wr - wl + 1;
            best_left = wl;
            best_right = wr;
        }
        wr++;
    }

    vector<int> ans;
    for (int i = best_left; i <= best_right; i++)
        ans.push_back(i);

    return ans;
}
