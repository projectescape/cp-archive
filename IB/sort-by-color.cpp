void Solution::sortColors(vector<int> &A) {
    int i, j, k;
    for (i = 0; i < A.size() && A[i] == 0; i++)
        ;
    for (j = A.size() - 1; j >= 0 && A[j] == 2; j--)
        ;
    for (k = i; k <= j;) {
        if (A[k] == 0 && k > i) {
            swap(A[k], A[i]);
            i++;
        } else if (A[k] == 2 && k < j) {
            swap(A[k], A[j]);
            j--;
        } else
            k++;
    }
}
