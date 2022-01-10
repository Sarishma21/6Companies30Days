// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
     
        priority_queue<pair<int, int>> MAXQ;

        for(int i = 0; i < k; ++i) {
            MAXQ.push({arr[i], i});
        }
        
        vector<int>ans;
        ans.push_back(MAXQ.top().first);

        for(int i = k; i < n; ++i) {
            MAXQ.push({arr[i], i});
            
            while(!MAXQ.empty() && MAXQ.top().second <= i - k) {
                MAXQ.pop();
            }
            
            ans.push_back(MAXQ.top().first);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends