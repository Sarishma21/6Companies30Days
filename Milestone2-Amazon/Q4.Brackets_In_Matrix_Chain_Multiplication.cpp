#include <bits/stdc++.h>
using namespace std;
#define pis pair<int, string>
class Solution{
public:
    string matrixChainOrder(int A[], int n){
         vector<vector<pis>> DP(n-1, vector<pis>(n-1));

        for(int i = 0; i < n-1; ++i) {
            string M = "";
            M += (char) ('A' + i);
            DP[i][i] = { 0, M };
        }
        

        for(int size = 1; size <= n; ++size) {
            int l = 0;
            int m = size;

            while(m < n-1) {

                DP[l][m].first = numeric_limits<int>::max();
    
                for(int i = l; i < m; ++i) {
                    int operations = DP[l][i].first + DP[i+1][m].first + A[l]*A[i+1]*A[m+1];

                    if(DP[l][m].first > operations) {
                        DP[l][m].second = "(" + DP[l][i].second + DP[i+1][m].second + ")";
                        DP[l][m].first = operations;
                    }
                    
                }

                ++l;
                ++m;
            }
        }

        return DP[0].back().second;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}