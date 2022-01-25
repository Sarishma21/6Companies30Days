// Find in Mountain Array

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
         int max_index = 0;
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
            
        }
       
        max_index = low;
        low = 0; high = max_index;
        while(low <= high){
             int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) < target)
                low = mid + 1;
            else if(mountainArr.get(mid) == target)
                return mid;
                
            else
                high = mid - 1;
            
            
        }
        
        low = max_index + 1, high = n - 1;
        while(low <= high){
             int mid = low + (high - low) / 2;
             if(mountainArr.get(mid) > target)
                low = mid + 1;
            
            else if(mountainArr.get(mid) == target)
                return mid;
                
            
            else
                high = mid - 1;
            
            
        }
        return -1;  
    }
};