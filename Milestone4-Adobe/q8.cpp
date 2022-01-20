// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0, k=1;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]<='9' && str[i]>='0'){
                ans=ans+(str[i]-'0')*k;
                k*=10;
            }else if (str[i]=='-'&& i==0) 
                return ans = ans*-1;
            else
                return -1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends