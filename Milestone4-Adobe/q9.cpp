// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
//9th question.
class Solution{
  public:
    string nextPalin(string s) { 
        //complete the function here
        int n = s.size();
        string half = s.substr(0,n/2);
        //string ans = "";
        while(next_permutation(half.begin(),half.end())){
            string ans = half;
            if(n&1){
                ans+=s[n/2];
            }
            reverse(half.begin(),half.end());
            ans+=half;
            return ans;
        }
        return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends