#include <bits/stdc++.h>
using namespace std;


class Solution
{
    private:
    
    void solve(string s, string &res, int k, int ind){
        if(k==0)
            return;
            
        if(ind==s.size())
            return;
            
        int ch= s[ind]-'0';
        for(int i=ind+1; i<s.size();i++){
            if(ch<s[i]-'0')
                ch=s[i]-'0';
        }
        if(ch!=s[ind]-'0')
            k--;
            
        for(int i=s.size()-1;i>=ind;i--){
            if(s[i]-'0'==ch){
                swap(s[ind],s[i]);
                res=max(res,s);
                solve(s,res,k,ind+1);
                swap(s[ind],s[i]);
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string res=str;
       solve(str,res,k,0);
       return res;
    }
};



int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}