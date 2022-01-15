class Solution {
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);

        arr[2] = max(arr[1], arr[0] + arr[2]);

        for(int i = 3; i < n; ++i) {
            arr[i] = max({arr[i-1], arr[i-2] + arr[i], arr[i-3] + arr[i]});
        }

        return arr[n-1];
    }
};