//Koko Eating Bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
          int low = 1, high = *max_element(piles.begin(), piles.end()) + 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            int sum = 0;
            for(auto p: piles) 
                sum += (p + mid -1) / mid;
            if(sum > h) low = mid + 1;
            else high = mid;
        }
        return low;
        
    }
};