#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int n)
    {
       string temp="";
       while(n>0){
           char ch='A'+(n-1)%26;
           temp=ch+temp;
           n=(n-1)/26;
       }
       return temp;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}