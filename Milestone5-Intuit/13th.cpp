//Minimum Swaps to Arrange a Binary Grid

class Solution {
public:
   int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n == 0){
        return 0;
    }

    vector<int> Rytzero(n, 0);
    int res = 0;
    
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=1; j--){
            if(grid[i][j] == 0){
		
                Rytzero[i]++;
            } 
			
            else{
                break;
            }
        }
    }
    
    for(int i=0; i<n-1; i++){
	
        int ans = n-i-1;
        int k=i;
        while(k < n && min(ans, Rytzero[k]) != ans){
            k++;
        }
       
        if(k == n){
            return -1;
        }
 
        res += (k - i);

        while(k > i){
            swap(Rytzero[k], Rytzero[k-1]);
            k--;
        }
    }
   
    return res;
}
    
};