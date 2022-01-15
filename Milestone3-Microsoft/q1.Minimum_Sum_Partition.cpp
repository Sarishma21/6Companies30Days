class Solution {

  public:
	int minDifference(int arr[], int n)  {

	    sort(arr, arr+n);

	    int sum = accumulate(arr, arr + n, 0);
	    
	    int half = sum/2;
	    
	    vector< vector<int> > dp(n + 1, vector<int>(half + 1, 0));
	    
	    for(int i = 0; i < n; ++i) {
	        for(int j = 1; j <= half; ++j) {
	            if(j < arr[i]) {
	                dp[i+1][j] = dp[i][j];
	                continue;
	            }
	            dp[i+1][j] = max({arr[i], dp[i][j - arr[i]] + arr[i], dp[i][j]});
	        }
	    }
	    return sum - dp.back().back()*2;
	}
};