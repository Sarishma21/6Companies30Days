// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int lis(vector<int> v)
 {
     vector<int> lis;
     for(int i=0;i<v.size();i++)
     {
          auto it = lower_bound(lis.begin(), lis.end(), v[i]);
         if(it!=lis.end())
         *it=v[i];
         else
         lis.push_back(v[i]);
     }
     return lis.size();
 }
    int minInsAndDel(int A[], int B[], int N, int M) {
      vector<int> v;
        unordered_set<int> s;
        
        for(int i=0;i<M;i++){
            s.insert(B[i]);
        }
        
        for(int i=0;i<N;i++){
            if(s.find(A[i])!=s.end()){
                v.push_back(A[i]); 
            }
        }
        int LCS=lis(v);
        return N+M-(2*LCS);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends