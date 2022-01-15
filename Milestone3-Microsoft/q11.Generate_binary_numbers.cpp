vector<string> generate(int N) {
    vector<string> ans(N);

	for(int i = 1; i <= N; ++i) {
	    int num = i;
	    while(num) {
	        ans[i - 1] += (char) ('0' + (num & 1));
	        num >>= 1;
	    }
	    reverse(ans[i - 1].begin(), ans[i - 1].end());
	}

	return ans;
}