#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    long long countWays(int m)
    {
        long long ans=m/2+1;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl;
    }
    return 0;
}  