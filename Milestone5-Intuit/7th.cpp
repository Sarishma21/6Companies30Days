//Capacity To Ship Packages Within D Days

class Solution {
public:
    
     bool isCheck(int mid, vector<int>&weights, int days){
        int day = 1, sum = 0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>mid)
                return false;
            if(sum+weights[i] <= mid)
                sum += weights[i];
                else{
                    day++;
                    sum = weights[i];
                }
            }
           
            return(day <= days);
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
         int low = 0, high = (int)(1e9+1);
            while(low < high){
            int mid = low + (high-low) / 2;
            if(isCheck(mid,weights,days))
            high = mid;
            else
                low = mid+1;
            
        }
        return low;
        
        
    }
};