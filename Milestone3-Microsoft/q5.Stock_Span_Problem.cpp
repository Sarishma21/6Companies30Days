class Solution {
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int> previous_peak;
        previous_peak.push(0);
        
        vector<int> ans(n);
        ans[0] = 1;

        for(int i = 1; i < n; ++i) {
            while(!previous_peak.empty() && price[previous_peak.top()] <= price[i]) {
                previous_peak.pop();
            }

            ans[i] = i - (previous_peak.empty() ? -1 : previous_peak.top());
            previous_peak.push(i);
        }

        return ans;
    }
};