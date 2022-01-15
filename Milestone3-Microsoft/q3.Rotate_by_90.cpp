void rotate(int n,int a[][n])
{
    int limit = (n+1)/2;

    for(int r = 0; r < limit; ++r) {
        for(int c = r; c < n-r-1; ++c) {
            int temp = a[r][c];
            a[r][c] = a[c][n - r - 1];
            a[c][n - r - 1] = a[n - r - 1][n - c - 1];
            a[n - r - 1][n - c - 1] = a[n - c - 1][r];
            a[n - c - 1][r] = temp;
        }
    }
}