#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int start=0, end=0, count=0, product=1;
        
        while(end < n){
            product=product*a[end];
            while(start<n && product>=k){
                product= product/a[start];
                start++;
            }
            if(product<k)
            count=count+end-start+1;
            end++;
        }
        return count;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int k;
		cin>>n>>k;
		vector<int>arr(n);
		for(int i=0; i<n; i++)
			cin>>arr[i];
		Solution ob;
		cout<< ob.countSubArrayProductLessThanK(arr, n, k) << endl;
	}
	return 0;
}