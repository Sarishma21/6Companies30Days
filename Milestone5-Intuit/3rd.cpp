#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}

/* You are required to complete this function
which return the required missing number
if present else return -1*/

int getValue(const string& str, int i, int m)
{
    if (i + m > str.length())
        return -1;
    int value = 0;
    for (int j = 0; j < m; j++)
    {
        int c = str[i + j] - '0';
        if (c < 0 || c > 9)
            return -1;
        value = value * 10 + c;
    }
    return value;
}

int missingNumber(const string& str)
{
    for(int m=1;m<=6;m++){
       int n = getValue(str, 0, m);
        if (n == -1)
           break;
        int missingNo = -1;
        bool fail = false;
        for (int i=m; i!=str.length(); i += 1 + log10l(n))
        {
            if ((missingNo == -1) &&
                (getValue(str, i, 1+log10l(n+2)) == n+2))
            {
                missingNo = n + 1;
                n += 2;
            }
            else if (getValue(str, i, 1+log10l(n+1)) == n+1)
                n++;
 
            else
            {
                fail = true;
                break;
            }
        }
 
        if (!fail)
          return missingNo;
            
        }
        
    
    return -1;
}