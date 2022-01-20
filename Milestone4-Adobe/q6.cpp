// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void f(int o,int c,string op,vector<string>&ans){
        if(c<o || c<0 || o<0 )return;
        if(c==0 && o==0){
            ans.push_back(op);
            return ;
        }
        f(o-1,c,op+"(",ans);
        f(o,c-1,op+")",ans);
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        f(n,n,"",ans);
        return ans;
        
                // Your code goes here 
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends