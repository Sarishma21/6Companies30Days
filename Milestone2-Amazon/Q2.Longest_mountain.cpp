class Solution {
public:
    bool isLocalMin(vector<int>& arr, int index) {
        int lastIndex = arr.size() - 1;

        if(index == 0) {
            return arr[0] < arr[1];
        }
        else if(index == lastIndex) {
            return arr[lastIndex - 1] > arr[lastIndex];
        }
        else {
            return arr[index - 1] >= arr[index] && arr[index] <= arr[index + 1];
        }
    }
    bool isLocalMax(vector<int>& arr, int index) {
        int lastIndex = arr.size() - 1;

        if(index == 0) {
            return arr[0] > arr[1];
        }
        else if(index == lastIndex) {
            return arr[lastIndex - 1] < arr[lastIndex];
        }
        else {
            return arr[index - 1] < arr[index] && arr[index] > arr[index + 1];
        }
    }
    int longestMountain(vector<int>& arr) {
        
        if(arr.size() < 3) return 0;
        
        int ans = 0;
        int lastLocalMin = -1;
        int lastLocalMax = -1;
        
        for(int i = 0; i < arr.size(); ++i) {
            if(isLocalMin(arr, i)) {
                if(lastLocalMin >= 0 && lastLocalMin < lastLocalMax && lastLocalMax < i) {
                    ans = max(ans, i - lastLocalMin + 1);
                }
                lastLocalMin = i;
            }
            else if(isLocalMax(arr, i)) {
                lastLocalMax = i;
            }
        }

        return ans;
    }
};