#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       deque<int> q;
        vector<int> res;
        
        for(int i=0; i<k; i++){
            while(not q.empty() and q.back() < arr[i])
                q.pop_back();
            q.push_back(arr[i]);
        }
        
        res.push_back(q.front());
        
        int l = 0, r = k-1;
        
        while(1){
            if(q.front() == arr[l])
                q.pop_front();
            l++;
            r++;
            if(r == n)
                break;
            while(not q.empty() and q.back() < arr[r])
                q.pop_back();
            q.push_back(arr[r]);
            res.push_back(q.front());
        }
        
        return res;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  