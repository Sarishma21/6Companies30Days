//Split array largest sum

class Solution {
public:
    
    bool check(int mid, vector<int>&nums, int m){
        int tot = 0, arr = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mid)
                return false;
            if(tot+nums[i] <= mid)
                tot += nums[i];
                else{
                    arr++;
                    tot = nums[i];
                }
            }
            arr++;
            return(arr <= m);
        
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = (int)(1e9+1);
        while(low < high){
            int mid = low + (high-low) / 2;
            if(check(mid,nums,m))
            high = mid;
            else
                low = mid+1;
            
        }
        return low;
        
    }
};