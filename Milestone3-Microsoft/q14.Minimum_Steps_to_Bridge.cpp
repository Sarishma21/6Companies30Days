class Solution {
public:
    int minSteps(int D, int position = 0, int lastStep = 0) {
        
        if(abs(position) == D) return 0;
        else if(abs(position) > D) return numeric_limits<int>::max();

        return min(
            minSteps(D, position + lastStep + 1, lastStep + 1),
            minSteps(D, position - lastStep - 1, lastStep + 1)
        ) + 1;
        
    }
};